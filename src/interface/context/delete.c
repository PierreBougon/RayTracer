/*
** delete.c for delete in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon May 16 20:18:36 2016 bougon_p
** Last update Mon May 16 23:15:42 2016 bougon_p
*/

#include "raytracer.h"

int	delete_form(t_data *data)
{
  data->itfc.obj_selected = data->rt.obj;

  if (data->click_action && data->itfc.obj_selected)
    {
      printf("Deleting form\n");
      data->rt.obj = data->rt.obj->next;
      data->itfc.obj_selected->next->prev = NULL;
      bunny_free(data->itfc.obj_selected);
    }
  data->click_action = false;
  return (0);
}
