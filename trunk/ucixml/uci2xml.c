#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <dirent.h>
#include <string.h>

#define UCI_DIR "./config"
#define XML_FILE "config2.xml"

#define BUF_SIZE 256
int get_cfg_parent(char *config, char *cfg_parent)
{
	char *el = 0, *el2 = 0;
	int len = 0;

	el = strchr(config, ' ');	
	if(!el && !(el = strchr(config, '\t'))) return 0;

	while(*el == ' ' || *el == '\t' || *el == '\'') el++;
	
	el2 = el;
	while(*el2 != '\0' && *el2 != ' ' && 
		*el2 != '\'' && *el2 != '\t' && *el2 !='\n') el2++;

	if(*el2 == '\0') return len;
	
	len = el2 -el;
	while(*el2 == ' ' || *el2 == '\'' || *el2 =='\t' || *el2== '\n') el2++;

	if(strlen(el) > 0) 
		strncpy(cfg_parent, el, len);
	else
		len = 0;

	cfg_parent[len] = '\0';
	
	return len;
}

void config_out(FILE *xmlfile, char *config, char *save)
{
	char *el = 0, *el2 = 0;

	el = strchr(config, ' ');
	if(!el && !(el = strchr(config, '\t'))) return;
	
	while(*el == ' ' || *el == '\t' || *el == '\'') el++;
	el2 = strchr(el, ' ');
	if(el2) {
		*el2++ = '\0';
		while(*el2 == ' ' || *el2 == '\t' || *el2 == '\'') el2++;

		fprintf(xmlfile, "      <%s>\n", el2);
		strcpy(save, el2);
	}
	else {
		fprintf(xmlfile, "    <%s>\n", el);
		strcpy(save, el);
	}
}

void option_out(FILE *xmlfile, char *option, bool depth)
{
	int i = 0;
	char *el, *val, *p;
	char *null = "";

	el = strchr(option, ' ');
	if(!el) {
		fprintf(stderr, "fomat error\n");
		return;
	}

	while(*el == ' ' || *el == '\t' || *el == '\'' || *el == '\"') el++;

	val = el;
	while(*val != ' ' && *val != '\'' && *val != '\"' && *val != '\t')
		val++;

	*val++ = '\0';
	while(*val == ' ' || *val == '\t' || *val == '\'' || *val=='\"') val++;

	p = val + strlen(val);
	
	while(*p == ' ' || *p == '\n' || *p == '\t' || *p == '\0'
			|| *p == '\'' ||*p == '\"' || *p == '\n')
		p--;
	*(p+1) = '\0';
	
	if(depth)
		fprintf(xmlfile, "        <%s>%s</%s>\n", el, val, el);
	else
		fprintf(xmlfile, "      <%s>%s</%s>\n", el, val, el);
}


int uci2xml(FILE *xmlfile, const char *package)
{
	char filename[128], buf[BUF_SIZE], *begin, *p;
	int i = 0, len = 0;
	FILE *ucifile = NULL;
	char tmp[128], element[128], last_cfg_parent[128];

	tmp[0]= '\0'; element[0] = '\0'; last_cfg_parent[0] = '\0';
	sprintf(filename, UCI_DIR"/%s", package);
	if(!(ucifile = fopen(filename, "r"))) {
		fprintf(stderr, "failed to open %s\n", filename);
		return -1;
	}

	fprintf(xmlfile, "  <%s>\n", package);
	while(!feof(ucifile)) {
		buf[0] = '\0';
		fgets(buf, BUF_SIZE, ucifile);
		
		len = strlen(buf);

		begin = NULL;
		for(i = 0; i< len; i++) {
			if(buf[i] != ' ' && buf[i] != '\t' && buf[i] != '\n') {
				if(buf[i] == '\'') continue;
				if(buf[i] != '#') begin = buf + i;
				break;
			}
		}
		
		if(!begin) continue;

		p = strchr(begin, '#');
		if(p) 
			*p = '\0';
		else 
			p = begin + strlen(begin);
	
		while(p-- > begin) {
			if(*p != ' ' && *p != '\t' && *p != '\n' && 
			   *p != '\'' && *p !='\r' && *p != '\'') {
				*(p+1) = '\0';
				break;
			}
		}
	
		if(strncmp(begin, "config", 6) == 0) {
			len = get_cfg_parent(begin, tmp);

			if(element[0] != '\0' && last_cfg_parent[0] == '\0')
				fprintf(xmlfile, "    </%s>\n", element);
			else if(element[0] != '\0')
				fprintf(xmlfile, "      </%s>\n", element);

			if(last_cfg_parent[0] != '\0') {
				if(strcmp(last_cfg_parent, tmp) != 0) {
					fprintf(xmlfile, "      </%s>\n", 
					last_cfg_parent);	
					last_cfg_parent[0] = '\0';
			   	}	
				//last_cfg_parent[0] = '\0';
			}

			if(len && strcmp(last_cfg_parent, tmp) != 0) {
                                fprintf(xmlfile, "    <%s>\n", tmp);
                                strcpy(last_cfg_parent, tmp);
			}

			config_out(xmlfile, begin, element);
		}
		else if((strncmp(begin, "option", 6) == 0) || 
					(strncmp(begin, "list", 4) == 0)) {
			option_out(xmlfile, begin, true);
		}
	}

	if(element[0] != '\0')
		if(last_cfg_parent[0] == '\0')
			fprintf(xmlfile, "    </%s>\n", element);
		else
			fprintf(xmlfile, "      </%s>\n", element);

	if(last_cfg_parent[0] != '\0')
		fprintf(xmlfile, "   </%s>\n", last_cfg_parent);
	
	fprintf(xmlfile, "  </%s>\n", package);
	fclose(ucifile);
	return 0;
}

int main(int argc, char **argv)
{
	DIR *dir;
	struct dirent *ptr;
	FILE *xmlfile = NULL;

	time_t t;
	time(&t);

#if 0
	if(!(xmlfile = fopen(XML_FILE, "w")))  {
		fprintf(stderr, "failed to create config.xml\n");
		return -1;
	}
#endif

	xmlfile = stdout;

	fprintf(xmlfile,"<?xml version=\"1.0\"?>\n"
			"<!-- \n"
			"  system configuration at %s -->\n"
			"<configuration>\n", ctime(&t));

	if(!(dir = opendir(UCI_DIR))) {
		fprintf(stderr, "failed to read config directory\n");
		fclose(xmlfile);
		return -1;
	}

	while((ptr = readdir(dir))) {
		if((strcmp(ptr->d_name, ".") == 0) || 
				(strcmp(ptr->d_name, "..") == 0)) 
			continue;
//		if(uci2xml(xmlfile, "dropbear")) {
		if(uci2xml(xmlfile, ptr->d_name)) {
			fprintf(stderr,"failed to translate %s\n", ptr->d_name);
			break;
		}
//		break;
	}
	closedir(dir);

	fprintf(xmlfile, "</configuration>\n");
	if(xmlfile != stdout && xmlfile != stderr)
		fclose(xmlfile);

	return 0;
}

