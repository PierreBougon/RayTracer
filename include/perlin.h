/*
** perlin.h for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Wed Apr 27 18:33:51 2016 romain samuel
** Last update Wed Apr 27 18:35:22 2016 romain samuel
*/

#ifndef PERLIN_H_
# define PERLIN_H_

# define B 0x100
# define BM 0xff
# define N 0x1000
# define NP 12   /* 2^N */
# define NM 0xfff
# define s_curve(t) ( t * t * (3. - 2. * t) )
# define lerp(t, a, b) ( a + t * (b - a) )
# define setup(i,b0,b1,r0,r1)\
        t = vec[i] + N;\
        b0 = ((int)t) & BM;\
        b1 = (b0+1) & BM;\
        r0 = t - (int)t;\
        r1 = r0 - 1.;
# define at2(rx,ry) ( rx * q[0] + ry * q[1] )
# define at3(rx,ry,rz) ( rx * q[0] + ry * q[1] + rz * q[2] )

void init(void);
double noise1(double);
double noise2(double *);
double noise3(double *);
void normalize3(double *);
void normalize2(double *);

double PerlinNoise1D(double,double,double,int);
double PerlinNoise2D(double,double,double,double,int);
double PerlinNoise3D(double,double,double,double,double,int);

#endif /* !PERLIN_H_ */
