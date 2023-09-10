NAME		= a.out

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD -MP -pedantic

SRCS		= main.cpp \
			  Base.cpp \
			  A.cpp \
			  B.cpp \
			  C.cpp \
			  D.cpp

OBJ_DIR		= objs
OBJ			= $(SRCS:%.cpp=%.o)
OBJS		= $(addprefix $(OBJ_DIR)/, $(OBJ))

DEPS		= $(OBJS:%.o=%.d)


all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CXX) $(CXXFALGS) -o $@ $^

$(OBJ_DIR)/%.o	: %.cpp
	@mkdir -p $$(dirname $@)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean	:
	rm -rf $(OBJ_DIR)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all

run		: re
	./$(NAME)


.PHONY	: all claen fclean re run

-include $(DEPS)