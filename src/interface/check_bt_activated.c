/*
** check_bt_activated.c for bt_activated
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Apr 18 20:22:42 2016 bougon_p
** Last update Tue Apr 19 00:59:55 2016 bougon_p
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
  n = 0;
  while (i < NB_BUTTON)
    {
      while (i == MOUSE || i == MOVE || i == ROTATE)
	i++;
      if (itfc->button[i])
	{
	  /* printf("\n==Button : %d IS Activated== FOR %d\n", i, n); */
	  itfc->fct_button[n](data);
	  return ;
	}
      i++;
      n++;
    }
}

void	check_button_activated(t_itfc *itfc, t_data *data)
{
  int	i;

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
