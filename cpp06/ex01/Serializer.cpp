#include "Serializer.hpp"

// cast of ptr : reinterpret_cast
uintptr_t Serializer::serialize(Data *ptr) {
	if (!ptr) {
		throw std::invalid_argument("ptr is null");
	}
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}