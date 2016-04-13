/*
** my_realloc.c for realloc in /home/bougon_p/rendu/PSU_2015_minishell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr  1 20:37:47 2016 bougon_p
** Last update Wed Apr  6 23:25:35 2016 bougon_p
*/

#include "my.h"

char	**my_realloc_tab(char **tab, int add_lines)
{
  char	**new_tab;
  int	act_lines;
  int	j;

  act_lines = -1;
  while (tab[++act_lines] != NULL);
  if ((new_tab = malloc(sizeof(char *)
			* (act_lines + add_lines + 1))) == NULL)
    return (NULL);
  new_tab[act_lines + add_lines] = NULL;
  j = -1;
  while (++j < act_lines)
    new_tab[j] = tab[j];
  free(tab);
  return (new_tab);
}

char	*my_realloc(char *line, size_t add)
{
  char  *new_line;
  int   size;
  int   i;

  i = 0;
  size = 0;
  while (line[size] != 0)
    size++;
  if ((new_line = malloc(sizeof(char) * (size + add + 2))) == NULL)
    return (NULL);
  while (i < size)
    {
      new_line[i] = line[i];
      i++;
    }
  while (i < (size + (int)add + 2))
    new_line[i++] = 0;
  free(line);
  return (new_line);
}
