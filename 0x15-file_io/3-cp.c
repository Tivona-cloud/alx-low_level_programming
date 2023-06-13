#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);

void close_file(int fd);

/**
 * create_buffer - Allocates 1024 bytes for buffers
 * @file: The name of file buffer is storing chars
 * Return: A pointer to new buffer
 */

char *create_buffer(char *file)

{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes file descriptor
 * @fd: The file descriptor for closure
 */

void close_file(int fd)

{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies contents of files to other files
 * @argc: Number of arguments supplied at program
 * @argv: An array of pointers at arguments
 * Return: 0 on success
 * Description: If argument count is incorrect - exit is code 97
 * If file_from does not exist/cannot be read - exit is code 98
 * If file_to cannot be created/written - exit is code 99
 * If file_to/file_from cannot be closed - exit is code 100
 */

int main(int argc, char *argv[])

{
	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
