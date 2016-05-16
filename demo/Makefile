##
## Makefile for wolf3d in /home/brout_m/rendu/projet/Infographie/gfx_wolf3d
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Thu Dec 17 13:59:43 2015 marc brout
## Last update Mon May 16 13:52:57 2016 marc brout
##

SRC     = bmploader.c

SRCS	= savebmp.c \
	my_bzero.c \

OBJS    = $(SRC:.c=.o)

OBJSS	= $(SRCS:.c=.o)

NAME    = bmpload

SAVE	= savebmp

CC      = gcc -g

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

$(NAME): $(SAVE) $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

$(SAVE): $(OBJSS)
	@$(CC) -o $(SAVE) $(OBJSS) $(LDFLAGS)

all: $(NAME)

clean:
	@$(RM) $(OBJSS)
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(SAVE)
	@$(RM) $(NAME)

re: fclean all
