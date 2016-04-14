/*
** check_buttons.c for BUTTONS in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Apr 14 02:25:05 2016 bougon_p
** Last update Thu Apr 14 02:41:38 2016 bougon_p
*/

#include "raytracer.h"

void	set_butt_false(t_itfc *itfc)
{
  int	i;

  i = 0;
  while (i < 19)
    {
      itfc->button[i] = false;
      i++;
    }
}

/*
** TODO :
**
** Need to remake this function this is
** only a hitbox test for the first button
** ---> REPLACE '0' BY an 'i' which loop on buttons
**
*/

void	check_all_buttons(t_itfc *itfc)
{
  const	t_bunny_position	*mpos;
  mpos = bunny_get_mouse_position();
  if (mpos->x >= BT_X && mpos->x <= BT_X + BT_WDT
      && mpos->y >= BT_Y && mpos->y <= BT_Y + BT_HGT)
    {
      if (!itfc->button[1])
	{
	  set_butt_false(itfc);
	  itfc->button[1] = true;
	  itfc->act_context = 1;
	}
      else
	{
	  set_butt_false(itfc);
	  itfc->button[0] = true;
	  itfc->act_context = 0;
	}
    }
}
