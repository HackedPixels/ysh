#include "main.h"

int
main(argc, argv)
	int argc;
	char** argv;
{
	char* line;
	char** args;
	int status;

	/* startup: read config file. */
	FILE* config_file;
	config_file = fopen("./.yshrc", "r");

	char* input_buffer = malloc(4 * sizeof(char));
	int config_buffer_size;
	
	printf("%d", sizeof(input_buffer) / sizeof(char));

	free(input_buffer);
	fclose(config_file);	

	do
	{
		printf("ysh>");
		line = ysh_readline();

		args = ysh_splitline(line);
		status = ysh_execute(args);

		free(line);
		free(args);
	} while(status);

	return OK;
}

int
ysh_launch(args)
	char** args;
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if(pid == 0)
	{
		if(execvp(args[0], args) == -1)
		{
			perror("ysh");
		}
		exit(EXIT_FAILURE);
	} else if(pid < 0)
	{
		perror("ysh");
	} else
	{
		do
		{
			wpid = waitpid(pid, &status, WUNTRACED);
		} while(!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return 1;
}

int
ysh_execute(args)
	char** args;
{
	int i;

	if(args[0] == NULL)
	{
		return 1;
	}

	for(i = 0; i < ysh_num_builtins(); i++)
	{
		if(strcmp(args[0], builtins[i]) == 0)
		{
			return (*builtin_funcs[i])(args);
		}
	}

	return ysh_launch(args);
}
