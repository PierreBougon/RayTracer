/*
** interface.c for interface in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr 15 15:51:45 2016 bougon_p
** Last update Thu Apr 21 22:53:00 2016 bougon_p
*/

#include "raytracer.h"

/*
** This fonction is called from the main loop
** It has actually no actions from main loop for
** the interface it's just reday to code
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

int	interface(UNUSED t_data *data)
{
  data->itfc.live = data->rt.live;
  check_status_selected(data);
  /* debug_tabbool(data->itfc.button); */
  /* check_button_activated(&data->itfc, data); */
  /* printf("STATUS => %d\n", data->itfc.status); */
  return (0);
}
