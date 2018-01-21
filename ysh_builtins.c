#include "ysh_builtins.h"

char* builtins[] =
{
	"cd",
	"help",
	"exit"
};

int (*builtin_funcs[]) (char**) =
{
	&ysh_cd,
	&ysh_help,
	&ysh_exit
};

int
ysh_num_builtins(void)
{
	return sizeof(builtins) / sizeof(char*);
}

/* Implementations. */
int
ysh_cd(args)
	char** args;
{
	if(args[1] == NULL)
	{
		fprintf(stderr, "ysh: expected argument to \"cd\"\n");
	} else
	{
		if(chdir(args[1]) != 0)
		{
			perror("ysh");
		}
	}

	return 1;
}

int
ysh_help(args)
	char** args;
{
	int i;
	for(i = 0; i < ysh_num_builtins(); i++)
	{
		printf("  %s\n", builtins[i]);
	}
	return 1;
}

int
ysh_exit(args)
	char** args;
{
	return 0;
}
