/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:23:47 by vlundaev          #+#    #+#             */
/*   Updated: 2025/10/07 09:21:30 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char ch)
{
	return (write(1, &ch, 1));
}

int	ft_putstr(char *str)
{
	int	len = 0;

	if (!str)
		return (write(1, "(null)", 6));
	while (str[len])
	{
		len += ft_putchar(str[len]);
	}
	return (len);
}

int	ft_putnbr(long nb)
{
	long num = nb;
	int	count = 0;

	if (nb < 0)
	{
		count += ft_putchar('-');
		num = -num;
	}
	if (num >= 10)
		count += ft_putnbr(num / 10);
	count += ft_putchar('0' + num % 10);
	return (count);
}

int	ft_puthex(unsigned int nb)
{
	char *base = "0123456789abcdef";
	int count = 0;

	if (nb >= 16)
		count += ft_puthex(nb / 16);
	count += ft_putchar(base[nb % 16]);
	return (count);
}

int ft_conversion(char type, va_list ap)
{
	if (type == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (type == 'd')
		return (ft_putnbr(va_arg(ap, long)));
	if (type == 'x')
		return (ft_puthex(va_arg(ap, unsigned int)));
	if (type == '%')
		return (ft_putchar('%'));
	return (0);
}

int ft_printf(const char *str, ...)
{
	va_list args;
	int len = 0;
	int check = 0;

	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len += ft_conversion(*str, args);

		}
		else
			len += ft_putchar(*str);
		if (*str)
			str++;
	}
	va_end(args);
	return (len);
}

#include <stdio.h>
int main(void)
{
	int a = ft_printf("Magic %s is %d\n", "number", 42);
	int b = printf   ("Magic %s is %d\n", "number", 42);
	ft_printf("ret=%d vs %d\n", a, b);

	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("Hexadecimal for %d is %x\n", 42, 42);
	ft_printf("%s\n", NULL);
}
