#include "monty.h"
/**
 * make_struct - Set values for struct.
 * @argu: Argument list.
 * Return: Struct for buffers.
 */
buf_struct *make_struct(char *argu[])
{
	static buf_struct a;

	a.argu = argu;
	memset(a.read_buff, 0, sizeof(a.read_buff));
	memset(a.list_cmd, 0, sizeof(a.list_cmd));
	memset(a.tok_cmd, 0, sizeof(a.tok_cmd));

	return (&a);
}
/**
 * main - Takes argument list and executes file given.
 * @argc: Argument count.
 * @argu: List of arguments.
 * Return: 0.
 */
int main(int argc, char *argu[])
{
	int fd;
	buf_struct *a;

	a = make_struct(argu);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	while ((fd = open(argu[1], O_RDONLY)) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argu[1]);
		exit(EXIT_FAILURE);
	}

	read(fd, a->read_buff, 4096);
	close(fd);
	split_newline(a);
	exec_loop(a);

	return (0);
}
