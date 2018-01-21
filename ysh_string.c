#include "ysh_string.h"

#define YSH_TOKEN_BUFFER_SIZE 64
#define YSH_TOKEN_DELIMITER " \t\r\n\a"

char**
ysh_splitline(line)
	char* line;
{
	int buffer_size = YSH_TOKEN_BUFFER_SIZE;
	int position = 0;
	char** tokens = malloc(buffer_size * sizeof(char*));
	char* token;

	if(tokens == NULL)
	{
		fprintf(stderr, "ysh: could not allocate tokens buffer.\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, YSH_TOKEN_DELIMITER);
	while(token != NULL)
	{
		tokens[position] = token;
		position++;

		if(position >= buffer_size)
		{
			buffer_size += YSH_TOKEN_BUFFER_SIZE;
			tokens = realloc(tokens, buffer_size * sizeof(char*));

			if(tokens == NULL)
			{
				fprintf(stderr, "ysh: failed to allocate.");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, YSH_TOKEN_DELIMITER);
	}
	tokens[position] = NULL;
	return tokens;
}
