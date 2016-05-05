/*
** raytracer.h for raytracer in /home/samuel_r/EPITECH/GFX
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Fri Apr  1 19:50:30 2016 romain samuel
** Last update Wed May  4 23:15:24 2016 bougon_p
*/

#ifndef RAYTRACER_H_
# define RAYTRACER_H_

/*
** DEBUG
*/
# include <stdio.h>

/*
** MACROES
*/
# define CARRE(val) ((val) * (val))
# define RAD(val) (((val) * M_PI) / 180)
# define DEG(val) (((val) * 180) / M_PI)

/*
** WINDOW DEFINES
*/
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define INIT_WIDTH 720
# define INIT_HEIGHT 720
# define FULL_WIDTH 1450
# define FULL_HEIGHT 920

/*
** COLOR DEFINES
*/
# define NULL_COLOR 0x00000000
# define BLUE_LOAD 0xFF5C5540
# define OBJ_COLOR 0xFFFFF020

/*
** TEXTURE DEFINES
*/
# define FULL 1
# define STRIPES 2
# define CHECKBOARD_2D 3
# define PLANAR_CHECKBOARD 4
# define CHECKBOARD_3D 5
# define PERLIN_NOISE 6
# define MARBLE_NOISE 7
# define IMAGE 8

# define NB_OBJ 5

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
# include "live_engine.h"

typedef enum	e_obj
  {
    LIGHT	= 1,
    SPHERE	= 2,
    CYLINDER	= 3,
    CONE	= 4,
    PLANE	= 5
  }		t_obj;

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

typedef struct		s_fresnel
{
  double		cos_theta1;
  double		cos_theta2;
  double		sin_theta1;
  double		sin_theta2;
  double		reflectance_ortho;
  double		reflectance_paral;
  double		reflectance;
  double		transmittance;
  double		n1;
  double		n2;
  t_acc			reflection_vct;
  t_acc			refraction_vct;
}			t_fresnel;

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
  double		refraction;
  t_color		color1;
  t_color		color2;
  t_bunny_pixelarray	*texture;
  double		k1;
  double		k2;
  t_acc			simple_inter2;
  t_acc			simple_inter1;
  t_acc			norm;
  t_fresnel		fresnel;
  double		n1;
  double		n2;
}			t_plan;

typedef struct		s_2order
{
  double		a;
  double		b;
  double		c;
  double		delta;
  double		root1;
  double		root2;
}			t_2order;

typedef struct		s_hyper
{
  t_pos			pos;
  t_pos			rot;
  int			a;
  int			b;
  int			c;
  t_color		color;
  t_bunny_pixelarray	*texture;
}			t_hyper;

typedef struct		s_parab
{
  t_pos			pos;
  t_pos			rot;
  int			a;
  int			b;
  t_color		color;
  t_bunny_pixelarray	*texture;
}			t_parab;

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
  double		refraction;
  t_color		color1;
  t_color		color2;
  t_bunny_pixelarray	*texture;
  double		k1;
  double		k2;
  t_acc			simple_inter2;
  t_acc			simple_inter1;
  t_acc			norm;
  t_fresnel		fresnel;
  double		n1;
  double		n2;
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
  double		refraction;
  t_color		color1;
  t_color		color2;
  t_bunny_pixelarray	*texture1;
  t_bunny_pixelarray	*texture2;
  double		k1;
  double		k2;
  t_acc			simple_inter2;
  t_acc			simple_inter1;
  t_acc			norm;
  int			limited;
  t_fresnel		fresnel;
  double		n1;
  double		n2;
}			t_cone;

typedef struct		s_box
{
  t_pos			pos;
  t_pos			rot;
  int			real;
  int			tex_type;
  t_pos			size;
  double		ka;
  double		kd;
  double		ks;
  double		brightness;
  double		reflection;
  double		opacity;
  double		refraction;
  t_color		color1;
  t_color		color2;
  t_bunny_pixelarray	*texture;
  double		k1;
  double		k2;
  t_acc			simple_inter2;
  t_acc			simple_inter1;
  t_acc			norm;
  int			limited;
  t_fresnel		fresnel;
  double		n1;
  double		n2;
}			t_box;

typedef	struct		s_solv
{
  double		a;
  double		b;
  double		c;
  double		d;
  double		e;
}			t_solv;

typedef	struct		s_int_tore
{
  double		k1;
  double		k2;
  double		k3;
  double		k4;
}			t_int_tore;

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
  double		refraction;
  t_color		color1;
  t_color		color2;
  t_bunny_pixelarray	*texture1;
  t_bunny_pixelarray	*texture2;
  double		k1;
  double		k2;
  t_acc			simple_inter2;
  t_acc			simple_inter1;
  t_acc			norm;
  int			limited;
  t_fresnel		fresnel;
  double		n1;
  double		n2;
}			t_cylinder;

