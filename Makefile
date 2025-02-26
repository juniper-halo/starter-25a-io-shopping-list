CXX=clang++
CXX_FLAGS=-std=c++20 -Iincludes -Wall -Wextra -O0 -g

exec: bin/exec
tests: bin/tests

bin/exec: ./src/driver.cc ./includes/student.hpp ./includes/solution.hpp ./src/solution.cc
	$(CXX) $(CXX_FLAGS) ./src/driver.cc ./src/solution.cc -fsanitize=address -o $@

bin/tests: ./tests/tests.cc ./includes/student.hpp ./includes/solution.hpp ./src/solution.cc
	$(CXX) $(CXX_FLAGS) -Itests ./tests/tests.cc ./src/solution.cc -o $@

.DEFAULT_GOAL := exec
.PHONY: exec clean

clean:
	rm -rf bin/*