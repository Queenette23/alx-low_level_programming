#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - reads a text file and prints it to stdout
 * @filename: name of the file to read
 * @letters: number of letters to read and print
 *
 * Return: number of letters read and printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t print_count = 0;
	char buf[1024];

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	while (letters && read(fd, buf, 1) > 0)
	{
		write(STDOUT_FILENO, buf, 1);
		print_count++;
		letters--;
	}

	close(fd);
	return (print_count);
}

