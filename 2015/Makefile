MAKEFLAGS += --no-print-directory -s

SRCDIR = src/
BINDIR = bin/
TESTDIR = test/

CPPFLAGS = -std=c++11 -Wall -Wextra -Werror -g3 -O0

SRC = $(wildcard $(SRCDIR)*.cpp)
EXES = $(addprefix $(BINDIR), $(notdir $(SRC:%.cpp=%)))
TESTSIN = $(wildcard $(TESTDIR)*.in)
TESTRESULTFILE = $(TESTDIR)results.res

.PHONY: default all mrproper _test test

default: $(EXES)

$(BINDIR)%: $(SRCDIR)%.cpp
	@mkdir -p $(BINDIR)
	@printf "%-13s <$<>...\n" "Compiling & Linking"
	@g++ $(CPPFLAGS) -o $@ $<

all: mrproper default

mrproper:
	@rm -rf $(BINDIR)

test: $(EXES) _test

_test: $(TESTSIN)
	@echo "Launching tests..."
	@$(foreach test,$^,$(call launchtest,$(test),$(notdir $(test:.in=))))
	@cat $(TESTRESULTFILE)
	@if [ `grep -c -E 'FAILED' $(TESTRESULTFILE)` -eq 0 ]; then echo "\n\033[1;37m\033[42mAll tests PASSED!\033[0m"; \
		else echo "\n\033[1;37m\033[41mSome tests FAILED!\033[0m"; rm -f $(TESTRESULTFILE); false; fi;
	@rm -f $(TESTRESULTFILE)

define launchtest
	exe=$1; \
	exe=$${exe%_*}; \
	exe=$${exe##*/}; \
	exe=$(addprefix $(BINDIR), $$exe); \
	if [ -f $$exe ] && [ -x $$exe ]; then \
		fileOut=$(1:.in=.out); \
		if [ ! -f $$fileOut ] || [ ! -r $$fileOut ]; then \
			echo "Missing output file <$$fileOut>" >> $(TESTRESULTFILE); \
		else \
			$$exe < $1 > tmp; \
			diff -qw $$fileOut tmp > /dev/null; \
			if [ $$? -eq 0 ]; then \
				echo "\033[32mTest $2 PASSED\033[0m" >> $(TESTRESULTFILE); \
			else \
				echo "\033[1;31mTest $2 FAILED\033[0m" >> $(TESTRESULTFILE); \
			fi; \
			rm -f tmp; \
		fi; \
	fi;
endef
