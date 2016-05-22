/*
** slide_ambient.c for slide in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed May  4 19:08:53 2016 bougon_p
** Last update Sun May 22 18:10:45 2016 benjamin duhieu
*/

#include "raytracer.h"

static	void	check_percentage(t_data *data)
{
  data->rt.opt.ambient = ((data->itfc.gen.pos_curs_amb.x  -
			   START_SLIDE_AMB_X) / 1.75) / 100.0;
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

int	slide_amb(t_data *data)
{
  const	t_bunny_position	*mpos;

  if (check_state(data) == 1)
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
      data->itfc.gen.acc_curs_amb.x += (data->itfc.gen.second_pos.x -
				       data->itfc.gen.first_pos.x);
      if (data->itfc.gen.acc_curs_amb.x < START_SLIDE_AMB_X)
	data->itfc.gen.acc_curs_amb.x = START_SLIDE_AMB_X;
      else if (data->itfc.gen.acc_curs_amb.x > END_SLIDE_AMB_X)
	data->itfc.gen.acc_curs_amb.x = END_SLIDE_AMB_X;
      data->itfc.gen.pos_curs_amb.x = (int)data->itfc.gen.acc_curs_amb.x;
      check_percentage(data);
      data->itfc.gen.first_pos = data->itfc.gen.second_pos;
    }
  return (0);
}
