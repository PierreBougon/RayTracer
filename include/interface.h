/*
** interface.h for ITFC in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Apr 13 22:53:18 2016 bougon_p
** Last update Fri Apr 15 22:25:50 2016 bougon_p
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

typedef struct	s_data	t_data;

typedef struct		s_itfc
{
  t_bunny_pixelarray	*layout;
  t_bunny_pixelarray	*context[9];
  int			act_context;
  t_bunny_position	context_pos;
  bool			button[19];
  int			status;
  int			(*fct_context[NB_CONTEXT])(t_data *);
  int			(*fct_button[4])(t_data *);
}			t_itfc;

/*
** MAIN
*/
int	interface(t_data *data);

/*
** Buttons
*/
int	check_all_buttons(t_itfc *);

void	form_button(t_itfc *, const t_bunny_position *);
void	gen_button(t_itfc *, const t_bunny_position *);
void	set_butt_false(t_itfc *);

/*
** Functions Pointer
*/
int	modif_form(t_data *);
int	add_form(t_data *);
int	sub_form(t_data *);
int	spotlight(t_data *);
int	new_scene(t_data *);
int	filters(t_data *);
int     gen_opt(t_data *);
int	render(t_data *);
int	live(t_data *);
int	open_file(t_data *);
int	help(t_data *);
int	save(t_data *);

#endif /* !INTERFACE  */
