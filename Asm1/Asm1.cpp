// Asm1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <limits.h>

//Hack from StackOverflow for printing binary format
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

void PrintTypes(short x, short y)
{
	printf("%-20s %-16hx %hx\n", "Hex:", x, y);
	printf("%-20s %-16hu %hu\n", "Unsigned decimal :", x, y);
	printf("%-20s %-16hi %hi\n", "Signed decimal:", x, y);
	printf("%-20s" BYTE_TO_BINARY_PATTERN" " BYTE_TO_BINARY_PATTERN" " BYTE_TO_BINARY_PATTERN" " BYTE_TO_BINARY_PATTERN"\n",
			"Binary:", BYTE_TO_BINARY(x >> 8), BYTE_TO_BINARY(x), BYTE_TO_BINARY(y >> 8), BYTE_TO_BINARY(y));
}


void PrintHexDec(short x, short y)
{
	printf("%-20s %-16hx %hx\n", "Hex:", x, y);
	printf("%-20s %-16hu %hu\n", "Unsigned decimal :", x, y);
}

#define PRINT_SIZE_OF(TYPE) printf("%-11s %i\n",""#TYPE, sizeof(TYPE));

int main()
{
	short x = -2;     
	short y = 0x7fff;//0111 1111 1111 1111b
	PrintTypes(x, y);

	signed short max_signed_short = SHRT_MAX;
	signed short min_signed_short = SHRT_MIN;
	printf("\n%-20s %-16s %-16s \n", "Signed", "min", "max");
	PrintTypes(min_signed_short, max_signed_short);


	unsigned short max_unsigned_short = USHRT_MAX;
	unsigned short min_unsigned_short = 0;
	printf("\n%-20s %-16s %-16s \n", "Unsigned", "min", "max");
	PrintTypes(min_unsigned_short, max_unsigned_short);

	{
		unsigned short x = 0x8008;
		unsigned short y = 0x1111;
		printf("\nx=0x%hx\ny=0x%hx\n", x, y);
		
		printf("%-20s %-16s %-16s \n", "Unsigned", "&", "|");
		PrintHexDec(x & y, x | y);

		printf("\n%-20s %-16s %-16s \n", "Unsigned", "~x", "-x");
		PrintHexDec( ~x, -x);

		printf("\n%-20s %-16s %-16s \n", "Unsigned", "x>>y", "x<<y");
		PrintHexDec(x>>y, x<<y);//x, y >16 so result  is 0;
	}

	{
		unsigned int x = 0x12345678;
		printf("x :%x\n", x);
		printf("(short *)x[0] %hx\n",x);// 5678, Little Endian
		short* x_next = (short*)(((char*)& x) + 2);
		printf("(short *)x[2] %hx\n", *x_next);// 1234, Little Endian
	}

	{
		const char *str = "abcd";
		const char *ru_str = "рсту";
		for (size_t i = 0; i < 4; i++)
		{
			printf("%lu, %c\n", i, str[i]);
		}
		for (size_t i = 0; i < 4; i++)
		{
			printf("%lu, %c\n", i, ru_str[i]);
		}
	}

	{
		const wchar_t *str = L"abcd";
		const wchar_t *ru_str = L"рсту";
		for (size_t i = 0; i < 4; i++)
		{
			wprintf(L"%lu, %c\n", i, str[i]);
		}
		for (size_t i = 0; i < 4; i++)
		{
			wprintf(L"%lu, %c\n", i, ru_str[i]);
		}
	}
	PRINT_SIZE_OF(char);
	PRINT_SIZE_OF(bool);
	PRINT_SIZE_OF(wchar_t);
	PRINT_SIZE_OF(short);
	PRINT_SIZE_OF(int);
	PRINT_SIZE_OF(long);
	PRINT_SIZE_OF(long long);
	PRINT_SIZE_OF(float);
	PRINT_SIZE_OF(double);
	PRINT_SIZE_OF(long double);
	PRINT_SIZE_OF(size_t);
	PRINT_SIZE_OF(ptrdiff_t);

}
