
  
#include "main.h"
#include <stdlib.h>

/**
 * _print_format - A function that prints a format
 * @format: The format to prints
 * @args: A list of variadic arguments
 *
 * Return: The length of the format
 */
int _print_format(const char *format, va_list args)
{
	int count = 0;
	int i = 0;

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			i++;

			while (format[i] == ' ')
				i++;

			if (format[i] == '%')
				count += _write(format[i]);

			if (_validate_char(format[i]) == 0)
			{
				count = _print_invalid_spec(format[i - 1], format[i], count);
			}
			else
			{
				count += _print_spec(format[i], args);
			}
		}
		else
		{
			count += _write(format[i]);
		}

		i++;
	}

	return (count);
}


/**
 * _print_spec - A funcyion that prints a valid specifier
 * @format: The specifier to prints
 * @args: A list of variadic arguments
 *
 * Return: The length of the specifier
 */
int _print_spec(char format, va_list args)
{
	int i  = 0;
	int len = 0;
	spc_dt _types[] = {
		{"c", _print_a_char},
		{"s", _print_a_string},
		{"d", _print_a_integer},
		{"i", _print_a_integer},
		{"b", _print_int_binary},
		{NULL, NULL}
	};

	while (_types[i].specifier)
	{
		if (*_types[i].specifier == format)
			len = _types[i].f(args);

		i++;
	}

	return (len);
}



/**
 * _print_invalid_spec - A function that prints a invalid specifier
 * @prev_format: The previous specifier of actual specifier
 * @format: The specifier to prints
 * @count: The current count before prints invalid specifiers
 *
 * Return: The current count after prints invalid specifiers
 */
int _print_invalid_spec(char prev_format, char format, int count)
{
	count += _write('%');

	if (prev_format == ' ')
	{
		count += _write(' ');
		count += _write(format);
	}
	else
	{
		count += _write(format);
	}

	return (count);
}


/**
 * _validate_char - validate the type
 * @_type: character to be comparate
 *
 * Return: 1 if char is equal to a type
 */
int _validate_char(char _type)
{
	char _types[] = {'c', 's', 'd', 'i', 'b', '%'};
	int i = 0;

	while (_types[i])
	{
		if (_types[i] == _type)
			return (1);
		i++;
	}

	return (0);
}


/**
 * _print_a_char - Prints a char
 * @args: A list of variadic arguments
 *
 * Return: The length of the character
 */
int _print_a_char(va_list args)
{
	_write(va_arg(args, int));
	return (1);
}

/**
 * _print_a_string - Prints a string
 * @args: A list of variadic arguments
 *
 * Return: The length of the string
 */
int _print_a_string(va_list args)
{
	char *arg = va_arg(args, char *);
	int i = 0;

	if (arg != NULL)
	{
		while (arg[i])
		{
			_write(arg[i]);
			i++;
		}
		return (i);
	}

	_write('(');
	_write('n');
	_write('u');
	_write('l');
	_write('l');
	_write(')');
	return (6);
}

/**
 * _print_a_integer - Prints a integer
 * @args: A list of variadic arguments
 *
 * Return: The length of the string
 */
int _print_a_integer(va_list args)
{
	int count = 1, m = 0;
	unsigned int n = 0;

	n = va_arg(args, int);
	m = n;
	if (m < 0)
	{
		_write('-');
		m = m * -1;
		n = m;
		count += 1;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}

	_recursion_integer(m);
	return (count);
}


/**
 * _recursion_integer - Prints a integer
 * @a: integer to print
 *
 * Return: Nothing
 */
void _recursion_integer(int a)
{
	unsigned int tmp;

	tmp = a;
	if (tmp / 10)
		_recursion_integer(tmp / 10);
	_write(tmp % 10 + '0');
}
