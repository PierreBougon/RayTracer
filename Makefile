##
## Makefile for RAYTRACER in /home/bougon_p/rendu/gfx_raytracer2
##
## Made by bougon_p
## Login   <bougon_p@epitech.net>
##
## Started on  Wed Apr 13 20:06:22 2016 bougon_p
## Last update Mon Apr 18 20:25:43 2016 bougon_p
##

# USEFUL VARIABLES

RM      =	rm -rf

GREEN	=	\033[1;32m

WHITE	=	\033[0m

ECHO	=	echo -e

# RT VARIABLES

MAIN		=	src/main/

ENGINE		=	src/engine/

ITFC		=	src/interface/

CONTEXT		=	context/

SRC		=	$(MAIN)main.c \
			$(MAIN)init_main.c \
			$(MAIN)delete_clipables.c \
			$(MAIN)blit_clipables.c \
			$(MAIN)fill_pxlarray.c \
			$(ENGINE)antialiasing.c \
			$(ENGINE)clear_list.c \
			$(ENGINE)create_obj_list.c \
			$(ENGINE)diffuse_light.c \
			$(ENGINE)display.c \
			$(ENGINE)display_objects.c \
			$(ENGINE)get_norm.c \
			$(ENGINE)get_simple_coords.c \
			$(ENGINE)inters.c \
			$(ENGINE)limited_objects.c \
			$(ENGINE)load_cone.c \
			$(ENGINE)load_cylinder.c \
			$(ENGINE)load_file.c \
			$(ENGINE)load_light.c \
			$(ENGINE)load_plan.c \
			$(ENGINE)load_sphere.c \
			$(ENGINE)order_hit_list.c \
			$(ENGINE)rotations.c \
			$(ENGINE)set_hit_values.c \
			$(ENGINE)shade.c \
			$(ENGINE)shadow.c \
			$(ENGINE)shadow_inters.c \
			$(ENGINE)shadow_limited_objects.c \
			$(ENGINE)shadow_simple_inters.c \
			$(ENGINE)specular_light.c \
			$(ENGINE)tekpixel.c \
			$(ENGINE)update_hit_list.c \
			$(ITFC)interface.c \
			$(ITFC)init_itfc.c \
			$(ITFC)check_buttons.c \
			$(ITFC)check_menu_buttons.c \
			$(ITFC)check_bt_activated.c \
			$(ITFC)buttons.c \
			$(ITFC)rendering.c \
			$(ITFC)mouse_state.c \
			$(ITFC)move_state.c \
			$(ITFC)rotate_state.c \
			$(ITFC)move_eye.c \
			$(ITFC)rotate_eye.c \
			$(ITFC)$(CONTEXT)save.c \
			$(ITFC)$(CONTEXT)modif_form.c \
			$(ITFC)$(CONTEXT)add_form.c \
			$(ITFC)$(CONTEXT)sub_form.c \
			$(ITFC)$(CONTEXT)spotlight.c \
			$(ITFC)$(CONTEXT)context_gen.c \
			src/debug.c \

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

LIBPATH =       lib/

LIB	=	lib/libmy.a

SRCLIB	=	$(LIBPATH)my/get_next_line.c \
		$(LIBPATH)my/my_getnbr.c \
		$(LIBPATH)my/my_power_rec.c \
		$(LIBPATH)my/my_printf.c \
		$(LIBPATH)my/my_printfcsspb.c \
		$(LIBPATH)my/my_printfdiouxx.c \
		$(LIBPATH)my/my_printfmetc.c \
		$(LIBPATH)my/my_putchar.c \
		$(LIBPATH)my/my_put_nbr.c \
		$(LIBPATH)my/my_putstr.c \
		$(LIBPATH)my/my_revstr.c \
		$(LIBPATH)my/my_strcmp.c \
		$(LIBPATH)my/my_strdup.c \
		$(LIBPATH)my/my_strlen.c \
		$(LIBPATH)my/my_strncmp.c \
		$(LIBPATH)my/my_puterr.c \
		$(LIBPATH)my/my_strcpy.c \
		$(LIBPATH)my/my_strcat.c \
		$(LIBPATH)my/my_bzero.c \
		$(LIBPATH)my/my_realloc.c \
		$(LIBPATH)my/my_alpha_num.c \
		$(LIBPATH)my/my_getcolor.c \
		$(LIBPATH)my/my_puterr.c \


LDFLAGS =       -lmy -L$(LIBPATH)

OBJSLIB	=	$(SRCLIB:.c=.o)


# PROJECT VARIABLES

NAME	=	raytracer

IFLAG	=	-Iinclude/

CFLAGS  =	-W -Wall -Wextra -g

CC      =	gcc $(CFLAGS) $(IFLAG)


# PROJECT RULES

$(NAME)		: 	$(LIB) $(OBJS)
			@$(ECHO) "$(GREEN)\n\n> Linking \"$(NAME)\"with : \n\
$(CC)\n\n>>>>>>>>>>\t DONE\n$(WHITE)"
			@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) $(LIB) $(LIBBUNNY)

$(LIB)		:	$(OBJSLIB)
			@ar rc $(LIB) $(OBJSLIB)
			@ranlib $(LIB)
			@$(ECHO) "$(GREEN)\n> Compiling Library\t\
 >>>>>>>>>> \t DONE\n$(WHITE)"


all		:	$(NAME)

clean		:
			@$(RM) $(OBJS)
			@$(RM) $(OBJSLIB)
			@$(ECHO) "$(GREEN)\n> Cleaning repository\t\
 >>>>>>>>>> \t DONE\n$(WHITE)"

fclean		: 	clean
			@$(RM) $(NAME)
			@$(RM) $(LIB)
			@$(ECHO) "$(GREEN)\n> Cleaning exec\t\t\
 >>>>>>>>>> \t DONE\n$(WHITE)"

re		:	fclean all

.c.o		:
			@$(CC) -c $< -o $@
			@$(ECHO) "$(GREEN)[OK] > $<\t \t $(WHITE)"