typedef struct		s_tore
{
  t_pos			pos;
  t_pos			rot;
  int			rad;
  int			dist;
  t_color		color;
  t_bunny_pixelarray	*texture;
}			t_tore;

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
  int			real;
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
  double		ambient_refraction;
  int			aa;
  int			skybox;
  t_bunny_pixelarray	*skybox_right;
  t_bunny_pixelarray	*skybox_left;
  t_bunny_pixelarray	*skybox_up;
  t_bunny_pixelarray	*skybox_down;
  t_bunny_pixelarray	*skybox_forward;
  t_bunny_pixelarray	*skybox_backward;
  int			ss;
  int			nb_rays_ss;
  int			ray_ss;
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
  double		reflection;
  t_fresnel		fresnel;
  double		n1;
  double		n2;
  double		opacity;
  int			tex_type;
  t_bunny_pixelarray	*texture1;
  t_bunny_pixelarray	*texture2;
  t_acc			texels;
  t_color		color1;
  t_color		color2;
}			t_hit;

typedef struct		s_shadow
{
  t_acc			simple_inter1;
  t_acc			simple_inter2;
  double		coef;
}			t_shadow;

typedef struct		s_noise
{
  int			p[512];
}			t_noise;

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
  double		*itab;
}			t_shade;

typedef struct		s_ftab
{
  int			(**inters_ftab)(t_rt *, t_object *);
  int			(**shadow_ftab)(t_rt *, t_object *);
  void			(**hit_ftab)(t_rt *, t_object *);
  void			(**tex_ftab)(t_rt *);
}			t_ftab;

typedef struct		s_rotation
{
  double		cos[360];
  double		sin[360];
  double		rotx[3][3];
  double		roty[3][3];
  double		rotz[3][3];
}			t_rotation;

typedef struct		s_rt
{
  t_bunny_pixelarray	*img;
  t_bunny_position	r_pos;
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
  t_rotation		rotation;
  int			width;
  int			height;
  bool			live;
  int			rec;
  float			coef_load;
  int			nb_coef;
  t_bunny_position	pos;
}			t_rt;

typedef	struct		s_loading
{
  t_bunny_position	pos;
  t_bunny_pixelarray	*loading;
  int			curr_line;
  int			nb_coef;
  float			coef_load;
  int			save_width;
}			t_loading;

typedef struct		s_data
{
  t_rt			rt;
  t_itfc		itfc;
  t_bunny_window	*win;
  t_bunny_event_state	mstate;
  t_bunny_mousebutton	mbutton;
  bool			wait_click;
  bool			click_action;
  t_loading		ld;
}			t_data;

/*
** Init
*/
int			init_main_data(t_data *);
int			init_rt_data(t_rt *, int, char **);
int			init_itfc_data(t_itfc *, t_data *);
int			init_engine_ftabs(t_ftab *ftabs);
t_bunny_position	center_rt(t_rt *);
char			*setnbr(int);
char			*setunsnbr(unsigned int);
char			*put_base(unsigned int, char *);

/*
** Blit
*/
void	blit_clipables(t_data *);

/*
** Free
*/
void	free_all(t_data *);
void	free_tab(char **);
void	delete_all_clipables(t_data *);

/*
** Translation
*/
void	translation(t_rotation *r, t_acc *vec, t_pos *rot, t_acc *pos);
void	translation_obj(t_rotation *r, t_acc *vec, t_pos *rot, t_pos *pos);

/*
** antialiasing.c
*/
t_color		melt_colors(t_rt *s, t_color *color);
t_color		antialiasing(t_rt *s,
			     t_bunny_position *pos,
			     t_acc *vct,
			     t_color *color);

/*
** checkerboards.c
*/
void		stripes(t_rt *s);
void		checkerboard_2d(t_rt *s);
void		planar_checkerboard(t_rt *s);
void		checkerboard_3d(t_rt *s);

/*
** clear_list.c
*/
int		clear_list(t_object *root);

/*
** color_operations.c
*/
t_color		compute_colors(t_color color1,
			       t_color color2,
			       double coef);
t_color		add_light_color(t_color color,
				t_color second_color);
t_color		apply_b(t_color color,
			t_color light_color,
			double brightness,
			double i);

/*
** create_obj_list.c
*/
t_object	*create_obj_list();
int		add_obj_elem(t_object *root);
t_object	*add_obj_elem_ret(t_object *root);

/*
** diffuse_light.c
*/
double		second_norm_brightness(t_rt *s);
double		diffuse_light(t_rt *s, t_object *it);

/*
** display.c
*/
int		inter_objects(t_rt *s);
t_color		display_objects(t_rt *s, t_acc *vct, t_acc eye);
int		display(t_rt *s, t_data *data);

