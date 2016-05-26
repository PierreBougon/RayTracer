/*
** interface.c for interface in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr 15 15:51:45 2016 bougon_p
** Last update Thu May 26 15:36:26 2016 bougon_p
*/

#include "raytracer.h"

/*
** This fonction is called from the main loop
** Redirect into the right function which need to be called
** Every loop.
*/
int	nothing_selected(UNUSED t_data *data)
{
  return (0);
}

void	check_status_selected(t_data *data)
{
  if (data->itfc.status == S_MOUSE)
    return ;
  else if (data->itfc.status == S_MOVE)
    {
      if (data->itfc.left_click)
	move_eye(data);
    }
  else if (data->itfc.status == S_ROTATE)
    {
      if (data->itfc.left_click)
	rotate_eye(data);
    }
}

int	interface(t_data *data)
{
  data->itfc.live = data->rt.live;
  check_status_selected(data);
  if (data->itfc.button[SAVE] || data->itfc.button[OPEN])
    data->itfc.txt.writing = true;
  else
    data->itfc.txt.writing = false;
  if (data->itfc.button[SAVE])
    data->itfc.save.fct_save[data->itfc.save.save_state](data);
  else if (data->itfc.button[OPEN])
    if (f_open_file(data) == 1)
      return (1);
  if (data->itfc.button[NO_BUTTON] || data->itfc.rendered)
    data->itfc.fct_bt_context = nothing_selected;
  if (data->rt.live && data->itfc.fct_bt_context(data) == 1)
    return (1);
  return (0);
}
