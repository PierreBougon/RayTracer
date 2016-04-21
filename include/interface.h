/*
** interface.h for ITFC in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Apr 13 22:53:18 2016 bougon_p
** Last update Thu Apr 21 12:06:04 2016 bougon_p
*/

#ifndef INTERFACE_H_
# define INTERFACE_H_

# include "button.h"
# include "context.h"

# define WORK_SPACE_X 433
# define MAX_WORK_SPACE_X 1904
# define WORK_SPACE_Y 72
# define MAX_WORK_SPACE_Y 985

# define START_STATUS 11
# define NB_STATUS 3

# define LOADING_COEF 14
# define LOADING_X 443
# define LOADING_Y 1025
# define LOADING_WDT 1450
# define LOADING_HGT 75


typedef enum			e_status
  {
    S_MOUSE,
    S_MOVE,
    S_ROTATE
  }				t_status;

typedef enum			e_buttons
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
  }				t_buttons;

typedef struct	s_data		t_data;

typedef	struct			s_move
{
  bool				needmoving;
  t_bunny_position		first_pos;
  t_bunny_position		second_pos;
}				t_move;

typedef struct			s_itfc
{
  t_bunny_picture		*layout;
  t_bunny_picture		*context[9];
  int				act_context;
  t_bunny_position		context_pos;
  bool				button[19];
  int				status;
  int				(*fct_context[NB_CONTEXT])(t_data *);
  int				(*fct_button[4])(t_data *);
  int				(*fct_state[NB_STATUS])(t_data *,
							t_bunny_event_state,
							t_bunny_mousebutton);
  bool				rendering;
  bool				rendered;
  bool				left_click;
  t_move			move;
  const	t_bunny_position	*mpos;
}				t_itfc;

/*
** Main
*/
int	interface(t_data *data);

/*
** State
*/
int	mouse_state(t_data *, t_bunny_event_state, t_bunny_mousebutton);
int	move_state(t_data *, t_bunny_event_state, t_bunny_mousebutton);
int	rotate_state(t_data *, t_bunny_event_state, t_bunny_mousebutton);
void	move_eye(t_data *);
void	rotate_eye(t_data *);

/*
** Buttons
*/
int	check_all_buttons(t_itfc *);
void	check_button_activated(t_itfc *, t_data *);
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

/*
** RENDERING
*/
void	start_rendering(t_data *);

#endif /* !INTERFACE  */
