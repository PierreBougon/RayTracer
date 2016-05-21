/*
** sobel.h for rt in ~/RENDU/INFOGRAPHIE/gfx_raytracer2
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon May 16 19:07:40 2016 marc brout
** Last update Fri May 20 21:32:20 2016 marc brout
*/

#ifndef SOBEL_H_
# define SOBEL_H_

# include "lapin.h"

# ifndef CARRE
#  define CARRE(value) ((value) * (value))
# endif
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

/*
** sobel_init.c
*/

void			init_kernels(int tabx[3][3], int taby[3][3]);
void			init_sobel(t_sobel *sobel);

/*
** borderland_filter.c
*/

int			borderland(t_bunny_pixelarray **pix,
				   const int value);

/*
** sobel_filter.c
*/

t_bunny_pixelarray	*get_sobel(t_bunny_pixelarray *pix);
int			sobel(t_bunny_pixelarray **pix,
			      const int value);

#endif /* !SOBEL_H_ */
