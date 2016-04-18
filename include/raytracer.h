/*
** raytracer.h for raytracer in /home/samuel_r/EPITECH/GFX
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Fri Apr  1 19:50:30 2016 romain samuel
** Last update Mon Apr 18 19:54:23 2016 bougon_p
*/

#ifndef RAYTRACER_H_
# define RAYTRACER_H_

/*
**DEBUG
*/
# include <stdio.h>

/*
** WINDOW DEFINES
*/
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define INIT_WIDTH 720
# define INIT_HEIGHT 720

/*
** TEXTURE DEFINES
*/
# define FULL 1
# define PERLIN_NOISE 2
# define MARBLE_NOISE 3
# define WOOD_NOISE 4
# define IMAGE 5

/*
** includes
*/
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <lapin.h>
# include <time.h>
# include "my.h"
# include "interface.h"

/*
** structures
*/
typedef struct		s_rt t_rt;

typedef struct		s_pos
{
  int			x;
  int			y;
  int			z;
}			t_pos;

typedef struct		s_acc
{
  float			x;
  float			y;
  float			z;
}			t_acc;

typedef struct		s_plan
{
  t_pos			pos;
  t_pos			rot;
  int			real;
  int			tex_type;
  int			height;
  int			width;
  int			case_size;
  double		ka;
  double		kd;
  double		ks;
  double		brightness;
  double		reflection;
  double		opacity;
  t_color		color1;
  t_color		color2;
  t_bunny_pixelarray	*texture;
  double		k1;
  double		k2;
  t_acc			simple_inter2;
  t_acc			simple_inter1;
  t_acc			norm;
}			t_plan;

typedef struct		s_sphere
{
  t_pos			pos;
  t_pos			rot;
  int			real;
  int			tex_type;
  int			size;
  double		ka;
  double		kd;
  double		ks;
  double		brightness;
  double		reflection;
  double		opacity;
  t_color		color;
  t_bunny_pixelarray	*texture;
  double		k1;
  double		k2;
  t_acc			simple_inter2;
  t_acc			simple_inter1;
  t_acc			norm;
}			t_sphere;

typedef struct		s_cone
{
  t_pos			pos;
  t_pos			rot;
  int			real;
  int			tex_type;
  int			angle;
  int			height;
  double		ka;
  double		kd;
  double		ks;
  double		brightness;
  double		reflection;
  double		opacity;
  t_color		color;
  t_bunny_pixelarray	*texture;
  double		k1;
  double		k2;
  t_acc			simple_inter2;
  t_acc			simple_inter1;
  t_acc			norm;
  int			limited;
}			t_cone;

typedef struct		s_cylinder
{
  t_pos			pos;
  t_pos			rot;
  int			real;
  int			tex_type;
  int			size;
  int			height;
  double		ka;
  double		kd;
  double		ks;
  double		brightness;
  double		reflection;
  double		opacity;
  t_color		color;
  t_bunny_pixelarray	*texture;
  double		k1;
  double		k2;
  t_acc			simple_inter2;
  t_acc			simple_inter1;
  t_acc			norm;
  int			limited;
}			t_cylinder;

typedef struct		s_light
{
  t_pos			pos;
  t_color		color;
  double		intensity;
}			t_light;

typedef struct		s_object
{
  void			*datas;
  int			type;
  double		k;
  struct s_object	*next;
  struct s_object	*prev;
}			t_object;

typedef struct		s_eye
{
  t_acc			pos;
  t_pos			rot;
}			t_eye;

typedef struct		s_opt
{
  double		ambient;
  int			aa;
}			t_opt;

typedef struct		s_ray
{
  t_acc			eye;
  t_acc			new_eye;
  t_acc			*vct;
}			t_ray;

typedef struct		s_hit
{
  double		k1;
  double		k2;
  double		cos_theta;
  t_acc			norm;
  t_acc			nnorm;
  t_acc			simple_inter1;
  t_acc			simple_inter2;
  t_acc			inter;
  t_acc			r;
  double		brightness;
  double		ka;
  double		ks;
  double		kd;
  int			limited;
}			t_hit;

typedef struct		s_shadow
{
  t_acc			simple_inter1;
  t_acc			simple_inter2;
}			t_shadow;

typedef struct		s_shade
{
  t_acc			inter;
  t_acc			vct;
  t_acc			nvct;
  t_acc			light_pos;
  t_shadow		shadow;
  int			diff;
  double		x_diff;
  double		y_diff;
  double		z_diff;
}			t_shade;

