/*
** my_bzero.c for ~/RENDU/CPE/dante/largeur2
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sat May 14 22:39:43 2016 marc brout
** Last update Mon May 16 03:57:55 2016 marc brout
*/

void		my_bzero(void *_ptr,
			 const unsigned int size,
			 const char value)
{
  unsigned int	i;
  char		*ptr;

  ptr = (char *)_ptr;
  i = 0;
  while (i < size)
    {
      *ptr = value;
      ++i;
      ++ptr;
    }
}
