CC=/usr/bin/g++

ASM = scan.s task3.s
CPP =scan.cpp

all: o S
	$(CC) $(ASM) -o main
o: $(ASM)
	$(CC) -c $(CPP)
S: $(CPP)
	$(CC) -S $(CPP)
