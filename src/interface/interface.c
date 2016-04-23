/*
** interface.c for interface in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr 15 15:51:45 2016 bougon_p
** Last update Sat Apr 23 19:43:50 2016 bougon_p
*/

#include "raytracer.h"

/*
** This fonction is called from the main loop
** Redirect into the right function which need to be called
** Every loop.
*/

void	check_status_selected(t_data *data)
{
  if (data->itfc.status == S_MOUSE)
    {
      /* printf("STATUS -> MOUSE\n"); */
      return ;
    }
  else if (data->itfc.status == S_MOVE)
    {
      /* printf("STATUS -> MOVE\n"); */
      if (data->itfc.left_click)
	move_eye(data);
    }
  else if (data->itfc.status == S_ROTATE)
    {
      /* printf("STATUS -> ROTATE\n"); */
      if (data->itfc.left_click)
	rotate_eye(data);
    }
}

int	interface(t_data *data)
{
  data->itfc.live = data->rt.live;
  check_status_selected(data);
  if (data->itfc.button[SAVE])
    data->itfc.save.fct_save[data->itfc.save.save_state](data);
  else if (data->itfc.button[OPEN])
    if (f_open_file(data) == 1)
      return (1);
  /*
  ** DEBUG
  */

  /* debug_tabbool(data->itfc.button); */
  /* printf("STATUS => %d\n", data->itfc.status); */
  return (0);
}
