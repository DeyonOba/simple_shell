#ifndef SHELL_H
#define SHELL_H
#define MAX_WORDS 100

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdarg.h>


int _putchar(char c, int file_descriptor);
void _print(char *string, int file_descriptor);
void prompt(void);
int _dprintf(int fd, const char *format, ...);

void command_error(char *file_name, int num_shell_calls, char *command);
void default_error(char *file_name, int num_shell_calls, char *command);
void file_error(char *file_name, int num_shell_calls, char *command);
void exit_error(char *file_name, int num_shell_calls, char **command);

int digit_count(int number);
int _power(int digit_count);
int digit_to_char(int number);
void number_to_string(int number, int fd);
int string_to_number(char *string);
int num_str_flags(const char *format);

char **hsh_parse_str(char *line, int *args_count, char *sep);

int execute_shell(char *line, int *num_shell_calls, char *file_name, int *ctrl_loop, char **env);
int exec_command(char *file_path, char **cmds, char **env);

void free_array(char **array);
void *_realloc(void *ptr, size_t size);

char *_getenv(char **env, char *vname);
char *_getpath(char *cmd, char **env);

int is_numeric(char *string);
int shell_exit(char *filename, char **cmds_args, int cmd_count, int num_shell_calls, int **ctrl_loop);
void print_env(char **env);

#endif
