# Project file
NAME	=	webserv
# Project builds
DIRPRS		= ./src/parser/
SRCNAMES	= $(shell ls $(DIRPRS) | grep -E ".+\.cpp")
SRCPRS 		= $(addprefix $(DIRPRS), $(SRCNAMES))
OBJ			= $(SRCPRS:.cpp=.o)
INCPRS 		= ./src/parser/
BUILDDIR 	= ./build/
BUILDOBJS 	= $(addprefix $(BUILDDIR), $(SRCNAMES:.cpp=.o))


# Optimization and compiler flags
CC			= g++
CFLAGS		= -Wall -Werror -Wextra

# Debug flag
DEBUG 		= -g

# Main rule
all:		$(BUILDDIR) $(LIBFT) $(NAME)

# Object dir rule
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Object dir rule
$(BUILDDIR)%.o:$(DIRPRS)%.cpp
	$(CC) -I$(INC) $(CFLAGS) -std=c++98 -g -o $@ -c $<

# Project file rule
$(NAME): $(BUILDOBJS)
	$(CC) -g -o $(NAME) $(BUILDOBJS)  
# Cleaning up the build files
clean:
	rm -rf $(BUILDOBJS)

# Getting rid of the project file
fclean: clean
	rm -rf $(NAME)
	rm -rf $(BUILDDIR)

# Do both of the above
re: fclean all

# Just in case those files exist in the root dir
.PHONY: all fclean clean re
