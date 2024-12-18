SRCS=$(wildcard src/*.c)
OBJS=$(SRCS:.c=.o)
HEADERS=$(SRCS:.c=.h)
TARGET=build/go

$(shell mkdir -p build/)

${TARGET}: ${OBJS} ${HEADERS}
	mpicc -o ${TARGET} ${OBJS}

clean:
	rm -rf build/ ${OBJS}
