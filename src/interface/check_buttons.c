/*
** check_buttons.c for BUTTONS in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Apr 14 02:25:05 2016 bougon_p
** Last update Wed Apr 27 20:38:30 2016 bougon_p
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

void	set_butt_false(t_itfc *itfc)
{
  int	i;

  i = 0;
  while (i < NB_BUTTON)
    {
      if (i != MOUSE && i != MOVE && i != ROTATE)
	itfc->button[i] = false;
      i++;
    }
}

void	set_status_false(t_itfc *itfc)
{
  itfc->button[MOUSE] = false;
  itfc->button[MOVE] = false;
  itfc->button[ROTATE] = false;
}

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
	      /* DEBUG */
	      if (nb_bt == 9)
		printf("==> BUTTON OPEN :  JE SUIS TOUCHE\n");
	      else
		printf("==> BUTTON HELP :  JE SUIS TOUCHE\n");
	      /* !DEBUG */
	      set_butt_false(itfc);
	      itfc->button[nb_bt] = true;
	      itfc->act_context = 0;
	    }
	}
      nb_bt++;
    }
}

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
	      /* DEBUG */
	      if (nb_bt == 11)
		printf("==> BUTTON MOUSE :  JE SUIS TOUCHE\n");
	      else if (nb_bt == 12)
		printf("==> BUTTON MOVE :  JE SUIS TOUCHE\n");
	      else if (nb_bt == 13)
		printf("==> BUTTON ROTATE :  JE SUIS TOUCHE\n");
	      /* !DEBUG */
	      set_status_false(itfc);
	      itfc->button[nb_bt] = true;
	      itfc->status = nb_bt - START_STATUS;
	      /* itfc->act_context = 0; */
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
	  /* DEBUG */
	  if (!itfc->button[nb_bt])
	    {
	      if (nb_bt == 14)
		printf("==> BUTTON RENDER :  JE SUIS TOUCHE\n");
	      else if (nb_bt == 15)
		printf("==> BUTTON LIVE :  JE SUIS TOUCHE\n");
	      /* !DEBUG */
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
