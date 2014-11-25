CC = gcc
CXX = g++
SHELL := /bin/bash

# performance evaluation
PERF_ITER ?= 10
PERF = perf stat -r $(PERF_ITER)

# Common flags, with user-selected debugging
OPTLVL ?= 2
COMMON_FLAGS = -O$(OPTLVL) -march=native -Wall -Wextra -Wpedantic
ifdef DEBUG
COMMON_FLAGS += -g
endif

# Special flags for either C or C++
CFLAGS ?= $(COMMON_FLAGS) -std=c99
CXXFLAGS ?= $(COMMON_FLAGS) -std=c++11

LDFLAGS := -lm
INCLUDES := -I.
DEFINES ?=

# Source and binaries
CFILES := $(wildcard *.c)
CXXFILES := $(wildcard *.cpp)
BINS = $(CFILES:.c=.cbin) $(CXXFILES:.cpp=.cxxbin)
PERFDAT = $(CFILES:.c=.perfdat)

.PHONY: all clean

all: $(BINS)

perfdiff: all $(PERFDAT)

%.cbin: %.c
	$(CC) $(CFLAGS) $(DEFINES) $(INCLUDES) $^ -o $@ $(LDFLAGS)

%.cxxbin: %.cpp
	$(CXX) $(CXXFLAGS) $(DEFINES) $(INCLUDES) $^ -o $@ $(LDFLAGS)

%.perfdat: %.cbin %.cxxbin
	@diff <($(PERF) ./$*.cbin 2>&1) <($(PERF) ./$*.cxxbin 2>&1) > $@ ||:

clean:
	@rm -f $(BINS) $(PERFDAT)
