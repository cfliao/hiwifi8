Server 	= {}
Post	= {}
Get		= {}
Request = {}
Cookies	= {}
Session	= {}

IsPost 	= false
IsGet	= true
function InitClpBase()
	Server.ServerSoftware = os.getenv("SERVER_SOFTWARE")
	Server.ServerName = os.getenv("SERVER_NAME")
	Server.GatewayInterface = os.getenv("GATEWAY_INTERFACE")
	Server.ServerProtocol = os.getenv("SERVER_PROTOCOL")
	Server.ServerPort = os.getenv("SERVER_PORT")
	Server.RequestMethod = os.getenv("REQUEST_METHOD")
	Server.PathInfo = os.getenv("PATH_INFO")
	Server.PathTranslated = os.getenv("PATH_TRANSLATED")
	Server.ScriptName = os.getenv("SCRIPT_NAME")
	Server.QueryString = os.getenv("QUERY_STRING")
	Server.RemoteHost = os.getenv("REMOTE_HOST")
	Server.RemoteAddr = os.getenv("REMOTE_ADDR")
	Server.AuthType = os.getenv("AUTH_TYPE")
	Server.RemoteUser = os.getenv("REMOTE_USER")
	Server.RemoteIdent = os.getenv("REMOTE_IDENT")
	Server.RenderBody = os.getenv("COMPILED_LUA_FILE");

	Server.ContentLength = os.getenv("CONTENT_LENGTH")
	Server.HttpAccept = os.getenv("HTTP_ACCEPT")
	Server.UserAgent = os.getenv("HTTP_USER_AGENT")
	Server.Referer = os.getenv("HTTP_REFERER")
	Server.Cookie = os.getenv("HTTP_COOKIE")
	Server.ContentType = os.getenv("CONTENT_TYPE")

	if Server.RequestMethod == "POST" then
		IsPost 	= true
		IsGet	= false
	end

	if IsPost then
		if Server.ContentType == "application/x-www-form-urlencoded" then
			cgiParsePostFormInput()
		elseif Server.ContentType == "multipart/form-data" then
			cgiParsePostMultipartInput()
		end
	end

	if Server.QueryString ~= nil and #Server.QueryString > 0 then
		cgiParseFormInput(Server.QueryString, #Server.QueryString, false)
	end
end

function cgiParseFormInput(data, length, ispost)
	-- url decode (from www.lua.org guide)
	local unescape = function(s)
		s = string.gsub(s, "+", " ")
		s = string.gsub(s, "%%(%x%x)", function (h)
			return string.char(tonumber(h, 16))
			end)
		return s
	end
	
	for k, v in string.gmatch(data, "([^&=]+)=([^&=]+)") do
		k = unescape(k)
		v = unescape(v)
		--[[
		if ispost then
			Post[k] = v
		else
			Get[k] = v
		end]]
		Request[k] = v
	end
end

function cgiParsePostFormInput()
	local length = tonumber(Server.ContentLength)
	if  length > 0 then
		Server.ContentData = io.read(length)
		return cgiParseFormInput(Server.ContentData, length, true)
	end
end

function cgiParsePostMultipartInput()
	local length = tonumber(Server.ContentLength)
	if length > 0 then
		Server.ContentData = io.read(length)
	end
end

function RenderBody()
	if Server.RenderBody then
		dofile(Server.RenderBody);
	end
end

function Layout()
	dofile("/tmp/layout.clua");
end

function Authentication()
	return true
end

function Controller()
	
end

InitClpBase()
if not Authentication() then
	dofile("/www/login.lp")
end

Controller()

print("Content-type: text/html\r\n");
Layout();
