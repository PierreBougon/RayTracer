/*
** check_buttons.c for BUTTONS in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Apr 14 02:25:05 2016 bougon_p
** Last update Wed May  4 23:59:47 2016 bougon_p
*/

#include "raytracer.h"

/*
** This file is use to check the hit on buttons
** We loop on buttons and set variables which need to be seted
** To the call of the button
**
** Flat number are here to define the decal on hitbox for each
** Buttons. You can find Defines in include/button.h
**
** TO know which button is hit you can refere to the bool tab
** -> itfc->button[] which is set on true only for the button currently
** acting.
*/
void	status_button(t_itfc *itfc, const t_bunny_position *mpos)
{
  int	nb_bt;

  nb_bt = START_STATUS;
  while (nb_bt < START_STATUS + NB_STATUS)
    {
      if (mpos->x >= OPT_X + (OPT_WDT * (nb_bt - 11)) + 7 * (nb_bt - 11)
	  && mpos->x <= OPT_X + OPT_WDT + (OPT_WDT * (nb_bt - 11)) + 7 * (nb_bt - 11)
	  && mpos->y >= OPT_Y
	  && mpos->y <= OPT_Y + OPT_HGT)
	{
	  if (!itfc->button[nb_bt])
	    {
	      set_status_false(itfc);
	      itfc->button[nb_bt] = true;
	      itfc->status = nb_bt - START_STATUS;
	    }
	}
      nb_bt++;
    }
}

void	opt_button(t_itfc *itfc, const t_bunny_position *mpos)
{
  int	nb_bt;

  status_button(itfc, mpos);
  nb_bt = START_STATUS + NB_STATUS;
  while (nb_bt < 16)
    {
      if (mpos->x >= OPT_X + (OPT_WDT * (nb_bt - 11)) + 7 * (nb_bt - 11)
	  && mpos->x <= OPT_X + OPT_WDT + (OPT_WDT * (nb_bt - 11)) + 7 * (nb_bt - 11)
	  && mpos->y >= OPT_Y
	  && mpos->y <= OPT_Y + OPT_HGT)
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

int	exit_button(UNUSED t_itfc *itfc, const t_bunny_position *mpos)
{
  if (mpos->x >= BT_EXIT_X && mpos->x <= BT_EXIT_X + EXIT_WDT
      && mpos->y >= BT_EXIT_Y && mpos->y <= BT_EXIT_Y + EXIT_HGT)
    {
      return (1);
    }
  return (0);
}

int	check_all_buttons(t_itfc *itfc)
{
  itfc->mpos = bunny_get_mouse_position();
  form_button(itfc, itfc->mpos);
  gen_button(itfc, itfc->mpos);
  save_button(itfc, itfc->mpos);
  file_button(itfc, itfc->mpos);
  opt_button(itfc, itfc->mpos);
  if (exit_button(itfc, itfc->mpos) == 1)
    return (1);
  return (0);
}
