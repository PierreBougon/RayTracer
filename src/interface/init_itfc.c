/*
** init_itfc.c for init in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Apr 13 23:33:13 2016 bougon_p
** Last update Thu Apr 14 13:08:28 2016 bougon_p
*/

#include "raytracer.h"

int	init_pix(t_itfc *itfc)
{
  if ((itfc->layout =
       bunny_load_pixelarray("assets/img/layout.png")) == NULL ||
      (itfc->context[0] =
       bunny_load_pixelarray("assets/img/context_basic.png")) == NULL ||
      (itfc->context[1] =
       bunny_load_pixelarray("assets/img/context_modifs.png")) == NULL ||
      (itfc->context[2] =
       bunny_load_pixelarray("assets/img/context_addform.png")) == NULL ||
      (itfc->context[3] =
       bunny_load_pixelarray("assets/img/context_delete.png")) == NULL ||
      (itfc->context[4] =
       bunny_load_pixelarray("assets/img/context_spot.png")) == NULL ||
      (itfc->context[5] =
       bunny_load_pixelarray("assets/img/context_scene.png")) == NULL ||
      (itfc->context[6] =
       bunny_load_pixelarray("assets/img/context_basic.png")) == NULL ||
      (itfc->context[7] =
       bunny_load_pixelarray("assets/img/context_genopt.png")) == NULL ||
      (itfc->context[8] =
       bunny_load_pixelarray("assets/img/context_save.png")) == NULL)
    return (my_puterr("Could not perform bunny_load_pixelarray"));
  return (0);
}

int	init_itfc_data(t_itfc *itfc)
{
  int	i;

  itfc->layout = NULL;
  if (init_pix(itfc) == -1)
    return (-1);
  itfc->act_context = 0;
  itfc->context_pos.x = 131;
  itfc->context_pos.y = 70;
  i = 0;
  while (i < 19)
    itfc->button[i++] = false;
  itfc->button[0] = true;
  return (0);
}
