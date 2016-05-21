/*
** sub_form.c for sub
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Apr 17 01:55:09 2016 bougon_p
** Last update Sat May 21 16:53:23 2016 bougon_p
*/

#include "raytracer.h"

static	void	check_sub(t_data *data, int i)
{
  if (i == 0)
    {
      data->wait_click = true;
      data->itfc.fct_bt_context = select_obj;
    }
  else if (i == 1)
    {
      data->itfc.fct_bt_context = delete_form;
      data->click_action = true;
    }
}

int				sub_form(t_data *data)
{
  int				i;
  const	t_bunny_position	*mpos;

  mpos = data->itfc.mpos;
  i = 0;
  while (i < NB_SUB_BT)
    {
      if (mpos->x > SUB_BT_X_FIRST
  	  && mpos->x < SUB_BT_X_FIRST + SUB_BT_WDT
  	  && mpos->y > SUB_BT_Y_FIRST + (SUB_BT_HGT * i) + (SUB_DECAL_Y * i)
  	  && mpos->y < SUB_BT_Y_FIRST + (SUB_BT_HGT * i)
  	  + SUB_BT_HGT + (SUB_DECAL_Y * i))
  	{
	  check_sub(data, i);
  	  break ;
  	}
      i++;
    }
  return (0);
}
