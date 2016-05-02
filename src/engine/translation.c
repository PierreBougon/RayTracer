/*
** translation.c for translation in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Apr 26 16:19:37 2016 bougon_p
** Last update Mon May  2 17:05:15 2016 marc brout
*/

#include "raytracer.h"

void	translation(t_rotation *r, t_acc *vec, t_pos *rot, t_acc *pos)
{
  rotation(r, vec, rot);
  pos->x += vec->x;
  pos->y += vec->y;
  pos->z += vec->z;
}

void	translation_obj(t_rotation *r, t_acc *vec, t_pos *rot, t_pos *pos)
{
  rotation(r, vec, rot);
  pos->x += vec->x;
  pos->y += vec->y;
  pos->z += vec->z;
}
