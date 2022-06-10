#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>



int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int ft_putstr(char *str)
{
	int i = 0;
	
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}


int ft_power(int base, int n)
{
	int i = 0;
	int factor = base;

	if (n == 0)
		return (1);
	while (--n)
		base *= factor;
	return (base);
}

int numb_len(int numb, int base)
{
	int i = 0;

	if (numb == 0)
		return (1);
	while (numb)
	{
		numb /= base;
		i++;
	}
	return (i);
}

int ft_putnbr(int numb)
{
	int i = 0;
	int sign_flag;
	int len = numb_len(numb, 10) - 1;

	if (numb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (numb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (numb < 0)
	{
		write(1, "-", 1);
		numb *= -1;
		i++;
	}
	while (numb != 0)
	{
		ft_putchar('0' + numb / ft_power(10, len));
		numb %= ft_power(10, len--);
		i++;
	}
	return (i);
}

int ft_putnbr_hex(unsigned int numb)
{
	int i = 0;
	int len = numb_len(numb, 16) - 1;
	char hex_base[16] = "0123456789abcdef";

	if (numb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (numb != 0)
	{
		ft_putchar(hex_base[numb / ft_power(16, len)]);
		numb %= ft_power(16, len--);
		i++;
	}
	return (i);
}

int ft_printf(const char *str, ...)
{
	va_list list;
	int ret = 0;
	int i = 0;

	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[++i] == 's')
				ret += ft_putstr(va_arg(list, char *));
			else if (str[i] == 'd')
				ret += ft_putnbr(va_arg(list, int));
			else if (str[i] == 'x')
				ret += ft_putnbr_hex(va_arg(list, unsigned int));
			i++;
		}
		else
			ret += ft_putchar(str[i++]);
	}
	return (ret);
}

int main (int argc, char **argv)
{
//	int a = ft_printf("Hexadecimal for %d is %x\n", 42, 42) - printf("Hexadecimal for %d is %x\n", 42, 42);
//	printf("\n{differ = %d}\n", a);
//	a = ft_printf("Magic %s is %d", "number", 42) - printf("Magic %s is %d", "number", 42);
//	printf("\n{differ = %d}\n", a);
//	a = ft_printf("%s\n", "toto") - printf("%s\n", "toto");
//	printf("\n{differ = %d}\n", a);
	ft_printf("%d%s%%", 124, "aboba");
}
