MAKEFLAGS += --no-print-directory

SRCDIR = src/
BINDIR = bin/
TESTDIR = test/

CPPFLAGS = -std=c++11 -Wall -Wextra -Werror -g3 -O0

SRC = $(wildcard $(SRCDIR)*.cpp)
EXES = $(addprefix $(BINDIR), $(notdir $(SRC:%.cpp=%)))
TESTFAMILIES = $(addprefix $(TESTDIR), $(notdir $(SRC:%.cpp=%)))
TESTSIN = $(wildcard $(TESTDIR)*.in)

.PHONY: default all mrproper test $(TESTFAMILIES) $(TESTSIN)

default: $(EXES)

$(BINDIR)%: $(SRCDIR)%.cpp
	@mkdir -p $(BINDIR)
	@printf "%-13s <$<>...\n" "Compiling & Linking"
	@g++ $(CPPFLAGS) -o $@ $<

all: mrproper default

mrproper:
	@rm -rf $(BINDIR)

test: $(EXES) $(TESTFAMILIES)

$(TESTFAMILIES): $(TESTDIR)%: $(BINDIR)%
	@$(MAKE) $@*.in

$(TESTDIR)*.in:
	@EXE=$(addprefix $(BINDIR), $(notdir $@)) ; \
	EXE=$${EXE%_*.in} ;\
	$(MAKE) -s $$EXE; \
	fileIn=$@; fileOut=$${fileIn%.in}.out; \
	printf "%-13s %-35s" "Testing" "<$@>..."; \
	if [ ! -f $$fileOut ] || [ ! -r $$fileOut ]; then \
		echo "Missing output file <$$fileOut>"; \
	else \
		$$EXE < $$fileIn > tmp; \
		diff -q $$fileOut tmp > /dev/null; \
		if [ $$? -eq 0 ]; then \
			echo "SUCCESSFUL"; \
		else \
			echo "FAILED"; \
		fi; \
		rm -f tmp; \
	fi;
