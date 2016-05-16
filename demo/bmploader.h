/*
** bmploader.h for loader
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Tue Jan 19 19:51:38 2016 marc brout
** Last update Mon May 16 13:44:35 2016 marc brout
*/

#ifndef BMPLOADER_H_
# define BMPLOADER_H_
# define UNUSED __attribute__((__unused__))

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "lapin.h"

typedef struct		s_head
{
  unsigned short	head;
  unsigned 		size;
  unsigned short 	app;
  unsigned short 	resapp;
  unsigned 		offset;
}			__attribute__((__packed__)) t_head;

typedef struct		s_bmp
{
  unsigned int		headsize;
  int			width;
  int			height;
  unsigned short int	plane;
  unsigned short int	type;
  unsigned int		compression;
  unsigned int		imgsize;
  int			hrez;
  int			vrez;
  unsigned int		nbcol;
  unsigned int		impcol;
}			__attribute__((__packed__)) t_bmp;

typedef struct		s_loop
{
  t_bunny_pixelarray	*pix;
  t_bunny_window	*win;
}			t_loop;

typedef struct		t_col
{
  unsigned char		a;
  unsigned char		r;
  unsigned char		b;
  unsigned char		alpha;
}			t_col;

void			my_bzero(void *ptr, const int size,
				 const char value);

#endif /* !BMPLOADER_H_ */
