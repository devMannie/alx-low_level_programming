#include "main.h"
#include <stdlib.h>
#include <stdio.h>

#define ERR_MSG "Error"

/**
 * is_digit - checks if a string contains a non-digit char
 *
 * @s: string to be evaluated
 *
 * Return: 0 if a non-digit is found, 1 otherwise
 */
int is_digit(char *s)
{
    int i = 0;

    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9')
            return (0);
        i++;
    }

    return (1);
}

/**
 * _strlen - returns the length of a string
 *
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
    int i = 0;

    while (s[i] != '\0')
    {
        i++;
    }

    return (i);
}

/**
 * errors - handles errors for main
 */
void errors(void)
{
    printf("%s\n", ERR_MSG);
    exit(98);
}

/**
 * multiply - multiplies two positive numbers
 *
 * @num1: first number to be multiplied
 * @num2: second number to be multiplied
 *
 * Return: a pointer to the result of the multiplication
 */
char *multiply(char *num1, char *num2)
{
    int len1 = _strlen(num1);
    int len2 = _strlen(num2);
    int len = len1 + len2 + 1;
    int i, j, carry, digit1, digit2;

    char *result = malloc(sizeof(char) * len);

    if (!result)
        return (NULL);

    for (i = 0; i <= len1 + len2; i++)
        result[i] = '0';

    for (i = len1 - 1; i >= 0; i--)
    {
        digit1 = num1[i] - '0';
        carry = 0;

        for (j = len2 - 1; j >= 0; j--)
        {
            digit2 = num2[j] - '0';
            carry += (result[i + j + 1] - '0') + (digit1 * digit2);
            result[i + j + 1] = (carry % 10) + '0';
            carry /= 10;
        }

        if (carry > 0)
            result[i + j + 1] += carry;
    }

    return (result);
}

/**
 * main - multiplies two positive numbers
 *
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: always 0 (Success)
 */
int main(int argc, char *argv[])
{
    char *num1, *num2, *result;
    int i;

    if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
        errors();

    num1 = argv[1], num2 = argv[2];

    result = multiply(num1, num2);

    if (result == NULL)
        errors();

    i = 0;
    while (result[i] == '0' && result[i + 1] != '\0')
        i++;

    printf("%s\n", result + i);

    free(result);

    return (0);
}
