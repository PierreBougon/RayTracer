/*
** display_object_complex.c for complex
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
*
*
** Started on  Thu May 12 19:23:53 2016 benjamin duhieu
** Last update Fri May 20 14:43:59 2016 benjamin duhieu
*/

#include <stdio.h>
#include "raytracer.h"

int		display_tore(t_rt *s, t_object *obj)
{
  t_tore	*tore;

  s->hit.limited = 0;
  tore = (t_tore *)obj->datas;
  inter_tore(s, tore);
  if (!(get_simple_inter_complex(s, s->ray.vct, &s->ray.new_eye)))
    {
      end_rotation(&s->rotation, s->ray.vct, &tore->rot);
      end_rotation(&s->rotation, &s->hit.simple_inter1, &tore->rot);
      get_norm_tore(s, tore);
      rotation(&s->rotation, &s->hit.simple_inter1, &tore->rot);
      tore->simple_inter1 = s->hit.simple_inter1;
      tore->simple_inter2 = s->hit.simple_inter2;
      tore->simple_inter3 = s->hit.simple_inter3;
      tore->simple_inter4 = s->hit.simple_inter4;
      tore->inter.k1 = s->hit.k1;
      tore->inter.k2 = s->hit.k2;
      tore->inter.k3 = s->hit.k3;
      tore->inter.k4 = s->hit.k4;
      tore->norm = s->hit.norm;
      update_hit_list_complex(s, tore, TORE, s->hit.k1);
    }
  else
    end_rotation(&s->rotation, s->ray.vct, &tore->rot);
  return (0);
}

int		display_hole_cube(t_rt *s, t_object *obj)
{
  t_hole_cube	*hole_cube;

  s->hit.limited = 0;
  hole_cube = (t_hole_cube *)obj->datas;
  inter_hole_cube(s, hole_cube);
  if (!(get_simple_inter_complex(s, s->ray.vct, &s->ray.new_eye)))
    {
      end_rotation(&s->rotation, s->ray.vct, &hole_cube->rot);
      end_rotation(&s->rotation, &s->hit.simple_inter1, &hole_cube->rot);
      get_norm_hole_cube(s, hole_cube);
      rotation(&s->rotation, &s->hit.simple_inter1, &hole_cube->rot);
      hole_cube->simple_inter1 = s->hit.simple_inter1;
      hole_cube->simple_inter2 = s->hit.simple_inter2;
      hole_cube->simple_inter3 = s->hit.simple_inter3;
      hole_cube->simple_inter4 = s->hit.simple_inter4;
      hole_cube->inter.k1 = s->hit.k1;
      hole_cube->inter.k2 = s->hit.k2;
      hole_cube->inter.k3 = s->hit.k3;
      hole_cube->inter.k4 = s->hit.k4;
      hole_cube->norm = s->hit.norm;
      update_hit_list_complex(s, hole_cube, HOLE_CUBE, s->hit.k1);
    }
  else
    end_rotation(&s->rotation, s->ray.vct, &hole_cube->rot);
  return (0);
}


int		display_parab(t_rt *s, t_object *obj)
{
  t_parab	*parab;

  s->hit.limited = 0;
  parab = (t_parab *)obj->datas;
  inter_parab(s, parab);
  if (!(get_simple_inter(s, s->ray.vct, &s->ray.new_eye)))
    {
      end_rotation(&s->rotation, s->ray.vct, &parab->rot);
      end_rotation(&s->rotation, &s->hit.simple_inter1, &parab->rot);
      get_norm_parab(s, parab);
      rotation(&s->rotation, &s->hit.simple_inter1, &parab->rot);
      parab->simple_inter1 = s->hit.simple_inter1;
      parab->simple_inter2 = s->hit.simple_inter2;
      parab->k1 = s->hit.k1;
      parab->k2 = s->hit.k2;
      parab->norm = s->hit.norm;
      update_hit_list(s, parab, 9, s->hit.k1);
    }
  else
    end_rotation(&s->rotation, s->ray.vct, &parab->rot);
  return (0);
}

int		display_hyper(t_rt *s, t_object *obj)
{
  t_hyper	*hyper;

  s->hit.limited = 0;
  hyper = (t_hyper *)obj->datas;
  inter_hyper(s, hyper);
  if (!(get_simple_inter(s, s->ray.vct, &s->ray.new_eye)))
    {
      end_rotation(&s->rotation, s->ray.vct, &hyper->rot);
      get_norm_hyper(s, hyper);
      rotation(&s->rotation, &s->hit.simple_inter1, &hyper->rot);
      hyper->simple_inter1 = s->hit.simple_inter1;
      hyper->simple_inter2 = s->hit.simple_inter2;
      hyper->k1 = s->hit.k1;
      hyper->k2 = s->hit.k2;
      hyper->norm = s->hit.norm;
      update_hit_list(s, hyper, HYPER, s->hit.k1);
    }
  else
    end_rotation(&s->rotation, s->ray.vct, &hyper->rot);
  return (0);
}
