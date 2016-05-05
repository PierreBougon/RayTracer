/*
** inter_box_sides.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Wed May  4 15:44:38 2016 romain samuel
** Last update Wed May  4 20:12:24 2016 romain samuel
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

int		init_rot(t_rt *s, t_box *box, t_pos rot[6])
{
  rot[0].x = box->rot.x + 90;
  rot[0].y = box->rot.y;
  rot[0].z = box->rot.z;
  rot[1].x = box->rot.x + 90;
  rot[1].y = box->rot.y;
  rot[1].z = box->rot.z;
  rot[2].x = box->rot.x;
  rot[2].y = box->rot.y + 90;
  rot[2].z = box->rot.z;
  rot[3].x = box->rot.x;
  rot[3].y = box->rot.y + 90;
  rot[3].z = box->rot.z;
  rot[4].x = box->rot.x;
  rot[4].y = box->rot.y;
  rot[4].z = box->rot.z;
  rot[5].x = box->rot.x;
  rot[5].y = box->rot.y;
  rot[5].z = box->rot.z;
  return (0);
}

int		inter_box_sides(t_rt *s, t_box *box)
{
  t_plan	plan;
  t_acc		vec[6];
  t_pos		rot[6];
  int		i;
  double	k1;

  i = 0;
  (void)plan;
  init_vecs(s, box, vec);
  init_rot(s, box, rot);
  while (i < 6)
    {
      plan.pos.x = box->pos.x + vec[i].x;
      plan.pos.y = box->pos.y + vec[i].y;
      plan.pos.z = box->pos.z + vec[i].z;
      plan.rot = rot[i];
      inter_plan(s, &plan);

      i++;
    }
  return (0);
}
