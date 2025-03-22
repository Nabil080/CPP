######################## SETTINGS ########################

NAME =  PmergeMe

CC = clang++

FLAGS = -std=c++98 -Wall -Wextra -Werror 
FLAGS += -Wshadow -pedantic

INCLUDES =	includes	

MAKEFLAGS += --no-print-directory

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

######################## SOURCES ########################

SRCS_NAMES =	main.cpp PmergeMe.cpp PmergeMeTest.cpp

SRCS_DIR = srcs/

SRCS = ${addprefix ${SRCS_DIR}, ${SRCS_NAMES}}

OBJS_DIR = objs/

OBJS = ${addprefix ${OBJS_DIR}, ${SRCS_NAMES:.cpp=.o}}

HEADERS = includes/PmergeMe.hpp includes/PmergeMeTest.hpp

######################## BASIC RULES ########################

all : 
	${MAKE} ${NAME}

re : fclean
	${MAKE} all

clean :
	rm -rf ${OBJS_DIR}

fclean : clean
	rm -f ${NAME}

norm :
	norminette ${SRCS} ${HEADERS}

######################## BUILD RULES ########################

${NAME} : ${OBJS_DIR} ${OBJS}
	${CC} ${FLAGS} ${OBJS} ${foreach lib, ${LIBS},${lib}/${lib}.a} -o $@

${OBJS_DIR} :
	mkdir $@

${OBJS_DIR}%.o : ${SRCS_DIR}%.cpp ${HEADERS}
	${CC} ${FLAGS} ${CPPFLAGS} ${foreach include, ${INCLUDES}, -I ${include}} -c $< -o $@

######################## TEST ########################

test : exemple

base : all
	./${NAME}

leak : all
	${VALGRIND} ./${NAME}

exemple: all
	./${NAME} "11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7"

no-err :
	${MAKE} test 2>/dev/null

