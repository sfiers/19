# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/25 16:30:52 by lduhamel          #+#    #+#              #
#    Updated: 2019/10/31 14:17:46 by lduhamel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c ft_memccpy.c ft_memmove.c ft_strlcpy.c ft_strrchr.c ft_atoi.c \
ft_isascii.c ft_memchr.c ft_memset.c ft_strlen.c ft_tolower.c ft_bzero.c ft_isdigit.c \
ft_memcmp.c ft_strchr.c ft_strncmp.c ft_toupper.c ft_isalnum.c ft_isprint.c ft_memcpy.c \
ft_strlcat.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_strjoin.c ft_strtrim.c ft_substr.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_strmapi.c ft_itoa.c ft_putstr.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstlast_bonus.c


HEADER = libft.h

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

BOBJS = $(BONUS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c -I$(HEADER) -o $@ $<

bonus:	$(OBJS) $(BOBJS)
	ar rc $(NAME) $(OBJS) $(BOBJS)

clean: 
	/bin/rm -f $(OBJS) $(BOBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus