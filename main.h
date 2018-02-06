#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "ysh_io.h"
#include "ysh_string.h"
#include "ysh_builtins.h"

#ifndef bool
	#define bool char
	#define false 0
	#define true 1
#endif

#define CONFIG_BUFFER_INPUT_SIZE 10

#define OK 0

int ysh_launch(char**);
int ysh_execute(char**);
