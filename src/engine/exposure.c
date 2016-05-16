/*
** exposure.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Wed May  4 18:48:15 2016 romain samuel
** Last update Wed May  4 18:49:45 2016 romain samuel
*/

#include "raytracer.h"

double			expose(double i)
{
  float			exposure;

  exposure = -1.0;
  i = 1.0 - expf(i * exposure);
  return (i);
}
