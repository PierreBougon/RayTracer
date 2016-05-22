/*
** glass.h for ~/RENDU/INFOGRAPHIE/gfx_raytracer2/include
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed May 18 16:24:11 2016 marc brout
** Last update Sun May 22 16:33:56 2016 marc brout
*/

#ifndef GLASS_H_
# define GLASS_H_

# define C_W clipable.clip_width
# define C_H clipable.clip_height
# define SIZE 49
# define RACSIZE 7
# define RADIUS 10

#include "lapin.h"

void	apply_median(t_bunny_pixelarray *src,
		     t_bunny_pixelarray *dst,
		     const int width,
		     const int height);
void	apply_shatter(t_bunny_pixelarray *pix,
		      t_bunny_pixelarray *save,
		      const int width,
		      const int height);

int	glass(t_bunny_pixelarray **pix,
	      const int value);
int	median_filter(t_bunny_pixelarray **pix,
		      const int value);

#endif /* !GLASS_H_ */
