#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
	Data data;

	Serializer::serialize(&data);
	return (0);
}
