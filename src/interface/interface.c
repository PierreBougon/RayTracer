/*
** interface.c for interface in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr 15 15:51:45 2016 bougon_p
** Last update Fri Apr 15 19:00:56 2016 bougon_p
*/

#include "raytracer.h"

int	check_context_activated(t_itfc *itfc, t_data *data)
{
  int	i;

  i = 1;
  while (i < NB_CONTEXT)
    {
      if (itfc->button[i])
	{
	  /* printf("\n==Button : %d IS Activated==\n", i); */
	  //itfc->fct_context[i](data);
	  return (-1);
	}
      i++;
    }
  return (i);
}

void	check_status_selected(t_itfc *itfc)
{
  int	i;

  i = START_STATUS;
  while (i < NB_STATUS + START_STATUS)
    {
      if (itfc->button[i])
	{
	  itfc->button[MOUSE] = false;
	  itfc->button[MOVE] = false;
	  itfc->button[ROTATE] = false;
	  itfc->status = i - START_STATUS;
	  itfc->button[i] = true;
	}
      i++;
    }
}

void	check_button_activated(t_itfc *itfc, t_data *data)
{
  int	i;

  check_status_selected(itfc);
  if (itfc->button[0])
    {
      /* printf("No Button is activated\n"); */
      return ;
    }
  i = check_context_activated(itfc, data);
  if (i == -1)
    return ;
  while (i < NB_BUTTON)
    {
      if (i == MOUSE || i == MOVE || i == ROTATE)
	i++;
      if (itfc->button[i])
	{
	  /* printf("\n==Button : %d IS Activated==\n", i); */
	  //itfc->
	}
      i++;
    }
}

int	interface(t_data *data)
{
  check_button_activated(&data->itfc, data);
  /* printf("STATUS => %d\n", data->itfc.status); */
  return (0);
}
