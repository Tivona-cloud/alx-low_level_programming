#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read the text file print to STDOUT.
 * @filename: The text file to be read
 * @letters: The number of letters to read
 * Return: w- the actual number of bytes read, printed 0 when function fails/filename is NULL
 */

ssize_t read_textfile(const char *filename, size_t letters)

{
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (w);
}
