CC=gcc
CFLAGS=-lraylib -lGL -lm -lpthread -ldl -lrt -lX11
SRC=sort.c
TARGET=csort

default:
	${CC} ${SRC} -o ${TARGET} ${CFLAGS} 


db:
	${CC} ${SRC} -o ${TARGET} ${CFLAGS} -g
