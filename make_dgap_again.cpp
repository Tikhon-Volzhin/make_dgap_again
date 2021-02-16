#include <iostream>
#include <vector>
#include <cmath>

int main()
{
	std::vector<int> array;
	for (int i = 0; i < 100; i++) {
		array.push_back(i);
		std::cout << array.capacity() << std::endl;
	}
	//результаты показывают, что при нехватке места он увеличивается в полтора раза
	std::vector<int> array_2;
	array_2.reserve(10);
	for (int i = 0; i < 100; i++) {
		array_2.push_back(i);
		std::cout << array_2.capacity() << std::endl;
	}
	
	//аналогично, когда количество достигает числа указанного в reserve, то массив начинает увеличиваться
	//в полтора раза

	/*std::vector<int> array_3(100000000000);
	for (int i = 0; i < 100; i++) {
		array_3.push_back(i);
		std::cout << array_3.capacity() << std::endl;
	}*/

	//наверное я не понял задания, но оно просто крашится
	return 0;
}