/*
** display_objects.c
*/
int		display_sphere(t_rt *s, t_object *obj);
int		display_cylinder(t_rt *s, t_object *obj);
int		display_cone(t_rt *s, t_object *obj);
int		display_plan(t_rt *s, t_object *obj);
int		display_box(t_rt *s, t_object *obj);

/*
** get_norm.c
*/
void		get_norm_plan(t_rt *s, t_plan *plan);
void		get_norm_sphere(t_rt *s);
void		get_norm_cylinder(t_rt *s, t_cylinder *cylinder);
void		get_norm_cone(t_rt *s, t_cone *cone);

/*
** get_refracted_vec.c
*/
t_fresnel	get_refracted_vec(t_rt *s, t_acc *norm, double n1, double n2);

/*
** get_simple_inters.c
*/
int		get_simple_inter(t_rt *s, t_acc *vct, t_acc *eye);

/*
** get_texels.c
*/
void		get_texels_plan(t_rt *s, t_plan *plan);
void		get_texels_sphere(t_rt *s, t_sphere *sphere);
void		get_texels_cyl_plan(t_rt *s, t_cylinder *cylinder);
void		get_texels_cylinder(t_rt *s, t_cylinder *cylinder);

/*
** init_shade.c
*/
int		init_soft_shadow(t_rt *s);
void		init_itab(double itab[1]);
void		init_lum(t_rt *s, t_acc *vct, t_acc eye, t_light *light);

/*
** inter_box_sides.c
*/
int		init_vecs(t_rt *s, t_box *box, t_acc vec[6]);
int		inter_box_sides(t_rt *s, t_box *box);

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
** limited_plan.c
*/
int		limited_plan(t_rt *s, t_plan *plan);

/*
** load_box.c
*/
int		load_box_datas(t_box *s, t_bunny_ini *ini, char *scope);
int		load_box_datas2(t_box *s, t_bunny_ini *ini, char *scope);
int		load_box_datas3(t_box *s, t_bunny_ini *ini, char *scope);
int		load_box_datas4(t_box *s, t_bunny_ini *ini, char *scope);
int		load_box(t_rt *rt, t_bunny_ini *ini, char *scope);

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
int		load_plan_datas4(t_plan *s, t_bunny_ini *ini, char *scope);
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
** noise_textures.c
*/
void		smooth_noise(t_rt *s);
void		marble_noise(t_rt *s);

/*
** matrices.c
*/
void		init_cos_sin(t_rotation *rot);
void		init_matrices(t_rotation *rot);
void		set_rotx(t_rotation *rot, int teta);
void		set_roty(t_rotation *rot, int teta);
void		set_rotz(t_rotation *rot, int teta);

/*
** order_hit_list.c
*/
int		swap_objs(t_object *it, t_object *it_prev);
int		order_list(t_object *root);
int		order_hit_list(t_object *root);

/*
** rotations.c
*/
t_acc		*rotate_x(t_rotation *r, t_acc *vct, int angle);
t_acc		*rotate_y(t_rotation *r, t_acc *vct, int angle);
t_acc		*rotate_z(t_rotation *r, t_acc *vct, int angle);
t_acc		*rotation(t_rotation *r, t_acc *vct, t_pos *rot);
t_acc		*end_rotation(t_rotation *r, t_acc *vct, t_pos *rot);

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
double		apply_light(t_rt *s, t_light *light, t_color *light_color);
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
double		shadow_simple_inters(t_rt *s, t_acc *vct, t_acc *eye, double k[2]);

/*
** skybox.c
*/
void		skybox_x(t_rt *s, t_acc *vct);
void		skybox_y(t_rt *s, t_acc *vct);
void		skybox_z(t_rt *s, t_acc *vct);
int		skybox(t_rt *s, t_acc *vct);

/*
** specular_light.c
*/
double		specular_light(t_rt *s, t_acc *vision);

/*
** texturize_obj.c
*/
void		full_color(t_rt *s);
void		get_image_texel(t_rt *s);
int		texturize_obj(t_rt *s);

/*
** TOOLS
*/
void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 t_color *color);
void		mult_tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 t_color *color);
void		fill_pxlarray(t_bunny_pixelarray *pxar,
			     unsigned int color);
int		fill_next_lines(t_bunny_pixelarray *pxar,
				unsigned int color,
				int line, int nb_line);

/*
** update_hit_list.c
*/
int		update_hit_list(t_rt *s, void *shape, int type, double k);

/*
** update_real_hit_list.c
*/
int		update_real_hit_list(t_rt *s);
int		delete_false_hit_objects(t_rt *s);

#endif /* !RAYTRACER_H_ */
