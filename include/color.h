/*
** color.h for color in ~/RENDU/INFOGRAPHIE/gfx_raytracer2
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu May 19 22:14:24 2016 marc brout
** Last update Thu May 19 22:20:53 2016 marc brout
*/

#ifndef COLOR_H_
# define COLOR_H_

# include "lapin.h"

void		color(t_bunny_pixelarray *pix,
		      const unsigned int color,
		      const double opacity);

#endif /* !COLOR_H_ */
