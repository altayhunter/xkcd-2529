PY = pypy3
SRC = main.py

.PHONY: run time clean

run:
	$(PY) $(SRC)

time:
	time ($(PY) $(SRC))

clean:
	-rm -rf __pycache__
