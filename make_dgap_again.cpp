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
	//���������� ����������, ��� ��� �������� ����� �� ������������� � ������� ����
	std::vector<int> array_2;
	array_2.reserve(10);
	for (int i = 0; i < 100; i++) {
		array_2.push_back(i);
		std::cout << array_2.capacity() << std::endl;
	}
	
	//����������, ����� ���������� ��������� ����� ���������� � reserve, �� ������ �������� �������������
	//� ������� ����

	/*std::vector<int> array_3(100000000000);
	for (int i = 0; i < 100; i++) {
		array_3.push_back(i);
		std::cout << array_3.capacity() << std::endl;
	}*/

	//�������� � �� ����� �������, �� ��� ������ ��������
	return 0;
}