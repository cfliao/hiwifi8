CFLAGS=-g -Wall
CC=gcc
LIBS=-llua5.1

all: lparser rlp_base rlp lp2lua 

install: rlp_base rlp
	cp rlp rlp_base /www

lparser: lparser.o
	
lp2lua: lp2lua.o lparser.o
	gcc lp2lua.o lparser.o -o lp2lua ${LIBS}

rlp_base: rlp_base.lua
	luac -o rlp_base -s rlp_base.lua

rlp: rlp.o
	gcc rlp.o lparser.o -o rlp ${LIBS}

clean:
	rm -f rlp rlp_base lp2lua *.o
