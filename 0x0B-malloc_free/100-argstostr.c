#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all arguments of a program
 *
 * @ac: number of arguments
 * @av: pointer to array of arguments
 *
 * Return: pointer to concatenated string of arguments
 */

char *argstostr(int ac, char **av)
{
	int i, n, r = 0, l = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (n = 0; av[i][n]; n++)
			l++;
	}
	l += ac;

	str = malloc(sizeof(char) * (l + 1));

	if (str == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (n = 0; av[i][n]; n++)
		{
			str[r] = av[i][n];
			r++;
		}

		if (str[r] == '\0')
		{
			str[r++] = '\n';
		}
	}

	return (str);
}
