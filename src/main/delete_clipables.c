/*
** delete_clipables.c for DELETE in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Apr 14 02:44:00 2016 bougon_p
** Last update Fri Apr 22 22:45:03 2016 bougon_p
*/

#include "raytracer.h"

void	delete_all_clipables(t_data *data)
{
  int	i;

  if (data->rt.img != NULL)
    bunny_delete_clipable(&data->rt.img->clipable);
  if (data->ld.loading != NULL)
    bunny_delete_clipable(&data->ld.loading->clipable);
  if (data->itfc.layout != NULL)
    bunny_delete_clipable(data->itfc.layout);
  if (data->itfc.txt.font != NULL)
    bunny_delete_clipable(data->itfc.txt.font);
  i = 0;
  while (i < 9)
    {
      if (data->itfc.context[i] != NULL)
	bunny_delete_clipable(data->itfc.context[i]);
      i++;
    }
}
