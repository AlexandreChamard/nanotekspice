##
## Makefile for ok in
##
## Made by Alexandre Chamard-bois
## Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
##
## Started on  Sat Sep 30 11:16:52 2017 Alexandre Chamard-bois
## Last update Sun Oct  8 18:04:03 2017 Alexandre Chamard-bois
##

NAME		=	nanotekspice

CXX		=	g++

RM		=	rm -f

RELEASE		=	false

OPTI_FLAG	=	-O2

CXXFLAGS	=	-std=c++14 -W -Wall -Wextra
CXXFLAGS	+=	-I./src/Type
CXXFLAGS	+=	-I./src/Shell

ifeq	($(RELEASE),true)
CXXFLAGS	+=	$(OPTI_FLAG)
CXXFLAGS	+=	-Werror -Wno-unused-result
else
CXXFLAGS	+=	-O0 -g
CXXFLAGS	+=	-Wuninitialized
endif

LDFLAGS		=

SRC		=	src/main.cpp			\
			src/Shell/Shell.cpp		\
			src/Type/Bool.cpp		\

OBJ		=	$(SRC:.cpp=.o)

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS) $(CXXFLAGS)

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY:		all clean fclean re
