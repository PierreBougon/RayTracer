/*
** my_putchar.c for my_putchar in ~/dev/lib
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed Sep 30 21:44:25 2015 marc brout
** Last update Thu Apr 28 14:18:11 2016 bougon_p
*/

#include <unistd.h>

void	 my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    return ;
}
