#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Funciones.hpp"
#include "Vectores.hpp"
#include <string>



using namespace std;

//Ejercicio 1



void exerciseOne() {

	initializeFiles();

	FILE* branchOne = fopen("branchOne.dat", "rb");
	FILE* branchTwo = fopen("branchTwo.dat", "rb");
	sale salesUnion[100] = {};
	sale saleOne;
	sale saleTwo;
	int lenSales = 0;
	int totalBranchOne = 0;
	int totalBranchTwo = 0;
	int pos = 0;

	fread(&saleOne, sizeof(sale), 1, branchOne);
	fread(&saleTwo, sizeof(sale), 1, branchTwo);

	while (!feof(branchOne)) {
		totalBranchOne += saleOne.amount * saleOne.price;
		salesUnion[lenSales] = saleOne;
		lenSales++;
		fread(&saleOne, sizeof(sale), 1, branchOne);
	}

	while (!feof(branchTwo)) {
		totalBranchTwo += saleTwo.amount * saleTwo.price;
		pos = searchItem(salesUnion,lenSales,saleTwo.code);
		if (pos == -1) {
			salesUnion[lenSales] = saleTwo;
			lenSales++;
		}
		else {
			salesUnion[pos].amount += saleTwo.amount;
		}
		
		fread(&saleTwo, sizeof(sale), 1, branchTwo);
	}

	fclose(branchOne);
	fclose(branchTwo);

	orderByAmount(salesUnion, lenSales);

	cout << "\nLos tres productos mas vendidos son:" << endl;
	cout << "Codigo: " << salesUnion[0].code << " / Nombre: " << salesUnion[0].desc << " / Cantidad: " << salesUnion[0].amount << " / Precio: " << salesUnion[0].price << endl;
	cout << "Codigo: " << salesUnion[1].code << " / Nombre: " << salesUnion[1].desc << " / Cantidad: " << salesUnion[1].amount << " / Precio: " << salesUnion[1].price << endl;
	cout << "Codigo: " << salesUnion[2].code << " / Nombre: " << salesUnion[2].desc << " / Cantidad: " << salesUnion[2].amount << " / Precio: " << salesUnion[2].price << endl;
	cout << "\n";

	if (totalBranchOne > totalBranchTwo) {
		cout << "La sucursal que mas recaudó fue la sucursal 1. \n" << endl;
	}
	else if (totalBranchOne < totalBranchTwo) {
		cout << "La sucursal que mas recaudó fue la sucursal 2. \n" << endl;
	}
	else {
		cout << "Las dos sucursales recaudaron lo mismo. \n" << endl;
	}

}

void initializeFiles() {
	FILE* branchOne = fopen("branchOne.dat", "wb");
	FILE* branchTwo = fopen("branchTwo.dat", "wb");

	sale sale;

	sale.code = 1;
	strcpy(sale.desc, "Martillo");
	sale.amount = 7;
	sale.price = 20;
	fwrite(&sale, sizeof(sale), 1, branchOne);

	sale.code = 2;
	strcpy(sale.desc, "Mouse");
	sale.amount = 20;
	sale.price = 10;
	fwrite(&sale, sizeof(sale), 1, branchOne);

	sale.code = 3;
	strcpy(sale.desc, "Teclado");
	sale.amount = 5;
	sale.price = 223;
	fwrite(&sale, sizeof(sale), 1, branchOne);

	sale.code = 4;
	strcpy(sale.desc, "Computadora");
	sale.amount = 53;
	sale.price = 5;
	fwrite(&sale, sizeof(sale), 1, branchOne);

	sale.code = 1;
	strcpy(sale.desc, "Martillo");
	sale.amount = 70;
	sale.price = 20;
	fwrite(&sale, sizeof(sale), 1, branchTwo);

	sale.code = 5;
	strcpy(sale.desc, "Bowl");
	sale.amount = 5;
	sale.price = 100;
	fwrite(&sale, sizeof(sale), 1, branchTwo);

	sale.code = 3;
	strcpy(sale.desc, "Teclado");
	sale.amount = 15;
	sale.price = 223;
	fwrite(&sale, sizeof(sale), 1, branchTwo);

	sale.code = 10;
	strcpy(sale.desc, "Ventilador");
	sale.amount = 9;
	sale.price = 500;
	fwrite(&sale, sizeof(sale), 1, branchTwo);

	fclose(branchOne);
	fclose(branchTwo);
}

void orderByAmount(sale arr[], int len) {

	bool boolSwap;
	sale aux;
	do {
		boolSwap = false;

		for (int i = 0; i < len - 1; i++) {
			if (arr[i].amount < arr[i + 1].amount) {
				aux = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = aux;

				boolSwap = true;
			}
		}

	} while (boolSwap);

}


int searchItem(sale arr[], int len, int code) {

	int posCode = -1;

	for (int i = 0; i < len; i++) {
		if (arr[i].code == code) {
			posCode = i;
		}
	}

	return posCode;
}

//Ejercicio 2

