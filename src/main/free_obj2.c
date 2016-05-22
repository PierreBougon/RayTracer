/*
** free_obj2.c for free in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun May 22 16:20:35 2016 bougon_p
** Last update Sun May 22 16:47:25 2016 bougon_p
*/

#include "raytracer.h"

void		free_tore(t_object *obj)
{
  t_tore	*tor;

  tor = obj->datas;
}

void	free_box(t_object *obj)
{
  t_box	*box;

  box = obj->datas;
}

void		free_hole_cube(t_object *obj)
{
  t_hole_cube	*hc;

  hc = obj->datas;
}

void		free_hyper(t_object *obj)
{
  t_hyper	*hyp;

  hyp = obj->datas;
}

void	free_parab(t_object *obj)
{
  t_parab	*para;

  para = obj->datas;
}
