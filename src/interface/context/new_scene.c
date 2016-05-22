/*
1;2802;0c** new_scene.c for new_scene.c in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun May  1 01:17:22 2016 bougon_p
** Last update Sun May 22 18:07:35 2016 benjamin duhieu
*/

#include "raytracer.h"

static void	check_hit(t_data *data, int i)
{
  if (i == 0)
    data->itfc.fct_bt_context = create_scene;
  else if (i == 1)
    data->itfc.fct_bt_context = basic_plane;
  else if (i == 2)
    data->itfc.fct_bt_context = basic_wallpaper;
}

static void	set_value_for_hit(t_data *data, int save)
{
  if (save < NB_NEW_BT)
    data->click_action = true;
  else
    data->click_action = false;
}

int				new_scene(t_data *data)
{
  int				i;
  const	t_bunny_position	*mpos;

  mpos = data->itfc.mpos;
  i = 0;
  while (i < NB_NEW_BT)
    {
      if ((i == 0 && mpos->x > NEW_BT_X_FIRST
	   && mpos->x < NEW_BT_X_FIRST + NEW_BT_WDT_FIRST
	   && mpos->y > NEW_BT_Y_FIRST
	   && mpos->y < NEW_BT_Y_FIRST + NEW_BT_HGT_FIRST) ||
	  (i > 0 && mpos->x > ADD_BT_X
	   && mpos->x < NEW_BT_X + NEW_BT_WDT
	   && mpos->y > NEW_BT_Y + (NEW_BT_HGT * (i - 1))
	   + (NEW_BT_DECAL * (i - 1))
	   && mpos->y < NEW_BT_Y + (NEW_BT_HGT * (i - 1))
	   + (NEW_BT_DECAL * (i - 1)) + NEW_BT_HGT))
        {
          check_hit(data, i);
	  break ;
        }
      i++;
    }
  set_value_for_hit(data, i);
  return (0);
}
