/*
** reset_obj.c for reset in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat May 21 17:46:39 2016 bougon_p
** Last update Sat May 21 17:47:04 2016 bougon_p
*/

#include "raytracer.h"

void	reset_select(t_object *save, t_data *data)
{
  while (save && save->type == LIGHT)
    save = save->next;
  if (save && save->type != LIGHT)
    data->itfc.obj_selected = save;
  else
    data->itfc.obj_selected = NULL;
}
