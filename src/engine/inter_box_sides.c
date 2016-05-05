/*
** inter_box_sides.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Wed May  4 15:44:38 2016 romain samuel
** Last update Wed May  4 17:08:23 2016 romain samuel
*/

#include "raytracer.h"

int		init_vecs(t_rt *s, t_box *box, t_acc vec[6])
{
  vec[0].x = 0;
  vec[0].y = box->size.y;
  vec[0].z = 0;
  rotation(&s->rotation, &vec[0], &box->rot);
  vec[1].x = 0;
  vec[1].y = - box->size.y;
  vec[1].z = 0;
  rotation(&s->rotation, &vec[1], &box->rot);
  vec[2].x = box->size.x;
  vec[2].y = 0;
  vec[2].z = 0;
  rotation(&s->rotation, &vec[2], &box->rot);
  vec[3].x = - box->size.x;
  vec[3].y = 0;
  vec[3].z = 0;
  rotation(&s->rotation, &vec[3], &box->rot);
  vec[4].x = 0;
  vec[4].y = 0;
  vec[4].z = box->size.z;
  rotation(&s->rotation, &vec[4], &box->rot);
  vec[5].x = 0;
  vec[5].y = 0;
  vec[5].z = - box->size.z;
  rotation(&s->rotation, &vec[5], &box->rot);
  return (0);
}

int		inter_box_sides(t_rt *s, t_box *box)
{
  t_plan	plan;
  t_acc		vec[6];

  (void)plan;
  init_vecs(s, box, vec);
  /* printf("0: x = %f y = %f z = %f\n\n", vec[0].x, vec[0].y, vec[0].z); */
  return (0);
}
