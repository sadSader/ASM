CC=/usr/bin/g++

ASM = task4.s main.s

all: o
	$(CC) $(ASM) -o main
o: $(ASM)
	$(CC) -c $(CPP)
check: $(ASM)
	$(CC) -g $(ASM) -o main
	gdb ./main