typedef struct		s_ftab
{
  int			(**inters_ftab)(t_rt *, t_object *);
  int			(**shadow_ftab)(t_rt *, t_object *);
  void			(**hit_ftab)(t_rt *, t_object *);
}			t_ftab;

typedef struct		s_rt
{
  t_bunny_pixelarray	*img;
  t_object		*obj;
  t_object		*obj_hit;
  t_color		*pixel_color;
  t_ftab		ftabs;
  t_ray			ray;
  t_shade		shade;
  t_hit			hit;
  t_opt			opt;
  t_eye			eye;
  t_color		final_color;
  int			width;
  int			height;
  bool			live;
}			t_rt;

typedef struct		s_data
{
  t_rt			rt;
  t_itfc		itfc;
  t_bunny_window	*win;
  t_bunny_event_state	mstate;
  t_bunny_mousebutton	mbutton;
}			t_data;

/*
** Init
*/
int	init_main_data(t_data *);
int	init_rt_data(t_rt *, int, char **);
int	init_itfc_data(t_itfc *, int);
int	init_engine_ftabs(t_ftab *ftabs);

/*
** Blit
*/
void	blit_clipables(t_data *);

/*
** Free
*/
void	delete_all_clipables(t_data *);


/*
** antialiasing.c
*/
t_color		melt_colors(t_rt *s, t_color *color);
t_color		antialiasing(t_rt *s,
			     t_bunny_position *pos,
			     t_acc *vct,
			     t_color *color);

/*
** clear_list.c
*/
int		clear_list(t_object *root);

/*
** create_obj_list.c
*/
t_object	*create_obj_list();
int		add_obj_elem(t_object *root);

/*
** diffuse_light.c
*/
double		second_norm_brightness(t_rt *s);
double		diffuse_light(t_rt *s, t_object *it);

/*
** display.c
*/
int		inter_objects(t_rt *s);
t_color		display_objects(t_rt *s, t_acc *vct, t_acc eye, int rec);
int		display(t_rt *s);

/*
** display_objects.c
*/
int		display_sphere(t_rt *s, t_object *obj);
int		display_cylinder(t_rt *s, t_object *obj);
int		display_cone(t_rt *s, t_object *obj);
int		display_plan(t_rt *s, t_object *obj);

/*
** get_norm.c
*/
void		get_norm_plan(t_rt *s, t_plan *plan);
void		get_norm_sphere(t_rt *s);
void		get_norm_cylinder(t_rt *s, t_cylinder *cylinder);
void		get_norm_cone(t_rt *s, t_cone *cone);

/*
** get_simple_inters.c
*/
int		get_simple_inter(t_rt *s, t_acc *vct, t_acc *eye);

/*
** inters.c
*/
t_acc		set_pos(double x, double y, double z);
int		inter_plan(t_rt *s, t_plan *plan);
int		inter_sphere(t_rt *s, t_sphere *sphere);
int		inter_cone(t_rt *s, t_cone *cone);
int		inter_cylinder(t_rt *s, t_cylinder *cylinder);

/*
** limited_objects.c
*/
int		get_cylinder_plan_inter1(t_rt *s, t_cylinder *cylinder);
int		get_cylinder_plan_inter2(t_rt *s, t_cylinder *cylinder);
int		get_cone_plan_inter(t_rt *s, t_cone *cone);
int		limited_cylinder(t_rt *s, t_cylinder *cylinder);
int		limited_cone(t_rt *s, t_cone *cone);

/*
** load_cone.c
*/
int		load_cone_datas(t_cone *s,
				t_bunny_ini *ini,
				char *scope);
int		load_cone_datas2(t_cone *s, t_bunny_ini *ini, char *scope);
int		load_cone_datas3(t_cone *s, t_bunny_ini *ini, char *scope);
int		load_cone_datas4(t_cone *s, t_bunny_ini *ini, char *scope);
int		load_cone(t_rt *rt, t_bunny_ini *ini, char *scope);

/*
** load_cylinder.c
*/
int		load_cylinder_datas(t_cylinder *s,
				    t_bunny_ini *ini,
				    char *scope);
int		load_cylinder_datas2(t_cylinder *s, t_bunny_ini *ini, char *scope);
int		load_cylinder_datas3(t_cylinder *s, t_bunny_ini *ini, char *scope);
int		load_cylinder_datas4(t_cylinder *s, t_bunny_ini *ini, char *scope);
int		load_cylinder(t_rt *rt, t_bunny_ini *ini, char *scope);

