#include <unistd.h>
#include <fcntl.h>

/**
 * append_text_to_file - appends text to the end of a file.
 * @filename: name of the file to append to
 * @text_content: text to append to the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, status = -1;
	ssize_t len, written;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		for (len = 0; text_content[len]; len++)
			;
		written = write(fd, text_content, len);
		if (written != len)
			status = -1;
		else
			status = 1;
	}
	else
		status = 1;

	close(fd);
	return (status);
}

