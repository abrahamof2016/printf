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
	char buffer[BUFF_SIZE];

	i = 0;
	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[i] = format[i];
		}
		else if (format[i] == '%')
		{
			format++;
			if (format[i] == 'c')
			{
				int val = va_arg(args, int);

				if ((val > -128) && (val < 127))
					buffer[i] = val;
			}
		}
	}
	va_end(args);
	write(1, &buffer[0], strlen(buffer));
	return (0);
}
