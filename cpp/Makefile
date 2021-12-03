TARGET = main
SHELL = bash
CC = $(shell if command -v clang++ >/dev/null 2>&1; then echo "clang++"; else echo "g++"; fi)
CFLAGS = -O3 -g -std=c++20 -DNDEBUG
DFLAGS = -O0 -g -std=c++20 -Wall -Wextra -fsanitize=integer -fsanitize=address -DDEBUG
SRCS := $(filter-out $(wildcard *_test.cpp), $(wildcard *.cpp))
OBJS := $(SRCS:.cpp=.o)
HDRS := $(filter-out $(wildcard *_test.hpp), $(wildcard *.hpp))

.PHONY: debug run time perf clean

%_test:
	$(CC) $(DFLAGS) -o $*_test.exe $*_test.cpp $*.cpp

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET).exe $(OBJS)

debug:
	$(CC) $(DFLAGS) -o $(TARGET).exe $(SRCS)

$(OBJS): $(HDRS) $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $(@:.o=.cpp)

run: $(TARGET)
	./$(TARGET).exe

time: $(TARGET)
	time ./$(TARGET).exe

perf: $(TARGET)
	perf record ./$(TARGET).exe && perf report

clean:
	-rm -f *.stackdump *.exe *.o *.swp perf.data*
