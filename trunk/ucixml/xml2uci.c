#include <stdio.h>
#include <stdbool.h>
#include <dirent.h>
#include <string.h>
#include <expat.h>

#define UCI_DIR "./output"
#define XML_FILE "config.xml"

enum node_type
{
	INVALID = 0,
	PACKAGE = 1,
	SECTION,
	OPTION,
};

int depth, slen;
enum node_type el_type;
char el_name[64], el_section[64], last_section[64], last_option[64];

FILE *outfile;
bool has_changed = false;// option changed to 'section'
bool is_list = false, last_islist = false;

void
start(void *data, const char *el, const char **attr)
{
	int i;
	char filename[128];

	strcpy(el_name, el);
	depth++;

	switch(depth) {
		case 2:
			el_type = PACKAGE;
			sprintf(filename, "./output/%s", el_name);
			outfile = fopen(filename, "w");
			break;
		case 3:
			el_type = SECTION;
			last_section[0] = '\0';
			break;
		case 4:
		case 5:
			el_type = OPTION;
			break;
		default:
			el_type = INVALID;
	}
	has_changed = false;
	
}  /* End of start handler */

void
end(void *data, const char *el) 
{
	if(el_type != OPTION && strlen(last_option) > 0) {
		fprintf(outfile, "\t%s %s\n", 
				(is_list ? "list" : "option"), last_option);
		last_option[0] = '\0';
	}

	if(depth == 2 && outfile) {
		fprintf(outfile, "\n");

		if(outfile != stdout && outfile != stderr)
			fclose(outfile);
	}

	el_type = INVALID;
	depth--;
}  /* End of end handler */

void value_handler(void *data, const char *s, int len)
{
	int i = 0;	
	char value[256];

	if(el_type != OPTION && el_type != SECTION) return;

	if(strncmp(s + len + 2, el_name, strlen(el_name)) != 0) {
		if(el_type == SECTION && has_changed == false) {
			sprintf(el_section, "\nconfig %s", el_name);	
			slen = strlen(el_section);
		} 
		else if(el_type == OPTION && has_changed == false) {
			if(len > 1 || s[0] == '*' ||
				(s[0] > '0' && s[0] < '9') ||
				(s[0] > 'a' && s[0] < 'z') ||
				(s[0] > 'A' && s[0] < 'Z')) {
				goto begin;
			}
			sprintf(el_section + slen, " '%s'", el_name);	
			el_type = SECTION;
		}
		else {
			return;
		}

		has_changed = true;
		return;
	} 

begin:
	if(strcmp(el_section, last_section) != 0) {
		fprintf(outfile, "%s\n", el_section);
		strcpy(last_section, el_section);
	}

	strncpy(value, s, len);
	value[len] = '\0';

        if(strncmp(last_option, el_name, strlen(el_name)) == 0) {
                is_list = true;
        }
        else {
                is_list = false;
        }

        if(last_option[0] != '\0') {
                fprintf(outfile, "\t%s %s\n",
				((is_list||last_islist) ? "list" : "option"), 
				last_option);
        }

	sprintf(last_option, "%s '%s'", el_name, value);
	last_islist = is_list;

	return;
}

#define BUF_SIZE 40960
int main(int argc, char **argv)
{
	XML_Parser parser;
	FILE *fp;
	char *buf;
	int len = 0, ret = 0;

	outfile = stdout;
	
	if(!(fp = fopen(XML_FILE, "r"))) {
		fprintf(stderr, "failed to open %s\n", XML_FILE);
		return -1;
	}

	parser = XML_ParserCreate(NULL);
	XML_SetElementHandler(parser, start, end);
	XML_SetCharacterDataHandler(parser, value_handler);
	while(!feof(fp)) {
		if(!(buf = XML_GetBuffer(parser, BUF_SIZE))) {
			fprintf(stderr, "failed to malloc buffer\n");
			ret = -1;
			goto done;
		}
		
		len = fread(buf, 1, BUF_SIZE, fp);
		if(!XML_ParseBuffer(parser, len, len != BUF_SIZE)) {
			printf("Parse error at line %u, Column %d, \n%s\n",
                	     	(int)XML_GetCurrentLineNumber(parser),
				(int)XML_GetCurrentColumnNumber(parser),
				XML_ErrorString(XML_GetErrorCode(parser)));
			break;	
		}	
	}

done:
	XML_ParserFree(parser);
	fclose(fp);
	return 0;
}

