int	in_set(char c, char const *set)
{
	if (c == '\0')
		return (0);
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

