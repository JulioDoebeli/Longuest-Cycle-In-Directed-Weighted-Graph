all: compile run run2 log log2

compile:
	gcc -Wall -Werror caminhada.c -o caminhada -lm -fopenmp
run:
	time ./caminhada <input.in
run2:
	time ./caminhada <input2.in
log:
	time ./caminhada <input.in >output.out
log2:
	time ./caminhada <input2.in >output2.out
