CC=g++
CXXFLAGS=-Wall -pedantic
CXXLDFLAGS=-static
STD=c++17

OBJS=main.o

BINDIR=bin
OBJDIR=obj
INCLUDEDIR=include
LIBDIR=lib

TARGET=grade

all: $(TARGET)

$(TARGET): clean $(OBJS)
	mkdir $(BINDIR) $(OBJDIR)
	$(CC) -std=$(STD) -I$(INCLUDEDIR) -L$(LIBDIR) $(CXXFLAGS) $(OBJS) -o $(BINDIR)/$(TARGET) $(CXXLDFLAGS)
	mv *.o obj

main.o: src/main.cpp
	$(CC) -std=$(STD) -I$(INCLUDEDIR) -L$(LIBDIR) $(CXXFLAGS) -c $^

clean:
	rm -rf bin obj *.log
