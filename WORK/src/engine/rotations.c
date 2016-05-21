/*
** rotations.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 18:36:12 2016 romain samuel
** Last update Thu May  5 19:30:03 2016 romain samuel
*/

#include "raytracer.h"

t_acc		*rotate_y(t_rotation *r, t_acc *vct, int angle)
{
  double	save_x;
  double	save_y;

  save_x = vct->x;
  save_y = vct->y;
  set_rotx(r, angle);
  vct->x = r->rotx[0][0] * save_x
    + r->rotx[0][1] * save_y + r->rotx[0][2] * vct->z;
  vct->y = r->rotx[1][0] * save_x
    + r->rotx[1][1] * save_y + r->rotx[1][2] * vct->z;
  vct->z = r->rotx[2][0] * save_x
    + r->rotx[2][1] * save_y + r->rotx[2][2] * vct->z;
  return (vct);
}

t_acc		*rotate_z(t_rotation *r, t_acc *vct, int angle)
{
  double	save_x;
  double	save_y;

  save_x = vct->x;
  save_y = vct->y;
  set_roty(r, angle);
  vct->x = r->roty[0][0] * save_x
    + r->roty[0][1] * save_y + r->roty[0][2] * vct->z;
  vct->y = r->roty[1][0] * save_x
    + r->roty[1][1] * save_y + r->roty[1][2] * vct->z;
  vct->z = r->roty[2][0] * save_x
    + r->roty[2][1] * save_y + r->roty[2][2] * vct->z;
  return (vct);
}

t_acc		*rotate_x(t_rotation *r, t_acc *vct, int angle)
{
  double	save_x;
  double	save_y;

  save_x = vct->x;
  save_y = vct->y;
  set_rotz(r, angle);
  vct->x = r->rotz[0][0] * save_x + r->rotz[0][1] * save_y
    + r->rotz[0][2] * vct->z;
  vct->y = r->rotz[1][0] * save_x + r->rotz[1][1] * save_y
    + r->rotz[1][2] * vct->z;
  vct->z = r->rotz[2][0] * save_x + r->rotz[2][1] * save_y
    + r->rotz[2][2] * vct->z;
  return (vct);
}

t_acc		*rotation(t_rotation *r, t_acc *vct, t_pos *rot)
{
  vct = rotate_x(r, vct, (360 - rot->x) % 360);
  vct = rotate_y(r, vct, (360 - rot->y) % 360);
  vct = rotate_z(r, vct, (360 - rot->z) % 360);
  return (vct);
}

t_acc		*end_rotation(t_rotation *r, t_acc *vct, t_pos *rot)
{
  vct = rotate_z(r, vct, (360 - (-rot->z)) % 360);
  vct = rotate_y(r, vct, (360 - (-rot->y)) % 360);
  vct = rotate_x(r, vct, (360 - (-rot->x)) % 360);
  return (vct);
}
