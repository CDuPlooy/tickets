# Connor Armand du Plooy
# u16169532

compile_bind_all: compile_nullObject compile_integer compile_list compile_listAsVector compile_listAsDynamicArray compile_container compile_matrix compile_fixedSizeMatrix
	@clear
	@echo "Binding and linking . . ."
	g++ src/NullObject.o src/Container.o src/Matrix.o src/FixedSizeMatrix.o src/Integer.o  src/List.o src/ListAsDynamicArray.o src/ListAsVector.o src/main.cpp -ggdb -o src/test -Wall
	@echo "Finished!\n"

compile_container:
	g++ -c src/Container.cpp -o src/Container.o -ggdb -Wall

compile_matrix:
	g++ -c src/Matrix.cpp -o src/Matrix.o -ggdb -Wall

compile_fixedSizeMatrix:
	g++ -c src/FixedSizeMatrix.cpp -o src/FixedSizeMatrix.o -ggdb -Wall

compile_list:
	g++ -c src/List.cpp -o src/List.o -ggdb -Wall

compile_listAsVector:
	g++ -c src/ListAsVector.cpp -o src/ListAsVector.o -ggdb -Wall

compile_listAsDynamicArray:
	g++ -c src/ListAsDynamicArray.cpp -o src/ListAsDynamicArray.o -ggdb -Wall

compile_integer:
	g++ -c src/Integer.cpp -o src/Integer.o -ggdb -Wall

compile_nullObject:
	g++ -c src/NullObject.cpp -o src/NullObject.o -ggdb -Wall

clean:
	rm src/*.o
