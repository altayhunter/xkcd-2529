TARGET := main.exe
SHELL := bash
CC := $(shell if command -v clang >/dev/null 2>&1; then echo "clang"; else echo "gcc"; fi)
INCLUDES := $(shell pkg-config --cflags glib-2.0)
LIBS := $(shell pkg-config --libs glib-2.0)
CFLAGS := -O3 -g -DNDEBUG
DFLAGS := -O0 -g -Wall -Wextra -fsanitize=integer -fsanitize=address -DDEBUG
SRCS := $(filter-out $(wildcard *_test.c), $(wildcard *.c))
OBJS := $(SRCS:.c=.o)
HDRS := $(filter-out $(wildcard *_test.h), $(wildcard *.h))

.PHONY: debug run time perf clean

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) -o $(TARGET) $(OBJS) $(LIBS) $(MAIN)

%_test.exe:
	$(CC) $(DFLAGS) -o $*_test.exe $*_test.c

debug:
	$(CC) $(DFLAGS) $(LIBS) -o $(TARGET) $(SRCS) $(INCLUDES) $(LIBS) $(MAIN)

$(OBJS): $(HDRS) $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $(@:.o=.c)

run: $(TARGET)
	./$(TARGET)

time: $(TARGET)
	time ./$(TARGET)

perf: $(TARGET)
	perf record ./$(TARGET) && perf report

clean:
	-rm -f *.stackdump *.exe *.o *.swp perf.data*
