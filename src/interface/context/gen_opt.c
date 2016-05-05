/*
** gen_opt.c for opt in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed May  4 18:01:50 2016 bougon_p
** Last update Thu May  5 17:29:07 2016 bougon_p
*/

#include "raytracer.h"

void	chose_past_pos(t_data *data)
{
  data->itfc.past.pos.x = FULL_PAST_X;
  if (data->rt.width == FULL_WIDTH && data->rt.height == FULL_HEIGHT)
    data->itfc.past.pos.y = FULL_PAST_Y;
  else if (data->rt.width == HIGH_WIDTH && data->rt.height == HIGH_HEIGHT)
    data->itfc.past.pos.y = FULL_PAST_Y + DECAL_PAST_FULLY * 1;
  else if (data->rt.width == HD_WIDTH && data->rt.height == HD_HEIGHT)
    data->itfc.past.pos.y = FULL_PAST_Y + DECAL_PAST_FULLY * 2;
  else if (data->rt.width == XGA_WIDTH && data->rt.height == XGA_HEIGHT)
    data->itfc.past.pos.y = FULL_PAST_Y + DECAL_PAST_FULLY * 3;
  else if (data->rt.width == VGA_WIDTH && data->rt.height == VGA_HEIGHT)
    data->itfc.past.pos.y = FULL_PAST_Y + DECAL_PAST_FULLY * 4;
}

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
  i = 0;
  while (i < NB_SIZE_BT)
    {
      if (mpos->x > CHOSE_SIZE_X
	  && mpos->x < CHOSE_SIZE_X + CHOSE_SIZE_WDT
	  && mpos->y > CHOSE_SIZE_Y + CHOSE_SIZE_DECAL_Y * i
	  && mpos->y < CHOSE_SIZE_Y + CHOSE_SIZE_HGT + CHOSE_SIZE_DECAL_Y * i)
	{
	  printf("SIZE NB => %d \n", i);
	  data->itfc.fct_set_size[i](data);
	}
      i++;
    }
  chose_past_pos(data);
  return (0);
}
