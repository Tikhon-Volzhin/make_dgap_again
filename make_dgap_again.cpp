#include <iostream>
#include <vector>

int main()
{
    std::cout << "Hello World!\n";
	std::vector<int> array;
	for (int i = 0; i < 100; i++) {
		array.push_back(i);
	}
	return 0;
}
