# Connor Armand du Plooy
# u16169532

compile_bind_all: compile_nullObject compile_integer compile_list compile_listAsVector compile_listAsDynamicArray compile_container compile_listAsSLL compile_listAsDLL compile_dynamicAuditorium compile_matrix compile_AuditoriumModeller compile_fixedSizeMatrix compile_fixedAuditorium compile_Auditorium
	@clear
	@echo "Binding and linking . . ."
	g++ src/NullObject.o src/Container.o src/Matrix.o src/FixedSizeMatrix.o src/Auditorium.o src/FixedAuditorium.o src/DynamicAuditorium.o src/AuditoriumModeller.o src/Integer.o  src/List.o src/ListAsDynamicArray.o src/ListAsVector.o src/ListAsSLL.cpp src/ListAsDLL.cpp  src/main.cpp -ggdb -o src/a.out -Wall
	@echo "\n"
	@echo "Finished!"

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

compile_listAsSLL:
	g++ -c src/ListAsSLL.cpp -o src/ListAsSLL.o -ggdb -Wall

compile_listAsDLL:
	g++ -c src/ListAsDLL.cpp -o src/ListAsDLL.o -ggdb -Wall

compile_listAsDynamicArray:
	g++ -c src/ListAsDynamicArray.cpp -o src/ListAsDynamicArray.o -ggdb -Wall

compile_fixedAuditorium:
	g++ -c src/FixedAuditorium.cpp -o src/FixedAuditorium.o -ggdb -Wall

compile_dynamicAuditorium:
	g++ -c src/DynamicAuditorium.cpp -o src/DynamicAuditorium.o -ggdb -Wall

compile_Auditorium:
	g++ -c src/Auditorium.cpp -o src/Auditorium.o -ggdb -Wall

compile_AuditoriumModeller:
	g++ -c src/AuditoriumModeller.cpp -o src/AuditoriumModeller.o -ggdb -Wall

compile_integer:
	g++ -c src/Integer.cpp -o src/Integer.o -ggdb -Wall

compile_nullObject:
	g++ -c src/NullObject.cpp -o src/NullObject.o -ggdb -Wall

clean:
	@rm src/*.o
	@clear
	@echo "Cleaned all object files!"
compile_docs:
	@echo "Compiling documentation..."
	@cd documentation
	@$(MAKE) -C documentation
	@echo "Finished compiling documentation!"
run:
	src/a.out
