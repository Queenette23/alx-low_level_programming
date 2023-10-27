#include "shell.h"

/**
 * executeFile - Executes commands from a file
 * @filename: The name of the file to be executed
 * @str: The buffer to store the read string
 *
 * Return: 1 on success, 0 otherwise
 */
int executeFile(char *filename, char **str)
{
	char buf[1024];
	static char **data;
	static int fd;
	int status;

	if (!fd)
	{
		data = NULL;
		fd = open(filename, O_RDONLY);
		if (fd < 0)
			return (0);
	}
	if (data == NULL)
	{
		status = read(fd, buf, 1024);
		if (status >= 0)
			data = parser(buf, "\n");
	}

	if (data != NULL)
	{
		*str = *(data++);
		if (*data != NULL)
			return (1);
	}
	close(fd);
	return (0);
}

int main(void)
{
	char *str = NULL;

	if (processFile("filename.txt", &str))
	{
		printf("%s", str);
		free(str);
	}
	else
	{
		printf("Failed to read file\n");
	}

	return (0);
}
