# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/18 16:29:51 by mhaziza           #+#    #+#              #
#    Updated: 2017/01/14 18:13:36 by mhaziza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
CC		=   @gcc
CFLAGS	= 	-I. -g
RM		=   @rm -f
SRCS	=   ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_toupperstr.c \
			ft_tolower.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_itoa.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putstrl.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putnbrl.c \
			ft_putints.c \
			ft_puttab_int.c \
			ft_puttab_str.c \
			ft_intlen_base.c \
			ft_putnbr_base.c \
			ft_atoi_base.c \
			ft_itoa_base.c \
			ft_wputchar.c \
			ft_wputstr.c \
			ft_wstrlen.c \
			ft_wstrncpy.c \
			printf.c \
			conv_alpha.c \
			conv_num.c \
			flags_utils.c \
			ft_uitoa_b.c \
			ft_ulitoa_b.c \
			casting.c \

OBJS	=   $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:     all clean fclean re
