# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmarcono <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 17:59:23 by bmarcono          #+#    #+#              #
#    Updated: 2023/01/28 18:57:20 by bmarcono         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
        ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
        ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
        ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
        ft_strdup.c ft_substr.c ft_strlcpy.c ft_calloc.c ft_strtrim.c \
        ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_split.c \
        ft_putnbr_fd.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_strjoin.c \
        ft_printf.c ft_print_hex.c ft_print_p.c ft_printstr.c ft_print_u.c

SRCS_B = 		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c 

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEADER = libft.h

.o: .c 
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rc ${NAME} $(OBJS)

all: $(NAME)

bonus: 	$(OBJS) $(OBJS_B)
		ar rc $(NAME) $(OBJS) $(OBJS_B)

clean: 	
		rm -f ${OBJS}
		rm -f ${OBJS_B}

fclean: clean 
		rm -f ${NAME}

re: fclean all
