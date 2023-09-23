TARGET = Walker
JC = javac
JR = java
SRCS := $(wildcard *.java)

.PHONY: run time perf clean

$(TARGET).class: $(SRCS)
	$(JC) $(SRCS)

run: $(TARGET).class
	$(JR) $(TARGET)

time: $(TARGET).class
	time ($(JR) $(TARGET))

perf: $(TARGET).class
	perf record $(JR) $(TARGET) && perf report

clean:
	-rm -f *.class perf.data*
