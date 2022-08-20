all:

	g++-11 Tensor.h 
	g++-11 TensorTests.cpp -o tensor

run:

	./tensor

try: all run