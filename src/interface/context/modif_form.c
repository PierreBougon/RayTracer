/*
** modif_form.c for form
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Apr 17 01:53:20 2016 bougon_p
** Last update Sat May 21 17:17:25 2016 bougon_p
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

static	void	check_refl_bt(const t_bunny_position *mpos, t_data *data)
{
  double		*reflect;

  reflect = (double *)data->itfc.obj_selected->datas + sizeof(t_pos);
  if ((mpos->x > MOD_REFL_X
       && mpos->x < MOD_REFL_X + MOD_REFL_WDT
       && mpos->y > MOD_REFL_Y
       && mpos->y < MOD_REFL_Y + (MOD_REFL_HGT)))
    {
      *reflect = 0.30;
      data->itfc.past.refl_state = YES;
    }
  else if ((mpos->x > MOD_REFL_X + MOD_REFL_DECAL
	    && mpos->x < MOD_REFL_X + MOD_REFL_WDT + (MOD_REFL_DECAL)
	    && mpos->y > MOD_REFL_Y
	    && mpos->y < MOD_REFL_Y + (MOD_REFL_HGT)))
    {
      *reflect = 0.00;
      data->itfc.past.refl_state = NO;
    }
}

static bool	check_bt(const t_bunny_position *mpos, t_data *data,
			 int i, int n)
{
  if ((mpos->x > MOD_BT_X
       && mpos->x < MOD_BT_X + MOD_BT_WDT
       && mpos->y > MOD_BT_Y + (MOD_BT_HGT * i)
       + (MOD_DECAL * i)
       && mpos->y < MOD_BT_Y + (MOD_BT_HGT * i)
       + MOD_BT_HGT + (MOD_DECAL * i)))
    {
      check_f_bt(i, data);
      return (true);
    }
  else if ((mpos->x > MOD_BT_X
	    && mpos->x < MOD_BT_X + MOD_BT_WDT
	    && mpos->y > MOD_SBT_Y + (MOD_BT_HGT * n)
	    + (MOD_DECAL * n)
	    && mpos->y < MOD_SBT_Y + (MOD_BT_HGT * n)
	    + MOD_BT_HGT + (MOD_DECAL * n)))
    {
      check_f_bt2(i, data);
      return (true);
    }
  return (false);
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
      if (check_bt(mpos, data, i, n))
	return (0);
      i++;
      n++;
    }
  return (0);
}
