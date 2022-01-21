vpath %.c ../src

CC = gcc
CFLAGS = -c -Wall -std=gnu99
LDFLAGS =

OBJDIR := obj
SRCDIR := src
TGDIR := bin

SRC = cyrex-fanconrol.c
OBJ = $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))

TARGET = bin/cyrex-fancontrol

CFLAGS += `pkg-config --cflags appindicator3-0.1`
LDFLAGS += `pkg-config --libs appindicator3-0.1`

install: $(TARGET)
	@echo Install to ${DSTDIR}/bin/
	@rm -rf $(OBJDIR)

$(TARGET): $(OBJ) Makefile
	@mkdir -p bin
	@echo linking $(TARGET) from $(OBJ)
	@$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS) -lm

clean:
	@rm -rf $(OBJDIR) $(TGDIR)

$(OBJDIR)/%.o : $(SRCDIR)/%.c Makefile
	@echo compiling $< 
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@
