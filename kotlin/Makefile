TARGET = xkcd
KC = kotlinc
KJSC = kotlinc-js
LIB = lib/kotlinx-coroutines-core-jvm-1.7.3.jar
SRCS := $(wildcard *.kt)

.PHONY: run time perf clean

$(TARGET).jar: $(SRCS)
	$(KC) -cp $(LIB) -include-runtime -d $(TARGET).jar $(SRCS)

$(TARGET).js: $(SRCS)
	$(KJSC) $(SRCS) -module-kind commonjs -main call -output $(TARGET).js

run: $(TARGET).jar
	java -ea -cp $(LIB):$(TARGET).jar MainKt

time: $(TARGET).jar
	time (java -cp $(LIB):$(TARGET).jar MainKt)

perf: $(TARGET).jar
	perf record java -cp $(LIB):$(TARGET).jar MainKt && perf report

clean:
	-rm -f *.jar *.class perf.data*
