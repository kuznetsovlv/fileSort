#Makefile
objects = main.o fileArray.o

.PHONY: all
all: fileSort

fileSort: ${objects}
	gcc -o fileSort ${objects} -lstdc++

main.o: fileArray.h
fileArray.o: fileArray.h

.PHONY: clean
clean:
	-rm -f fileSort *.o *.tmp 2>/dev/null
