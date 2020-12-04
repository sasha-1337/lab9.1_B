#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>

using namespace std;

enum Speciality { PROGRAMMER, ENGINEER, ELECTRICIAN };
string specStr[] = { "програміст", "інженер", "електрик" };
struct Student
{
	string prizv;
	unsigned kurs;
	Speciality spec;
	int phisic;
	int math;
	int inform;
	int pedagogy;
	int NumMeth;
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
int goodMARK(const int N, int mark);
float midMark(const int N, int mark_1, int mark_2, int mark_3);
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть кількість студентів: "; cin >> N;
	Student* p = new Student[N];

	Create(p, N);
	Print(p, N);

	return 0;
}

void Create(Student* p, const int N)
{
	int spec, midMARK;
	for (int i = 0; i < N; i++)
	{
		cout << " Студент № " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();

		cout << " Прізвище: "; getline(cin, p[i].prizv);
		cout << " Курс: "; cin >> p[i].kurs;
		cout << " Cпеціальність (0 - програміст, 1 - інженер, 2 - електрик): "; cin >> spec;
		p[i].spec = (Speciality)spec;
		switch (p[i].spec)
		{
		case PROGRAMMER:
			cout << " Фізика "; cin >> p[i].phisic;
			cout << " Математика "; cin >> p[i].math;
			cout << " інформатика "; cin >> p[i].inform;
			break;
		case ENGINEER:
			cout << " Фізика "; cin >> p[i].phisic;
			cout << " Математика "; cin >> p[i].math;
			cout << " Чисельні методи "; cin >> p[i].NumMeth;
			break;
		case ELECTRICIAN:
			cout << " Фізика "; cin >> p[i].phisic;
			cout << " Математика "; cin >> p[i].math;
			cout << " Педагогіка "; cin >> p[i].pedagogy;
			break;
		}
		cout << endl;
	}
}

void Print(Student* p, const int N)
{
	cout << "================================================================================================================"
		<< endl;
	cout << "| № | Прізвище | Курс | Спеціальність | Фізика | Математика | Інформатика | Чисельні методи | Педагогіка | С/б |"
		<< endl;
	cout << "----------------------------------------------------------------------------------------------------------------"
		<< endl;

	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(9) << left << p[i].prizv
			<< "| " << setw(4) << right << p[i].kurs << " "
			<< "| " << setw(14) << left << specStr[p[i].spec];
		switch (p[i].spec)
		{
		case PROGRAMMER:
			cout << "|" << setw(8) << setprecision(2) << fixed << p[i].phisic << "|" << p[i].math << setw(12) << right 
				<< "|" << p[i].inform << setw(13) << "|" << setw(18) << "|" << setw(13) << "|" 
				<< setprecision(2) << midMark(N, p[i].phisic, p[i].math, p[i].inform) << " |" << endl;
			break;
		case ENGINEER:
			cout << "|" << setw(8) << setprecision(2) << fixed << p[i].phisic << "|" << p[i].math << setw(12) << right << "|"
				<< setw(14) << "|" << p[i].NumMeth << setw(17) << "|" << setw(13) << "|"
				<< setprecision(2) << midMark(N, p[i].phisic, p[i].math, p[i].NumMeth) << " |" << endl;
			break;
		case ELECTRICIAN:
			cout << "|" << setw(8) << setprecision(2) << fixed << p[i].phisic << "|" << p[i].math << setw(12) << right << "|" 
				<< setw(14) << "|" << setw(18) << "|" << p[i].pedagogy << setw(12) << "|" 
				<< setprecision(2) << midMark(N, p[i].phisic, p[i].math, p[i].pedagogy) << " |" << endl;
			break;
		}
	}
	cout << "================================================================================================================" << endl;
	cout << endl;

	int count_Phisic = 0, count_Math = 0, count_IT = 0, count_NumMeth = 0, count_Pedagogy = 0;
	for (int i = 0; i < N; i++) 
	{
		count_Phisic += goodMARK(N, p[i].phisic);
		count_Math += goodMARK(N, p[i].math);
		count_IT += goodMARK(N, p[i].inform);
	    count_NumMeth += goodMARK(N, p[i].NumMeth);
		count_Pedagogy += goodMARK(N, p[i].pedagogy);
	}

	cout << " Таблиця: кількість оцінок 'добре' з кожного предмету." << endl;
	cout << "=======================" << endl;
	cout << "|      Фізика     | " << count_Phisic << " |" << endl;
	cout << "-----------------------" << endl;
	cout << "|    Математика   | " << count_Math << " |" << endl;
	cout << "-----------------------" << endl;
	cout << "|   Інформатика   | " << count_IT << " |" << endl;
	cout << "-----------------------" << endl;
	cout << "| Чисельні методи | " << count_NumMeth << " |" << endl;
	cout << "-----------------------" << endl;
	cout << "|    Педагогіка   | " << count_Pedagogy << " |" << endl;
	cout << "=======================" << endl;
}

int goodMARK(const int N, int mark) {// лічильник гарних оцінок
	int count = 0;
	(mark == 4 || mark == 5) ? count++ : count = 0;
	return count;
}

float midMark(const int N, int mark_1, int mark_2, int mark_3) {
	float midMARK = 0;
	for (int i = 0; i < N; i++)
		midMARK = (mark_1 + mark_2 + mark_3) / 3.; // розрахунок середнього балу
	return midMARK;
}