/*
 * Program to learn how to use a variable number of arguments for a function.
 *
 * The a function with (int x, ...) args tells the compiler to expect a variable number of arguments
 * as long as the first argument is x of int type.
 *
 * Use type va_list to store the variable arguments list.
 *
 * Macros required from stdarg.h:
 *	va_start - initializes the list. Accepts va_list and name of arg that precedes "..." in the 
 *		   signature.
 *	va_arg	 - returns the next argument in the list. Accepts a va_list and a var type, and returns the 
 *	           next argument in the list of that variable type.
 *	va_end   - cleans up the variable argument list. Accepts a va_list type.
 *
 */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void printerror(char *s, ...);

int
main(void)
{
	
	return 0;
}

void printerror(char *s, ...) {
	va_list messages;

	va_start(messages, s);
	printf("%s\n", argv[1]);
	va_end(messages);
}

double average (int num, ...) {

	va_list arguments;
	double sum = 0;

	// Initializing args to store values after num
	va_start (arguments, num);

	for (int i = 0; i < num; i++) {
		sum += va_arg(arguments, double);
	}
	va_end(arguments);

	return sum / num;
}
