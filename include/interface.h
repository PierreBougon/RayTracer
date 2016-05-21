/*
** interface.h for ITFC in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Apr 13 22:53:18 2016 bougon_p
** Last update Sat May 21 10:28:59 2016 bougon_p
*/

#ifndef INTERFACE_H_
# define INTERFACE_H_

# include "button.h"
# include "context.h"

# define DELETE 8
# define RETURN 13

# define WORK_SPACE_X 433
# define MAX_WORK_SPACE_X 1904
# define WORK_SPACE_Y 75
# define MAX_WORK_SPACE_Y 1012

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
# define FIRST_Y 12
# define DECAL_X 2
# define SIZE_Y 36
# define CH_LINE 32

/*
** PAST DEFINES
*/
# define PAST_X 341
# define PAST_Y 210
# define PAST_DECAL_Y 89

# define PAST_X_ 345
# define PAST_Y_ 754
# define PAST_DECAL_Y_ 40

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

typedef	enum			e_tex_state
  {
    FLAT,
    PERLIN,
    IMG
  }				t_tex_state;

typedef	enum			e_bt_state
  {
    YES,
    NO
  }				t_bt_state;

typedef struct	s_data		t_data;
typedef struct	s_rt		t_rt;
typedef struct	s_object	t_object;
typedef	struct	s_acc		t_acc;

typedef	struct			s_move
{
  bool				needmoving;
  t_bunny_position		first_pos;
  t_bunny_position		second_pos;
}				t_move;

typedef	struct			s_text
{
  bool				writing;
  t_bunny_window		*win;
  t_bunny_position		txt_pos;
  t_bunny_picture		*font;
}				t_text;

typedef	struct			s_save
{
  int				(*fct_save[5])(t_data *);
  char				*(*fct_save_ini_name[NB_OBJ])(t_data *, int);
  void				(*fct_save_ini_obj[NB_OBJ])(t_data *,
							    t_object *, t_bunny_ini *, int);
  int				save_state;
  int				curs;
  char				*file;
  bool				need_save;
  char				**obj_names;
}				t_save;

typedef	struct			s_open
{
  int				curs;
  char				*file;
  bool				need_open;
}				t_open;

typedef	struct			s_past
{
  int				rad_state;
  int				refl_state;
  t_bunny_position		pos;
  t_bunny_picture		*img;
}				t_past;

typedef	struct			s_gen
{
  t_bunny_position		pos_curs_li;
  t_bunny_accurate_position	acc_curs_li;
  t_bunny_position		pos_curs_aa;
  t_bunny_position		pos_curs_amb;
  t_bunny_accurate_position	acc_curs_aa;
  t_bunny_accurate_position	acc_curs_amb;
  t_bunny_position		first_pos;
  t_bunny_position		second_pos;
  bool				needmoving;
}				t_gen;

typedef	struct			s_key
{
  t_bunny_keysym		key_move[4];
  t_bunny_keysym		key_rot[4];
  int				(*f_key_move[4])(t_data *);
  int				(*f_key_rot[4])(t_data *);
}				t_key;

typedef struct			s_itfc
{
  t_move			move;
  t_text			txt;
  t_save			save;
  t_open			open;
  t_past			past;
  t_gen				gen;
  t_key				key;
  t_object			*obj_selected;
  t_object			*light_selected;
  t_bunny_picture		*curs;
  t_bunny_picture		*layout;
  t_bunny_picture		*context[9];
  int				act_context;
  t_bunny_position		context_pos;
  bool				button[19];
  int				status;
  bool				rendering;
  bool				rendered;
  bool				left_click;
  bool				obj_click;
  bool				askobj_click;
  bool				live;
  const	t_bunny_position	*mpos;
  int				(*fct_resize[NB_OBJ])(t_data *, t_acc *);
  int				(*fct_apply_image[NB_OBJ])(t_data *);
  int				(*fct_context[NB_CONTEXT])(t_data *);
  int				(*fct_button[4])(t_data *);
  int				(*fct_state[NB_STATUS])(t_data *,
							t_bunny_event_state,
							t_bunny_mousebutton);
  int				(*fct_bt_context)(t_data *);
  int				(*fct_set_size[NB_SIZE_BT])(t_data *);
  char				**env;
}				t_itfc;

/*
** Main
*/
int	interface(t_data *data);
int	nothing_selected(t_data *data);
int	init_ftabs(t_itfc *);
void	prerender(t_rt *, int, t_data *);

