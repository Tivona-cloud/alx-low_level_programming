#include "main.h"

/**
 * set_bit - Sets a bit at the given index to 1
 * @n: The pointer to number to change
 * @index: Index of a bit to set at 1
 * Return: 1 for success and -1 for failure
 */

int set_bit(unsigned long int *n, unsigned int index)

{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
