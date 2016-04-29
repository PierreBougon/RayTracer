/*
** free.c for FREE in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr 22 22:48:42 2016 bougon_p
** Last update Fri Apr 29 16:33:32 2016 bougon_p
*/

#include "raytracer.h"

void	free_all(t_data *data)
{
  free(data->itfc.save.file);
  free(data->itfc.open.file);
}

void	free_tab(char **tab)
{
  int	j;

  j = -1;
  while (tab[++j] != NULL)
    {
      free(tab[j]);
    }
  free(tab);
}
