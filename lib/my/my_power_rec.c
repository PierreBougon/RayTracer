/*
** my_power_rec.c for lib
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Mar 14 18:50:35 2016 marc brout
** Last update Mon Mar 14 22:54:41 2016 marc brout
*/

int	my_power_rec(int nb, int i)
{
  if (i < 0 || i > 100000)
    return (0);
  if (i == 0)
    return (1);
  return (nb * my_power_rec(nb, i - 1));
}
