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
ifeq	($(RELEASE),true)
CXXFLAGS	+=	$(OPTI_FLAG)
CXXFLAGS	+=	-Werror -Wno-unused-result
else
CXXFLAGS	+=	-O0 -g
CXXFLAGS	+=	-Wuninitialized
endif

CXXFLAGS	+=	-I./src/Lib
CXXFLAGS	+=	-I./src/Type
CXXFLAGS	+=	-I./src/Shell
CXXFLAGS	+=	-I./src/Circuit
CXXFLAGS	+=	-I./src/Parser
CXXFLAGS	+=	-I./src/Components
CXXFLAGS	+=	-I./src/Errors

# LDFLAGS		=

SRC		=	main.cpp				\
			Circuit/Circuit.cpp			\
			Parser/Parser.cpp			\
			Lib/ParsFile.cpp			\
			Lib/Tools.cpp				\
			Type/Bool.cpp				\
			Components/ComponentFactory.cpp		\
			Components/4001/4001.cpp		\
			Components/4011/4011.cpp		\
			Components/4013/4013.cpp		\
			Components/4030/4030.cpp		\
			Components/4069/4069.cpp		\
			Components/4071/4071.cpp		\
			Components/4081/4081.cpp		\
			Components/4512/4512.cpp		\
			Components/Default/Default.cpp		\
			Components/False/False.cpp		\
			Components/Clock/Clock.cpp		\
			Components/Input/Input.cpp		\
			Components/Output/Output.cpp		\
			Components/True/True.cpp		\

SDIR		=	src
ODIR		=	obj

OBJ		=	$(addprefix $(ODIR)/,$(SRC:.cpp=.o))

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS) $(CXXFLAGS)

$(ODIR)/%.o	:	$(SDIR)/%.cpp
			@ var=$@ && mkdir -p $${var%/*}
			$(CXX) $(CXXFLAGS) -c -o $@ $<


clean		:
			@ $(RM) -r $(ODIR)
			@ echo remove $(ODIR)

fclean		:	clean
			@ $(RM) $(NAME)
			@ echo remove $(NAME)

re		:	fclean all

.PHONY:		all clean fclean re
