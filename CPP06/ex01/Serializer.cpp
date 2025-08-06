#include "Serializer.hpp"

// ~-~-~-~-~-~-~-~-~ Constructors ~-~-~-~-~-~-~-~-~ //

Serializer &Serializer::operator=(const Serializer &copy)
{
	(void)copy;
	return (*this);
}

// ~-~-~-~-~-~-~-~-~ Functions ~-~-~-~-~-~-~-~-~ //

uintptr_t Serializer::serialize(Data *ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data*>(raw));
}