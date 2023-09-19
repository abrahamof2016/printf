#include "main.h"
/**
  * _printf: writes a string and character to stdout.
  * @format: format string.
  * Return: 0 on success.
  *
  */
int _printf(const char *format, ...)
{
	int i;
	va_list args;
	char buffer[BUFF_SIZE];

	i = 0;
	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[i] = format[i];
		}
		if (format[i] == '%')
		{
			format++;
			if (*format == 'c')
				buffer[i] = va_arg(args, int);

		}
		i++;
	}
	va_end(args);
	write(1, &buffer[0], strlen(buffer));
	return (0);
}
