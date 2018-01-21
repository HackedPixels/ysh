#include <stdio.h>
#include <unistd.h>

extern char* builtins[];
extern int (*builtin_funcs[]) (char**);

int ysh_num_builtins(void);

int ysh_cd(char**);
int ysh_help(char**);
int ysh_exit(char**);
