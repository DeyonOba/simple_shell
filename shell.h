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

void command_error(char *file_name, int sh_call_num, char *command);
void default_error(char *file_name, int sh_call_num, char *command);
void file_error(char *file_name, int sh_call_num, char *command);

int digit_count(int number);
int _power(int digit_count);
int digit_to_char(int number);
void number_to_string(int number, int fd);
int string_to_number(char *string);
int num_str_flags(const char *format);

char *hsh_read_line(void);
char **hsh_parse_str(char *line, int *args_count, char *sep);

void execute_shell(int *hsh_sh_calls);
void exec_command(char **cmds);

void free_array(char **array, int array_count);
void *_realloc(void *ptr, size_t size);

#endif
