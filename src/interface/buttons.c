/*
** buttons.c for buttons in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr 15 22:00:12 2016 bougon_p
** Last update Sun May 22 21:24:31 2016 benjamin duhieu
*/

#include <unistd.h>
#include "raytracer.h"

int	render(t_data *data)
{
  if (!data->itfc.rendering && !data->itfc.rendered && data->rt.img)
    {
      data->itfc.rendering = true;
      data->rt.live = false;
      if (start_rendering(data) == 1)
	return (1);
    }
  return (0);
}

int	live(t_data *data)
{
  data->rt.live = true;
  data->itfc.rendered = false;
  data->itfc.rendering = false;
  data->ld.loading->clipable.clip_width = 0;
  return (0);
}

int	open_file(UNUSED t_data *data)
{
  return (0);
}

int	help(t_data *data)
{
  pid_t	cpid;
  char	*url[3];

  url[0] = "firefox";
  url[1] = "http://raytracer.strikingly.com/";
  url[1] = "http://raytracer.strikingly.com/";
  url[2] = NULL;
  cpid = fork();
  if (cpid == 0)
    {
      if (execve("/usr/bin/firefox", url, data->itfc.env) == -1)
      	{
	  url[0] = "chromium";
	  if (execve("/usr/bin/chromium-browser", url, data->itfc.env)
	      == -1)
	    {
	      my_puterr("Could not open firefox nor chormium.");
	      exit (1);
	    }
	}
    }
  return (0);
}
