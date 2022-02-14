CC       = gcc
CFLAGS   = -Wall -pg
LDFLAGS  = -lgmp
OBJFILES = cmp_uint31_div3.o rng.o fast_remainder.o
TARGET   = cmp

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
clean:
	rm -f $(OBJFILES) $(TARGET) *~
