#include "monty.h"

info_t info = {NULL, NULL, NULL, 0};

/**
 * main - start of code
 * @argc: number of argummnets
 * @argv: pointer of arguments
 *
 * Return: return 0 or error state
 */
int main(int argc, char *argv[])
{
	unsigned int num = 0;
	size_t line_len = 1;
	FILE *f;
	size_t size;
	char *lineptr;
	stack_t *stak = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	f = fopen(argv[1], "r");
	info.f = f;
	if (!f)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (line_len >= 1)
	{
		num++;
		lineptr = NULL;
		line_len = getline(&lineptr, &size, f);
		info.lineptr = lineptr;
		if (line_len >= 1)
		{
			func(lineptr, &stak, num, f);
		}
		free(lineptr);
	}
	free_stak(stak);
	fclose(f);
	return (0);
}
