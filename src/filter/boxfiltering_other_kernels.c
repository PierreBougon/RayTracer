/*
** boxfiltering_other_kernels.c in /RENDU/INFOGRAPHIE/gfx_raytracer2
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri May 20 12:40:19 2016 marc brout
** Last update Fri May 20 12:41:05 2016 marc brout
*/

void			init_kernel_edge(int kernel[9])
{
  kernel[0] = kernel[1] = kernel[2] = kernel[3] = kernel[5] =
    kernel[6] = kernel[7] = kernel[8] = -1;
  kernel[4] = 8;
}

void			init_kernel_raised(int kernel[9])
{
  kernel[0] = kernel[1] = kernel[7] = kernel[3] =
    kernel[5] = kernel[8] = 0;
  kernel[2] = -2;
  kernel[4] = 2;
  kernel[6] = 1;
}
