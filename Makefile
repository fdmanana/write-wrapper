OS=$(shell uname -s)

all: write-wrapper.so test

write-wrapper.so: write-wrapper.c
ifeq ($(OS),Linux)
	gcc -D_GNU_SOURCE -Wall -fPIC -Wl,-no-undefined -shared -o write-wrapper.so write-wrapper.c -ldl
endif
ifeq ($(OS),Darwin)
	gcc -Wall -Wl,-undefined -Wl,dynamic_lookup -dynamiclib -o write-wrapper.so write-wrapper.c -ldl
endif

test:
	gcc -Wall -o test test.c

clean:
	rm -f test write-wrapper.so *~
