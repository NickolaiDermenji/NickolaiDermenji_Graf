#include "Function.h"

void Mat_Smejnocti(int** (&arr), int(&n))
{
	cout << "������� ���������� ������: "; cin >> n;
	arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
	}

	cout << endl << "��������� �������" << endl
		<< "-------------------" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "��������� ������ � [" << i + 1 << "] �������" << endl;
		for (int j = 0; j < n; j++)
		{
			cin >> arr[j][i];
		}
		system("cls");
	}
}
void Mat_Intindentosti (int**(&arr), int(&n),int (&m))
{
	cout << "������� ���������� ������: "; cin >> n;
	cout << "������� ���������� ����: "; cin >> m;
	arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	cout << endl << "��������� ������� ���������" << endl;
	for (int i = 0; i < m; i++)
	{
		system("cls");
		cout << "���� (" << i + 1 << ")" << endl;
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
}
void Spisok_Smej(vector<int>** (&vert), int(&n))
{
	cout << "������� ���������� ������:"; cin >> n;
	vert = new vector<int> * [n];

	for (int i = 0; i < n; i++)
	{
		cout << "������� �������, ������� " << i + 1 << " �������" << endl;;
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
	cout << "�������� ��������" << endl
		<< "--------------------------------" << endl
		<< "1. ���� ������� ���������" << endl
		<< "2. ���� ������� ���������������" << endl
		<< "3. ���� ������� ���������" << endl
		<< "4. ������� �� ������� ��������� � ������ ���������" << endl 
		<< "5. ������� �� ������ ��������� � ������� ���������" << endl 
		<< "6. ������� �� ������� ������������� � ������ ���������" << endl 
		<< "7. ������� �� ������ ��������� � ������� �������������" << endl 
		<< "8. ����� ������ ���������" << endl 
		<< "9. ����� ������� ���������" << endl 
		<< "10. ����� ������� ���������������" << endl << endl 
		<< "��� �����: "; cin >> k1;
}