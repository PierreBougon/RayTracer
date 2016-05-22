/*
** free_obj2.c for free in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun May 22 16:20:35 2016 bougon_p
** Last update Sun May 22 17:19:57 2016 bougon_p
*/

#include "raytracer.h"

void		free_tore(t_object *obj)
{
  t_tore	*tor;

  tor = obj->datas;
  if (tor->tex_name)
    bunny_free(tor->tex_name);
  if (tor->texture)
    bunny_delete_clipable(&tor->texture->clipable);
}

void	free_box(t_object *obj)
{
  t_box	*box;

  box = obj->datas;
  if (box->tex_name)
    bunny_free(box->tex_name);
  if (box->texture)
    bunny_delete_clipable(&box->texture->clipable);
}

void		free_hole_cube(t_object *obj)
{
  t_hole_cube	*hc;

  hc = obj->datas;
  if (hc->tex_name)
    bunny_free(hc->tex_name);
  if (hc->texture)
    bunny_delete_clipable(&hc->texture->clipable);
}

void		free_hyper(t_object *obj)
{
  t_hyper	*hyp;

  hyp = obj->datas;
  hyp = obj->datas;
  if (hyp->tex_name)
    bunny_free(hyp->tex_name);
  if (hyp->texture)
    bunny_delete_clipable(&hyp->texture->clipable);
}

void	free_parab(t_object *obj)
{
  t_parab	*para;

  para = obj->datas;
  para = obj->datas;
  if (para->tex_name)
    bunny_free(para->tex_name);
  if (para->texture)
    bunny_delete_clipable(&para->texture->clipable);
}
