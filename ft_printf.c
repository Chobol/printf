/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chobol <chobol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:46:59 by chobol            #+#    #+#             */
/*   Updated: 2021/02/25 13:59:30 by chobol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
//#include <stdlib.h>
//#include <math.h>
//#include <stdarg.h>

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
                printf("%c", letter);	//putnbr
            }

			//if (textinput[n]== 's')
				//string of characters
			
			//if (textinput[n]== 'p')
				//pointer adress
			
            if ((textinput[n]== 'd') || (textinput[n]== 'i'))
            {
                int number = va_arg(list, int);
                printf("%d", number);	//change
            }
            
            if (textinput[n]== 'u')
            {
                unsigned int number = va_arg(list, unsigned int);
                printf("%u", number);	//change
			}
			
			//if (textinput[n]== 'x')
				//unsigned hexadecimal integer

			//if (textinput[n]== 'X')
				//unsigned hexadecimal integer(uppercase)

			//if (textinput[n]== '%')
        }
		else
		{
			printf("%c", textinput[n]);			//putchar
		}
		n++;
    }
	va_end(list);
	return (n);
}

int	main()
{
	//ft_printf("YAY! %c\n", 'a');
	printf("YAY! %c\n", 'a');

	return (0);
}