CFLAGS=-g -Wall
CC=gcc
LIBS=-llua5.1

all: rlp_base.clua rlp

install: rlp_base.clua rlp
	cp clp /www
	cp rlp_base.clua /www

rlp_base: rlp_base.lua
	luac -o rlp_base -s rlp_base.lua

rlp: rlp.o
	gcc clp.o -o clp ${LIBS}

clean:
	rm -f *.o *.a *.clua *.cgi 
