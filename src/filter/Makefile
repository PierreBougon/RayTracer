##
## Makefile for RT in /home/bougon_p/rendu/gfx_raytracer2
##
## Made by bougon_p
## Login   <bougon_p@epitech.net>
##
## Started on  Wed Apr 20 17:06:08 2016 bougon_p
## Last update Thu May 19 23:32:36 2016 marc brout
##

# USEFUL VARIABLES

RM		=	rm -rf

GREEN		=	\033[1;32m

WHITE		=	\033[0m

ECHO		=	echo -e

DEBUG		=	no

OPTI		=	no

# RT VARIABLES

SRC		=	boxfiltering.c \

OBJS    	=	$(SRC:.c=.o)


# LIBRARY VARIABLES

LIBBUNNY     =		-L/home/${USER}/.froot/lib/ -llapin \
	                -L/usr/local/lib \
			-lsfml-audio \
	                -lsfml-graphics \
			-lsfml-window \
			-lsfml-system \
			-lstdc++ -ldl \
			-lm

# PROJECT VARIABLES

NAME	=	glass

IFLAG	=	-I../../include/

CFLAGS  =	-W -Wall -Wextra #-D LAPIN_ALLOCATOR_OVERLOAD

ifeq ($(DEBUG),yes)
CFLAGS	+=	-g  #-D LAPIN_ALLOCATOR_DEACTIVATED
endif

ifeq ($(OPTI),yes)
CFLAGS	+=	-O2
endif

CC      =	gcc $(CFLAGS) $(IFLAG) -g


# PROJECT RULES

$(NAME)		: 	$(OBJS)
			@$(ECHO) "$(GREEN)\n\n> Linking \"$(NAME)\" with : \n\
$(CC)\n\n>>>>>>>>>>\t DONE\n$(WHITE)"
			@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) $(LIBBUNNY)


all		:	$(NAME)
			@make -j 4 -s compile

clean		:
			@$(RM) $(OBJS)
			@$(ECHO) "$(GREEN)\n> Cleaning repository\t\
 >>>>>>>>>> \t DONE\n$(WHITE)"

fclean		: 	clean
			@$(RM) $(NAME)
			@$(ECHO) "$(GREEN)\n> Cleaning exec\t\t\
 >>>>>>>>>> \t DONE\n$(WHITE)"

re		:	fclean all

.c.o		:
			@$(CC) -c $< -o $@
			@$(ECHO) "$(GREEN)[OK] > $<\t \t $(WHITE)"

.PHONY		:	compile all clean fclean re
