#include "nashell.h"

char *nastrchr(char *d, char c);
int nastrspn(char *d, char *accept);
int nastrcmp(char *p, char *o);
int nastrncmp(const char *p, const char *o, size_t f);

/**
 * nastrchr - Locates
 * @d: string
 * @c: char.
 *
 * Return: pointer
 *         NULL
 */
char *nastrchr(char *d, char c)
{
	int naindex;

	for (naindex = 0; s[naindex]; naindex++)
	{
		if (s[naindex] == c)
			return (s + naindex);
	}

	return (NULL);
}

/**
 * nastrspn - length
 * @d: string
 * @accept: prefix
 *
 * Return: The number of bytes in s which
 *         consist only of bytes from accept.
 */
int nastrspn(char *d, char *accept)
{
	int nabytes = 0;
	int naindex;

	while (*d)
	{
		for (naindex = 0; accept[naindex]; naindex++)
		{
			if (*d == accept[naindex])
			{
				nabytes++;
				break;
			}
		}
		d++;
	}
	return (nabytes);
}

/**
 * nastrcmp - Compare
 * @p: first
 * @o: second
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 = s2
 *         Negative byte difference if s1 < s2
 */
int nastrcmp(char *p, char *o)
{
	while (*p && *o && *p == *o)
	{
		p++;
		o++;
	}

	if (*p != *o)
		return (*p - *o);

	return (0);
}

/**
 * nastrncmp - Compare
 * @p: Poiner.
 * @o: Pointer.
 * @f: The first n bytes of the strings to compare.
 *
 * Return: Less than 0 if s1 is shorter than s2.
 *         0 if s1 and s2 match.
 *         Greater than 0 if s1 is longer than s2.
 */
int nastrncmp(const char *p, const char *o, size_t f)
{
	size_t i;

	for (i = 0; p[i] && o[i] && i < f; i++)
	{
		if (p[i] > o[i])
			return (p[i] - o[i]);
		else if (p[i] < o[i])
			return (p[i] - o[i]);
	}
	if (i == f)
		return (0);
	else
		return (-15);
}
