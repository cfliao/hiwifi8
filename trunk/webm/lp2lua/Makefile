CFLAGS=-g -Wall
CC=gcc
LIBS=-llua5.1

all: rlp_base rlp

install: rlp_base rlp
	cp rlp rlp_base /www

rlp_base: rlp_base.lua
	luac -o rlp_base -s rlp_base.lua

rlp: rlp.o
	gcc rlp.o -o rlp ${LIBS}

clean:
	rm -f rlp rlp_base *.o
