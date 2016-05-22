/*
** free.c for FREE in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr 22 22:48:42 2016 bougon_p
** Last update Sun May 22 16:14:59 2016 bougon_p
*/

#include "raytracer.h"

void	free_all(t_data *data)
{
  bunny_free(data->itfc.save.file);
  bunny_free(data->itfc.open.file);
  clear_full_list(data->rt.obj, &data->rt.ftabs);
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
