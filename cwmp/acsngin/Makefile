

all:
	gcc -DDEBUG -DWITH_COOKIES -o cwmp cwmp_acs_impl.c soapC.c soapClient.c soapServer.c stdsoap2.c session.c -lpthread -lmysqlclient
	
clean:
	rm -rf cwmp 

