#include <stdio.h>

/**
 * main - Prints the lowercase alphabets in reverse,
 * followed by a new line
 * Return: Always 0 (success)
 */
int main(void)
{
        char ch;

        for (ch = 'z'; ch >= 'a'; ch--)
        {
                putchar(ch);
        }
        putchar('\n');
        return (0);
}
