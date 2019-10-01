CC=/usr/bin/g++

ASM = main.s task1.s
CPP =main.cpp

all: o S
	$(CC) $(ASM) -o main
o: $(ASM)
	$(CC) -c $(CPP)
S: $(CPP)
	$(CC) -S $(CPP)
