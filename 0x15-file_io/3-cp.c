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
		error("Usage: cp file_from file_to\n");
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
		error(strerror(errno));
	}

	fd_t = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_t == -1)
	{
		close(fd_f);
		error(strerror(errno));
	}

	while ((nr = read(fd_f, buffer, BUFFER_SIZE)) > 0)
	{
		nw = write(fd_t, buffer, nr);
		if (nw == -1)
		{
			close(fd_f);
			close(fd_t);
			error(strerror(errno));
		}
		if (nw != nr)
		{
			close(fd_f);
			close(fd_t);
			error("Incomplete write");
		}
	}
	if (nr == -1)
	{
		close(fd_f);
		close(fd_t);
		error(strerror(errno));
	}
	if (close(fd_f) == -1)
	{
		error(strerror(errno));
	}
	if (close(fd_t) == -1)
	{
		error(strerror(errno));
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
