#include "ft_printf.h"

int	ft_len_ptr(uintptr_t num)
{
	size_t	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_ptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_put_ptr(ptr / 16);
		ft_put_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + 48), 1);
		else
			ft_putchar_fd((ptr - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	length;

	if (ptr == 0)
		return (write(1, "0x0", 3));
	write(1, "0x", 2);
	length = 2;
	ft_put_ptr(ptr);
	length += ft_len_ptr(ptr);
	return (length);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}