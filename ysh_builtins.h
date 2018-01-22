#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

extern char* builtins[];
extern int (*builtin_funcs[]) (char**);

int ysh_num_builtins(void);

int ysh_cd(char**);
int ysh_ls(char**);
int ysh_help(char**);
int ysh_exit(char**);
