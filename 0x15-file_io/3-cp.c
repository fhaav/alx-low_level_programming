#include "main.h"

#define BUFFER_SIZE 4096

/**
 * main - a program that copies the content of a file to another file.
 *
 * @file_from: ...
 * @file_to: ...
 * Return: ...
 */

void copy_file(char *file_from, char *file_to);
void error(char *message);

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
	int fd_f;
	int fd_t;
	ssize_t nr;
	ssize_t nw;
	char buffer[BUFFER_SIZE];

	fd_f = open(file_from, O_RDONLY);
	if (fd_f == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s",
				file_from);
		exit(98);
	}

	fd_t = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd_t == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s: %s\n",
				file_to, strerror(errno));
		exit(99);
	}

	while ((nr = read(fd_f, buffer, BUFFER_SIZE)) > 0)
	{
		nw = write(fd_t, buffer, nr);
		if (nw == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s: %s\n",
					file_to, strerror(errno));
			exit(99);
		}
		if (nw != nr)
		{
			dprintf(STDERR_FILENO, "Error: Incomplete write %s\n",
					file_to);
			exit(99);
		}
	}
	if (nr == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s: %s\n",
				file_from, strerror(errno));
		exit(98);
	}
	if (close(fd_f) == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't close fd %d: %s\n",
				fd_f, strerror(errno));
		exit(100);
	}
	if (close(fd_t) == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't close fd %d: %s\n",
				fd_t, strerror(errno));
		exit(100);
	}
}

/**
 * error - ...
 * @message: ...
 * Return: ...
 */
void error(char *message)
{
	fprintf(stderr, "Error: %s\n", message);
	exit(EXIT_FAILURE);
}
