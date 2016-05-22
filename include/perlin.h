/*
** perlin.h for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Wed Apr 27 18:33:51 2016 romain samuel
** Last update Sun May 22 16:33:15 2016 marc brout
*/

#ifndef PERLIN_H_
# define PERLIN_H_

# define B 0x100
# define BM 0xff
# define N 0x1000
# define NP 12
# define NM 0xfff
# define s_curve(t) (t * t * (3. - 2. * t))
# define lerp(t, a, b) (a + t * (b - a))
# define at2(rx, ry) (rx * q[0] + ry * q[1])
# define at3(rx, ry, rz, q) (rx * q[0] + ry * q[1] + rz * q[2])

typedef struct	s_noise_3d
{
  int		i;
  int		j;
  int		bx0;
  int		bx1;
  int		by0;
  int		by1;
  int		bz0;
  int		bz1;
  int		b00;
  int		b10;
  int		b01;
  int		b11;
  float		rx0;
  float		rx1;
  float		ry0;
  float		ry1;
  float		rz0;
  float		rz1;
  float		sy;
  float		sz;
  float		a;
  float		b;
  float		c;
  float		d;
  float		t;
  float		u;
  float		v;
  double	*q;
  int		p[B + B + 2];
}		t_noise_3d;

/*
** init_noise.c
*/
void		normalize_2d(double v[2]);
void		normalize_3d(double v[3]);
void		init_gradients(int i, int j);
void		init();

/*
** noise.c
*/
double		noise_end(t_noise_3d noise);
double		noise_3d(double vec[3]);

/*
** perlin_noise.c
*/
double		perlin_noise_3d(double p[3], double alpha, double beta, int n);

/*
** setup_noise.c
*/
void		setup_r(double vec[3], int i, float *r0, float *r1);
void		setup_b(double vec[3], int i, int *b0, int *b1);

#endif /* !PERLIN_H_ */
