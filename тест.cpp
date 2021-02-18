#include "Function.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	int k = -1, n = 0, m = 0; //выбор меню, вершины, ребра
	vector<int>** vertex = nullptr; // список смежности
	int** srr = nullptr; // матрица смежности
	int** irr = nullptr; // матрица инцидентности 
	while (k != 0)
	{
		Menu(k);
		switch (k)
		{
		case 1: // Матрица смежности
			system("cls");
			if (srr==nullptr)
			{
				Mat_Smejnocti(srr,n);
				system("cls");
				cout << "Граф заполнен" << endl;
			}
			else cout << "Ошибка! Заполните граф" << endl;
			break;
		case 2: // Матрица инцидентности
			system("cls");
			if (irr==nullptr)
			{
				Mat_Intindentosti(irr, n, m);
				system("cls");
				cout << "Граф заполнен" << endl;
			}
			else cout << "Ошибка! Заполните граф" << endl;
			break;
		case 3: // Список смежности
			system("cls");
			if (vertex==nullptr)
			{
				Spisok_Smej(vertex, n);
				system("cls");
				cout << "Граф заполнен" << endl;
			}
			break;
		case 4: // Из матрицы смежности в список смежности
			system("cls");
			if (srr != nullptr && vertex==nullptr)
			{
				MatSM_SpisokSmej(srr, vertex, n);
				system("cls");
				cout << "Конвертация прошла успешно" << endl;
			}
			else cout << "Ошибка! Заполните граф"<<endl;
			break;
		case 5: // Из списка смежности в матрицу смежности 
			system("cls");
			if (vertex != nullptr && srr == nullptr )
			{
				SpisokSmej_MatSM(vertex, srr, n);
				system("cls");
				cout << "Конвертация прошла успешно" << endl;
			}
			else cout << "Ошибка! Заполните граф" << endl;
			break;
		case 6: // Из матрицы инцидентности в список смежности 
			system("cls");
			if (irr!= nullptr && vertex == nullptr)
			{
				MatIntident_SpisokSmej(irr, vertex, m, n);
				system("cls");
				cout << "Конвертация прошла успешно" << endl;
			}
			else cout << "Ошибка! Заполните граф" << endl;
			break;
		case 7: // Из списка смежности в матрицу инцидентности
			system("cls");
			if (vertex != nullptr && irr == nullptr)
			{
				SpisokSmej_MatIntident(vertex, irr, m, n);
				system("cls");
				cout << "Конвертация прошла успешно" << endl;
			}
			else cout << "Ошибка! Заполните граф" << endl;
			break;
		case 8: // Вывод списка смежности

			system("cls");
			if (vertex != nullptr)
			{
				Print_spisok_smejnosti(vertex, n);
			}
			else cout << "Ошибка! Заполните граф" << endl;
			break;
		case 9: // Вывод матрицы смежности
			system("cls");
			if (srr != nullptr)
			{
				Print_Mat(srr, n, n);
			}
			else cout << "Ошибка! Заполните граф" << endl;
			break;
			
		case 10: // Вывод матрицы инцидентности
			system("cls");
			if (irr != nullptr)
			{
				Print_Mat(irr, m, n);
			}
			else cout << "Ошибка! Заполните граф" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
