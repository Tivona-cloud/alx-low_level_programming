#include "main.h"
#include <unistd.h>

/**
 * _putchar - Will write a character c to stdout
 * @c: The character for print
 * Return: On success 1,on error -1 is returned, errno is set appropriately
 */

int _putchar(char c)

{
	return (write(1, &c, 1));
}
