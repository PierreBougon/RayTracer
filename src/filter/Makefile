##
## Makefile for wolf3d in /home/brout_m/rendu/projet/Infographie/gfx_wolf3d
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Thu Dec 17 13:59:43 2015 marc brout
## Last update Tue May 17 16:45:18 2016 marc brout
##

SRC     = sobel_filter.c

OIL	= oil_effect.c

OBJS    = $(SRC:.c=.o)

OBJO	= $(OIL:.c=.o)

NAME    = sobel

OILN	= oil

CC      = gcc -g -O2 -I../../include

CFLAGS  = -W -Wall -Werror -ansi -pedantic

CFLAGS	+= -I/home/${USER}/.froot/include

LDFLAGS = -L/home/${USER}/.froot/lib \
	-llapin \
	-lsfml-audio \
	-lsfml-graphics \
	-lsfml-window \
	-lsfml-system \
	-lstdc++ -ldl \
	-lm \
	-L./lib/ \

RM      = rm -f

.c.o:
	$(CC) -c $< -o $@ $(CFLAGS)

$(NAME): $(OILN) $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

$(OILN): $(OBJO)
	@$(CC) -o $(OILN) $(OBJO) $(LDFLAGS)

all: $(NAME)

clean:
	@$(RM) $(OBJO)
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(OILN)
	@$(RM) $(NAME)

re: fclean all
