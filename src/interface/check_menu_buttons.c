/*
** check_menu_buttons.c for BUTTON in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Apr 14 21:13:14 2016 bougon_p
** Last update Thu Apr 21 22:58:59 2016 bougon_p
*/

#include "raytracer.h"

void	form_button(t_itfc *itfc, const t_bunny_position *mpos)
{
  int	nb_bt;

  nb_bt = 1;
  while (nb_bt < 5)
    {
      if (mpos->x >= BT_X && mpos->x <= BT_X + BT_WDT
	  && mpos->y >= BT_Y + (BT_HGT * (nb_bt - 1))
	  && mpos->y <= BT_Y + BT_HGT + (BT_HGT * (nb_bt - 1)))
	{
	  if (!itfc->button[nb_bt])
	    {
	      set_butt_false(itfc);
	      itfc->button[nb_bt] = true;
	      itfc->act_context = nb_bt;
	      break;
	    }
	  else
	    {
	      set_butt_false(itfc);
	      itfc->button[0] = true;
	      itfc->act_context = 0;
	    }
	}
      nb_bt++;
    }
}

void	gen_button(t_itfc *itfc, const t_bunny_position *mpos)
{
  int	nb_bt;

  nb_bt = 5;
  while (nb_bt < 8)
    {
      if (mpos->x >= BT_X && mpos->x <= BT_X + BT_WDT
	  && mpos->y >= BT2_Y + (BT_HGT * (nb_bt - 5))
	  && mpos->y <= BT2_Y + BT_HGT + (BT_HGT * (nb_bt - 5)))
	{
	  if (!itfc->button[nb_bt])
	    {
	      set_butt_false(itfc);
	      itfc->button[nb_bt] = true;
	      itfc->act_context = nb_bt;
	      break;
	    }
	  else
	    {
	      set_butt_false(itfc);
	      itfc->button[0] = true;
	      itfc->act_context = 0;
	    }
	}
      nb_bt++;
    }
}
