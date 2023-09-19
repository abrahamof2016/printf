#include "main.h"
/**
 * _printf - writes a character and string to stdout.
 * @format: format string.
 * Return: 0 on success.
 **/
int _printf(const char *format, ...)
{
	int i;
	va_list args;
	char *buffer = malloc(strlen(format) + 1);

	if (format == NULL || buffer == NULL)
		return (-1);
	i = 0;
	va_start(args, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[i] = format[i];
		}
		else if (format[i] == '%')
		{
			++format;
			if (format[i] == 'c')
			{
				int val = va_arg(args, int);

				if ((val > -128) && (val < 127))
					buffer[i] = val;
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(args, char *);

				if (str != NULL)
				{
					buffer = realloc(buffer, strlen(format) + strlen(str) + 1);
					strncpy(&buffer[i], str, strlen(str));
					i += strlen(str);
				}
			}
		}
	}
	va_end(args);
	write(1, &buffer[0], strlen(buffer));
	free(buffer);
	return (0);
}
