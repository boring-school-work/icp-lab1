all: run clean

build:
	@g++ ComplexNumber.cpp -o main.out

run: build
	@./main.out

clean:
	@rm *.out

debug:
	@g++ -g ComplexNumber.cpp -o main.out
	@gdb main.out
