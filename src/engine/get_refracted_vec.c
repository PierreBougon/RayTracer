/*
** get_refracted_vec.c for RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr 19 18:49:28 2016 romain samuel
** Last update Sun May 22 17:45:27 2016 benjamin duhieu
*/

#include "raytracer.h"

int		get_fresnel_coefs(t_fresnel *f)
{
  double	r;

  if (f->sin_theta2 > 0.99999)
    {
      f->reflectance = 1;
      f->cos_theta2 = 0;
    }
  else
    {
      r = pow((f->n2 - 1.0), 2) / pow((f->n2 + 1.0), 2);
      f->reflectance = r + (1.0 - r) * pow((1.0 - f->cos_theta1), 5);
      f->transmittance = 1.0 - f->reflectance;
    }
  return (0);
}

int		refraction(t_fresnel *f, t_acc *nnorm, t_acc *nvct)
{
  f->cos_theta2 = sqrt(1 - f->sin_theta2 * f->sin_theta2);
  f->refraction_vct.x = ((f->n1 / f->n2) * nvct->x)
    + ((f->n1 / f->n2) * f->cos_theta1 - f->cos_theta2) * nnorm->x;
  f->refraction_vct.y = ((f->n1 / f->n2) * nvct->y)
    + ((f->n1 / f->n2) * f->cos_theta1 - f->cos_theta2) * nnorm->y;
  f->refraction_vct.z = ((f->n1 / f->n2) * nvct->z)
    + ((f->n1 / f->n2) * f->cos_theta1 - f->cos_theta2) * nnorm->z;
  return (0);
}

int		reflection(t_fresnel *f, t_acc *nnorm, t_acc *nvct)
{
  f->reflection_vct.x = 2 * f->cos_theta1 * nnorm->x + nvct->x;
  f->reflection_vct.y = 2 * f->cos_theta1 * nnorm->y + nvct->y;
  f->reflection_vct.z = 2 * f->cos_theta1 * nnorm->z + nvct->z;
  return (0);
}

t_fresnel	get_refracted_vec(t_rt *s, t_acc *norm,
				  double n1, double n2)
{
  t_acc		nvct;
  double	len;
  t_acc		nnorm;
  t_fresnel	f;

  len = sqrt(pow(s->ray.vct->x, 2) + pow(s->ray.vct->y, 2)
	     + pow(s->ray.vct->z, 2));
  nvct.x = s->ray.vct->x / len;
  nvct.y = s->ray.vct->y / len;
  nvct.z = s->ray.vct->z / len;
  len = sqrt(pow(norm->x, 2) + pow(norm->y, 2) + pow(norm->z, 2));
  nnorm.x = norm->x / len;
  nnorm.y = norm->y / len;
  nnorm.z = norm->z / len;
  f.cos_theta1 = - ((nnorm.x * nvct.x) + (nnorm.y * nvct.y)
		  + (nnorm.z * nvct.z));
  f.sin_theta1 = sqrt(1 - f.cos_theta1 * f.cos_theta1);
  f.sin_theta2 = (n1 / n2) * f.sin_theta1;
  f.n1 = n1;
  f.n2 = n2;
  get_fresnel_coefs(&f);
  reflection(&f, &nnorm, &nvct);
  refraction(&f, &nnorm, &nvct);
  return (f);
}
