#ifndef _MAIN_
#define _MAIN_
#include <stddef.h>

char *enter_command(char *msg);
char **to_args(char *cmd_str, size_t max_args);

#endif
