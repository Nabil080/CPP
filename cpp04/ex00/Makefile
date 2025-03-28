######################## SETTINGS ########################

NAME = ex00

CCXX = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -Wshadow

INCLUDES =	

MAKEFLAGS += --no-print-directory

######################## SOURCES ########################

SRCS_NAMES =	main.cpp \
				WrongAnimal.cpp \
				Animal.cpp \
				Cat.cpp \
				WrongCat.cpp \
				Dog.cpp \

SRCS_DIR = 

SRCS = ${addprefix ${SRCS_DIR}, ${SRCS_NAMES}}

OBJS_DIR = objs/

OBJS = ${addprefix ${OBJS_DIR}, ${SRCS_NAMES:.cpp=.o}}

HEADERS =	Animal.hpp \
			WrongAnimal.hpp \
			WrongCat.hpp \
			Cat.hpp \
			Dog.hpp \

######################## BASIC RULES ########################

all : 
	${MAKE} -j ${NAME}

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

sane : ${OBJS_DIR} ${OBJS}
	${CC} ${FLAGS} -Ddebug=1 -g3 -fsanitize=address ${OBJS} ${foreach lib, ${LIBS},${lib}/${lib}.a} -o ${NAME}

${OBJS_DIR} :
	mkdir $@

${OBJS_DIR}%.o : ${SRCS_DIR}%.cpp ${HEADERS}
	${CC} ${FLAGS} ${CPPFLAGS} ${foreach include, ${INCLUDES},-I ${include}} -c $< -o $@

######################## TEST ########################

test : base

base : all
	./${NAME}

debug : sane
	./${NAME}

leak : all
	valgrind ./${NAME}

silent :
	${MAKE} -s test
