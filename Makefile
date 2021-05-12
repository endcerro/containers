#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edal--ce <edal--ce@sudent.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 14:27:31 by edal--ce          #+#    #+#              #
#    Updated: 2020/08/18 21:53:32 by edal--ce         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	containers

DIRSRC		=	src
OBJD		=	obj
INCLUDE		=	incl

SRC			=	main.cpp

OBJ			=	$(SRC:.cpp=.o)
OBJS		=	$(OBJ:%=$(OBJD)/%)

CFLAGS		=	-g3 -fsanitize=address -std=c++98 #-Wall -Wextra -Werror 

CC			=	clang++
RM			=	rm -f
ECHO		=	echo

$(NAME)		:	$(LIB) $(OBJD) $(OBJS)
				$(CC) -I./$(INCLUDE) $(CFLAGS) $(OBJS) -o $(NAME) 

$(OBJD)		:
				@mkdir $(OBJD)

$(OBJD)/%.o	:	$(DIRSRC)/%.cpp
				$(CC) -I./$(INCLUDE) $(CFLAGS) -o $@ -c $<

all			:	$(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

bonus		:	all

re			:	fclean all

.PHONY		:	all clean re fclean