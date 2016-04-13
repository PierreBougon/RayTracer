/*
** my_strlen.c for my_strlen in /home/brout_m/dev/PJ4
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Oct  1 16:44:35 2015 marc brout
** Last update Mon Mar 21 19:31:48 2016 Marel la plus belle <3
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    i = i + 1;
  return (i);
}
