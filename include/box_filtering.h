/*
** box_filtering.h ~/RENDU/INFOGRAPHIE/gfx_raytracer2
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu May 19 22:57:28 2016 marc brout
** Last update Fri May 20 12:44:31 2016 marc brout
*/

#ifndef BOX_FILTERING_H_
# define BOX_FILTERING_H_

# define CW clipable.clip_width
# define CH clipable.clip_height

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

typedef struct		s_box
{
  void			(*init_kernel[MAX])(int [9]);
  double		div;
  int			box[9];
  double		red;
  double		blue;
  double		green;
  int			kernel[9];
}			t_box;

int			box_filtering(t_bunny_pixelarray **pix,
				      const int effect);
void			init_kernel_functab(t_box *box);
void			init_kernel_edge(int kernel[9]);
void			init_kernel_raised(int kernel[9]);

#endif /* !BOX_FILTERING_H_ */
