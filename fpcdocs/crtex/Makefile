#######################################################################
#
# Makefile to compile all examples and convert them to LaTeX
# 
#######################################################################

# Compiler

ifndef FPC
ifdef PP
FPC=$(PP)
endif
endif
ifndef FPC
FPCPROG:=$(strip $(wildcard $(addsuffix /fpc$(SRCEXEEXT),$(SEARCHPATH))))
ifneq ($(FPCPROG),)
FPCPROG:=$(firstword $(FPCPROG))
FPC:=$(shell $(FPCPROG) -PB)
ifneq ($(findstring Error,$(FPC)),)
override FPC=ppc386
endif
else
override FPC=ppc386
endif
endif
override FPC:=$(subst $(SRCEXEEXT),,$(FPC))
override FPC:=$(subst \,/,$(FPC))$(SRCEXEEXT)


# Unit directory
# UNITDIR=/usr/lib/ppc/0.99.0/linuxunits


# Any options you wish to pass.
PPOPTS=

# Script to convert the programs to LaTeX examples which can be included.
PP2TEX=../pp2tex

# Script to collect all examples in 1 file.
MAKETEX=make1tex

#######################################################################
# No need to edit after this line.
#######################################################################

ifdef UNITDIR
PPOPTS:=$(PPOPTS) -Up$(UNITDIR);
endif

.SUFFIXES: .pp .tex

.PHONY: all tex clean

OBJECTS=ex1 ex2 ex3 ex4 ex5 ex6 ex7 ex8 ex9 ex10 ex11 ex12 ex13 ex14 \
        ex15 ex16

TEXOBJECTS=$(addsuffix .tex, $(OBJECTS))

all : $(OBJECTS)

tex : $(TEXOBJECTS)

onetex : tex
	$(MAKETEX) $(TEXOBJECTS)

clean : 
	-rm -f *.o *.s $(OBJECTS) $(TEXOBJECTS)
	-rm -f *.ow *.sw *.exe *.dll
 
$(OBJECTS): %: %.pp
	$(FPC) $(PPOPTS) $*

$(TEXOBJECTS): %.tex: %.pp head.tex foot.tex
	$(PP2TEX) $*
