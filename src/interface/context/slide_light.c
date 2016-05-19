/*
** slide_light.c for slide in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed May 18 21:09:40 2016 bougon_p
** Last update Wed May 18 21:36:55 2016 bougon_p
*/

#include "raytracer.h"

static void		check_percentage(t_data *data)
{
  t_light	*light;

  light = data->itfc.light_selected->datas;
  printf("INTENSITY = %f\n",
	 (data->itfc.gen.pos_curs_li.x -
	  START_SLIDE_LI_X) / 1.71);
  light->intensity = ((data->itfc.gen.pos_curs_li.x  -
		       START_SLIDE_LI_X) / 1.71) / 100.0;
  if (light->intensity > 100.0)
    light->intensity = 100.0;
}

static	int	check_state(t_data *data)
{
  static bool	changing = true;

  if (data->mbutton == BMB_LEFT && data->mstate == GO_DOWN && changing)
    {
      data->itfc.gen.needmoving = false;
      changing = false;
    }
  if (data->mbutton == BMB_LEFT && data->mstate == GO_UP)
    {
      changing = true;
      data->itfc.gen.needmoving = false;
      return (1);
    }
  return (0);
}

int	slide_light(t_data *data)
{
  const	t_bunny_position	*mpos;

  if (!data->itfc.light_selected || check_state(data) == 1)
    return (0);
  mpos = data->itfc.mpos;
  if (!data->itfc.gen.needmoving)
    {
      data->itfc.gen.first_pos = *mpos;
      data->itfc.gen.needmoving = true;
    }
  else
    {
      data->itfc.gen.second_pos = *mpos;
      data->itfc.gen.acc_curs_li.x += (data->itfc.gen.second_pos.x -
				       data->itfc.gen.first_pos.x);
      if (data->itfc.gen.acc_curs_li.x < START_SLIDE_LI_X)
	data->itfc.gen.acc_curs_li.x = START_SLIDE_LI_X;
      else if (data->itfc.gen.acc_curs_li.x > END_SLIDE_LI_X)
	data->itfc.gen.acc_curs_li.x = END_SLIDE_LI_X;
      data->itfc.gen.pos_curs_li.x = (int)data->itfc.gen.acc_curs_li.x;
      check_percentage(data);
      data->itfc.gen.first_pos = data->itfc.gen.second_pos;
    }
  return (0);
}
