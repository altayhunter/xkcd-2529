TARGET = main
SHELL = bash
CC = $(shell if command -v clang >/dev/null 2>&1; then echo "clang"; else echo "gcc"; fi)
SRCS := $(wildcard *.goose)

.PHONY: run time perf clean

$(TARGET): $(SRCS)
	GOOSE_CC=$(CC) goose build $(TARGET).goose

run: $(TARGET)
	./$(TARGET)

time: $(TARGET)
	time ./$(TARGET)

perf: $(TARGET)
	perf record ./$(TARGET) && perf report

clean:
	-rm -f ./$(TARGET) *.swp perf.data*
