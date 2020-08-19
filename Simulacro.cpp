#include <iostream>
#include "Funciones.hpp"
#include <string.h>

int main()
{

    int optionMenu = 0;



    //Ejercicio 3
    int arrayA[10] = { 1,2,3,4,5,6 };
    int arrayB[10] = { 1,2,3,4,5,6 };
    int arrayC[20] = {};
    int lenA = 6;
    int lenB = 5;
    int lenC = 0;

    //Ejercicio 4

    int day = 0;
    int month = 0;
    int year = 0;
    int dayWeek = 0;

    

    
    do{

        cout << "1) Ejercicio 1" << endl;
        cout << "2) Ejercicio 2" << endl;
        cout << "3) Ejercicio 3" << endl;
        cout << "4) Ejercicio 4" << endl;
        cout << "0) Salir" << endl;
        cout << "\n";

        cout << "Ingrese su opcion:";
        cin >> optionMenu;

        cout << "\n";

        switch (optionMenu) {
        case 1:
            exerciseOne();
            break;
        case 2:
            exerciseTwo();
            break;
        case 3:
            exerciseThree(arrayA, arrayB, lenA, lenB, lenC, arrayC);

            for (int i = 0; i < lenC; i++) {
                cout << arrayC[i] << endl;
            }
            break;
        case 4:
            cout << "Ingresa el dia: ";
            cin >> day;
            cout << "Ingresa el mes: ";
            cin >> month;
            cout << "Ingresa el año: ";
            cin >> year;

            dayWeek = exerciseFour(day, month, year);

            cout << "El " << day << "/" << month << "/" << year << " cae un dia " << getDayName(dayWeek) << "\n"<< endl;

            break;
        default:
            break;
        }
    }while(optionMenu != 0);
        

}

