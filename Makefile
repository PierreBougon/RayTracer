##
## Makefile for BLIT in /home/bougon_p/rendu/gfx_raytracer2
## 
## Made by bougon_p
## Login   <bougon_p@epitech.net>
## 
## Started on  Wed Apr 20 17:06:08 2016 bougon_p
## Last update Fri Apr 29 02:03:50 2016 bougon_p
##

# USEFUL VARIABLES

RM      =	rm -rf

GREEN	=	\033[1;32m

WHITE	=	\033[0m

ECHO	=	echo -e

DEBUG	=	yes

# RT VARIABLES

MAIN		=	src/main/

ENGINE		=	src/engine/

LIVE_ENGINE	=	src/live_engine/

ITFC		=	src/interface/

CONTEXT		=	context/

SRC		=	$(MAIN)main.c \
			$(MAIN)init_main.c \
			$(MAIN)free.c \
			$(MAIN)setnbr.c \
			$(MAIN)delete_clipables.c \
			$(MAIN)blit_clipables.c \
			$(MAIN)tekpixel.c \
			$(MAIN)fill_pxlarray.c \
			$(ENGINE)antialiasing.c \
			$(ENGINE)translation.c \
			$(ENGINE)clear_list.c \
			$(ENGINE)color_operations.c \
			$(ENGINE)create_obj_list.c \
			$(ENGINE)diffuse_light.c \
			$(ENGINE)display.c \
			$(ENGINE)display_objects.c \
			$(ENGINE)get_norm.c \
			$(ENGINE)get_simple_coords.c \
			$(ENGINE)init_shade.c \
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
			$(ENGINE)update_hit_list.c \
			$(ENGINE)update_real_hit_list.c \
			$(LIVE_ENGINE)display.c \
			$(LIVE_ENGINE)live_shade.c \
			$(ITFC)init_itfc.c \
			$(ITFC)init_ftabs.c \
			$(ITFC)interface.c \
			$(ITFC)zoom.c \
			$(ITFC)text.c \
			$(ITFC)open_file.c \
			$(ITFC)check_buttons.c \
			$(ITFC)check_menu_buttons.c \
			$(ITFC)check_file_buttons.c \
			$(ITFC)check_bt_activated.c \
			$(ITFC)set_bt_false.c \
			$(ITFC)buttons.c \
			$(ITFC)rendering.c \
			$(ITFC)mouse_state.c \
			$(ITFC)move_state.c \
			$(ITFC)rotate_state.c \
			$(ITFC)move_eye.c \
			$(ITFC)rotate_eye.c \
			$(ITFC)$(CONTEXT)add_plane.c \
			$(ITFC)$(CONTEXT)add_sphere.c \
			$(ITFC)$(CONTEXT)add_cone.c \
			$(ITFC)$(CONTEXT)add_cylinder.c \
			$(ITFC)$(CONTEXT)add_cube.c \
			$(ITFC)$(CONTEXT)add_torus.c \
			$(ITFC)$(CONTEXT)add_perf_cube.c \
			$(ITFC)$(CONTEXT)save_bt.c \
			$(ITFC)$(CONTEXT)save.c \
			$(ITFC)$(CONTEXT)save_ini.c \
			$(ITFC)$(CONTEXT)save_ini_obj.c \
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

CFLAGS  =	-W -Wall -Wextra #-D LAPIN_ALLOCATOR_OVERLOAD

ifeq ($(DEBUG),yes)
CFLAGS	+=	-g
endif

CC      =	gcc $(CFLAGS) $(IFLAG)


# PROJECT RULES

$(NAME)		: 	$(LIB) $(OBJS)
			@$(ECHO) "$(GREEN)\n\n> Linking \"$(NAME)\" with : \n\
$(CC)\n\n>>>>>>>>>>\t DONE\n$(WHITE)"
			@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) $(LIB) $(LIBBUNNY)

$(LIB)		:	$(OBJSLIB)
			@ar rc $(LIB) $(OBJSLIB)
			@ranlib $(LIB)
			@$(ECHO) "$(GREEN)\n> Compiling Library\t\
 >>>>>>>>>> \t DONE\n$(WHITE)"

compile		:	$(OBJS)
			@$(ECHO) "$(GREEN)\n\n> Linking \"$(NAME)\" with : \n\
$(CC)\n\n>>>>>>>>>>\t DONE\n$(WHITE)"
			@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) $(LIB) $(LIBBUNNY)

all		:	$(LIB)
			@make -j 4 -s compile

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

.PHONY		:	comp all clean fclean re
