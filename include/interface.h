/*
** interface.h for ITFC in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Apr 13 22:53:18 2016 bougon_p
** Last update Fri Apr 15 16:51:03 2016 bougon_p
*/

#ifndef INTERFACE_H_
# define INTERFACE_H_

# include "button.h"

# define CONTEXT_WIDTH 289
# define CONTEXT_HEIGHT 1010

# define NB_CONTEXT 8

# define WORK_SPACE_X 433
# define MAX_WORK_SPACE_X 1904
# define WORK_SPACE_Y 72
# define MAX_WORK_SPACE_Y 985

# define START_STATUS 11
# define NB_STATUS 3

enum			status
  {
    S_MOUSE,
    S_MOVE,
    S_ROTATE
  };

enum			buttons
  {
    NO_BUTTON,
    MODIF_FORM,
    ADD_FORM,
    SUB_FORM,
    SPOTLIGHT,
    NEW_SCENE,
    FILTERS,
    GEN_OPT,
    SAVE,
    OPEN,
    HELP,
    MOUSE,
    MOVE,
    ROTATE,
    RENDER,
    LIVE,
    PREV,
    NEXT,
    EXIT
  };

typedef struct		s_itfc
{
  t_bunny_pixelarray	*layout;
  t_bunny_pixelarray	*context[9];
  int			act_context;
  t_bunny_position	context_pos;
  bool			button[19];
  int			status;
}			t_itfc;

/*
** MAIN
*/
typedef struct	s_data	t_data;
int	interface(t_data *data);

/*
** Buttons
*/
int	check_all_buttons(t_itfc *);

void	form_button(t_itfc *, const t_bunny_position *);
void	gen_button(t_itfc *, const t_bunny_position *);
void	set_butt_false(t_itfc *);

#endif /* !INTERFACE  */
