CFLAGS=-g -Wall
CC=gcc
LIBS=-llua5.1

all: rlp_base rlp lp2lua

install: rlp_base rlp
	cp rlp rlp_base /www

lp2lua: lp2lua.o
	gcc lp2lua.o -o lp2lua ${LIBS}

rlp_base: rlp_base.lua
	luac -o rlp_base -s rlp_base.lua

rlp: rlp.o
	gcc rlp.o -o rlp ${LIBS}

clean:
	rm -f rlp rlp_base lp2lua *.o
