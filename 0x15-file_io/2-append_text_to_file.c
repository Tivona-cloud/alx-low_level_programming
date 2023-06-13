#include "main.h"

/**
 * append_text_to_file - Appends text at end of the file
 * @filename: A pointer at the name of the file.
 * @text_content: A string to add at end of the file
 * Return: If the function fails/filename is NULL -1, if the file doesn't exist user lacks writing permission -1 otherwise - 1
 */

int append_text_to_file(const char *filename, char *text_content)

{
	int o, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	w = write(o, text_content, len);

	if (o == -1 || w == -1)
		return (-1);

	close(o);

	return (1);
}
