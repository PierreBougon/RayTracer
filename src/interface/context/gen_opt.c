/*
** gen_opt.c for opt in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed May  4 18:01:50 2016 bougon_p
** Last update Wed May  4 19:10:40 2016 bougon_p
*/

#include "raytracer.h"

int				gen_opt(t_data *data)
{
  int				i;
  const	t_bunny_position	*mpos;

  mpos = data->itfc.mpos;
  if (mpos->x > START_SLIDE_AA_X && mpos->x < END_SLIDE_AA_X
      && mpos->y > START_SLIDE_AA_Y && mpos->y < END_SLIDE_AA_Y)
    data->itfc.fct_bt_context = slide_aa;
  else if (mpos->x > START_SLIDE_AMB_X && mpos->x < END_SLIDE_AMB_X
      && mpos->y > START_SLIDE_AMB_Y && mpos->y < END_SLIDE_AMB_Y)
    data->itfc.fct_bt_context = slide_amb;
  return (0);
}
