/*
** sobel_init.c for rt2 in INFOGRAPHIE/gfx_raytracer2/src/filter
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed May 18 14:50:17 2016 marc brout
** Last update Wed May 18 14:52:49 2016 marc brout
*/

#include "sobel.h"

void			init_kernels(int tabx[3][3],
				     int taby[3][3])
{
  tabx[0][0] = tabx[2][0] =  -1;
  tabx[0][1] = tabx[1][1] = tabx[2][1] = 0;
  tabx[0][2] = tabx[2][2] = 1;
  tabx[1][0] = -2;
  tabx[1][2] = 2;
  taby[0][0] = taby[0][2] = -1;
  taby[1][0] = taby[1][1] = taby[1][2] = 0;
  taby[2][0] = taby[2][2] = 1;
  taby[0][1] = -2;
  taby[2][1] = 2;
}

void			init_sobel(t_sobel *sobel)
{
  sobel->x_red = 0;
  sobel->x_blue = 0;
  sobel->x_green = 0;
  sobel->y_red = 0;
  sobel->y_blue = 0;
  sobel->y_green = 0;
}
