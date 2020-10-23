#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int read_file(int x[3][3]) {
	ifstream in("condition.txt");
	if (in.is_open())
	{
		

		//Считаем матрицу из файла
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				in >> x[i][j];

		//Выведем матрицу
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				cout << x[i][j] << "\t";
			cout << "\n";
		}

		in.close();//под конец закроем файла
		return **x;
	}
	else
	{
		//Если открытие файла прошло не успешно
		cout << "Файл не знайдено.";
	}


}

int Valda(int x[3][3]){
	int min[3], max=0;
	cout << endl;

	for (int i = 0; i < 3; i++) {
		min[i] = x[i][0];
		for (int j = 0; j < 3; j++) {
			if (min[i] >= x[i][j]) {
				min[i] = x[i][j];
				//cout << "min[" << i << "] = " << min[i];
				//cout << ": [" <<i<<"][" <<j <<"] -" << x[i][j] << "\n";
			}	
		}
	}
	cout << endl << "Метод Вальда: \n";
	for (int i = 0; i < 3; i++) {
		cout << "\t" << min[i] << "\n";
	}
	//cout << endl;
	
	for (int i = 0; i < 3; i++) {
		if (max < min[i])
			max = min[i];
	}

	cout << "Найкраще рiшення: " << max << endl << endl;
	return 0;
}

int Maximum(int x[3][3]) {
	int max_a[3], max=0;
	for (int i = 0; i < 3; i++) {
		max_a[i] = x[i][0];
		for (int j = 0; j < 3; j++) {
			if (max_a[i] <= x[i][j]) {
				max_a[i] = x[i][j];
				//cout << "min[" << i << "] = " << min[i];
				//cout << ": [" <<i<<"][" <<j <<"] -" << x[i][j] << "\n";
			}
		}
	}
	cout << endl << "Максимальний: \n";
	for (int i = 0; i < 3; i++) {
		cout << "\t" << max_a[i] << "\n";
	}
	//cout << endl;

	for (int i = 0; i < 3; i++) {
		if (max < max_a[i])
			max = max_a[i];
	}
	cout << "Найкраще рiшення: " << max << endl << endl;
	return 0;
}

int Gurvica(int x[3][3]) {
	int min[3], max_a[3], max=0, gur[3];
	double coef = 0.6;

	for (int i = 0; i < 3; i++) {
		min[i] = x[i][0];
		max_a[i] = x[i][0];
		for (int j = 0; j < 3; j++) {
			if (min[i] >= x[i][j]) {
				min[i] = x[i][j];
			}
			if (max_a[i] <= x[i][j]) {
				max_a[i] = x[i][j];
			}
		}
		gur[i] = coef* min[i] + (1 - coef)*max_a[i];
	}

	cout << endl << "Метод Гурвiца: \n";
	for (int i = 0; i < 3; i++) {
		cout << "\t" << gur[i] << "\n";
	}

	for (int i = 0; i < 3; i++) {
		if (max < gur[i])
			max = gur[i];
	}
	cout << "Найкраще рiшення: " << max << endl << endl;

	return 0;
}

int Laplasa(int x[3][3]) {
	double lap[3], max = 0;
	
	for (int i = 0; i < 3; i++) {
		lap[i] = 0;
		for (int j = 0; j < 3; j++) {
			lap[i] += x[i][j];
		}
		lap[i] /= 3;
	}
	cout << endl << "Метод Лапласа: \n";
	for (int i = 0; i < 3; i++) {
		cout << "\t" << lap[i] << "\n";
	}
	for (int i = 0; i < 3; i++) {
		if (max < lap[i])
			max = lap[i];
	}
	cout << "Найкраще рiшення: " << max << endl << endl;

	return 0;
}

int Bayesa_Laplasa(int x[3][3]) {
	double p1=0.5, p2=0.35, p3=0.15, bl[3], max=0;
	for (int i = 0; i < 3; i++) {
		bl[i] = 0;
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				//cout << "bl[" << i << "] - x[" << i << "][" << j << "]-" << x[i][j] << "*" << p1 << endl;
				bl[i] += x[i][j] * p1;
				//cout << "bl[" << i << "] - "<< bl[i] << "\t";
			}
			else if (j == 1) {
				//cout << "bl[" << i << "] - x[" << i << "][" << j << "]-" << x[i][j] << "*" << p2 << endl;
				bl[i] += x[i][j] * p2;
				//cout << "bl[" << i << "] - " << bl[i] << "\t";
			}
			else
			{
				//cout << "bl[" << i << "] - x[" << i << "][" << j << "]-" << x[i][j] << "*" << p2 << endl;
				bl[i] += x[i][j] * p3;
				//cout << "bl[" << i << "] - " << bl[i] << "\t";
			}
		}
		//cout << endl;
	}
	cout << endl << "Метод Байєса-Лапласа: \n";
	for (int i = 0; i < 3; i++) {
		cout << "\t" << bl[i] << "\n";
	}
	for (int i = 0; i < 3; i++) {
		if (max < bl[i])
			max = bl[i];
	}
	cout << "Найкраще рiшення: " << max << endl << endl;

	return 0;
}

void main()
{
	setlocale(LC_ALL, "Ukrainian");
	int x[3][3];

	read_file(x);
	Valda(x);
	Maximum(x);
	Gurvica(x);
	Laplasa(x);
	Bayesa_Laplasa(x);

	system("pause");
}

