# Connor Armand du Plooy
# u16169532

FLAGS = -Wall -Werror -ggdb -pedantic-errors

compile_bind_all: compile_nullObject compile_integer compile_list compile_listAsVector compile_listAsDynamicArray compile_NullPerson compile_container compile_Seat compile_listAsSLL compile_Person compile_listAsDLL compile_dynamicAuditorium compile_matrix compile_AuditoriumModeller compile_fixedSizeMatrix compile_fixedAuditorium compile_Auditorium
	@clear
	@echo "Binding and linking . . ."
	g++ src/NullObject.o src/Container.o src/Matrix.o src/FixedSizeMatrix.o src/Auditorium.o src/FixedAuditorium.o src/DynamicAuditorium.o src/AuditoriumModeller.o src/Seat.o src/Integer.o src/Person.o src/NullPerson.o src/List.o src/ListAsDynamicArray.o src/ListAsVector.o src/ListAsSLL.cpp src/ListAsDLL.cpp  src/main.cpp -ggdb -o src/a.out -Wall
	@echo "\n"
	@echo "Finished!"

compile_container: src/Container.cpp src/Container.h
	g++ -c src/Container.cpp -o src/Container.o ${FLAGS}

compile_matrix: src/Matrix.cpp src/Matrix.h
	g++ -c src/Matrix.cpp -o src/Matrix.o ${FLAGS}

compile_fixedSizeMatrix: src/FixedSizeMatrix.cpp src/FixedSizeMatrix.h
	g++ -c src/FixedSizeMatrix.cpp -o src/FixedSizeMatrix.o ${FLAGS}

compile_list:src/List.cpp src/List.h
	g++ -c src/List.cpp -o src/List.o ${FLAGS}

compile_listAsVector:src/ListAsVector.cpp src/ListAsVector.h
	g++ -c src/ListAsVector.cpp -o src/ListAsVector.o ${FLAGS}

compile_listAsSLL:src/ListAsSLL.cpp src/ListAsSLL.h
	g++ -c src/ListAsSLL.cpp -o src/ListAsSLL.o ${FLAGS}

compile_listAsDLL:src/ListAsDLL.cpp src/ListAsDLL.h
	g++ -c src/ListAsDLL.cpp -o src/ListAsDLL.o ${FLAGS}

compile_listAsDynamicArray: src/ListAsDynamicArray.cpp src/ListAsDynamicArray.h
	g++ -c src/ListAsDynamicArray.cpp -o src/ListAsDynamicArray.o ${FLAGS}

compile_fixedAuditorium: src/FixedAuditorium.cpp src/FixedAuditorium.h
	g++ -c src/FixedAuditorium.cpp -o src/FixedAuditorium.o ${FLAGS}

compile_dynamicAuditorium:src/DynamicAuditorium.cpp src/DynamicAuditorium.h
	g++ -c src/DynamicAuditorium.cpp -o src/DynamicAuditorium.o ${FLAGS}

compile_Auditorium:src/Auditorium.cpp src/Auditorium.h
	g++ -c src/Auditorium.cpp -o src/Auditorium.o ${FLAGS}

compile_AuditoriumModeller:src/AuditoriumModeller.cpp src/AuditoriumModeller.h
	g++ -c src/AuditoriumModeller.cpp -o src/AuditoriumModeller.o ${FLAGS}

compile_Person:src/Person.cpp src/Person.h
	g++ -c src/Person.cpp -o src/Person.o ${FLAGS}

compile_NullPerson:src/NullPerson.cpp src/NullPerson.h
	g++ -c src/NullPerson.cpp -o src/NullPerson.o ${FLAGS}

compile_Seat:src/Seat.cpp src/Seat.h
	g++ -c src/Seat.cpp -o src/Seat.o ${FLAGS}

compile_integer:src/Integer.cpp src/Integer.h
	g++ -c src/Integer.cpp -o src/Integer.o ${FLAGS}

compile_nullObject:src/NullObject.cpp src/NullObject.h
	g++ -c src/NullObject.cpp -o src/NullObject.o ${FLAGS}

clean:
	@rm src/*.o
	@rm -r documentation/html
	@rm -r documentation/latex
	@clear
	@echo "Cleaned all object files!"

compile_docs: documentation/doxyConfig.cfg
	@echo "Compiling documentation..."
	@$(MAKE) -C documentation	#Executes make in a directory
	@echo "Finished compiling documentation!"

run:
	src/a.out
