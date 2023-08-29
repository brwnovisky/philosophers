NAME			= philo

FILE_PATH		= ./src
OBJS_PATH		= ./obj

HEADERS			= inc/philo.h

FILES			= start_here.c \
				  how_philosophers_are_born.c \
				  philo_news_and_fallacies_refuted.c \
				  philosophers_lifestyle.c \
				  philosophical_utilities.c \
				  when_philos_leaves_this_world.c

CFLAGS			= -Wall -Wextra -Werror -g

LFLAGS			= -lpthread

CC				= gcc
RM				= rm -rf

OBJS			= $(addprefix $(OBJS_PATH)/, $(FILES:.c=.o))

all:			$(NAME)
$(NAME):		$(OBJS_PATH) $(OBJS)
				@$(CC) $(OBJS) -o $(NAME) $(LFLAGS)
				@echo "Philosophers created!!"

$(OBJS_PATH):
				@mkdir -p $(OBJS_PATH)


$(OBJS_PATH)/%.o: $(FILE_PATH)/%.c $(HEADERS)
				@$(CC) $(CFLAGS) -c $< -o $@
					
clean:
				@$(RM) $(OBJS)
				@rm -rf $(OBJS_PATH)
				@echo "clean Done!"

fclean:			clean
				@$(RM) $(NAME) $(OBJS_PATH)
				@echo "fclean Done!"

re:				fclean all

.PHONY: 		all clean fclean re

VALGRIND 		= @valgrind \
				--leak-check=full \
				--show-leak-kinds=all \
				--track-origins=yes \
				--trace-children=yes \
				--log-file=valgrind-out.txt -s

HELGRIND		= @valgrind \
				--tool=helgrind \
				--trace-children=yes \
				--log-file=helgrind-out.txt -s

valgrind:		$(NAME)
				$(VALGRIND) ./${NAME}

helgrind:		$(NAME)
				$(HELGRIND) ./${NAME}
