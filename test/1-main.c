#include "main.h"
#include <stdio.h>
/**
  * main - test function.
  * Return: an integer.
  */
int main(void)
{
	char *string;

	string = "I am jara\n";
	_printf("Hello this is %c\n", 65);
	printf("Hello this is %c\n", 'b');
	_printf("Hello from _prinf %s", string);
	printf("Hello from printf %s", string);
	return (0);
}
