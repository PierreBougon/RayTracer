/*
** spotlight.c for spot
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Apr 17 01:55:44 2016 bougon_p
** Last update Sun May 22 18:12:54 2016 benjamin duhieu
*/

#include "raytracer.h"

static void	check_sec_button_spot(t_data *data, int i)
{
  if (i == 3)
    {
      data->itfc.fct_bt_context = move_spot;
      data->itfc.askobj_click = true;
    }
}

static void	check_button_spot(t_data *data, int i)
{
  if (i == 0)
    data->itfc.fct_bt_context = select_spot;
  else if (i == 1)
    {
      data->itfc.fct_bt_context = add_spot;
      data->click_action = true;
    }
  else if (i == 2)
    {
      data->itfc.fct_bt_context = delete_spot;
      data->click_action = true;
    }
  check_sec_button_spot(data, i);
}

int				spotlight(t_data *data)
{
  int				i;
  const t_bunny_position	*mpos;

  mpos = data->itfc.mpos;
  i = 0;
  if (mpos->x > START_SLIDE_LI_X && mpos->x < END_SLIDE_LI_X
      && mpos->y > START_SLIDE_LI_Y && mpos->y < END_SLIDE_LI_Y)
    data->itfc.fct_bt_context = slide_light;
  while (i < NB_SPOT_BT)
    {
      if (mpos->x > SPOT_BT_X_FIRST
          && mpos->x < SPOT_BT_X_FIRST + SPOT_BT_WDT
          && mpos->y > SPOT_BT_Y_FIRST + (SPOT_BT_HGT * i)
	  + (SPOT_DECAL_Y * i)
          && mpos->y < SPOT_BT_Y_FIRST + (SPOT_BT_HGT * i)
          + SPOT_BT_HGT + (SPOT_DECAL_Y * i))
        {
	  data->itfc.askobj_click = false;
	  check_button_spot(data, i);
	  break ;
	}
      i++;
    }
  return (0);
}
