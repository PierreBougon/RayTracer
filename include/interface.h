/*
** interface.h for ITFC in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Apr 13 22:53:18 2016 bougon_p
** Last update Sun Apr 24 18:36:30 2016 bougon_p
*/

#ifndef INTERFACE_H_
# define INTERFACE_H_

# include "button.h"
# include "context.h"

# define DELETE 8
# define RETURN 13

# define WORK_SPACE_X 433
# define MAX_WORK_SPACE_X 1904
# define WORK_SPACE_Y 72
# define MAX_WORK_SPACE_Y 985

# define START_STATUS 11
# define NB_STATUS 3

/*
** LOADING DEFINES
*/
# define LOADING_COEF 14
# define LOADING_X 443
# define LOADING_Y 1025
# define LOADING_WDT 1450
# define LOADING_HGT 36

/*
** SAVE DEFINES
*/
# define FILE_LEN 75
# define TXT_X (LOADING_X + (LOADING_WDT / 2) - ((FILE_LEN * 19) / 2))
# define TXT_Y LOADING_Y - 4

/*
** TXT DEFINES
*/
#define FIRST_Y 12
#define DECAL_X 2
#define SIZE_Y 36
#define CH_LINE 32

typedef enum			e_status
  {
    S_MOUSE,
    S_MOVE,
    S_ROTATE
  }				t_status;

typedef enum			e_save_state
  {
    NOTHING,
    PNG,
    JPG,
    BMP,
    INI
  }				t_save_state;

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

typedef	struct			s_text
{
  t_bunny_window		*win;
  t_bunny_position		txt_pos;
  t_bunny_picture		*font;
}				t_text;

typedef	struct			s_save
{
  int				(*fct_save[5])(t_data *);
  int				save_state;
  int				curs;
  char				*file;
  bool				need_save;
}				t_save;

typedef	struct			s_open
{
  int				curs;
  char				*file;
  bool				need_open;
}				t_open;

typedef struct			s_itfc
{
  t_move			move;
  t_text			txt;
  t_save			save;
  t_open			open;
  t_bunny_picture		*layout;
  t_bunny_picture		*context[9];
  int				act_context;
  t_bunny_position		context_pos;
  bool				button[19];
  int				status;
  bool				rendering;
  bool				rendered;
  bool				left_click;
  bool				live;
  const	t_bunny_position	*mpos;
  int				(*fct_context[NB_CONTEXT])(t_data *);
  int				(*fct_button[4])(t_data *);
  int				(*fct_state[NB_STATUS])(t_data *,
							t_bunny_event_state,
							t_bunny_mousebutton);
  int				(*fct_bt_context)(t_data *);
}				t_itfc;

/*
** Main
*/
int	interface(t_data *data);
int	nothing_selected(t_data *data);

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

/*
** TEXT
*/
void	text(char *, t_itfc *, int, int);

/*
** SAVE
*/
int	nothing_selected(t_data *);
int	save_png(t_data *);
int	save_jpg(t_data *);
int	save_bmp(t_data *);
int	save_ini(t_data *);

/*
** OPEN
*/
int	f_open_file(t_data *);

/*
** ADD FORM
*/
int	add_plane(t_data *);
int	add_sphere(t_data *);
int	add_cone(t_data *);
int	add_cylinder(t_data *);
int	add_cube(t_data *);
int	add_torus(t_data *);
int	add_perf_cube(t_data *);

#endif /* !INTERFACE  */
