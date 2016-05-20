/*
** boxfiltering_init_kernels.c ~RENDU/INFOGRAPHIE/gfx_raytracer2
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri May 20 12:35:12 2016 marc brout
** Last update Fri May 20 12:39:56 2016 marc brout
*/

#include "box_filtering.h"

static void		init_kernel_imgblur(int kernel[9])
{
  kernel[0] = kernel[1] = kernel[3] = kernel[5] = kernel[7] =
    kernel[8] = 0;
  kernel[2] = kernel[6] = 2;
  kernel[4] = 1;
}

static void		init_kernel_sharpen(int kernel[9])
{
  kernel[0] = kernel[1] = kernel[2] = kernel[3] = kernel[5] =
    kernel[6] = kernel[7] = kernel[8] = -1;
  kernel[4] = 9;
}

static void		init_kernel_smooth(int kernel[9])
{
  kernel[0] = kernel[1] = kernel[2] = kernel[3] = kernel[5] =
    kernel[6] = kernel[7] = kernel[8] = 1;
  kernel[4] = 2;
}

static void		init_kernel_normal(int kernel[9])
{
  kernel[0] = kernel[1] = kernel[2] = kernel[3] = kernel[5] =
    kernel[6] = kernel[7] = kernel[8] = 0;
  kernel[4] = 1;
}

void			init_kernel_functab(t_box *box)
{
  box->init_kernel[NORMAL] = &init_kernel_normal;
  box->init_kernel[RAISED] = &init_kernel_raised;
  box->init_kernel[SMOOTH] = &init_kernel_smooth;
  box->init_kernel[SHARPEN] = &init_kernel_sharpen;
  box->init_kernel[BLUR] = &init_kernel_imgblur;
  box->init_kernel[EDGE] = &init_kernel_edge;
}
