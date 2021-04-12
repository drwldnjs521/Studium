tests:
	checkmk dyn_array_tests.ts > dyn_array_tests.c

compile: tests
	gcc -Wall -std=c99 -g dyn_array.c dyn_array_tests.c -o tests `pkg-config --cflags --libs check`

run: compile
	./tests

clean:
	rm -f dyn_array_tests.c tests


