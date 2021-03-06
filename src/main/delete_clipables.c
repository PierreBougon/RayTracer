/*
** delete_clipables.c for DELETE in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Apr 14 02:44:00 2016 bougon_p
** Last update Sun May 22 20:23:10 2016 bougon_p
*/

#include "raytracer.h"

void	delete_other_clipable(t_data *data)
{
  if (data->rt.opt.skybox_right != NULL && data->rt.opt.skybox_left != NULL
      && data->rt.opt.skybox_up != NULL
      && data->rt.opt.skybox_down != NULL
      && data->rt.opt.skybox_forward != NULL
      && data->rt.opt.skybox_backward != NULL)
    {
      bunny_delete_clipable(&data->rt.opt.skybox_right->clipable);
      bunny_delete_clipable(&data->rt.opt.skybox_up->clipable);
      bunny_delete_clipable(&data->rt.opt.skybox_down->clipable);
      bunny_delete_clipable(&data->rt.opt.skybox_left->clipable);
      bunny_delete_clipable(&data->rt.opt.skybox_forward->clipable);
      bunny_delete_clipable(&data->rt.opt.skybox_backward->clipable);
    }
}

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
  if (data->itfc.past.img != NULL)
    bunny_delete_clipable(data->itfc.past.img);
  if (data->itfc.curs != NULL)
    bunny_delete_clipable(data->itfc.curs);
  i = 0;
  while (i < 9)
    {
      if (data->itfc.context[i] != NULL)
  	bunny_delete_clipable(data->itfc.context[i]);
      i++;
    }
  delete_other_clipable(data);
}
