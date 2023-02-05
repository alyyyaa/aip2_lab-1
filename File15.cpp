//Дан файл вещественных чисел. Найти сумму его элементов с четными номерами.
#include<iostream>
#include<fstream>
#include <iomanip>

using namespace std;

int main() {

	const int n = 10;
	double array[n] = { 1.1, 2.2, 3.4, 5.5, 6.6, 7.7, 6.4, 7.6, 9.8, 3.9 };
	double readArray[n];

	ofstream f1("txt.bin", ios_base::binary);
	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
		f1.write((char*)&array[i], sizeof(double));
	}
	f1.close();

	cout << endl;

	double sum = 0;
	ifstream f2("txt.bin", ios_base::binary);
	std::cout << std::setprecision(3);
	for (int i = 0; i < n; i++) {
		f2.read((char*)&readArray[i], sizeof(double));
		if ((i+1) % 2 == 0)
			sum = sum + readArray[i];
	}
	cout << sum;
	f2.close();
}
