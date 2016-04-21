/*
** my_strdup.c for strdup in /home/bougon_p/rendu/PSU_2015_minisell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Mar 28 12:33:47 2016 bougon_p
** Last update Wed Apr  6 23:47:19 2016 bougon_p
*/

#include "my.h"

char	**my_dup_tab(char **tab)
{
  char	**new_tab;
  int	act_lines;
  int	j;

  act_lines = -1;
  while (tab[++act_lines] != NULL);
  if ((new_tab = malloc(sizeof(char *)
			* (act_lines + 2))) == NULL)
    return (NULL);
  new_tab[act_lines] = NULL;
  new_tab[act_lines + 1] = NULL;
  j = -1;
  while (++j < act_lines)
    {
      if ((new_tab[j] = malloc(sizeof(char) * my_strlen(tab[j]))) == NULL)
	return (NULL);
      new_tab[j] = my_strdup(tab[j]);
    }
  return (new_tab);
}

char    *my_strdup(char *src)
{
  int   i;
  char  *dest;

  i = 0;
  if ((dest = malloc(sizeof(char) * my_strlen(src) + 1)) == NULL)
    return (NULL);
  while (src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = 0;
  return (dest);
}
