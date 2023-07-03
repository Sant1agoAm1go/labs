#include "Array.h"
#include "ArraySequence.h"
#include "Sequence.h"
#include "Vector.h"
#include <iostream>
template <typename T> 
	int main_t() {
	int object;
	int length;
	int choice;
	int position;
	int mult;
	T value;
	std::cout<<"Length: "<<std::endl;
	std::cin>>length;
	auto vec = Vector<T>(length);
	for (int i = 0; i < length; i++) {
		std::cin >> value;
		vec.InsertAt(i,value);
		std::cin.clear();
	}
	auto vec2 = vec;
	do {
		std::cout<<"-------------Menu-------------"<<std::endl;
		std::cout<<"1. Norm"<<std::endl;
		std::cout<<"2. Scalar"<<std::endl;
		std::cout<<"3. Multiply"<<std::endl;
		std::cout<<"4. Print"<<std::endl;
		std::cout<<"5. Exit"<<std::endl;
		std::cout<<"---------------------"<<std::endl;
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		std::cout << std::endl;
		switch(choice) {
			case 1:
			std::cout<<"Norm of vector: "<<vec.Norm()<<std::endl;
			break;
			case 2:
			std::cout << "Scalar product of vec and equal vector:" << std::endl; 
			std::cout << "ScalarMult(vec, vec) = " << vec.ScalarMult(&vec2) << std::endl;
			break;
			case 3:
			std::cin>>mult;
			vec.VectorScal(mult);
			std::cout<<"Vector multiply on our choice"<<std::endl;
			break;
			case 4:
			std::cout<<"vector= "<<vec;
			break;
			case 5:
			std::cout<<"Exiting..."<<std::endl;
			break;
		}
		
	} while(choice != 5);
	return 0;
}

int main() {
	std::cout<<"Choode stored type:"<<std::endl;
	std::cout<<"0-integer, 1 -real"<<std::endl;
	int type;
	std::cin>>type;
	switch(type){
	case 0:
		return main_t<int>();
	case 1:
		return main_t<double>();
	}
	// return main_t<int>();
}
    
