/*
** check_reflect.c for reflect in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun May 22 13:51:46 2016 bougon_p
** Last update Sun May 22 14:02:37 2016 bougon_p
*/

#include "raytracer.h"

static	void	reflect2_on(t_data *data)
{
  t_cylinder	*cyl;
  t_plan	*pla;

  if (data->itfc.obj_selected->type == CYLINDER)
    {
      cyl = data->itfc.obj_selected->datas;
      cyl->reflection = 0.30;
      data->itfc.past.refl_state = YES;
    }
  else if (data->itfc.obj_selected->type == PLANE)
    {
      pla = data->itfc.obj_selected->datas;
      pla->reflection = 0.30;
      data->itfc.past.refl_state = YES;
    }
}

static	void	reflect_on(t_data *data)
{
  t_sphere	*sph;
  t_cone	*con;

  if (data->itfc.obj_selected->type == SPHERE)
    {
      sph = data->itfc.obj_selected->datas;
      sph->reflection = 0.30;
      data->itfc.past.refl_state = YES;
    }
  else if (data->itfc.obj_selected->type == CONE)
    {
      con = data->itfc.obj_selected->datas;
      con->reflection = 0.30;
      data->itfc.past.refl_state = YES;
    }
  reflect2_on(data);
}

static	void	reflect2_off(t_data *data)
{
  t_cylinder	*cyl;
  t_plan	*pla;

  if (data->itfc.obj_selected->type == CYLINDER)
    {
      cyl = data->itfc.obj_selected->datas;
      cyl->reflection = 0.00;
      data->itfc.past.refl_state = NO;
    }
  else if (data->itfc.obj_selected->type == PLANE)
    {
      pla = data->itfc.obj_selected->datas;
      pla->reflection = 0.00;
      data->itfc.past.refl_state = NO;
    }
}

static	void	reflect_off(t_data *data)
{
  t_sphere	*sph;
  t_cone	*con;

  if (data->itfc.obj_selected->type == SPHERE)
    {
      sph = data->itfc.obj_selected->datas;
      sph->reflection = 0.00;
      data->itfc.past.refl_state = NO;
    }
  else if (data->itfc.obj_selected->type == CONE)
    {
      con = data->itfc.obj_selected->datas;
      con->reflection = 0.00;
      data->itfc.past.refl_state = NO;
    }
  reflect2_off(data);
}

void	check_refl_bt(const t_bunny_position *mpos, t_data *data)
{
  if (!data->itfc.obj_selected)
    return ;
  if ((mpos->x > MOD_REFL_X
       && mpos->x < MOD_REFL_X + MOD_REFL_WDT
       && mpos->y > MOD_REFL_Y
       && mpos->y < MOD_REFL_Y + (MOD_REFL_HGT)))
    {
      reflect_on(data);
    }
  else if ((mpos->x > MOD_REFL_X + MOD_REFL_DECAL
	    && mpos->x < MOD_REFL_X + MOD_REFL_WDT + (MOD_REFL_DECAL)
	    && mpos->y > MOD_REFL_Y
	    && mpos->y < MOD_REFL_Y + (MOD_REFL_HGT)))
    {
      reflect_off(data);
    }
}
