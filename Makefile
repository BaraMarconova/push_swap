# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmarcono <bmarcono@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/01 17:45:25 by bmarcono          #+#    #+#              #
#    Updated: 2023/09/11 18:59:11 by bmarcono         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = src/calculations.c src/group_builder.c src/operations_container_2.c src/push_swap.c \
       src/sort.c src/stack_operations.c src/ft_sort_int_tab.c src/operations_container.c \
       src/presort.c src/rotations.c src/stack_init.c src/utils.c src/utils_2.c \
       src/fill_list.c src/validate.c

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -Iincludes

RM = rm -rf

PRINT_FORMAT = @printf "\033[1;34m[%s]\033[0m \033[1;32m%s\033[0m\n"


all: ${NAME} 

${NAME}: ${OBJS}
	@${MAKE} -s -C ./libft
	${PRINT_FORMAT} "SUCCESS" "Successfully compiled libft"
	@${CC} ${CFLAGS} ${OBJS}  ./libft/libft.a -o ${NAME}
	${PRINT_FORMAT} "SUCCESS" "${NAME} is ready to use"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean: 
	@${MAKE} -C ./libft fclean
	${PRINT_FORMAT} "SUCCESS" "Libft is removed"
	@${RM} ${OBJS}
	${PRINT_FORMAT} "SUCCESS" "push_swap is removed"
	@${RM} ${OBJSB}
	${PRINT_FORMAT} "SUCCESS" "checker is removed"

fclean: clean
	@${RM} ${NAME}
	@${RM} ${BONUS}

re: fclean all

.PHONY: all clean fclean re
