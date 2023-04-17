#include "main.h"

/**
 * main - a program that copies the content of a file to another file.
 *
 * @argc: ...
 * @argv: ...
 * Return: ...
 */

int main(int argc, char *argv[])
{
	int fd_f;
	int fd_t;
	int nr;
	int nw;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_f = open(argv[1], O_RDONLY);
	if (fd_f == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s: %s\n",
				argv[1], strerror(errno));
		exit(98);
	}
	fd_t = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_t == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s: %s\n",
				argv[2], strerror(errno));
		exit(99);
	}
	while ((nr = read(fd_f, buffer, BUFFER_SIZE)) > 0)
	{
		nw = write(fd_t, buffer, nr);
		if (nw == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s: %s\n",
					argv[2], strerror(errno));
			exit(99);
		}
		if (nw != nr)
		{
			dprintf(STDERR_FILENO, "Error: Incomplete write %s\n",
					argv[2]);
			exit(99);
		}
	}
	if (nr == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s: %s\n",
				argv[1], strerror(errno));
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
	return (0);
}
