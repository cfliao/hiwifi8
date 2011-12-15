

all:
	gcc -DDEBUG -DWITH_COOKIES -o cwmp cwmp_acs_impl.c cwmp_rpc.c soapC.c soapClient.c soapServer.c stdsoap2.c database.c session.c log.c -lpthread -lmysqlclient
	
clean:
	rm -rf cwmp 

