#include "main.h"

/**
 * create_file - a function that creates a file.
 *
 * @filename: the name of the file to create.
 * @text_content: a NULL terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */

int create_file(const char *filename, char *text_content)
{
	int fd;
	int len = 0;
	int nw;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);
	if (text_content != NULL && text_content[len])
	{
		for (len = 0; text_content[len];)
			len++;
	}
	nw = write(fd, text_content, len);

	if (nw == -1 || fd == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (1);
}
