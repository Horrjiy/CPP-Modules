#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdint>

struct Data
{
	int i;
	float x;
};

class Serializer
{
public:
	Serializer() = delete;
	Serializer(const Serializer &copy) = delete;
	Serializer &operator=(const Serializer &copy);
	~Serializer() = delete;

	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif /* SERIALIZER_HPP */