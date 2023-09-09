NAME		= convert

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++11 -MMD -MP -pedantic

ifdef WITH_DEBUG
	CXXFLAGS += -D DEBUG
endif

SRCS		= main.cpp \
			  ScalarConverter.cpp


OBJ_DIR		= objs
OBJ			= $(SRCS:%.cpp=%.o)
OBJS		= $(addprefix $(OBJ_DIR)/, $(OBJ))

DEPS		= $(OBJS:%.o=%.d)


all	: $(NAME)

$(NAME)	: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o	: %.cpp
	@mkdir -p $$(dirname $@)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean	:
	rm -rf $(OBJ_DIR)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all

debug	:
	make re WITH_DEBUG=1

run		: debug
	./$(NAME)

.PHONY	: all clean fclean re debug run

-include $(DEPS)