/*
** check_bt_activated.c for bt_activated
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Apr 18 20:22:42 2016 bougon_p
** Last update Thu May  5 19:03:55 2016 bougon_p
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
  while (i <= NB_CONTEXT)
    {
      if (itfc->button[i])
	{
	  printf("\n==Button : %d IS Activated==\n", i);
	  if (itfc->fct_context[i - 1](data) == 1)
	    return (1);
	  return (-1);
	}
      i++;
    }
  return (i);
}

int	check_bt_activated(t_itfc *itfc, t_data *data)
{
  int	i;
  int	n;

  i = 9;
  n = 0;
  while (i < NB_BUTTON)
    {
      while (i == MOUSE || i == MOVE || i == ROTATE)
	i++;
      if (itfc->button[i])
	{
	  printf("\n==Button : %d IS Activated== FOR %d\n", i, n);
	  if (itfc->rendering && (i != LIVE && i != HELP))
	    return (0);
	  if (itfc->fct_button[n](data) == 1)
	    return (1);
	  return (0);
	}
      i++;
      n++;
    }
  return (0);
}

int	check_button_activated(t_itfc *itfc, t_data *data)
{
  int	i;

  i = 0;
  if (itfc->button[0])
    {
      /* printf("No Button is activated\n"); */
      return (0);
    }
  if (data->rt.live && (i = check_context_activated(itfc, data)) == 1)
    return (1);
  if (i == -1)
    return (0);
  if (check_bt_activated(itfc, data) == 1)
    return (1);
  return (0);
}
