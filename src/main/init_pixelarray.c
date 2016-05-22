/*
** init_pixelarray.c for init_pixelarray
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun May 22 21:13:26 2016 benjamin duhieu
** Last update Sun May 22 21:18:10 2016 benjamin duhieu
*/

#include "raytracer.h"

void	init_array(t_data *data)
{
  int	i;

  data->rt.img = NULL;
  data->ld.loading = NULL;
  data->itfc.layout = NULL;
  data->itfc.txt.font = NULL;
  data->itfc.past.img = NULL;
  data->itfc.curs = NULL;
  i = -1;
  while (++i < 9)
    data->itfc.context[i] = NULL;
  data->rt.opt.skybox_right = NULL;
  data->rt.opt.skybox_left = NULL;
  data->rt.opt.skybox_up = NULL;
  data->rt.opt.skybox_down = NULL;
  data->rt.opt.skybox_forward = NULL;
  data->rt.opt.skybox_backward = NULL;
}
