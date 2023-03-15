#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strdup - duplicates a string to a new memory space location
 * @str: pointer to the string to duplicate
 *
 * Return: pointer to the duplicated string, NULL if fail
 */
char *_strdup(char *str)
{
	char *new_str;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	new_str = malloc(sizeof(char) * (len + 1));

	if (new_str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		new_str[i] = str[i];

	new_str[i] = '\0';

	return (new_str);
}
