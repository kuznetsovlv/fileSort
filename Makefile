#Makefile
objects = main.o exception.o fileArray.o

.PHONY: all
all: fileSort

fileSort: ${objects}
	gcc -o fileSort ${objects} -lstdc++

main.o: fileArray.h
fileArray.o: fileArray.h exception.h
exception.o: exception.h

.PHONY: clean
clean:
	-rm -f fileSort *.o *.tmp *.txt 2>/dev/null
