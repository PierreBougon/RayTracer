/*
** load_plan_sides.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue May 17 00:39:59 2016 romain samuel
** Last update Tue May 17 02:54:03 2016 romain samuel
*/

#include "raytracer.h"

static	int	init_vecs(t_rt *s, t_box *box, t_acc vec[6])
{
  vec[0].x = 0;
  vec[0].y = box->size.y;
  vec[0].z = 0;
  end_rotation(&s->rotation, &vec[0], &box->rot);
  vec[1].x = 0;
  vec[1].y = - box->size.y;
  vec[1].z = 0;
  end_rotation(&s->rotation, &vec[1], &box->rot);
  vec[2].x = box->size.x;
  vec[2].y = 0;
  vec[2].z = 0;
  end_rotation(&s->rotation, &vec[2], &box->rot);
  vec[3].x = - box->size.x;
  vec[3].y = 0;
  vec[3].z = 0;
  end_rotation(&s->rotation, &vec[3], &box->rot);
  vec[4].x = 0;
  vec[4].y = 0;
  vec[4].z = box->size.z;
  end_rotation(&s->rotation, &vec[4], &box->rot);
  vec[5].x = 0;
  vec[5].y = 0;
  vec[5].z = - box->size.z;
  end_rotation(&s->rotation, &vec[5], &box->rot);
  return (0);
}

static int	init_rot(t_box *box, t_pos rot[6])
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

static int	init_sizes(t_box *box, int width[6], int height[6])
{
  width[0] = box->size.x;
  height[0] = box->size.z;
  width[1] = box->size.x;
  height[1] = box->size.z;
  width[2] = box->size.y;
  height[2] = box->size.z;
  width[3] = box->size.y;
  height[3] = box->size.z;
  width[4] = box->size.x;
  height[4] = box->size.y;
  width[5] = box->size.x;
  height[5] = box->size.y;
  return (0);
}

int	load_plan_sides(t_rt *s, t_box *box)
{
  t_acc	vec[6];
  t_pos	rot[6];
  int	height[6];
  int	width[6];
  int	i;

  i = 0;
  init_vecs(s, box, vec);
  init_rot(box, rot);
  init_sizes(box, width, height);
  while (i < 6)
    {
      box->plan[i].pos.x = box->pos.x + vec[i].x;
      box->plan[i].pos.y = box->pos.y + vec[i].y;
      box->plan[i].pos.z = box->pos.z + vec[i].z;
      box->plan[i].rot = rot[i];
      box->plan[i].height = height[i];
      box->plan[i].width = width[i];
      i++;
    }
  return (0);
}
