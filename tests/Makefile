##
## Makefile for ok in
##
## Made by Alexandre Chamard-bois
## Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
##
## Started on  Sat Sep 30 11:16:52 2017 Alexandre Chamard-bois
## Last update Sun Oct  8 18:04:03 2017 Alexandre Chamard-bois
##

NAME		=	test_nanotekspice

CXX		=	g++

RM		=	rm -f

RELEASE		=	false

OPTI_FLAG	=	-O2

CXXFLAGS	=	-std=c++14 -W -Wall -Wextra
ifeq	($(RELEASE),true)
CXXFLAGS	+=	$(OPTI_FLAG)
CXXFLAGS	+=	-Werror -Wno-unused-result
else
CXXFLAGS	+=	-O0 -g
CXXFLAGS	+=	-Wuninitialized
endif

CXXFLAGS	+=	-I../src/Lib
CXXFLAGS	+=	-I../src/Type
CXXFLAGS	+=	-I../src/Shell
CXXFLAGS	+=	-I../src/Circuit
CXXFLAGS	+=	-I../src/Parser
CXXFLAGS	+=	-I../src/Components
CXXFLAGS	+=	-I../src/Errors

# LDFLAGS		=

SRC		=	../src/Circuit/Circuit.cpp			\
			../src/Parser/Parser.cpp			\
			../src/Lib/ParsFile.cpp				\
			../src/Lib/Tools.cpp				\
			../src/Type/Bool.cpp				\
			../src/Components/ComponentFactory.cpp		\
			../src/Components/4001/4001.cpp			\
			../src/Components/4011/4011.cpp			\
			../src/Components/4013/4013.cpp			\
			../src/Components/4030/4030.cpp			\
			../src/Components/4069/4069.cpp			\
			../src/Components/4071/4071.cpp			\
			../src/Components/4081/4081.cpp			\
			../src/Components/4512/4512.cpp			\
			../src/Components/Default/Default.cpp		\
			../src/Components/False/False.cpp		\
			../src/Components/Clock/Clock.cpp		\
			../src/Components/Input/Input.cpp		\
			../src/Components/Output/Output.cpp		\
			../src/Components/True/True.cpp			\

SRC		+=	main.cpp		\
			input.cpp		\
			output.cpp		\
			4001.cpp		\
			ComponentFactory.cpp	\

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
