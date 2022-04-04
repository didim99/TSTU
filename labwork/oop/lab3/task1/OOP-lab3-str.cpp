#include <stdio.h>
#include "string.h"

int main()
{
	string *str1 = new string("Test string");
	string *str2 = new string("It Works?");
	string *str3 = new string("Yes, it works!");
	string *str4 = new string(str2);
	str4->concat(new string(" "));
	str4->concat(str3);
	
	printf("%-25s -> %d\n", str1->toPrint(), str1->sentencesCount());
	printf("%-25s -> %d\n", str2->toPrint(), str2->sentencesCount());
	printf("%-25s -> %d\n", str3->toPrint(), str3->sentencesCount());
	printf("%-25s -> %d\n", str4->toPrint(), str4->sentencesCount());
	getchar();
	return 0;
}
