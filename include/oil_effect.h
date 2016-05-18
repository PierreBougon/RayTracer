/*
** oil_effect.h for rt2 in ~/RENDU/INFOGRAPHIE/gfx_raytracer2
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Tue May 17 12:09:28 2016 marc brout
** Last update Wed May 18 15:05:14 2016 marc brout
*/

#ifndef OIL_EFFECT_H_
# define OIL_EFFECT_H_

# define LEVEL 20
# define RADIUS 10

#include "lapin.h"

typedef struct		s_oil
{
  t_bunny_position	pos;
  int			intensity_count[LEVEL + 1];
  double		red;
  double		blue;
  double		green;
  int			r_avg[LEVEL + 1];
  int			b_avg[LEVEL + 1];
  int			g_avg[LEVEL + 1];
}			t_oil;

typedef	struct		s_data
{
  t_bunny_pixelarray	*pix;
  t_bunny_window	*win;
}			t_data;

/*
** oil_effect.c
*/

int			oil(t_bunny_pixelarray **pix);

/*
** init_oil.c
*/

void			init_oil(t_oil, const unsigned int size);

#endif /* !OIL_EFFECT_H_ */
