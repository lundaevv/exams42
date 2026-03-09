#include <stdlib.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;
	size_t	j;
	size_t check;

	i = 0;

	while (s[i])
	{
		j = 0;
		check = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
				check = 1;
			j++;
		}
		if (check == 0)
			return (i);
		i++;
	}
	return (i);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	printf("%zu\n", ft_strspn(argv[1], argv[2]));
	return (0);
}
