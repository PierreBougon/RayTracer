/*
** perlin_noise.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Sun Apr 24 11:58:33 2016 romain samuel
** Last update Wed Apr 27 18:29:22 2016 romain samuel
*/

#include "raytracer.h"

unsigned char perm[512] = {
  151,160,137,91,90,15,131,13,201,95,96,53,194,233,7,225,140,
  36,103,30,69,142,8,99,37,240,21,10,23,190,6,148,247,120,234,
  75,0,26,197,62,94,252,219,203,117,35,11,32,57,177,33,88,237,
  149,56,87,174,20,125,136,171,168,68,175,74,165,71,134,139,
  48,27,166,77,146,158,231,83,111,229,122,60,211,133,230,220,
  105,92,41,55,46,245,40,244,102,143,54,65,25,63,161,1,216,80,
  73,209,76,132,187,208,89,18,169,200,196,135,130,116,188,159,
  86,164,100,109,198,173,186,3,64,52,217,226,250,124,123,5,
  202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,58,17,
  182,189,28,42,223,183,170,213,119,248,152,2,44,154,163,70,
  221,153,101,155,167,43,172,9,129,22,39,253,19,98,108,110,79,
  113,224,232,178,185,112,104,218,246,97,228,251,34,242,193,
  238,210,144,12,191,179,162,241,81,51,145,235,249,14,239,107,
  49,192,214,31,181,199,106,157,184,84,204,176,115,121,50,45,
  127,4,150,254,138,236,205,93,222,114,67,29,24,72,243,141,
  128,195,78,66,215,61,156,180, 151,160,137,91,90,15,131,13,
  201,95,96,53,194,233,7,225,140,127,4,150,254,138,236,205,93,
  222,114,67,29,24,72,243,141,128,195,78,66,215,61,156,180
};

static int grad[16][3] = {
  {1,1,0},{-1,1,0},{1,-1,0},{-1,-1,0},
  {1,0,1},{-1,0,1},{1,0,-1},{-1,0,-1},
  {0,1,1},{0,-1,1},{0,1,-1},{0,-1,-1},
  {1,1,0},{-1,1,0},{0,-1,1},{0,-1,-1}
};

double		linear_interpolate(double a, double b, double t)
{
  return ((1.0 - t) * a + t * b);
}

double		dot_product(const int *v, const double x,
			    const double y, const double z)
{
  return (v[0] * x + v[1] * y  + v[2] * z);
}

int		*get_grad(int x, int y, int z)
{
  int		rand_value;

  rand_value = perm[z + perm[y + perm[x]]];
  return (grad[rand_value & 15]);
}

double		quintic_poly(const double t)
{
  double	t3;

  t3 = t * t * t;
  return (t3 * (t * (t * 6.0 - 15.0) + 10.0));
}

void		int_and_frac(double value, int *integer_part, double *fractional_part)
{
  *integer_part = (int)value;
  if (value < 0)
    integer_part -= 1;
  *fractional_part = value - *integer_part;
}

double		perlin_noise_3d(double x_pos, double y_pos, double z_pos)
{
  int		X;
  int		Y;
  int		Z;
  double	x;
  double	y;
  double	z;
  double	g000;
  double	g001;
  double	g010;
  double	g011;
  double	g100;
  double	g101;
  double	g110;
  double	g111;
  double	u;
  double	v;
  double	w;
  double	x00;
  double	x10;
  double	x01;
  double	x11;
  double	xy0;
  double	xy1;
  double	xyz;

  if (x_pos < 0)
    x_pos *= -1;
  if (y_pos < 0)
    y_pos *= -1;
  if (z_pos < 0)
    z_pos *= -1;
  int_and_frac(x_pos, &X, &x);
  int_and_frac(y_pos, &Y, &y);
  int_and_frac(z_pos, &Z, &z);
  X &= 255;
  Y &= 255;
  Z &= 255;
  g000 = dot_product(get_grad(X, Y, Z), x, y, z);
  g001 = dot_product(get_grad(X, Y, Z + 1), x, y, z - 1.0);
  g010 = dot_product(get_grad(X, Y + 1, Z), x, y - 1.0, z);
  g011 = dot_product(get_grad(X, Y + 1, Z + 1), x, y - 1.0, z - 1.0);
  g100 = dot_product(get_grad(X + 1, Y, Z), x - 1.0, y, z);
  g101 = dot_product(get_grad(X + 1, Y, Z + 1), x - 1.0, y, z - 1.0);
  g110 = dot_product(get_grad(X + 1, Y + 1, Z), x - 1.0, y - 1.0, z);
  g111 = dot_product(get_grad(X + 1, Y + 1, Z + 1), x - 1.0, y - 1.0, z - 1.0);
  u = quintic_poly(x);
  v = quintic_poly(y);
  w = quintic_poly(z);
  x00 = linear_interpolate(g000, g100, u);
  x10 = linear_interpolate(g010, g110, u);
  x01 = linear_interpolate(g001, g101, u);
  x11 = linear_interpolate(g011, g111, u);
  xy0 = linear_interpolate(x00, x10, v);
  xy1 = linear_interpolate(x01, x11, v);
  xyz = linear_interpolate(xy0, xy1, w);
  return (xyz);
}

double		perlin(int octaves,
		       double frequency,
		       double persistence,
		       double x,
		       double y,
		       double z)
{
  double	r;
  double	f;
  double	amplitude;
  double	geo_lim;
  int		i;

  r = 0;
  f = frequency;
  amplitude = 1;
  while (i < octaves)
    {
      r += perlin_noise_3d(x * f, y * f, z * f) * amplitude;
      amplitude *= persistence;
      f *= 2;
      i++;
    }
  geo_lim = (1 - persistence) / (1 - amplitude);
  return (r * geo_lim);
}
