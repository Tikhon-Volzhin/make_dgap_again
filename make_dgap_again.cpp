#include <iostream>
#include <vector>
//minecraft is my life
int main()
{
    std::cout << "Hello World!\n";
	std::vector<int> array;
	for (int i = 0; i < 100; i++) {
		array.push_back(i);
	}
	return 0;
}
//merge позвол€ет соедин€ть ветки в несколько коммитов, оставл€€ в истории merge commit, а rebase позвол€ет делать коммиты как будто 
//нова€ ветка отсоединилась от master только в момент вызова rebase, таким образом не захламл€€ историю коммитов
