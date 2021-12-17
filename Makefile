#Makefile
objects = main.o create.o exception.o fileArray.o files.o sort.o work.o

.PHONY: all
all: fileSort

fileSort: ${objects}
	gcc -o fileSort ${objects} -lstdc++

main.o: files.h work.h
create.o: create.h
exception.o: exception.h
fileArray.o: fileArray.h exception.h
files.o: files.h
sort.o: sort.h
work.o: work.h create.h sort.h

.PHONY: clean
clean:
	-rm -f fileSort *.o *.tmp *.txt 2>/dev/null
