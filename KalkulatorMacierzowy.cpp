#include <iostream>

#include <iomanip>

using namespace std;

void firstmenu()
{
	//menu startowe

	cout << setw(10) << "||--------------------------------------------------------------------||" << setw(10) << endl;
	cout << setw(10) << "                      KALKULATOR MACIERZOWY 3x3                         " << setw(10) << endl;
	cout << endl;
	cout << setw(10) << "    Podaj najpierw macierz A oraz macierz B, by przejsc do dzialan.     " << setw(10) << endl;
	cout << endl;
	cout << setw(10) << "||--------------------------------------------------------------------||" << setw(10) << endl;
	cout << endl;
}

void mainmenu()
{
	//menu glowne


	cout << setw(10) << "||--------------------------------------------------------------------||   " << setw(10) << endl;
	cout << setw(10) << "                      KALKULATOR MACIERZOWY    3x3                         " << setw(10) << endl;
	cout << endl;
	cout << setw(10) << "                        Wybierz dzialanie.                                 " << setw(10) << endl;
	cout << endl;
	cout << setw(10) << "                       1. Dodawanie.                                       " << setw(10) << endl;
	cout << endl;
	cout << setw(10) << "                       2. Odejmowanie.                                     " << setw(10) << endl;
	cout << endl;
	cout << setw(10) << "                       3. Mnozenie.                                        " << setw(10) << endl;
	cout << endl;
	cout << setw(10) << "                       4. Transpozycja                                     " << setw(10) << endl;
	cout << setw(10) << "||--------------------------------------------------------------------||   " << setw(10) << endl;
	cout << endl;
}


// wyswietlanie macierzy

void seeMatrix(int m[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j == 2)
			{
				cout << setw(5) << m[i][j] << setw(5) << endl;
			}
			else
			{
				cout << setw(5) << m[i][j] << setw(5);
			}
		}
	}
}

// dodawanie 2 macierzy

void sumMatrix(int m1[3][3], int m2[3][3])
{
	int mres[3][3]{};
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			mres[x][y] = m1[x][y] + m2[x][y];
		}
	}

	seeMatrix(mres);
	
}


// dzielenie 2 macierzy

void subMatrix(int m1[3][3], int m2[3][3])
{
	int mres[3][3]{};
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			mres[x][y] = m1[x][y] - m2[x][y];
		}
	}

	seeMatrix(mres);

	
}

// transponowanie wybranej macierzy

void transMatrix(int m1[3][3])
{
	int mres[3][3]{};
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			mres[x][y] = m1[y][x];
		}
	}

	seeMatrix(mres);
	
}

// mnozenie macierzy

void multiMatrix(int m1[3][3], int m2[3][3])
{
	int mres[3][3]{};
	int res = 0;
	int counter = 0;
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			for (int z = 0; z < 3; z++)
			{
				mres[x][y] += m1[x][z] * m2[z][y];
			}
		}
	}
	seeMatrix(mres);
	
}

// sprawdza poprawnosc wyboru opcji uzytkownika, w przypadku blednej podajemy ja jeszcze raz

void validCheck(int& choice)
{
	cin >> choice;
	while (!cin || choice < 1 || choice > 4)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Podaj poprawna opcje: " << endl;
		cin >> choice;
	}
}

void matrixElCheck(int& el)
{
	while(!cin)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Podaj poprawna liczbe/cyfre: " << endl;
		cin >> el;
	}
}


int main()
{
	firstmenu();

	int matrix1[3][3]{};
	int matrix2[3][3]{};

	int el;

	cout << "MACIERZ A" << endl;
	cout << endl << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "Podaj A" << "[" << i+1 <<"]" << "[" << j + 1 << "]" << ":" << endl;
			cin >> el;
			matrixElCheck(el);
			matrix1[i][j] = el;


		}
	} 
	system("cls");

	firstmenu();

	cout << "MACIERZ B" << endl;
	cout << endl << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "Podaj B" << "[" << i + 1 << "]" << "[" << j + 1 << "]" << ":" << endl;
			cin >> el;
			matrixElCheck(el);
			matrix2[i][j] = el;
		}
	}
	system("cls");

	cout << "Podana macierz A: " << endl << endl;

	seeMatrix(matrix1);

	cout << endl;

	cout << "Podana macierz B: " << endl << endl;

	seeMatrix(matrix2);

	mainmenu();

	cout << "Wybierz opcje [ 1 - 4 ]: ";
	int choice;
	validCheck(choice);
	while (true)
	{
		if (choice == 1)
		{
			system("cls");
			cout << "Macierz A: " << endl << endl;
			seeMatrix(matrix1);
			cout << endl << endl;
			cout << "Macierz B: " << endl << endl;
			seeMatrix(matrix2);
			cout << endl << endl;
			cout << "Macierz wynikowa: " << endl << endl;
			sumMatrix(matrix1, matrix2);
			mainmenu();
			cout << "Wybierz opcje [ 1 - 4 ]: ";
			
		}
		if (choice == 2)
		{
			system("cls");
			cout << "Macierz A: " << endl << endl;
			seeMatrix(matrix1);
			cout << endl << endl;
			cout << "Macierz B: " << endl << endl;
			seeMatrix(matrix2);
			cout << endl << endl;
			cout << "Macierz wynikowa: " << endl << endl;
			subMatrix(matrix1, matrix2);
			mainmenu();
			cout << "Wybierz opcje [ 1 - 4 ]: ";
			
		}
		if (choice == 3)
		{
			system("cls");
			cout << "Macierz A: " << endl << endl;
			seeMatrix(matrix1);
			cout << endl << endl;
			cout << "Macierz B: " << endl << endl;
			seeMatrix(matrix2);
			cout << endl << endl;
			cout << "Macierz wynikowa: " << endl << endl;
			multiMatrix(matrix1, matrix2);
			mainmenu();
			cout << "Wybierz opcje [ 1 - 4 ]: ";
		}

		if (choice == 4)
		{
			system("cls");
			int ch;
			cout << "Macierz A: " << endl;
			seeMatrix(matrix1);
			cout << "Macierz B: " << endl;
			seeMatrix(matrix2);
			cout << "Wybierz jaka macierz, chcesz transponowac(1 dla A, 2 dla B): " << endl;
			cin >> ch;
			matrixElCheck(ch);
			if (ch == 1)
			{
				system("cls");

				cout << "Macierz A: " << endl << endl;
				seeMatrix(matrix1);

				cout << "Macierz B: " << endl << endl;
				seeMatrix(matrix2);

				cout << "Macierz przed dzialaniem: " << endl << endl;
				seeMatrix(matrix1);
				cout << "Macierz stransponowana: " << endl << endl;
				transMatrix(matrix1);
			}
			else if (ch == 2)
			{
				system("cls");

				cout << "Macierz A: " << endl << endl;
				seeMatrix(matrix1);

				cout << "Macierz B: " << endl << endl;
				seeMatrix(matrix2);

				cout << "Macierz przed dzialaniem: " << endl << endl;
				seeMatrix(matrix2);
				cout << endl;
				cout << "Macierz stransponowana: " << endl << endl;
				transMatrix(matrix2);
			} else
			{
				cout << "Zla opcja, sprobuj ponownie:" << endl;

			}
			mainmenu();
			cout << "Wybierz opcje [ 1 - 4 ]: ";
			validCheck(choice);
		}
		else {
			
			validCheck(choice);
		}
	}
	
	return 0;
}
