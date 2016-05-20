/*
** modif_form.c for form
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Apr 17 01:53:20 2016 bougon_p
** Last update Fri May 20 14:43:29 2016 bougon_p
*/

#include "raytracer.h"

static	void		check_f_bt(int i, t_data *data)
{
  if (i == 0)
    {
      printf("SELECT\n");
    }
  if (i == 1)
    {
      printf("TEXT\n");
    }
}

static	void		check_f_bt2(int n, t_data *data)
{
  if (n == 0)
    {
      printf("RESIZE\n");
    }
  if (n == 1)
    {
      printf("MOVE\n");
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