void exerciseTwo() {

	initializeStudents();

	FILE* students = fopen("students.dat", "rb");
	approved approvedStudents[250];
	calification calification;
	approved approved;
	int lenApproved = 0;
	
	float sumIterations;
	float sumAverage;
	int bestDocket = -1;
	float bestAverage = -1;
	int worstDocket = -1;
	float worstNote = -1;
	fread(&calification, sizeof(calification), 1, students);
	
	while (!feof(students)) {
		int actualDocket = calification.docket;
		sumAverage = 0;
		sumIterations = 0;
		while (!feof(students) && actualDocket == calification.docket) {

			sumAverage = sumAverage + calification.note;
			sumIterations++;
			if (calification.note > 6) {
				approved.docket = calification.docket;
				strcpy(approved.name, calification.name);
				approved.gradeCode = calification.gradeCode;
				approvedStudents[lenApproved] = approved;
				lenApproved++;
			}

			if (worstNote = -1) {
				worstNote = calification.note;
				worstDocket = actualDocket;
			}
			else if (worstNote > calification.note) {

			}

			fread(&calification, sizeof(calification), 1, students);
		}

		cout << "El legajo " << actualDocket << " tiene un promedio de: " << sumAverage / sumIterations << endl;
		if (bestAverage < sumAverage / sumIterations) {
			bestAverage = sumAverage / sumIterations;
			bestDocket = actualDocket;
		}


	}


	fclose(students);

	
	insertApproved(approvedStudents, lenApproved);
	cout << "El mejor promedio es del legajo: " << bestDocket << " con una nota de: " << bestAverage << endl;
	cout << "La peor nota es del legajo: " << worstDocket << " con una nota de: " << worstNote << "\n" << endl;
}

void insertApproved(approved students[], int lenApproved) {
	FILE* approved = fopen("approved.dat", "wb");

	for (int i = 0; i < lenApproved; i++) {
		fwrite(&students[i], sizeof(approved), 1, approved);
	}

	fclose(approved);

}

void initializeStudents() {
	FILE* student = fopen("students.dat", "wb");

	calification calification;

	calification.docket = 1;
	strcpy(calification.name, "Matematica");
	calification.gradeCode = 1;
	calification.note = 8;
	fwrite(&calification, sizeof(calification), 1, student);

	calification.docket = 1;
	strcpy(calification.name, "Lengua");
	calification.gradeCode = 1;
	calification.note = 5;
	fwrite(&calification, sizeof(calification), 1, student);

	calification.docket = 1;
	strcpy(calification.name, "Biologia");
	calification.gradeCode = 1;
	calification.note = 7;
	fwrite(&calification, sizeof(calification), 1, student);

	calification.docket = 2;
	strcpy(calification.name, "Matematica");
	calification.gradeCode = 1;
	calification.note = 10;
	fwrite(&calification, sizeof(calification), 1, student);

	calification.docket = 3;
	strcpy(calification.name, "Sociales");
	calification.gradeCode = 1;
	calification.note = 3;
	fwrite(&calification, sizeof(calification), 1, student);


	fclose(student);
}

//Ejercicio 3

void exerciseThree(int arrayA[], int arrayB[], int& lenA, int& lenB, int& lenC, int arrayC[]){

	bool repeated = false;

	for (int a = 0; a < lenA; a++) {
		
		repeated = false;

		for (int i = 0; i < lenB; i++) {
			if (arrayA[a] == arrayB[i]) {
				repeated = true;
			}
		}

		if (!repeated) {
			arrayC[lenC] = arrayA[a];
			lenC++;
		}

	}

	for (int b = 0; b < lenB; b++) {
		arrayC[lenC] = arrayB[b];
		lenC++;
	}

}

//Ejercicio 4

int exerciseFour(int day, int month, int year) {
	int x = calculateX(month, year);
	int dayWeek = ((year - 1) % 7 + ((year - 1) / 4 - (3 * (year - 1) / 100 + 1) / 4) % 7 + x + day % 7) % 7;

	return dayWeek;
}

bool isLeapYear(int year) {

	bool leap = false;

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		leap = true;
	}

	return leap;
}

int calculateX(int month, int year) {

	int vecRegular[12] = { 0,3,3,6,1,4,6,2,5,0,3,5 };
	int vecBisiesto[12] = { 0,3,4,0,2,5,0,3,6,1,4,6 };

	int x = vecRegular[month - 1];


	bool leap = isLeapYear(year);

	if (leap)
		x = vecBisiesto[month - 1];

	return x;
}

string getDayName(int day) {

	string dayName = "";

	switch (day) {
	case 0:
		dayName = "Domingo";
		break;
	case 1:
		dayName = "Lunes";
		break;
	case 2:
		dayName = "Martes";
		break;
	case 3:
		dayName = "Miercoles";
		break;
	case 4:
		dayName = "Jueves";
		break;
	case 5:
		dayName = "Viernes";
		break;
	case 6:
		dayName = "Sabado";
		break;
	}

	return dayName;
}