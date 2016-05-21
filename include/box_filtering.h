/*
** box_filtering.h ~/RENDU/INFOGRAPHIE/gfx_raytracer2
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu May 19 22:57:28 2016 marc brout
** Last update Fri May 20 21:16:10 2016 marc brout
*/

#ifndef BOX_FILTERING_H_
# define BOX_FILTERING_H_

# define CW clipable.clip_width
# define CH clipable.clip_height

# ifndef LAPIN_H_
#  include "lapin.h"
# endif

typedef enum		e_touch
  {
    RAISED_F		= 0,
    SMOOTH_F		= 1,
    SHARPEN_F		= 2,
    BLUR_F		= 3,
    EDGE_F		= 4,
    BORDERLAND_F	= 5,
    OIL_F		= 6,
    GLASS_F		= 7,
    MEDIAN_F		= 8
  }			t_touch;

typedef enum		e_kernel
  {
    NORMAL		= 0,
    RAISED		= 1,
    SMOOTH		= 2,
    SHARPEN		= 3,
    BLUR		= 4,
    EDGE		= 5,
    MAX			= 6
  }			t_kernel;

typedef struct		s_boxe
{
  void			(*init_kernel[MAX])(int [9]);
  double		div;
  int			box[9];
  double		red;
  double		blue;
  double		green;
  int			kernel[9];
}			t_boxe;

int			box_filtering(t_bunny_pixelarray **pix,
				      const int effect);
void			init_kernel_functab(t_boxe *box);
void			init_kernel_edge(int kernel[9]);
void			init_kernel_raised(int kernel[9]);

#endif /* !BOX_FILTERING_H_ */
