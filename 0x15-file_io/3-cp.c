#include "main.h"

#define BUFFER_SIZE 1024

/**
 * main - a program that copies the content of a file to another file.
 *
 * @file_from: ...
 * @file_to: ...
 * Return: ...
 */

void copy_file(char *file_from, char *file_to);

/**
 * main - a program that copies the content of a file to another file.
 *
 * @argc: ...
 * @argv: ...
 * Return: ...
 */

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	copy_file(argv[1], argv[2]);

	return (0);
}

/**
 * copy_file - ...
 * @file_from: ...
 * @file_to: ...
 * Return: 0 on success
 */
void copy_file(char *file_from, char *file_to)
{
	ssize_t fd_f;
	ssize_t fd_t;
	ssize_t nr;
	ssize_t nw;
	char buffer[BUFFER_SIZE];

	fd_f = open(file_from, O_RDONLY);
	if (fd_f == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}

	fd_t = open(file_to, O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0664);
	if (fd_t == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		exit(99);
	}

	while (nr = read(fd_f, buffer, BUFFER_SIZE))
	{
		if (nr == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
			exit(98);
		}

		nw = write(fd_t, buffer, nr);
		if (nw == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			exit(99);
		}
		if (nw != nr)
		{
			dprintf(STDERR_FILENO, "Error: Incomplete write %s\n", file_to);
			exit(99);

		}
	}
	if (close(fd_f) == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't close fd %ld\n", fd_f);
		exit(100);
	}
	if (close(fd_t) == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't close fd %ld\n", fd_t);
		exit(100);
	}
}
