#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	srand(time (NULL));
	system("pause");
	cout << "Для того чтобы бросить кости нажмите Enter" << "\n";
	int ran1, ran2, ran3, ran4, summa1 = 0, summa2 = 0;
	ran1 = 1 + rand() % (6 - 1 + 1);
	ran2 = 1 + rand() % (6 - 1 + 1);
	ran3 = 1 + rand() % (6 - 1 + 1);
	ran4 = 1 + rand() % (6 - 1 + 1);
	cout << "Вам выпало: " << ran1 << " " << ran2 << "\n";
	cout << "Ход компьютера" << "\n";
	cout << "Ему выпало: " << ran3 << " " << ran4 << "\n";
	for (int i = 0; i <= 5; i++) {
		if (ran1 == ran2) {
			ran1 *= 2;
			ran2 *= 2;
		}
		if (ran3 == ran4) {
			ran3 *= 2;
			ran4 *= 2;
		}
		if (ran1 + ran2 > ran3 + ran4) {
			cout << "Итого вы выиграли:";
			summa1++;
			cout << " счёт " << summa1 << " : " << summa2 << "\n";
		}
		if (ran1 + ran2 < ran3 + ran4) {
			cout << "Итого вы проиграли:";
			summa2++;
			cout << " счёт " << summa1 << " : " << summa2 << "\n";
		}
		if ((ran1 + ran2) == (ran3 + ran4)) {
			cout << "Итого ничья:";
			cout << " счёт " << summa1 << " : " << summa2 << "\n";
		}
		if (summa1 == 3 || summa2 == 3) break;

		system("pause");
		
		ran1 = 1 + rand() % (6 - 1 + 1);
		ran2 = 1 + rand() % (6 - 1 + 1);
		ran3 = 1 + rand() % (6 - 1 + 1);
		ran4 = 1 + rand() % (6 - 1 + 1);
		cout << "Вам выпало: " << ran1 << " " << ran2 << "\n";
		cout << "Ход компьютера" << "\n";
		cout << "Ему выпало: " << ran3 << " " << ran4 << "\n";
	}
}