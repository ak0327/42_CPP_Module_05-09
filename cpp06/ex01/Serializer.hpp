#pragma once

#include <string>
#include <cstdint>

struct Data {
	std::string	str;
	int num;
};

class Serializer {
public:
	//It takes a pointer and converts it to the unsigned integer type uintptr_t
	static uintptr_t serialize(Data *ptr);

	// It takes an unsigned integer parameter and converts it to a pointer to Data
	static Data *deserialize(uintptr_t raw);
};

// Write a program to test that your class works as expected.
// You must create a non-empty (it means it has data members) Data structure.
// Use serialize() on the address of the Data object and pass its return value to deserialize().
// Then, ensure the return value of deserialize() compares equal to the original pointer.
// Do not forget to turn in the files of your Data structure.