/*
** free_obj.c for free in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun May 22 16:16:07 2016 bougon_p
** Last update Sun May 22 17:24:15 2016 bougon_p
*/

#include "raytracer.h"

void		free_light(UNUSED t_object *obj)
{
  return ;
}

void		free_sphere(t_object *obj)
{
  t_sphere	*sph;

  sph = obj->datas;
  if (sph->tex_name)
    bunny_free(sph->tex_name);
  if (sph->texture)
    bunny_delete_clipable(&sph->texture->clipable);
}

void		free_cylinder(t_object *obj)
{
  t_cylinder	*cyl;

  cyl = obj->datas;
  if (cyl->tex1_name)
    bunny_free(cyl->tex1_name);
  if (cyl->texture1)
    bunny_delete_clipable(&cyl->texture1->clipable);
  if (cyl->tex2_name)
    bunny_free(cyl->tex2_name);
  if (cyl->texture2)
    bunny_delete_clipable(&cyl->texture2->clipable);
}

void		free_cone(UNUSED t_object *obj)
{
  return ;
}

void		free_plane(t_object *obj)
{
  t_plan	*pla;

  pla = obj->datas;
  if (pla->tex_name)
    bunny_free(pla->tex_name);
  if (pla->texture)
    bunny_delete_clipable(&pla->texture->clipable);
}
