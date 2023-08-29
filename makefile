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

#-------------- Valgrind tests ------------------------------------------------#

VALGRIND 		= @valgrind \
				--leak-check=full \
				--show-leak-kinds=all \
				--track-origins=yes \
				--trace-children=yes \
				--log-file=valgrind_out.txt -s

HELGRIND		= @valgrind \
				--tool=helgrind \
				--log-file=helgrind_out.txt -s

DRD				= @valgrind \
				--tool=drd \
				--log-file=drd_out.txt -s

TEST			= 4 450 200 200 2

val:		$(NAME)
				$(VALGRIND) ./$(NAME) $(TEST)

hel:		$(NAME)
				$(HELGRIND) ./$(NAME) $(TEST)

drd:			$(NAME)
				$(DRD) ./$(NAME) $(TEST)