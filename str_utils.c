#include "shell.h"

/**
 * _putchar - Outputs character to stdout
 * @c: Character
 * @fd: Std file descriptor
 *
 * Return: 0 (Success)
 */
int _putchar(char c, int fd)
{
		write(fd, &c, fd);

		return (0);
}

/**
 * _print - Print string to stdout
 * @string: String
 * @fd: Std file description
 */
void _print(char *string, int fd)
{
	int index = 0;

	while (string[index] != '\0')
	{
		_putchar(string[index], fd);
		index++;
	}
}

/**
 * prompt - Shell (hsh) prompt
 */
void prompt(void)
{
	char *alert = "($) ";

	_print(alert, STDOUT_FILENO);
}

/**
 * _dprintf - Display a formated string to file descriptor
 * @fd: File descriptor
 * @format: Specified string format
 *
 * Return: Number of character displayed
 */
int _dprintf(int fd, const char *format, ...)
{
	int f_index = 0, num;
	/*int count = num_str_flags(format), num;*/
	char *string;
	va_list args;

	va_start(args, 0);

	while (format[f_index] != '\0')
	{
		if (format[f_index] == '%')
		{
			if (format[f_index + 1] == 'd')
			{
				num = va_arg(args, int);
				number_to_string(num, fd);
				f_index += 2;
				continue;
			}
			else if (format[f_index + 1] == 's')
			{
				string = va_arg(args, char*);
				_print(string, fd);
				f_index += 2;
				continue;
			}
			else
			{
				_putchar(format[f_index], fd);
				f_index++;
				continue;
			}
		}
		_putchar(format[f_index], fd);
		f_index++;
		continue;
	}
	va_end(args);
	return (EXIT_SUCCESS);
}

/**
 * num_str_flags - Counts the number of flags in a string
 * @format: String
 *
 * Return: Number of format flag
 */
int num_str_flags(const char *format)
{
	int i, count = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
			count++;
	}
	return (count);
}
