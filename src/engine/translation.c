/*
** translation.c for translation in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Apr 26 16:19:37 2016 bougon_p
** Last update Wed Apr 27 19:32:01 2016 bougon_p
*/

#include "raytracer.h"

void	translation(t_acc *vec, t_pos *rot, t_acc *pos)
{
  rotation(vec, rot);
  pos->x += vec->x;
  pos->y += vec->y;
  pos->z += vec->z;
}

void	translation_obj(t_acc *vec, t_pos *rot, t_pos *pos)
{
  rotation(vec, rot);
  pos->x += vec->x;
  pos->y += vec->y;
  pos->z += vec->z;
}
