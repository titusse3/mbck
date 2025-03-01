mbck_dir = ../
CC = gcc
CFLAGS = -std=c23 \
	-I$(mbck_dir)
vpath %.c $(mbck_dir)
vpath %.h $(mbck_dir)
objects = mbck.o main.o
executable = exemple
makefile_indicator = .\#makefile\#

.PHONY: all clean

all: $(executable)

clean:
	$(RM) $(objects) $(executable)
	@$(RM) $(makefile_indicator)

$(executable): $(objects)
	$(CC) $(objects) -o $(executable) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

mbck.o: mbck.c mbck.h
main.o: main.c mbck.h

include $(makefile_indicator)

$(makefile_indicator): makefile
	@touch $@
	@$(RM) $(objects) $(executable)