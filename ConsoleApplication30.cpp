
#include <iostream>
#include <ctime>

using namespace std;

#define tab "\t"
int main();
void Choise_columns(int**&arr, int& m, int& n);

//////////////////////////////////////////////////////////////////////////////////   Заготовленные функции

void ShowArrDuo(int**& arr, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}

}
void RandArrDuo(int**& arr, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 50;
		}

	}
}

//////////////////////////////////////////////////////////////////////////////////   Функции для работы со строками массива

void Arr_row_delete_index(int**& arr, int& m, int& n, int index)
{
	int** arr_copy = new int* [m - 1]{};
	for (int i = 0; i < m - 1; i++)
	{
		i < index ? arr_copy[i] = arr[i] : arr_copy[i] = arr[i + 1];
	}
	delete[] arr;
	arr = arr_copy;
	m--;
	
}
void Arr_row_push_index(int**& arr, int& m, int& n, int index)
{

	int** arr_copy = new int* [m + 1]{};
	arr_copy[index] = new int [n] {};
	for (int i = 0; i < m; i++)
	{
		i < index ? arr_copy[i] = arr[i] : arr_copy[i+1] = arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		arr_copy[index][i] = rand() % 50;
	}
	delete[] arr;
	arr = arr_copy;
	m++;

}
void Choise_row(int**& arr, int& m, int& n)
{
	system("cls");
	ShowArrDuo(arr, m, n);
	cout << endl << endl;
	cout << "Выберите действие с двумерным массивом\n"
		<< "1) Добавить строку в конец\n"
		<< "2) Добавить строку в начало\n"
		<< "3) Удалить строку в конце\n"
		<< "4) Удалить строку в начале\n"
		<< "5) Удалить строку по индексу\n"
		<< "6) Добавить строку по индексу\n"
		<< "7) Пересобрать массив\n"
		<< "8) Вернуться в начало программы\n"
		<< "9) Перейти к работе с столбцами массива\n"
		<< "10) Закрыть программу\n\n";

	int a = 0; cin >> a;
	system("cls");
	switch (a)
	{
	case 1:
	{
		Arr_row_push_index(arr, m, n, m);
		Choise_row(arr, m, n);
	}
	case 2:
	{
		Arr_row_push_index(arr, m, n, 0);
		Choise_row(arr, m, n);
	}
	case 3:
	{
		Arr_row_delete_index(arr, m, n, m);
		Choise_row(arr, m, n);
	}
	case 4:
	{
		Arr_row_delete_index(arr, m, n, 0);
		Choise_row(arr, m, n);
	}
	case 5:
	{

		int index = -1;
		while (index > m-1 || index < 0)
		{		
			ShowArrDuo(arr, m, n);
		    cout << "Введите индекс удаляемого столбца\n";
			cin >> index;
			system("cls");
		}
		Arr_row_delete_index(arr, m, n, index);
		Choise_row(arr, m, n);
	}
	case 6:
	{

		int index = -1;
		while (index > m-1 || index < 0)
		{
	     	ShowArrDuo(arr, m, n);
		    cout << "Введите индекс добавляемого столбца\n";
			cin >> index;
			system("cls");
		}
		Arr_row_push_index(arr, m, n, index);
		Choise_row(arr, m, n);
	}
	case 7:
	{
		RandArrDuo(arr, m, n);
		Choise_row(arr, m, n);
	}
	case 8:
	{
		for (int i = 0; i < m; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
		main();
	}
	case 9:
	{
		Choise_columns(arr, m, n);
	}
	case 10:
	{
		exit(0);
	}
	}

}

///////////////////////////////////////////////////////////////////////////////      Функции для работы со столбцами массива

void Arr_columns_push_index(int**& arr, int& m, int& n, int index)
{
	int** arr_copy = new int* [m]{};
	for (int i = 0; i < m; i++)
	{
		arr_copy[i] = new int [n+1] {};
		for (int j = 0; j < n+1; j++)
		{
			j < index ? arr_copy[i][j] = arr[i][j] : arr_copy[i][j + 1] = arr[i][j];
			
			            
		}
		delete[] arr[i];
	}
	delete[] arr;

	for (int i = 0; i < m; i++)
	{
		arr_copy[i][index] = rand() % 50;
	}
	
	arr = arr_copy;
	n++;
}
void Arr_columns_delete_index(int**& arr, int& m, int& n, int index)
{
	int** arr_copy = new int* [m] {};
	for (int i = 0; i < m; i++)
	{
		arr_copy[i] = new int[n - 1]{};
		for (int j = 0; j < n - 1; j++)
		{
			j < index ? arr_copy[i][j] = arr[i][j] : arr_copy[i][j] = arr[i][j + 1];
		}
		delete[] arr[i];
	}
	delete[] arr;
	arr = arr_copy;
	n--;
}
void Choise_columns(int**& arr, int& m, int& n)
{
	system("cls");
	ShowArrDuo(arr, m, n);
	cout << endl << endl;
	cout << "Выберите действие с двумерным массивом\n"
		<< "1) Добавить столбец в конец\n"
		<< "2) Добавить столбец в начало\n"
		<< "3) Удалить столбец в конце\n"
		<< "4) Удалить столбец в начале\n"
		<< "5) Удалить столбец по индексу\n"
		<< "6) Добавить столбец по индексу\n"
		<< "7) Пересобрать массив\n"
		<< "8) Вернуться в начало программы\n"
		<< "9) Перейти к работе со строками массива\n"
		<< "10) Закрыть программу\n\n";


	int a = 0; cin >> a;
	system("cls");
	switch (a)
	{
	case 1:
	{
		Arr_columns_push_index(arr, m, n, n);
		Choise_columns(arr, m, n);
	}
	case 2:
	{
		Arr_columns_push_index(arr, m, n, 0);
		Choise_columns(arr, m, n);
	}
	case 3:
	{
		Arr_columns_delete_index(arr, m, n, n);
		Choise_columns(arr, m, n);
	}
	case 4:
	{
		Arr_columns_delete_index(arr, m, n, 0);
		Choise_columns(arr, m, n);
	}
	case 5:
	{
		int index = -1;
		while (index > n-1 || index < 0)
		{		
			ShowArrDuo(arr, m, n);
			cout << "Введите индекс удаляемого столбца\n";
			cin >> index;
			system("cls");
		}
		Arr_columns_delete_index(arr, m, n, index);
		Choise_columns(arr, m, n);
	}
	case 6:
	{

        int index = -1;
		while (index > n-1 || index < 0)
		{
		   	 ShowArrDuo(arr, m, n);
		     cout << "Введите индекс добавляемого столбца\n";
			 cin >> index;
			 system("cls");
		}
		Arr_columns_push_index(arr, m, n, index);
		Choise_columns(arr, m, n);
	}
	case 7:
	{
		RandArrDuo(arr, m, n);
		Choise_columns(arr, m, n);
	}
	case 8:
	{
		for (int i = 0; i < m; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
		main();
	}
	case 9:
	{
		Choise_row(arr, m, n);
	}
	case 10:
	{
		exit(0);
	}
	}

}

//////////////////////////////////////////////////////////////////////////////       Главный switch

void Choise_main(int**& arr, int& m, int& n)
{
	system("cls");
	ShowArrDuo(arr, m, n);
	cout << "\n\n1)Изменять строки массива\n2)Изменять столбцы массива\n";
	int a = 0; cin >> a;
	switch (a)
	{
	case 1:
		{
			Choise_row(arr,m,n);
		}
	case 2:
	    {
		Choise_columns(arr, m, n);
	    }
	}
}

//////////////////////////////////////////////////////////////////////////////        main()
int main()
{
	setlocale(LC_ALL, "ru");

	cout << "Введите строки\n";
	int m = 0; cin >> m;
	cout << "Введите столбцы\n";
	int n = 0; cin >> n;
	system("cls");

	int** arr = new int* [m] {};
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int [n] {};
	}
	
    RandArrDuo(arr, m, n);
	Choise_main(arr, m, n);
}