/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:40:20 by vlundaev          #+#    #+#             */
/*   Updated: 2025/10/07 10:05:28 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int ft_putstr(char *str)
{
	int len = 0;
	int count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[len])
		len += ft_putchar(str[len]);
	return (len);
}

int ft_putnbr(int n, int base)
{
	long nb = n;
	int count = 0;
	char *signs = "0123456789abcdef";

	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= base)
		count += ft_putnbr((nb / base), base);
	count += ft_putchar(signs[nb % base]);
	return (count);
}

int ft_conversion(char type, va_list vargs)
{
	if (type == 's')
		return (ft_putstr(va_arg(vargs, char*)));
	if (type == 'd')
		return (ft_putnbr(va_arg(vargs, int), 10));
	if (type == 'x')
		return (ft_putnbr(va_arg(vargs, int), 16));
	if (type == '%')
		return (ft_putchar('%'));
	return (0);
}

int ft_printf(const char *str, ...)
{
	va_list vargs;
	int len = 0;

	va_start(vargs, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len += ft_conversion(*str, vargs);
		}
		else
			len += ft_putchar(*str);
		if (*str)
			str++;
	}
	va_end(vargs);
	return (len);
}

#include <stdio.h>
int main(void)
{
	int a = ft_printf("Magic %s is %d\n", "number", 42);
	int b = printf("Magic %s is %d\n", "number", 42);
	printf("my %d vs original %d\n", a, b);

	ft_printf("hex for %d is %x\n", 42, 42);
	printf("hex for %d is %x\n", 42, 42);
	ft_printf("%s\n", NULL);
}

