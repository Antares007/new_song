CC|=clang
CFLAGS+=-std=gnu99 -Wall
LDFLAGS+=-luv

src/main: src/main.c src/nar.o src/soll.o
	${CC} $^ -o $@ ${CFLAGS} ${LDFLAGS}

clean:
	rm -f src/main src/*.o

.PHONY: clean
