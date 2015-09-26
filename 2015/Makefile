SRCDIR = src/
BINDIR = bin/

CPPFLAGS = -std=c++11 -Wall -Wextra -Werror -g3 -O0

SRC = $(wildcard $(SRCDIR)*.cpp)
EXE = $(addprefix $(BINDIR), $(notdir $(SRC:%.cpp=%)))

.PHONY: default all mrproper

default: $(EXE)

$(BINDIR)%: $(SRCDIR)%.cpp
	@mkdir -p $(BINDIR)
	@printf "%-13s <$<>...\n" "Compiling & Linking"
	@g++ $(CPPFLAGS) -o $@ $<

all: mrproper default

mrproper:
	@rm -rf $(BINDIR)

