#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

//Prototipes of functions
void Menu(int& k1);
void Mat_Smejnocti(int** (&arr), int(&n));
void Mat_Intindentosti(int** (&arr), int(&n), int(&m));
void Spisok_Smej(vector<int>** (&vert), int(&n));
void MatSM_SpisokSmej(int** arr, vector<int>** (&vert), int n);
void SpisokSmej_MatSM(vector<int>** vert, int** (&arr), int n);
void MatIntident_SpisokSmej(int** arr, vector<int>** (&vert), int m,int n);
void SpisokSmej_MatIntident(vector<int>** vert, int** (&arr), int(&m), int n);
void Print_spisok_smejnosti(vector<int>** vert, int n);
void Print_Mat(int** arr, int m, int n);