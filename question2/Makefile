all: run clean

build:
	@g++ NewtonRaphson.cpp -o main.out

run: build
	@./main.out

clean:
	@rm *.out

debug:
	@g++ -g NewtonRaphson.cpp -o main.out
	@gdb main.out
