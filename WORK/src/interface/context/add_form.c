/*
** add_form.c for addform
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Apr 17 01:54:34 2016 bougon_p
** Last update Sun May  1 19:37:55 2016 bougon_p
*/

#include "raytracer.h"

/*
** This file is use to find the button which is hit when you're
** On the right context. This is called from tab of functions pointers
** On a click action. Set the right fontion in the function pointer
** To call this on the main loop.
*/
static void	first_add(t_data *data, int i)
{
  if (i == 0)
    data->itfc.fct_bt_context = add_plane;
  else if (i == 1)
    data->itfc.fct_bt_context = add_sphere;
  else if (i == 2)
    data->itfc.fct_bt_context = add_cone;
}

static void	second_add(t_data *data, int i)
{
  if (i == 3)
    data->itfc.fct_bt_context = add_cylinder;
  else if (i == 4)
    data->itfc.fct_bt_context = add_cube;
  else if (i == 5)
    data->itfc.fct_bt_context = add_torus;
}

static	void	check_hit(int i, t_data *data)
{
  if (i >= 0 && i < 3)
    first_add(data, i);
  else if (i >= 3 && i < 6)
    second_add(data, i);
  else if (i == 6)
    data->itfc.fct_bt_context = add_perf_cube;
}

static void	set_value_for_hit(t_data *data, int save)
{
  if (save < NB_ADD_BT)
    {
      data->itfc.past.pos.x = PAST_X;
      data->itfc.past.pos.y = PAST_Y + save * PAST_DECAL_Y;
      data->wait_click = true;
    }
  else
    data->itfc.past.pos.x = 0;
}

int				add_form(t_data *data)
{
  int				i;
  const t_bunny_position	*mpos;
  int				save;

  mpos = data->itfc.mpos;
  i = 0;
  save = NB_ADD_BT + 1;
  while (i < NB_ADD_BT)
    {
      if (mpos->x > ADD_BT_X
	  && mpos->x < ADD_BT_X + ADD_BT_WDT
	  && mpos->y > ADD_BT_Y + (ADD_BT_HGT * i) + (ADD_BT_DECAL * i)
	  && mpos->y < ADD_BT_Y + (ADD_BT_HGT * i)
	  + (ADD_BT_DECAL * i) + ADD_BT_HGT)
	{
	  check_hit(i, data);
	  save = i;
	}
      i++;
    }
  set_value_for_hit(data, save);
  return (0);
}
