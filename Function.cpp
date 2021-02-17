#include "Function.h"

void Mat_Smejnocti(int** (&arr), int(&n))
{
	cout << "Введите количество вершин: "; cin >> n;
	arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
	}

	cout << endl << "Заполните матрицу" << endl
		<< "-------------------" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Заполните данные о [" << i + 1 << "] вершине" << endl;
		for (int j = 0; j < n; j++)
		{
			cin >> arr[j][i];
		}
		system("cls");
	}
}
void Mat_Intindentosti (int**(&arr), int(&n),int (&m))
{
	cout << "Введите количество вершин: "; cin >> n;
	cout << "Введите количество рёбер: "; cin >> m;
	arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	cout << endl << "Заполните матрицу построчно" << endl;
	for (int i = 0; i < m; i++)
	{
		system("cls");
		cout << "Дуга (" << i + 1 << ")" << endl;
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
}
void Spisok_Smej(vector<int>** (&vert), int(&n))
{
	cout << "Введите количество вершин:"; cin >> n;
	vert = new vector<int> * [n];

	for (int i = 0; i < n; i++)
	{
		cout << "Введите вершины, смежные " << i + 1 << " вершине" << endl;;
		int x = -1;
		vert[i] = new vector<int>;
		while (x != 0)
		{
			cin >> x;
			vert[i]->push_back(x);
		}
	}
}
void MatSM_SpisokSmej(int** arr, vector<int>** (&vert), int n)
{
	vert = new vector<int>*[n];
	for (int i = 0; i < n; i++)
	{
		vert[i] = new vector<int>;
		for (int j = 0; j < n; j++)
		{
			if (arr[j][i] == -1)
			{
				vert[i]->push_back(j+1);
			}
		}
		vert[i]->push_back(0);
	}
}
void SpisokSmej_MatSM(vector<int>** vert, int** (&arr), int n)
{
	arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		vector<int>::iterator it = vert[i]->begin();
		for (int j = 0; j < n; j++)
		{
			if (*it == j + 1)
			{
				arr[i][j] = 1;
				arr[j][i] = -1;
				if (*(it + 1) != 0) { it++; }
				else continue;
			}
		}
	}
}
void MatIntident_SpisokSmej(int ** arr,vector<int>**(&vert),int m,int n)
{
	vert = new vector<int> * [n];
	for (int i = 0; i < n; i++)
	{
		vert[i] = new vector<int>;
	}
	for (int i = 0; i < m; i++)
	{
		int k = -1;
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == -1)
			{
				k = j;
			}
			if (k != -1 && arr[i][j] == 1)
			{
				vert[k]->push_back(j + 1);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		vert[i]->push_back(0);
	}
}
void SpisokSmej_MatIntident(vector<int>** vert, int** (&arr), int(&m), int n)
{
	for (int i = 0; i < n; i++)
	{
		m += vert[i]->size()-1;
	}
	arr = new int* [m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 0;
		}
	}
	vector<int>::iterator it;
	int k = 0;
	for (int i = 0; i < m;)
	{
		it = vert[k]->begin();
		while (*(it) != 0)
		{
			arr[i][k] = -1;
			arr[i][(*it)-1] = 1;
			it++;
			i++;
		}
		k++;
	}
}
void Print_spisok_smejnosti(vector<int>** vert, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << " - ";
		for (vector<int>::iterator it = vert[i]->begin(); it < vert[i]->end(); it++)
		{
			if (it < vert[i]->end()-1)
			{
				cout << *it << ",";
			}
			else cout << *it << endl;
		}
	}
}
void Print_Mat(int** arr, int n, int m)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "  ";
		}
		cout << endl;
	}
}
void Menu(int& k1)
{
	setlocale(LC_ALL, "Rus");
	cout << "Выберите действие" << endl
		<< "--------------------------------" << endl
		<< "1. Ввод матрицы смежности" << endl
		<< "2. Ввод матрицы инценденстности" << endl
		<< "3. Ввод списока смежности" << endl
		<< "4. Перевод из матрицы смежности в список смежности" << endl 
		<< "5. Перевод из списка смежности в матрицу смежности" << endl 
		<< "6. Перевод из матрицы инцидентности в список смежности" << endl 
		<< "7. Перевод из списка смежности в матрицу инцидентности" << endl 
		<< "8. Вывод списка смежности" << endl 
		<< "9. Вывод матрицы смежности" << endl 
		<< "10. Вывод матрицы инценденстности" << endl << endl 
		<< "Ваш выбор: "; cin >> k1;
}