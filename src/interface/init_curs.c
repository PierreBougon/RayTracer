/*
** init_curs.c for init in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat May 21 14:17:00 2016 bougon_p
** Last update Sat May 21 14:17:30 2016 bougon_p
*/

#include "raytracer.h"

void	set_aa_curs(t_data *data, t_itfc *itfc)
{
  int	i;
  int	add;

  i = 4;
  add = 20;
  if (data->rt.opt.aa <= 1)
    itfc->gen.pos_curs_aa.x = (int)itfc->gen.acc_curs_aa.x +
      (0);
  while (i <= 32)
    {
      if (data->rt.opt.aa == i)
	itfc->gen.pos_curs_aa.x = (int)itfc->gen.acc_curs_aa.x +
	  (add * 1.75);
      i *= 2;
      add += 20;
    }
}

void	init_slide_pos(t_itfc *itfc, t_data *data)
{
  itfc->gen.acc_curs_li.x = START_SLIDE_LI_X;
  itfc->gen.acc_curs_li.y = START_SLIDE_LI_Y;
  itfc->gen.pos_curs_li.x = (int)itfc->gen.acc_curs_li.x;
  itfc->gen.pos_curs_li.y = (int)itfc->gen.acc_curs_li.y + 3;
  itfc->gen.acc_curs_amb.x = START_SLIDE_AMB_X +
    data->rt.opt.ambient * 175;
  itfc->gen.acc_curs_amb.y = START_SLIDE_AMB_Y + HALF_CURS_Y;
  itfc->gen.pos_curs_amb.x = (int)itfc->gen.acc_curs_amb.x;
  itfc->gen.pos_curs_amb.y = (int)itfc->gen.acc_curs_amb.y;
  itfc->gen.acc_curs_aa.x = START_SLIDE_AA_X;
  itfc->gen.acc_curs_aa.y = START_SLIDE_AA_Y + HALF_CURS_Y;
  itfc->gen.pos_curs_aa.y = (int)itfc->gen.acc_curs_aa.y;
  set_aa_curs(data, itfc);
  itfc->gen.needmoving = false;
}
