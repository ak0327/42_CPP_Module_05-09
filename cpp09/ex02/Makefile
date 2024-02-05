NAME		=	PmergeMe

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -MMD -MP -pedantic

SRCS		=	main.cpp

OBJS_DIR	=	objs
OBJ			=	$(SRCS:%.cpp=%.o)
OBJS		=	$(addprefix $(OBJS_DIR)/, $(OBJ))

DEPS		=	$(OBJS:%.o=%.d)

INCLUDES	=	-I.


.PHONY	: all
all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

$(OBJS_DIR)/%.o : %.cpp
	mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

.PHONY	: clean
clean	:
	rm -rf $(OBJS_DIR)

.PHONY	: fclean
fclean	: clean
	rm -rf $(NAME)

.PHONY	: re
re		: fclean all

.PHONY	: debug
debug	: CXXFLAGS += -D DEBUG
debug	: re

#.PHONY	: test
#test	:
#	cmake -S . -B build
#	cmake --build build
#	./build/unit_test

-include $(DEPS)
