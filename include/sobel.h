/*
** sobel.h for rt in ~/RENDU/INFOGRAPHIE/gfx_raytracer2
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon May 16 19:07:40 2016 marc brout
** Last update Tue May 17 14:19:29 2016 marc brout
*/

#ifndef SOBEL_H_
# define SOBEL_H_

# include "lapin.h"

# define CARRE(value) ((value) * (value))
# define CUT 25
# define BORDER 0xFF000000
# define BACK 0xFFFFFFFF

typedef struct		s_sobel
{
  t_bunny_position	pos;
  int			x_red;
  int			x_blue;
  int			x_green;
  int			y_red;
  int			y_blue;
  int			y_green;
  int			width;
  int			height;
}			t_sobel;

typedef struct		s_data
{
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*sobel;
  t_bunny_window	*win;
}			t_data;

#endif /* !SOBEL_H_ */
