#include "ysh_io.h"

#define BUFFER_SIZE_BLOCK 16

char*
ysh_readline(void)
{
	int buffer_size = BUFFER_SIZE_BLOCK;
	int position    = 0;
	char* buffer = malloc(sizeof(char) * buffer_size);
	int c;
	
	/* Check if memory allocation failed. */
	if(buffer == NULL)
	{
		fprintf(stderr, "ysh: could not allocate line buffer!\n");
		exit(EXIT_FAILURE);
	}

	/* Read the entered line until the end. */
	while(1)
	{
		/* Read a character. */
		c = getchar();

		/* If the line is finished (EOF is reached), replace it with
		 * NULL character and return the string */
		if(c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			
			// return it.
			return buffer;
		/* If not, continue writing. */
		} else
		{
			buffer[position] = c;
		}
		/* Increment position pointer. */
		position++;

		/* If the buffer is to small, we need to increase the size. */
		if(position >= buffer_size)
		{
			buffer_size += BUFFER_SIZE_BLOCK;
			buffer = realloc(buffer, buffer_size);
			
			/* Again, check if malloc failed. */
			if(buffer == NULL)
			{
				fprintf(stderr, "ysh: could not allocate line buffer!\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
