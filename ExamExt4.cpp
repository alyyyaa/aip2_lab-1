//На вход подаются сведения о клиентах фитнес-центра. В первой строке указывается целое число N, а каждая из последующих N строк имеет формат
//<Номер месяца> <Год> <Код клиента> <Продолжительность занятий(в часах)> Все данные целочисленные.
//Найти строку исходных данных с максимальной продолжительностью занятий.Вывести эту продолжительность, а также соответствующие ей год и номер месяца.
//Если имеется несколько строк с максимальной продолжительностью, то вывести данные, соответствующие самой поздней дате.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct FitnessCentre {
	int userID;
	int month;
	int year;
	int trainingTime;

	void printStruct() {
		cout << this->userID << " " << this->month << " " << this->year << " " << this->trainingTime << endl;
	}
	double transformDate() {
		return (double(this->year) + double(this->month) / 12);
	}
};

bool readStructFromTextFile(string file, FitnessCentre* pUsers, int n) {
	ifstream in(file);
	if (!in.is_open())
		return false;
	for (int i = 0; i < n; i++)
	{
		(in >> pUsers->userID >> pUsers->month >> pUsers->year >> pUsers->trainingTime);
		pUsers++;
	}
	in.close();
	return true;
}

int main(){
	const int n = 7;
	FitnessCentre sFileUser[n];
	FitnessCentre sUser[n] = {
		{56, 4, 2000, 10},
		{57, 5, 2001, 11},
		{58, 4, 2005, 12},
		{59, 4, 2006, 13},
		{60, 4, 2003, 14},
		{61, 4, 2007, 15},
		{62, 4, 2008, 15} };
	FitnessCentre* pChoice = &sUser[0];
	for (int i = 1; i < n; i++) {
		if (pChoice->trainingTime < sUser[i].trainingTime) {
			pChoice = &sUser[i];
		}
		else if (pChoice->trainingTime == sUser[i].trainingTime) {
			if ( pChoice->transformDate() < sUser[i].transformDate() )
				pChoice = &sUser[i];
		}
	}
	pChoice->printStruct();

	if (readStructFromTextFile("C:\\Users\\Alena\\Desktop\\1 лаб\\ExamExt4\\ExamExt4\\a.dat.txt", &sFileUser[0], 7) == false)
		cout << "Не удалось открыть файл";
	pChoice = &sFileUser[0];
	for (int i = 1; i < n; i++) {
		sFileUser[i].printStruct();
		if (pChoice->trainingTime < sFileUser[i].trainingTime) {
			pChoice = &sFileUser[i];
		}
		else if (pChoice->trainingTime == sFileUser[i].trainingTime) {
			if (pChoice->transformDate() < sFileUser[i].transformDate())
				pChoice = &sFileUser[i];
		}
	}
	pChoice->printStruct();
}

