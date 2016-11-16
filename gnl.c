#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE 1024

/*
** Function to read file to buffer. Return
** 1 if file has been succesfully read, otherwise
** it returns 0
*/

int		rd_f(char *f, char buff[BUFF_SIZE])
{
	int		fd;
	int		len;

	if ((fd = open(f, O_RDONLY)) != -1)
	{
		printf("fd: %d\n", fd);
		if ((len = read(fd, buff, 700)) > 0)
		{
			buff[len] = '\0';
			return (1);
		}
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char buff[BUFF_SIZE];

	if (argc == 2)
	{
		rd_f(argv[1], buff);
		printf("%s", buff);
	}
	printf("\n");
	return (0);
}
