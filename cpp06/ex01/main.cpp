#include <iostream>
#include "Serializer.hpp"
#include <limits>

int main() {
	{
		try {
			std::cout << "===== initial : Data data1 =====" << std::endl;
			Data data1;
			std::cout << " &data1 = " << &data1 << " (init)" << std::endl;

			data1.str = "test string";
			data1.num = 42;

			std::cout << " &data1 = " << &data1 << std::endl;
			std::cout << " str    = " << data1.str << std::endl;
			std::cout << " num    = " << data1.num << std::endl;
			std::cout << std::endl;


			uintptr_t ptr1 = 0;
			std::cout << "===== serialized : uintptr_t ptr1 = serialize(&data1) =====" << std::endl;
			std::cout << " &ptr1  = " << &ptr1 << ", ptr = " << ptr1 << " (init)" <<  std::endl;
			ptr1 = Serializer::serialize(&data1);
			std::cout << " &ptr1  = " << &ptr1 << ", ptr = " << ptr1 << " (serialized)" << std::endl;
			std::cout << "                             " << "0x" << std::hex << ptr1 << std::dec << " (hex)" <<  std::endl;
			std::cout << std::endl;


			Data *data2;
			std::cout << "===== deserialized : Data *data2 = deserialize(ptr1) =====" << std::endl;
//			std::cout << " &data2 = " << data2 << " (init)" << std::endl;

			data2 = Serializer::deserialize(ptr1);

			std::cout << " &data2 = " << data2 << " (deserialized)" << std::endl;
			std::cout << " str    = " << data2->str << std::endl;
			std::cout << " num    = " << data2->num << std::endl;
			std::cout << std::endl;

		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;

	}

//	system("leaks -q a.out");
	return 0;
}