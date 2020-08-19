#pragma once
#include <string>
using namespace std;

struct sale {
	int code;
	char desc[30];
	int amount;
	float price;
};

struct calification {
	int docket;
	char name[30];
	int gradeCode;
	float note;
};

struct approved {
	int docket;
	char name[30];
	int gradeCode;
};
#ifndef Funciones
#define Funciones

//vec: El vector en si.
//n: Cantidad de elementos totales que puede almacenar el vector.
//len: cantidad de elementos reales que hay dentro del vector actualmente.
//v: valor a ser agregado.

//Ejercicio 1
void exerciseOne();
int searchItem(sale arr[], int len, int code);
void initializeFiles();
void orderByAmount(sale arr[], int len);

//Ejercicio 2

void exerciseTwo();
void initializeStudents();
void insertApproved(approved students[], int lenApproved);

//Ejercicio 3
void exerciseThree(int arrayA[], int arrayB[], int& lenA, int& lenB, int& lenC, int arrayC[]);

//Ejercicio 4
int exerciseFour(int day, int month, int year);
bool isLeapYear(int year);
int calculateX(int month, int year);
string getDayName(int day);

#endif