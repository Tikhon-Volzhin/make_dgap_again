#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iterator>
int main()
{
	std::random_device rd;   
	std::mt19937 gen(rd());
	std::vector<int> P_1(100);
	//создаем последовательность ѕ1 из случайных чисел
	for (int i = 0; i < 100; i++) {
		P_1[i] = gen()%11;
	}
	//добавл€ем несколько через cin
	for (int i = 0; i < 3; i++) {
		int a;
		std::cin >> a;
		P_1.push_back(a);
	}
	//перетасовываем
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(P_1), std::end(P_1), rng);
	//удал€ем дубликаты
	std::unique(P_1.begin(), P_1.end());
	//считаем число нечетных чисел
	int number = std::count_if(P_1.begin(), P_1.end(), [](int i) {return i % 2 == 0; });
	//минимальный - максимальный элемент
	auto min = std::min_element(P_1.begin(),P_1.end());
	auto max = std::max_element(P_1.begin(), P_1.end());
	std::cout << *min << " " << *max << std::endl;
	//простое число
	auto odd_number = std::find_if(P_1.begin(), P_1.end(), [](int i) {return (i == 2) || (i == 3 )|| (i == 5) ||( i == 7); });
	std::cout << odd_number[0]<< std::endl;
	//замен€ем квадратами (ничего лучше не придумал, так как непон€тно как ссылатьс€ на сам элемент, который нужно заменить)
	//for (int i = *min; i < *max + 1; i++) {
	//	std::replace(P_1.begin(), P_1.end(), i, i*i);
	//}
	//создаем P_2
	std::vector<int> P_2(P_1.size());
	
	for (int i = 0; i < P_1.size(); i++) {
		P_2[i] = gen()%10;
	}
	//сумма элементов P_2
	int sum = 0; 
	std::for_each(P_2.begin(), P_2.end(), [&](int i) { sum += i; });
	std::cout << sum;
	//замен€ем первые элементы P_2
	std::replace_if(P_1.begin(), P_1.begin() + 5, [](int i) {return true; }, 1);
	std::cout << sum;
	// последовательность ѕ_3 как разность ѕ_1 и ѕ_2
	std::vector<int> P_3;
	std::sort(P_1.begin(), P_1.end());
	std::sort(P_2.begin(), P_2.end());
	std::set_difference(P_1.begin(), P_1.end(), P_2.begin(), P_2.end(),
	std::inserter(P_3, P_3.begin()));
	//каждый отрицательный элемент в P_3 замен€ем нулем
	std::replace_if(P_3.begin(), P_3.end(), [](int i) {return i < 0; }, 1);
	//удал€ем нулевые элементы
	P_3.erase(std::remove_if(P_3.begin(),
		P_3.end(),
		[](int i) {return i == 0; }), P_3.end());
	//обратный пор€док
	std::reverse(P_3.begin(), P_3.end());
	//сортировка P_1, P_2
	std::sort(P_1.begin(), P_1.end());
	std::sort(P_2.begin(), P_2.end());
	//сли€ние P_1 и P_2 в P_4
	std::vector<int> P_4;
	std::set_union(P_1.begin(), P_1.end(),
		P_2.begin(), P_2.end(), std::inserter(P_4, P_4.begin()));
	//вывод массивов
	std::copy(P_1.begin(), P_1.end(), std::ostream_iterator<int>(std::cout, " "));
	std::copy(P_2.begin(), P_2.end(), std::ostream_iterator<int>(std::cout, " "));
	std::copy(P_3.begin(), P_3.end(), std::ostream_iterator<int>(std::cout, " "));
	std::copy(P_4.begin(), P_4.end(), std::ostream_iterator<int>(std::cout, " "));
	return 0;
}