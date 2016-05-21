/*
** modif_form_rad.c for rad in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat May 21 17:17:00 2016 bougon_p
** Last update Sat May 21 17:17:43 2016 bougon_p
*/

#include "raytracer.h"

static	int	do_check(t_data *data, int i)
{
  if (data->itfc.obj_selected && i == 0)
    {
      data->itfc.past.rad_state = FLAT;
      apply_flat_texture(data);
    }
  if (data->itfc.obj_selected && i == 1)
    {
      data->itfc.past.rad_state = PERLIN;
      apply_perlin_texture(data);
    }
  if (data->itfc.obj_selected && i == 2)
    {
      data->itfc.past.rad_state = IMAGE;
      if (apply_image_texture(data))
	return (1);
    }
  return (0);
}

int	check_rad_bt(const t_bunny_position *mpos,
		     t_data *data)
{
  int		i;

  i = 0;
  while (i < NB_MOD_RAD)
    {
      if ((mpos->x > MOD_RAD_X
	   && mpos->x < MOD_RAD_X + MOD_RAD_WDT
	   && mpos->y > MOD_RAD_Y + (MOD_RAD_HGT * i)
	   + (MOD_RAD_DECAL * i)
	   && mpos->y < MOD_RAD_Y + (MOD_RAD_HGT * i)
	   + MOD_RAD_HGT + (MOD_RAD_DECAL * i)))
	{
	  if (do_check(data, i) == 1)
	    return (1);;
	  break ;
	}
      i++;
    }
  return (0);
}
