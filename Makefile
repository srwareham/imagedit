CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-std=c++11 -Wall

H_FILES := $(wildcard *.h)
CPP_FILES := $(wildcard *.cpp)
OBJ_FILES := $(notdir $(CPP_FILES:.cpp=.o))

all: imagedit

imagedit: $(H_FILES) $(CPP_FILES) $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o imagedit $(CPPFLAGS)

clean:
	$(RM) $(OBJ_FILES)

distclean: clean
	$(RM) imagedit
