/*
** my_realloc.c for realloc in /home/bougon_p/rendu/PSU_2015_minishell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr  1 20:37:47 2016 bougon_p
** Last update Thu Apr 28 21:57:42 2016 bougon_p
*/

#include "my.h"

#include <stdio.h>

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

char	*myrealloc(char *line, size_t add)
{
  char  *new_line;
  int   size;
  int   i;

  size = my_strlen(line);
  if ((new_line = malloc(sizeof(char) * (size + add + 2))) == NULL)
    return (NULL);
  my_bzero(new_line, size + add + 2);
  i = -1;
  while (line[++i])
    new_line[i] = line[i];
  free(line);
  return (new_line);
}
