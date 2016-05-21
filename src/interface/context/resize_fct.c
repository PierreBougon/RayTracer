/*
** resize_fct.c for resize in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri May 20 22:27:41 2016 bougon_p
** Last update Sat May 21 01:23:04 2016 bougon_p
*/

#include "raytracer.h"

int		resize_sphere(t_data *data, t_acc *coef)
{
  t_sphere	*sph;

  sph = data->itfc.obj_selected->datas;
  sph->size += (int)coef->x;
  if (sph->size <= 10)
    sph->size = 10;
  return (0);
}

int	resize_cylinder(t_data *data, t_acc *coef)
{
  t_cylinder	*cyl;

  cyl = data->itfc.obj_selected->datas;
  if (cyl->size + (int)coef->x >= 10)
    cyl->size += (int)coef->x;
  if (cyl->height + (int)(coef->y) >= 10)
    cyl->height += (int)(coef->y);
  return (0);
}

int	resize_cone(t_data *data, t_acc *coef)
{
  t_cone	*con;
  int		ret;

  con = data->itfc.obj_selected->datas;
  if ((ret = con->angle + (int)(coef->x / 30.0)) >= 20
      && ret < 89)
    con->angle += (int)(coef->x / 30.0);
  if (con->height + (int)coef->y / 2 >= 15)
    con->height += (int)coef->y / 2;
  return (0);
}

int	resize_plan(t_data *data, t_acc *coef)
{
  t_plan	*pla;

  pla = data->itfc.obj_selected->datas;
  pla->width += (int)coef->x;
  pla->height += (int)coef->y;
  if (pla->width <= 100)
    pla->width = 100;
  if (pla->height <= 100)
    pla->height = 100;
  return (0);
}
