#include "functions.h"
#include <chrono>
#include <tuple>
using namespace std;
using namespace std::chrono;

int main() {
	setlocale(LC_ALL, "");
	srand(time(NULL));
	cout << "Лабораторная работа №9 ИКБО-13-21 Черномуров С.А. Вариант 23" << endl << endl;
	cout << "Выберите номер задания:\n1) Линейный поиск\n2) Поиск с барьером\n3) Поиск по бору\n0) Закончить программу\n";

	int choice1;

	do {
		cin >> choice1;

		if (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 0) cout << "Введено неверное значение, попробуйте снова.\n";
	} while (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 0);

	Node* root=new Node();
	vector <Node2*> vec;

	cout << "Введите размер таблицы: ";
	int len;
	cin >> len;
	switch (choice1) {
	case 1: {
		for (int i = 1; i <= len; i++) {
			Node2* node = new Node2();
			node->number = to_string(i);
			vec.push_back(node);
		}
		auto start = steady_clock::now();
		auto t=linear_search(vec, to_string(len));
		auto end = steady_clock::now();
		cout << "Худший случай: " << duration_cast<microseconds>(end - start).count()<<endl;

		 auto start2 = steady_clock::now();
		auto f = linear_search(vec, to_string(len/2));
		 auto end2 = steady_clock::now();
		 cout << "Средний случай: " << duration_cast<microseconds>(end2 - start2).count()<<endl;

		 auto start3 = steady_clock::now();
		 auto fс = linear_search(vec, to_string(1));
		 auto end3 = steady_clock::now();
		 cout << "Лучший случай: " << duration_cast<microseconds>(end3 - start3).count() << endl;
		break;
	}
	case 2:
	{
		for (int i = 1; i <= len; i++) {
			Node2* node = new Node2();
			node->number = to_string(i);
			vec.push_back(node);
		}
		Node2* node = new Node2();
		node->number = to_string(len);
		auto start = steady_clock::now();
		auto t = barrier_search(vec, node);
		auto end = steady_clock::now();
		cout << "Худший случай: " << duration_cast<microseconds>(end - start).count() << endl;

		node = new Node2();
		node->number = to_string(len/2);
		auto start2 = steady_clock::now();
		auto f = barrier_search(vec, node);
		auto end2 = steady_clock::now();
		cout << "Средний случай: " << duration_cast<microseconds>(end2 - start2).count() << endl;

		node->number = to_string(1);
		auto start3 = steady_clock::now();
		auto fс = barrier_search(vec, node);
		auto end3 = steady_clock::now();
		cout << "Лучший случай: " << duration_cast<microseconds>(end3 - start3).count() << endl;
		break;
	}

	case 3: {
		for (int i = len; i <= 2 * len; i++) {
			string s = to_string(i),r="";
			;
			for (int j = 0; j < 3; j++)
				r+=s[j];
			
			add_node(r, "", "", "", root);
		}
		auto start = steady_clock::now();
		auto t = is_found(to_string(10), root);
		auto end = steady_clock::now();
		cout << "Худший случай: " << duration_cast<nanoseconds>(end - start).count() << endl;

		/*auto start2 = steady_clock::now();
		auto f = is_found(to_string(10), root);
		auto end2 = steady_clock::now();
		cout << "Средний случай: " << duration_cast<nanoseconds>(end2 - start2).count() << endl;

		auto start3 = steady_clock::now();
		auto fc = is_found(to_string(10), root);
		auto end3 = steady_clock::now();
		cout << "Лучший случай: " << duration_cast<nanoseconds>(end3 - start3).count() << endl;*/
		break;
	}
	case 0:
		return 0;
	}

	main();
}