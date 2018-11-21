
CFLAGS=-g -Wall -Werror -Iinclude
CC=g++
EXECUTABLE_NAME=a4.exe

SOURCES:=$(wildcard *.cpp)
HEADERS:=$(wildcard include/*.h)
OBJDIR:=obj
OBJECTS:=$(addprefix $(OBJDIR)/,$(SOURCES:.cpp=.o))

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): $(OBJECTS)
	$(CC) -o $(EXECUTABLE_NAME) $(CFLAGS) $(OBJECTS)

$(OBJDIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(OBJDIR)
	$(CC) -o $@ $(CFLAGS) -c $<

.PHONY: clean

clean:
	rm -f $(OBJDIR)/*.o $(EXECUTABLE_NAME)
	rmdir $(OBJDIR)
