/*
** check_file_buttons.c for check button
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Apr 28 15:27:06 2016 bougon_p
** Last update Thu Apr 28 15:30:09 2016 bougon_p
*/

#include "raytracer.h"

void	save_button(t_itfc *itfc, const t_bunny_position *mpos)
{
  int	nb_bt;

  nb_bt = 8;
  if (mpos->x >= BT_SAVE_X && mpos->x <= BT_SAVE_X + SAVE_WDT
      && mpos->y >= BT_SAVE_Y && mpos->y <= BT_EXIT_Y + SAVE_HGT)
    {
      if (!itfc->button[nb_bt])
	{
	  set_butt_false(itfc);
	  itfc->button[nb_bt] = true;
	  itfc->act_context = nb_bt;
	}
      else
	{
	  set_butt_false(itfc);
	  itfc->button[0] = true;
	  itfc->act_context = 0;
	}
    }
}

void	file_button(t_itfc *itfc, const t_bunny_position *mpos)
{
  int	nb_bt;

  nb_bt = 9;
  while (nb_bt < 11)
    {
      if (mpos->x >= BT_SAVE_X + (SAVE_WDT * (nb_bt - 8)) + 5
	  && mpos->x <= BT_SAVE_X + SAVE_WDT + (SAVE_WDT * (nb_bt - 8)) + 5
	  && mpos->y >= BT_SAVE_Y
	  && mpos->y <= BT_SAVE_Y + SAVE_HGT)
	{
	  if (!itfc->button[nb_bt])
	    {
	      set_butt_false(itfc);
	      itfc->button[nb_bt] = true;
	      itfc->act_context = 0;
	    }
	}
      nb_bt++;
    }
}
