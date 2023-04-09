#include "main.h"

/**
 * read_textfile - a function that reads a text file and
 * prints it to the POSIX standard output.
 *
 * @filename: name of the file to be read.
 * @letters: maximum number of characters to be read and pointed from the file.
 *
 * Return: actual number of letters it could read and print.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t nr;
	ssize_t nw;
	ssize_t fp;

	if (filename == NULL)
		return (0);

	fp = open(filename, O_RDONLY);
	if (fp == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	nr = read(fp, buffer, letters);
	nw = write(STDOUT_FILENO, buffer, nr);

	free(buffer);
	close(fp);
	return (nw);
}
