/*
** data.h for data in /home/bougon_p/rendu/gfx_raytracer2/extra_fct
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Apr 20 18:20:24 2016 bougon_p
** Last update Sat May 21 11:48:45 2016 bougon_p
*/

#ifndef DATA_H_
# define DATA_H_

# include "lapin.h"

typedef	struct		s_cols
{
  t_color		col1;
  t_color		col2;
  t_color		colres;
}			t_cols;

typedef struct		s_data
{
  t_bunny_pixelarray    *px1;
  t_bunny_pixelarray    *px2;
  t_bunny_pixelarray    *res;
  t_bunny_window        *win;

}			t_data;

void	tekpixel(t_bunny_pixelarray *pix,
		   t_bunny_position *pos,
		   t_color *color);

#endif /* !DATA_H_ */
