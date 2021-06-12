CC = gcc
CFLAGS = -g -W -Wall -std=c11 -pedantic

PREPROCESSOR = $(CC) -E $(CPPFLAGS)
COMPILER = $(CC) -c $(CFLAGS)
LINKER = $(CC) $(LDFALGS)

CPPCHECK = cppcheck --enable=warning,style --std=$(STD)
STD = c11
TARGET = stringsort

OBJECTS = \
  stringsort.o \
  bubblesort.o \

all: stringsort

clean:
	rm -f stringsort $(OBJECTS) $(OBJECTS:.o=.i)

stringsort: $(OBJECTS)
	$(LINKER) -o stringsort $(OBJECTS)

stringsort.o: stringsort.i
	$(COMPILER) stringsort.i

bubblesort.o: bubblesort.i
	$(COMPILER) bubblesort.i

stringsort.i: stringsort.c bubblesort.h
	$(PREPROCESSOR) stringsort.c -o stringsort.i

bubblesort.i: bubblesort.c bubblesort.h
	$(PREPROCESSOR) bubblesort.c -o bubblesort.i

cppcheck: $(TARGET).c
	$(CPPCHECK) $<
