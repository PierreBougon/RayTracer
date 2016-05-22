/*
** free_obj.c for free in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun May 22 16:16:07 2016 bougon_p
** Last update Sun May 22 16:43:25 2016 bougon_p
*/

#include "raytracer.h"

void		free_light(t_object *obj)
{
  return ;
}

void		free_sphere(t_object *obj)
{
  t_sphere	*sph;

  sph = obj->datas;
  bunny_free(sph->tex_name);
  bunny_delete_clipable(&sph->texture->clipable);
}

void		free_cylinder(t_object *obj)
{
  t_cylinder	*cyl;

  cyl = obj->datas;
}

void		free_cone(t_object *obj)
{
  t_cone	*con;

  con = obj->datas;
}

void		free_plane(t_object *obj)
{
  t_plan	*pla;

  pla = obj->datas;
}
