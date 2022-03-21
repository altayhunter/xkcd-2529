TARGET = xkcd
KC = kotlinc
KJSC = kotlinc-js
SRCS := $(wildcard *.kt)

.PHONY: run time perf clean

$(TARGET): $(SRCS)
	$(KC) -include-runtime -d $(TARGET).jar $(SRCS)

javascript: $(SRCS)
	$(KJSC) $(SRCS) -module-kind commonjs -main call -output $(TARGET).js

run: $(TARGET)
	java -jar ./$(TARGET).jar

time: $(TARGET)
	time java -jar ./$(TARGET).jar

perf: $(TARGET)
	perf record java -jar ./$(TARGET).jar && perf report

clean:
	-rm -f *.jar *.class perf.data*
