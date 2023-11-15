#include "nashell.h"

int nastrlen(const char *d);
char *nastrcpy(char *dest, const char *src);
char *nastrcat(char *dest, const char *src);
char *nastrncat(char *dest, const char *src, size_t f);

/**
 * nastrlen - length
 * @d: pointer
 *
 * Return: length
 */
int nastrlen(const char *d)
{
	int nalength = 0;

	if (!d)
		return (nalength);
	for (nalength = 0; d[nalength]; nalength++)
		;
	return (nalength);
}

/**
 * strcat - Concantenatees.
 * @dest: Pointer
 * @src: Pointer
 *
 * Return: Pointer
 */
char *nastrcat(char *dest, const char *src)
{
	char *nadest;
	const char *nasrc;

	nadest = dest;
	nasrc =  src;

	while (*nadest != '\0')
		nadest++;

	while (*nasrc != '\0')
		*nadest++ = *nasrc++;
	*nadest = '\0';
	return (dest);
}

/**
 * nastrcpy - Copies.
 * @dest: Pointer
 * @src: Pointer
 *
 * Return: Pointer to dest.
 */
char *nastrcpy(char *dest, const char *src)
{
        size_t i;

        for (i = 0; src[i] != '\0'; i++)
                dest[i] = src[i];
        dest[i] = '\0';
        return (dest);
}

/**
 * nastrncat - Concantenates two strings where n number
 *            of bytes are copied from source.
 * @dest: Pointer
 * @src: Pointer
 * @f: f byte
 *
 * Return: Pointer
 */
char *nastrncat(char *dest, const char *src, size_t f)
{
	size_t nalen = nastrlen(dest);
	size_t i;

	for (i = 0; i < f && src[i] != '\0'; i++)
		dest[nalen + i] = src[i];
	dest[nalen + i] = '\0';

	return (dest);
}
