//File34. Дан файл целых чисел. Удалить из него все отрицательные числа.
#include<iostream>
#include<fstream>
#include <iomanip>

using namespace std;

int main() {

	const int n = 10;
	int array[n] = { 1, -1, 2, 4, 5, 6, -7, -8, 9, 10 };
	int readArray[n];

	ofstream f1("txt.bin", ios_base::binary);
	f1.write((char*)&array[0], sizeof(int)*n);
	//for (int i = 0; i < n; i++) {
	//	cout << array[i] << " ";
	//	f1.write((char*)&array[i], sizeof(int));
	//}
	f1.close();

	cout << endl;

	ifstream f2("txt.bin", ios_base::binary);
	//std::cout << std::setprecision(3);
	int value;
	int size = 0;
	while (!f2.eof()) {
		f2.read((char*)&value, sizeof(int));
		if (f2.fail())
			break;
		if (value > 0 ) {
			readArray[size] = value;
			cout << readArray[size] << " ";
			size++;
		}
	}
	cout << endl;
	cout << "Размер массива: " << size << endl;
	f2.close();

	ofstream f3("txt.bin", ios_base::binary);
	for (int i = 0; i < size; i++) {
		cout << readArray[i] << " ";
		f3.write((char*)&readArray[i], sizeof(int));
	}
	f3.close();
}
