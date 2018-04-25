C = gcc
flag = -c  

./bin/work: ./build/main.o ./build/bstree.o
	$(C) ./build/main.o  ./build/bstree.o -o ./bin/work

./build/main.o: ./src/main.c
	$(C) $(flag) ./src/main.c -o ./build/main.o

./build/bstree.o: ./src/bstree.c ./src/bstree.h
	$(C) $(flag) ./src/bstree.c -o ./build/bstree.o

.PHONY: clean
clean:
	rm -rf ./build/*.o
