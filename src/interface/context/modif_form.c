/*
** modif_form.c for form
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Apr 17 01:53:20 2016 bougon_p
** Last update Sat May 21 10:22:02 2016 bougon_p
*/

#include "raytracer.h"

static	void		check_f_bt(int i, t_data *data)
{
  if (i == 0)
    {
      data->itfc.fct_bt_context = select_obj;
      data->wait_click = true;
    }
}

static	void		check_f_bt2(int n, t_data *data)
{
  if (n == 0)
    {
      data->itfc.fct_bt_context = resize_obj;
      data->itfc.askobj_click = true;
    }
  if (n == 1)
    {
      printf("MOVE\n");
      data->itfc.fct_bt_context = move_obj;
      data->itfc.askobj_click = true;
    }
}

static	int	check_rad_bt(const t_bunny_position *mpos, t_data *data)
{
  int		i;

  i = 0;
  while (i < NB_MOD_RAD)
    {
      if ((mpos->x > MOD_RAD_X
	   && mpos->x < MOD_RAD_X + MOD_RAD_WDT
	   && mpos->y > MOD_RAD_Y + (MOD_RAD_HGT * i)
	   + (MOD_RAD_DECAL * i)
	   && mpos->y < MOD_RAD_Y + (MOD_RAD_HGT * i)
	   + MOD_RAD_HGT + (MOD_RAD_DECAL * i)))
	{
	  if (data->itfc.obj_selected && i == 0)
	    {
	      data->itfc.past.rad_state = FLAT;
	      apply_flat_texture(data);
	    }
	  if (data->itfc.obj_selected && i == 1)
	    {
	      data->itfc.past.rad_state = PERLIN;
	      apply_perlin_texture(data);
	    }
	  if (data->itfc.obj_selected && i == 2)
	    {
	      data->itfc.past.rad_state = IMAGE;
	      if (apply_image_texture(data))
		return (1);
	    }
	  break ;
	}
      i++;
    }
  return (0);
}

static	void	check_refl_bt(const t_bunny_position *mpos, t_data *data)
{
  double		*reflect;

  reflect = (double *)data->itfc.obj_selected->datas + sizeof(t_pos);
  if ((mpos->x > MOD_REFL_X
       && mpos->x < MOD_REFL_X + MOD_REFL_WDT
       && mpos->y > MOD_REFL_Y
       && mpos->y < MOD_REFL_Y + (MOD_REFL_HGT)))
    {
      printf("YES\n");
      *reflect = 0.30;
      data->itfc.past.refl_state = YES;
    }
  else if ((mpos->x > MOD_REFL_X + MOD_REFL_DECAL
	    && mpos->x < MOD_REFL_X + MOD_REFL_WDT + (MOD_REFL_DECAL)
	    && mpos->y > MOD_REFL_Y
	    && mpos->y < MOD_REFL_Y + (MOD_REFL_HGT)))
    {
      printf("NO\n");
      *reflect = 0.00;
      data->itfc.past.refl_state = NO;
    }
}

int				modif_form(t_data *data)
{
  int				i;
  int				n;
  const	t_bunny_position	*mpos;

  mpos = data->itfc.mpos;
  i = 0;
  n = 0;
  if (check_rad_bt(mpos, data) == 1)
    return (1);
  check_refl_bt(mpos, data);
  while (i < NB_MOD_BT / 2)
    {
      if ((mpos->x > MOD_BT_X
	   && mpos->x < MOD_BT_X + MOD_BT_WDT
	   && mpos->y > MOD_BT_Y + (MOD_BT_HGT * i)
	   + (MOD_DECAL * i)
	   && mpos->y < MOD_BT_Y + (MOD_BT_HGT * i)
	   + MOD_BT_HGT + (MOD_DECAL * i)))
        {
	  check_f_bt(i, data);
	  break ;
	}
      else if ((mpos->x > MOD_BT_X
		&& mpos->x < MOD_BT_X + MOD_BT_WDT
		&& mpos->y > MOD_SBT_Y + (MOD_BT_HGT * n)
		+ (MOD_DECAL * n)
		&& mpos->y < MOD_SBT_Y + (MOD_BT_HGT * n)
		+ MOD_BT_HGT + (MOD_DECAL * n)))
	{
	  check_f_bt2(i, data);
	  break ;
	}
      i++;
      n++;
    }
  return (0);
}
