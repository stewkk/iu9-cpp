CC=g++
CFLAGS= -g -std=c++20 -Wall -Wextra -O2 -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion \
		-Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align \
		-fsanitize=address -fsanitize=undefined
CDEBUGFLAGS= -g -std=gnu++20 -Wall -Wextra -O0 -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion
task=test
sources := $(wildcard *.cpp)
headers := $(wildcard *.h)

all: run

run: build
	./a

build: a

a: $(sources) $(headers)
	$(CC) $(CFLAGS) $(sources) -o a

debug: d

d: $(sources) $(headers)
	$(CC) $(CDEBUGFLAGS) $(sources) -o d && gdb --tui --silent ./d

format: $(sources) $(headers)
	clang-format -i --style=WebKit $(sources) $(headers)

test:
	echo "NOT IMPLEMENTED"

clean:
	-{ find -regex '.*/a'; find -regex '.*/d'; find -regex '.*/\.ccls-cache'; } | xargs rm -r

create:
	mkdir $(task) && cd $(task) && ln -sr ../Makefile ./ && touch main.cpp

.PHONY: all create build run debug clean test format

