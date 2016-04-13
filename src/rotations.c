/*
** rotations.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 18:36:12 2016 romain samuel
** Last update Tue Apr  5 18:38:01 2016 romain samuel
*/

#include "raytracer.h"

t_acc		*rotate_x(t_acc *vct, double angle)
{
  double	m[3][3];
  double	save_x;
  double	save_y;

  save_x = vct->x;
  save_y = vct->y;
  m[0][0] = 1;
  m[0][1] = 0;
  m[0][2] = 0;
  m[1][0] = 0;
  m[1][1] = cos(angle);
  m[1][2] = -sin(angle);
  m[2][0] = 0;
  m[2][1] = sin(angle);
  m[2][2] = cos(angle);
  vct->x = m[0][0] * save_x + m[0][1] * save_y + m[0][2] * vct->z;
  vct->y = m[1][0] * save_x + m[1][1] * save_y + m[1][2] * vct->z;
  vct->z = m[2][0] * save_x + m[2][1] * save_y + m[2][2] * vct->z;
  return (vct);
}

t_acc		*rotate_y(t_acc *vct, double angle)
{
  double	m[3][3];
  double	save_x;
  double	save_y;

  save_x = vct->x;
  save_y = vct->y;
  m[0][0] = cos(angle);
  m[0][1] = 0;
  m[0][2] = sin(angle);
  m[1][0] = 0;
  m[1][1] = 1;
  m[1][2] = 0;
  m[2][0] = -sin(angle);
  m[2][1] = 0;
  m[2][2] = cos(angle);
  vct->x = m[0][0] * save_x + m[0][1] * save_y + m[0][2] * vct->z;
  vct->y = m[1][0] * save_x + m[1][1] * save_y + m[1][2] * vct->z;
  vct->z = m[2][0] * save_x + m[2][1] * save_y + m[2][2] * vct->z;
  return (vct);
}

t_acc		*rotate_z(t_acc *vct, double angle)
{
  double	m[3][3];
  double	save_x;
  double	save_y;

  save_x = vct->x;
  save_y = vct->y;
  m[0][0] = cos(angle);
  m[0][1] = -sin(angle);
  m[0][2] = 0;
  m[1][0] = sin(angle);
  m[1][1] = cos(angle);
  m[1][2] = 0;
  m[2][0] = 0;
  m[2][1] = 0;
  m[2][2] = 1;
  vct->x = m[0][0] * save_x + m[0][1] * save_y + m[0][2] * vct->z;
  vct->y = m[1][0] * save_x + m[1][1] * save_y + m[1][2] * vct->z;
  vct->z = m[2][0] * save_x + m[2][1] * save_y + m[2][2] * vct->z;
  return (vct);
}

t_acc		*rotation(t_acc *vct, t_pos *rot)
{
  vct = rotate_x(vct, (double)((rot->x * M_PI) / 180));
  vct = rotate_y(vct, (double)((rot->y * M_PI) / 180));
  vct = rotate_z(vct, (double)((rot->z * M_PI) / 180));
  return (vct);
}

t_acc		*end_rotation(t_acc *vct, t_pos *rot)
{
  vct = rotate_z(vct, (double)((- rot->z * M_PI) / 180));
  vct = rotate_y(vct, (double)((- rot->y * M_PI) / 180));
  vct = rotate_x(vct, (double)((- rot->x * M_PI) / 180));
  return (vct);
}
