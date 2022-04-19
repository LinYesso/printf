#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _print_a_char - A function that prints a char
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
 * _print_a_string - A function that prints a string
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
 * _print_a_integer -A function that prints a integer
 * @args: A list of variadic arguments
 *
 * Return: The length of the string
 */
int _print_a_integer(va_list args)
{
	int count = 1;
	int m = 0;
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
 * _recursion_integer - A function that prints a integer
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