/*
** Key actions
*/
int	move_up(t_data *);
int	move_down(t_data *);
int	move_left(t_data *);
int	move_right(t_data *);
int	rot_up(t_data *);
int	rot_down(t_data *);
int	rot_left(t_data *);
int	rot_right(t_data *);
int	check_key(t_data *, t_bunny_event_state, t_bunny_keysym);

/*
** Eye
*/
void	move_eye(t_data *);
void	rotate_eye(t_data *);
void	zoom(t_data *, int, int);
void	move_on_wheel(t_data *, int, int);

/*
** State
*/
int	mouse_state(t_data *, t_bunny_event_state, t_bunny_mousebutton);
int	move_state(t_data *, t_bunny_event_state, t_bunny_mousebutton);
int	rotate_state(t_data *, t_bunny_event_state, t_bunny_mousebutton);

/*
** Buttons
*/
int	check_all_buttons(t_itfc *);
int	check_button_activated(t_itfc *, t_data *);
void	form_button(t_itfc *, const t_bunny_position *);
void	save_button(t_itfc *, const t_bunny_position *);
void	file_button(t_itfc *, const t_bunny_position *);
void	gen_button(t_itfc *, const t_bunny_position *);
void	set_butt_false(t_itfc *);
void	set_status_false(t_itfc *);

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
** Rendering
*/
int	start_rendering(t_data *);

/*
** Text
*/
void			text(char *, t_itfc *, int, int);
t_bunny_response	my_txtinput(uint32_t, void *);

/*
** Save
*/
int	nothing_selected(t_data *);
int	save_png(t_data *);
int	save_jpg(t_data *);
int	save_bmp(t_data *);
int	save_ini(t_data *);
void	set_first_scope(t_data *, t_bunny_ini *);
void	save_new_ini(t_data *);
char	*sphere_name(t_data *, int);
char	*cylinder_name(t_data *, int);
char	*cone_name(t_data *, int);
char	*plane_name(t_data *, int);
char	*light_name(t_data *, int);
void	sphere_obj(t_data *, t_object *, t_bunny_ini *, int);
void	cylinder_obj(t_data *, t_object *, t_bunny_ini *, int);
void	cone_obj(t_data *, t_object *, t_bunny_ini *, int);
void	plane_obj(t_data *, t_object *, t_bunny_ini *, int);
void	light_obj(t_data *, t_object *, t_bunny_ini *, int);

/*
** Open
*/
int	f_open_file(t_data *);

/*
** Add form
*/
int	add_plane(t_data *);
int	add_sphere(t_data *);
int	add_cone(t_data *);
int	add_cylinder(t_data *);
int	add_cube(t_data *);
int	add_torus(t_data *);
int	add_perf_cube(t_data *);

/*
** Create scene
*/
int	create_scene(t_data *);
int	basic_plane(t_data *);
int	basic_wallpaper(t_data *);


/*
** Slide Bar
*/
int	slide_aa(t_data *);
int	slide_amb(t_data *);

/*
** Size functions
*/
int	set_full_size(t_data *);
int	set_high_size(t_data *);
int	set_hd_size(t_data *);
int	set_xga_size(t_data *);
int	set_vga_size(t_data *);

/*
** Delete
*/
int	delete_form(t_data *);

/*
** SpotLight
*/
int	move_spot(t_data *);
int	add_spot(t_data *);
int	delete_spot(t_data *);
int	select_spot(t_data *);
int	move_stateobj(t_data *, t_bunny_event_state,
		      t_bunny_mousebutton);
int	slide_light(t_data *);

/*
** Check workspace
*/
bool	check_workspace(const t_bunny_position *, t_rt *);

/*
** Modif obj
*/
int	select_obj(t_data *);
int	move_obj(t_data *);
int	resize_obj(t_data *);
int	texture_obj(t_data *);
int	resize_sphere(t_data *, t_acc *);
int	resize_cylinder(t_data *, t_acc *);
int	resize_cone(t_data *, t_acc *);
int	resize_plan(t_data *, t_acc *);
int	apply_sphere(t_data *);
int	apply_cone(t_data *);
int	apply_cylinder(t_data *);
int	apply_plan(t_data *);
int	apply_flat_texture(t_data *);
int	apply_perlin_texture(t_data *);
int	apply_image_texture(t_data *);

#endif /* !INTERFACE  */
