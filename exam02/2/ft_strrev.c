#include <stdio.h>

char    *ft_strrev(char *str)
{
	int len;
	int	i;
	char tmp;

	len = 0;
	i = 0;

	while (str[len])
		len++;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;
		i++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	printf("%s\n", ft_strrev(argv[1]));
	return (0);
}
