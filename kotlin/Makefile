TARGET = xkcd
KC = kotlinc
KJSC = kotlinc-js
SRCS := $(wildcard *.kt)

.PHONY: run time perf clean

$(TARGET): $(SRCS)
	$(KC) -cp lib/kotlinx-coroutines-core-1.4.0.jar -include-runtime -d $(TARGET).jar $(SRCS)

javascript: $(SRCS)
	$(KJSC) $(SRCS) -module-kind commonjs -main call -output $(TARGET).js

run: $(TARGET)
	java -ea -cp lib/kotlinx-coroutines-core-1.4.0.jar:$(TARGET).jar MainKt

time: $(TARGET)
	time (java -cp lib/kotlinx-coroutines-core-1.4.0.jar:$(TARGET).jar MainKt)

perf: $(TARGET)
	perf record java -cp lib/kotlinx-coroutines-core-1.4.0.jar:$(TARGET).jar MainKt && perf report

clean:
	-rm -f *.jar *.class perf.data*
