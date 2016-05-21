/*
** move_state.c for move in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Apr 17 15:42:56 2016 bougon_p
** Last update Thu Apr 21 22:20:50 2016 bougon_p
*/

#include "raytracer.h"

int	move_state(t_data *data,
		   t_bunny_event_state mstate,
		   t_bunny_mousebutton mbutton)
{
  if (data->rt.img != NULL)
    {
      if (mbutton == BMB_RIGHT && mstate == GO_DOWN)
	{
	  data->itfc.left_click = true;
	  data->itfc.move.needmoving = false;
	}
      else if (mbutton == BMB_RIGHT && mstate == GO_UP)
	{
	  data->itfc.left_click = false;
	  data->itfc.move.needmoving = false;
	}
    }
  return (0);
}