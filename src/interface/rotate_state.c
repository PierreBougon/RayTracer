/*
** rotate_state.c for rotate in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Apr 17 15:43:43 2016 bougon_p
** Last update Thu Apr 21 22:18:12 2016 bougon_p
*/

#include "raytracer.h"

int	rotate_state(t_data *data,
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
