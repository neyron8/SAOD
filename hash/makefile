C = gcc
flag = -c  

./bin/work: ./build/main.o ./build/hashtab.o
	$(C) ./build/main.o  ./build/hashtab.o -o ./bin/work
	gcc ./build/main.o ./build/hashtab.o -g -o ./bin/gdb
./build/main.o: ./src/main.c
	$(C) $(flag) ./src/main.c -o ./build/main.o

./build/hashtab.o: ./src/hashtab.c ./src/hashtab.h
	$(C) $(flag) ./src/hashtab.c -o ./build/hashtab.o

.PHONY: clean
clean:
	rm -rf ./build/*.o
