/*
** slide_antialias.c for slide in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed May  4 19:07:40 2016 bougon_p
** Last update Wed May  4 22:42:10 2016 bougon_p
*/

#include "raytracer.h"

static	void	check_percentage(t_data *data)
{
  if (data->itfc.gen.pos_curs_aa.x < START_SLIDE_AA_X + (20 * 1.75))
    data->rt.opt.aa = 1;
  else if (data->itfc.gen.pos_curs_aa.x < START_SLIDE_AA_X + (40 * 1.75))
    data->rt.opt.aa = 4;
  else if (data->itfc.gen.pos_curs_aa.x < START_SLIDE_AA_X + (60 * 1.75))
    data->rt.opt.aa = 8;
  else if (data->itfc.gen.pos_curs_aa.x < START_SLIDE_AA_X + (80 * 1.75))
    data->rt.opt.aa = 16;
  else if (data->itfc.gen.pos_curs_aa.x < START_SLIDE_AA_X + (100 * 1.75))
    data->rt.opt.aa = 32;
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

int				slide_aa(t_data *data)
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
      data->itfc.gen.acc_curs_aa.x += (data->itfc.gen.second_pos.x -
				       data->itfc.gen.first_pos.x);
      if (data->itfc.gen.acc_curs_aa.x < START_SLIDE_AA_X)
	data->itfc.gen.acc_curs_aa.x = START_SLIDE_AA_X;
      else if (data->itfc.gen.acc_curs_aa.x > END_SLIDE_AA_X)
	data->itfc.gen.acc_curs_aa.x = END_SLIDE_AA_X;
      data->itfc.gen.pos_curs_aa.x = (int)data->itfc.gen.acc_curs_aa.x;
      check_percentage(data);
      data->itfc.gen.first_pos = data->itfc.gen.second_pos;
    }
  return (0);
}
