/*
** interface.h for ITFC in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Apr 13 22:53:18 2016 bougon_p
** Last update Thu Apr 14 02:39:25 2016 bougon_p
*/

#ifndef INTERFACE_H_
# define INTERFACE_H_

# define CONTEXT_WIDTH 289
# define CONTEXT_HEIGHT 1010

# define WORK_SPACE_X 433
# define MAX_WORK_SPACE_X 1904
# define WORK_SPACE_Y 72
# define MAX_WORK_SPACE_Y 985

# define BT_X 9
# define BT_Y 126
# define BT_WDT 110
# define BT_HGT 110

typedef struct		s_itfc
{
  t_bunny_pixelarray	*layout;
  t_bunny_pixelarray	*context[9];
  int			act_context;
  t_bunny_position	context_pos;
  bool			button[19];
}			t_itfc;

/*
** Buttons
*/
void	check_all_buttons(t_itfc *);

#endif /* !INTERFACE  */