/*
** load_file.c
*/
int		load_type(t_rt *rt,
			  t_bunny_ini *ini,
			  int (**ftab)(t_rt *rt, t_bunny_ini *ini,
				       char *scope),
			  char *scope);
int		load_object(t_rt *s, t_bunny_ini *ini, char *scope);
int		load_eye(t_rt *s, t_bunny_ini *ini);
int		load_scene_parameters(t_rt *s, t_bunny_ini *ini);
int		load_file(t_rt *s, char *file);

/*
** load_light.c
*/
int		load_light_datas(t_light *s,
				 t_bunny_ini *ini,
				 char *scope);
int		load_light(t_rt *rt, t_bunny_ini *ini, char *scope);

/*
** load_plan.c
*/
int		load_plan_datas(t_plan *s,
				t_bunny_ini *ini,
				char *scope);
int		load_plan_datas2(t_plan *s, t_bunny_ini *ini, char *scope);
int		load_plan_datas3(t_plan *s, t_bunny_ini *ini, char *scope);
int		load_plan(t_rt *rt, t_bunny_ini *ini, char *scope);

/*
** load_sphere.c
*/
int		load_sphere_datas(t_sphere *s,
				  t_bunny_ini *ini,
				  char *scope);
int		load_sphere_datas2(t_sphere *s, t_bunny_ini *ini, char *scope);
int		load_sphere_datas3(t_sphere *s, t_bunny_ini *ini, char *scope);
int		load_sphere_datas4(t_sphere *s, t_bunny_ini *ini, char *scope);
int		load_sphere(t_rt *rt, t_bunny_ini *ini, char *scope);

/*
** order_hit_list.c
*/
int		swap_objs(t_object *it, t_object *it_prev);
int		order_list(t_object *root);
int		order_hit_list(t_object *root);

/*
** rotations.c
*/
t_acc		*rotate_x(t_acc *vct, double angle);
t_acc		*rotate_y(t_acc *vct, double angle);
t_acc		*rotate_z(t_acc *vct, double angle);
t_acc		*rotation(t_acc *vct, t_pos *rot);
t_acc		*end_rotation(t_acc *vct, t_pos *rot);

/*
** set_hit_values.c
*/
void		set_hit_values_from_sphere(t_rt *s, t_object *obj);
void		set_hit_values_from_cylinder(t_rt *s, t_object *obj);
void		set_hit_values_from_cone(t_rt *s, t_object *obj);
void		set_hit_values_from_plan(t_rt *s, t_object *obj);
int		set_hit_values(t_rt *s, t_object *obj);

/*
** shade.c
*/
void		init_lum(t_rt *s, t_acc *vct, t_acc eye, t_light *light);
t_color		add_light_color(t_color color,
				t_color second_color);
t_color		apply_b(t_color color,
			t_color light_color,
			double brightness,
			double i);
int		shade(t_rt *s, t_acc *vct, t_acc eye);

/*
** shadow.c
*/
int		shadow_sphere(t_rt *s, t_object *obj);
int		shadow_cone(t_rt *s, t_object *obj);
int		shadow_cylinder(t_rt *s, t_object *obj);
int		shadow_plan(t_rt *s, t_object *obj);
int		shadow(t_rt *s);

/*
** shadow_inters.c
*/
double		return_k(double k[2]);
double		shadow_inter_sphere(t_rt *s, t_sphere *sphere);
double		shadow_inter_cone(t_rt *s, t_cone *cone);
double		shadow_inter_cylinder(t_rt *s, t_cylinder *cylinder);
double		shadow_inter_plan(t_rt *s, t_plan *plan);

/*
** shadow_limited_objects.c
*/
double		shadow_limited_cylinder(t_rt *s, t_cylinder *cylinder, double k);
double		shadow_limited_cone(t_rt *s, t_cone *cone, double k);

/*
** shadow_simple_inters.c
*/
int		shadow_simple_inters(t_rt *s, t_acc *vct, t_acc *eye, double k[2]);

/*
** specular_light.c
*/
double		specular_light(t_rt *s, t_acc *vision);

/*
** TOOLS
*/
void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 t_color *color);
void		fill_pxlarray(t_bunny_pixelarray *pxar,
			     unsigned int color);

/*
** update_hit_list.c
*/
int		update_hit_list(t_rt *s, void *shape, int type, double k);

#endif /* !RAYTRACER_H_ */
