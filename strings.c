#include <string.h>
#include "monty.h"
/**
 * _strdup - allocates new memory that contains a copy of string parameter
 *
 * @str: string to be copied into newly allocated memory
 *
 * Return: a pointer to the newly allcoated memory containing a copy of 'str'
 */
char *_strdup(char *str)
{
	int i, size;
	char *str1;
	size_t n = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	else
	{
		size = strlen(str);
		str1 = malloc((sizeof(*str) * size) + 256);
		n = size + 256;
		if (str1 == NULL)
		{
			return (NULL);
		}
		else
		{
			memset(str1, 0, n);
			for (i = 0; i < size; i++)
			{
				str1[i] = str[i];
			}
		}
	}
	return (str1);
}
