#include "hash.h"

int main()
{
	tHashmap<std::string, int> favoriteNumbersByName;
	favoriteNumbersByName["Terry"] = 5;
	std::cout << favoriteNumbersByName["Terry"] << std::endl; // 5
	while (true) {}
	return 0;
}