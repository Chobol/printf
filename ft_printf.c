/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chobol <chobol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:46:59 by chobol            #+#    #+#             */
/*   Updated: 2021/02/25 20:02:52 by chobol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
//#include <stdlib.h>
//#include <math.h>
//#include <stdarg.h>


/*
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int a;

	a = 0;
	if (nb >= 0)
		a = nb;
	if (nb < 0)
	{
		a = nb * -1;
		ft_putchar_fd('-', fd);
	}
	if (a > 9)
		ft_putnbr_fd(a / 10, fd);
	ft_putchar_fd((a % 10) + 48, fd);
}*/

//void	ft_putchar_fd(char c, int fd);				//this is working!
//void	ft_putnbr_fd(int nb, int fd);

int ft_printf(const char *textinput, ...)
{
    int n = 0;

    va_list list;
    va_start(list, textinput);
    
    while (textinput[n] != 0)
    {
        if  (textinput[n]=='%')
        {
            n++;
			if (textinput[n]== 'c')
            {
                char letter = va_arg(list, int);
                //printf("%c", letter);
				ft_putchar_fd(letter, 1);					//por qué se pone delante???
            }

			//if (textinput[n]== 's')
				//string of characters
			
			//if (textinput[n]== 'p')
				//pointer adress
			
            if ((textinput[n]== 'd') || (textinput[n]== 'i'))
            {
                int number = va_arg(list, int);
                //printf("%d", number);
				ft_putnbr_fd(number, 1);
            }
            
            if (textinput[n]== 'u')
            {
                unsigned int number = va_arg(list, unsigned int);
                //printf("%u", number);
				ft_putnbr_fd(number, 1);				//que lo pone delante loco...
			}
			
			//if (textinput[n]== 'x')
				//unsigned hexadecimal integer

			//if (textinput[n]== 'X')
				//unsigned hexadecimal integer(uppercase)

			//if (textinput[n]== '%')
        }
		else
		{
			//printf("%c", textinput[n]);
			ft_putchar_fd(textinput[n], 1);				//si pongo esto aquí parece que va bien WTF
		}
		n++;
    }
	va_end(list);
	return (n);
}

int	main()
{
	printf("tarde o temprano funcionará %c %d %i %u\n", 'A', 42, 14, 7000);
	ft_printf("tarde o temprano funcionará %c %d %i %u\n", 'A', 42, 14, 7000);
	//gcc ft_printf.c ft_putchar_fd.c ft_putnbr_fd.c


	return (0);
}