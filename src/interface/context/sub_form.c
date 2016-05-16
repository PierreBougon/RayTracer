/*
** sub_form.c for sub
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Apr 17 01:55:09 2016 bougon_p
** Last update Mon May 16 21:22:36 2016 bougon_p
*/

#include "raytracer.h"

int				sub_form(UNUSED t_data *data)
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
  	  if (i == 0)
	    {
	      printf("SELECT\n");
	      data->wait_click = true;
	      /* data->itfc.fct_bt_context = select_form; */
	    }
  	  else if (i == 1)
	    {
	      data->itfc.fct_bt_context = delete_form;
	      data->click_action = true;
	    }
  	  break ;
  	}
      i++;
    }
  return (0);
}
