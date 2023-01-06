#include <iostream>

#include <iomanip>

using namespace std;

void firstmenu()
{
	//menu startowe

	cout << setw(10) << "||--------------------------------------------------------------------||" << setw(10) << endl;
	cout << setw(10) << "                      KALKULATOR MACIERZOWY 3x3                        " << setw(10) << endl;
	cout << endl;
	cout << setw(10) << "    Podaj najpierw macierz A oraz macierz B, by przejsc do dzialan.  " << setw(10) << endl;
	cout << endl;
	cout << setw(10) << "||--------------------------------------------------------------------||" << setw(10) << endl;
	cout << endl;
}

void mainmenu()
{
	//menu glowne


	cout << "||--------------------------------------------------------------------||" << endl;
	cout << "                      KALKULATOR MACIERZOWY    3x3                         " << endl;
	cout << endl;
	cout << "                        Wybierz dzialanie.                              " << endl;
	cout << endl;
	cout << "                       1. Dodawanie.                                      " << endl;
	cout << endl;
	cout << "                       2. Odejmowanie.                                      " << endl;
	cout << endl;
	cout << "                       3. Mnozenie.                                      " << endl;
	cout << endl;
	cout << "                       4. Transpozycja                                     " << endl;
	cout << "||--------------------------------------------------------------------||" << endl;
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

int sumMatrix(int m1[3][3], int m2[3][3])
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

	return mres[3][3];
}


// dzielenie 2 macierzy

int subMatrix(int m1[3][3], int m2[3][3])
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

	return mres[3][3];
}

// transponowanie wybranej macierzy

int transMatrix(int m1[3][3])
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
	return mres[3][3];
}

// mnozenie macierzy

int multiMatrix(int m1[3][3], int m2[3][3])
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
	return mres[3][3];
}


int main()
{
	firstmenu();

	int matrix1[3][3]{};
	int matrix2[3][3]{};

	cout << "MACIERZ A" << endl;
	cout << endl << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "Podaj a" << i + 1 << j + 1 << ":" << endl;
			cin >> matrix1[i][j];
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
			cout << "Podaj b" << i + 1 << j + 1 << ":" << endl;
			cin >> matrix2[i][j];
		}
	}
	system("cls");

	cout << "Podana macierz A: " << endl;

	seeMatrix(matrix1);

	cout << endl;

	cout << "Podana macierz B: " << endl;

	seeMatrix(matrix2);

	mainmenu();
	int choice;
	cin >> choice;

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
			break;
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
			break;
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
			break;
		}

		if (choice == 4)
		{
			system("cls");
			string ch;
			cout << "Macierz A: " << endl;
			seeMatrix(matrix1);
			cout << "Macierz B: " << endl;
			seeMatrix(matrix2);
			cout << "Wybierz jaka macierz, chcesz transponowac(A lub B): " << endl;
			cin >> ch;
			if (ch == "A" || ch == "a")
			{
				cout << "Macierz przed dzialaniem: " << endl << endl;
				seeMatrix(matrix1);
				cout << "Macierz stransponowana: " << endl << endl;
				transMatrix(matrix1);
			}
			if (ch == "B" || ch == "b")
			{
				cout << "Macierz przed dzialaniem: " << endl;
				seeMatrix(matrix2);
				cout << "Macierz stransponowana: " << endl;
				transMatrix(matrix2);
			} else
			{
				cout << "Zly wybor" << endl;
				
			}

			break;
		}
		cout << "Podana opcja nie istnieje, sprobuj jeszcze raz." << endl;
		cin >> choice;
	}

	return 0;
}
