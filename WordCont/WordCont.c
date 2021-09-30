#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Incorrect arguments");
		return 1;
	}

	char letter = 0;
	char last_letter = 0;

	int str_count = 0;
	int word_count = 0;
	int byte_count = 0;

	FILE* file_reader;
	file_reader = fopen(argv[2], "r");

	if (!file_reader)
	{
		printf("file error");
		return 1;
	}

	while ((letter = fgetc(file_reader)) != EOF)
	{
		if ((letter == ' ') && ((last_letter != ' ') && (last_letter != '\n')))
		{
			word_count++;
		}

		if (letter == '\n')
		{
			str_count++;
			word_count++;
			byte_count++;
		}

		byte_count++;
		last_letter = letter;
	}

	fclose(file_reader);

	str_count++;

	if ((!strcmp(argv[1], "-l")) || (!strcmp(argv[1], "--lines")))
	{
		printf("str: %d\n", str_count);
	}
	else if ((!strcmp(argv[1], "-c")) || (!strcmp(argv[1], "--bytes")))
	{
		printf("bytes: %d\n", byte_count);
	}
	else if ((!strcmp(argv[1], "-w")) || (!strcmp(argv[1], "--words")))
	{
		printf("words: %d\n", word_count);
	}
}	