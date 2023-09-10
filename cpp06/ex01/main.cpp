#include <iostream>
#include "Serializer.hpp"

int main() {
	{
		try {
			std::cout << "===== data -> serialize -> deserialize =====" << std::endl;

			std::cout << "1) data" << std::endl;
			Data src_data = {};
			src_data.str = "test string";
			src_data.num = 42;

			std::cout << " &src_data = " << &src_data << std::endl;
			std::cout << " str       = " << src_data.str << std::endl;
			std::cout << " num       = " << src_data.num << std::endl;
			std::cout << std::endl;


			std::cout << "2) serialize data" << std::endl;
			uintptr_t serialized = 0;
			std::cout << "2-1) serialized initial value" << std::endl;
			std::cout << " &serialized  = " << &serialized << std::endl;
			std::cout << " serialized   = " << serialized << std::endl;
			std::cout << std::endl;

			serialized = Serializer::serialize(&src_data);
			std::cout << "2-2) serialized = serialize(&src_data)" << std::endl;
			std::cout << " &serialized  = " << &serialized << std::endl;
			std::cout << " serialized   = " << serialized << std::endl;
			std::cout << "              = " << "0x" << std::hex << serialized << std::dec << std::endl;
			std::cout << std::endl;


			std::cout << "3) deserialize serialized data" << std::endl;
			Data *deserialized = NULL;

			deserialized = Serializer::deserialize(serialized);
			std::cout << " &deserialized = " << deserialized << std::endl;
			std::cout << " str           = " << deserialized->str << std::endl;
			std::cout << " num           = " << deserialized->num << std::endl;
			std::cout << std::endl;
			std::cout << "&src == deserialized : " << std::boolalpha << (&src_data == deserialized) << std::endl;
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		try {
			std::cout << "===== serialize(NULL) =====" << std::endl;
			Serializer::serialize(NULL);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
}

#ifdef __APPLE__

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q a.out");
}

#endif
