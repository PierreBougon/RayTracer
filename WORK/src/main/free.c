/*
** free.c for FREE in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr 22 22:48:42 2016 bougon_p
** Last update Thu May  5 21:18:05 2016 romain samuel
*/

#include "raytracer.h"

void	free_all(t_data *data)
{
  bunny_free(data->itfc.save.file);
  bunny_free(data->itfc.open.file);
}

void	free_tab(char **tab)
{
  int	j;

  j = -1;
  while (tab[++j] != NULL)
    {
      bunny_free(tab[j]);
    }
  bunny_free(tab);
}
