/*
** set_bt_false.c for set in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Apr 28 15:31:08 2016 bougon_p
** Last update Thu Apr 28 15:32:07 2016 bougon_p
*/

#include "raytracer.h"

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
