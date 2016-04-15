/*
** interface.c for interface in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr 15 15:51:45 2016 bougon_p
** Last update Fri Apr 15 22:41:53 2016 bougon_p
*/

#include "raytracer.h"

/*
** This file is use to check which button is currently
** Activated, that call the function pointer needed by this button
** That also set itfc->status on the right enum
*/

int	check_context_activated(t_itfc *itfc, t_data *data)
{
  int	i;

  i = 1;
  while (i < NB_CONTEXT)
    {
      if (itfc->button[i])
	{
	  /* printf("\n==Button : %d IS Activated==\n", i); */
	  itfc->fct_context[i - 1](data);
	  return (-1);
	}
      i++;
    }
  return (i);
}

void	check_bt_activated(t_itfc *itfc, t_data *data)
{
  int	i;
  int	n;

  i = 9;
  n = i;
  while (i < NB_BUTTON)
    {
      if (i == MOUSE || i == MOVE || i == ROTATE)
	{
	  i++;
	  n = 12;
	}
      if (itfc->button[i])
	{
	  /* printf("\n==Button : %d IS Activated== FOR %d\n", i, i - n); */
	  itfc->fct_button[i - n](data);
	  return ;
	}
      i++;
    }
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
  check_bt_activated(itfc, data);
}

int	interface(t_data *data)
{
  check_button_activated(&data->itfc, data);
  /* printf("STATUS => %d\n", data->itfc.status); */
  return (0);
}
