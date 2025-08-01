# HERE TO PROJECT NAME
NAME		:= Harl2

CXX		 := c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98 -pedantic
OPT		 := -O2
RM		  := rm -rf
DEFINE	  := -DDEBUG_MODE=DEBUG_NONE

ROOT_DIR	:= .
SRC_DIR	 := $(ROOT_DIR)
INC_DIR	 := $(ROOT_DIR)
OBJ_DIR	 := $(ROOT_DIR)/obj

IDFLAGS	 := -I$(INC_DIR)

# HERE TO SRC FILES
SRC :=	main.cpp\
		Harl.cpp\
	

OBJ := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC))

all:
	$(MAKE) __build -j $(shell nproc)

re:
	$(MAKE) fclean
	$(MAKE) __build -j $(shell nproc)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

__build: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OPT) $(OBJ) $(IDFLAGS) $(DEFINE) -o $(NAME)
	@echo "====================="
	@echo "== Build Complete! =="
	@echo "====================="

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(OPT) $(IDFLAGS) $(DEFINE) -fPIC -MMD -MP -c $< -o $@

# ============ DEBUG BUILDS ============
debug:
	$(MAKE) __debug -j $(shell nproc)

__debug: OPT	:= -g -fsanitize=address -O1 -fno-omit-frame-pointer
__debug: DEFINE := -DDEBUG_MODE=DEBUG_ALL
__debug: $(NAME)

# ============ CHECKS ============
valgrind: $(NAME)
	valgrind -q --leak-check=full --track-origins=yes ./$(NAME) $(ARGS)

forbidden:
	@echo "Checking for forbidden functions (malloc, free, printf)..."
	@grep -nr --color -E '\b(malloc|calloc|realloc|free|printf)\b' $(SRC_DIR) || true

check: forbidden valgrind

.PHONY: all clean fclean re debug valgrind forbidden check norm