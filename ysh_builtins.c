#include "ysh_builtins.h"

char* builtins[] =
{
	"cd",
	"ls",
	"help",
	"exit"
};

int (*builtin_funcs[]) (char**) =
{
	&ysh_cd,
	&ysh_ls,
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
ysh_ls(args)
	char** args;
{
	int len;
	struct dirent *pDirent;
	DIR *pDir;

	char* working_directory = malloc(1024 * sizeof(char));
	getcwd(working_directory, 1024);

	pDir = opendir(working_directory);
	if(pDir == NULL)
	{
		fprintf(stderr, "Cannot open directory...\n");
	} else
	{
		strcat(working_directory, "/");
		while((pDirent = readdir(pDir)) != NULL)
		{
			struct stat path_stat;

			char* file = malloc(strlen(working_directory)+strlen(pDirent->d_name)+1);
			//Please dont fail on memory allocation...
			/*TODO: Add check. */
			strcpy(file, working_directory);
			strcat(file, pDirent->d_name);

			stat(file, &path_stat);
			if(S_ISREG(path_stat.st_mode))
				printf("%s\n", pDirent->d_name);
			else
				printf("[\033[7m%s\033[0m]\n", pDirent->d_name);
		}
		closedir(pDir);
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
