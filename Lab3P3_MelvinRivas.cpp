#include <iostream>
using namespace std;
#include <stdio.h>     
#include <stdlib.h>    
#include <time.h>  
#include <math.h>   


int triangulo_pascal(int filas, int columnas) {
	
	if (columnas == 0 || columnas == filas)
	{
		return 1;
	}
	return triangulo_pascal(filas - 1, columnas - 1) + triangulo_pascal(filas - 1, columnas);
	cout << "filas:" << filas << "columnas : " << columnas;
}

void ecuaciones_puntos() {
	srand(time(NULL));
	int tamano = 2;
	do {
		cout << "Ingrese el tamano del arreglo que quiere generar: ";
		cin >> tamano;
		if (tamano < 2)
		{
			cout << "Cuidado no puede ser menor que 2" << endl;
		}
	} while (tamano < 2);
	int* arreglo1 = new int[tamano];
	for (size_t i = 0; i < tamano; i++)
	{
		arreglo1[i] = rand() % 20 + 1;
	}
	int* arreglo2 = new int[tamano];
	for (size_t i = 0; i < tamano; i++)
	{
		arreglo2[i] = rand() % 20 + 1;
	}
	cout << "Puntos en X generados : [ ";
	for (size_t i = 0; i < tamano; i++)
	{
		cout << arreglo1[i] << " ";
	}
	cout << "]" << endl;
	cout << "Puntos en Y generados : [ ";
	for (size_t i = 0; i < tamano; i++)
	{
		cout << arreglo2[i] << " ";
	}
	cout << "]" << endl;

	int punto1 = 1, punto2 = 2;
	do {
		cout << "Ingrese la posicion del punto 1: ";
		cin >> punto1;
	} while (punto1 < 0 || punto1 > tamano);
	do {
		cout << "Ingrese la posicion del punto 2: ";
		cin >> punto2;
	} while (punto2 < 0 || punto2 > tamano);
	punto1 = punto1 - 1;
	punto2 = punto2 - 1;
	cout << "Punto 1: " <<"(" << arreglo1[punto1] << " , " << arreglo2[punto1] << ")" << endl;
	cout << "Punto 2: " << "(" << arreglo1[punto2] << " , " << arreglo2[punto2] << ")" << endl;
	double resultado;
	resultado = (arreglo2[punto2] - arreglo2[punto1]) / (arreglo1[punto2] - arreglo1[punto1]);
	cout << "La ecuacion de la recta que pasa por los 2 puntos es m = " << resultado << endl;
	delete[] arreglo1;
	delete[] arreglo2;
}

void suma_vectores() {
	srand(time(NULL));
	int tamano = 2;
	do {
		cout << "Ingrese el tamano del arreglo que quiere generar: ";
		cin >> tamano;
		if (tamano < 2)
		{
			cout << "Cuidado no puede ser menor que 2" << endl;
		}
	} while (tamano < 2);
	int* vector1 = new int[tamano];
	for (size_t i = 0; i < tamano; i++)
	{
		vector1[i] = rand() % 20 + 1;
	}
	int* vector2 = new int[tamano];
	for (size_t i = 0; i < tamano; i++)
	{
		vector2[i] = rand() % 20 + 1;
	}
	cout << "Valores generados en vector 1 : [ ";
	for (size_t i = 0; i < tamano; i++)
	{
		cout << vector1[i] << " ";
	}
	cout << "]" << endl;
	cout << "Valores generados en vector 2 : [ ";
	for (size_t i = 0; i < tamano; i++)
	{
		cout << vector2[i] << " ";
	}
	cout << "]" << endl;
	double* vector3 = new double[tamano];
	for (size_t i = 0; i < tamano; i++)
	{
		vector3[i] = vector1[i] + vector2[i];
	}
	cout << "El resultado de la suma de vectores es: [ ";
	for (size_t i = 0; i < tamano; i++)
	{
		cout << vector3[i] << " ";
	}
	cout << "]" << endl;
	double elevado, resultado = 0;
	for (size_t i = 0; i < tamano; i++)
	{
		elevado = pow(vector3[i], 2);
		resultado = resultado + elevado;
	}
	resultado = sqrt(resultado);
	cout << "La norma de la suma de los vectores 1 y 2 es: " << resultado << endl;
	delete[] vector1;
	delete[] vector2;
	delete[] vector3;
}

void operaciones() {
	int opciones_operaciones = 0;
	while (opciones_operaciones != 3)
	{
		cout << "---- MENU ----" << endl << "1. Ecuaciones de la recta que pasa por 2 puntos" <<
			 endl <<"2. Suma de vectores y su norma" << endl << "3. Salir" << endl << "Cual desea elegir: ";
		cin >> opciones_operaciones;
		cout << endl;
		switch (opciones_operaciones)
		{
		case 1: {
			ecuaciones_puntos();
			break;
		}
		case 2: {
			suma_vectores();
			break;
		}
		case 3: {
			cout << "Regresando";
			break;
		}
		default:
			cout << "Caracter invalido, porfavor vuelva a intentarlo";
			break;
		}
	}
}

void menu() {

	int opciones = 0;
	while (opciones != 3)
	{
		cout << "---- MENU ----" << endl << "1. Triangulo de Pascal " << endl <<
			"2. Operaciones de numero" << endl << "3. Salir" << endl <<
			"Cual desea elegir: ";
		cin >> opciones;
		cout << endl;
		switch (opciones)
		{
		case 1: {
			int filas;
			cout << "Ingrese el numero de filas para el triangulo  de pascal: ";
			cin >> filas;
			triangulo_pascal(filas,3);
			break;
		}
		case 2: {
			operaciones();
			break;
		}
		case 3: {
			cout << "Adios, hasta la proxima";
			break;
		}
		default:
			cout << "Caracter invalido, porfavor vuelva a intentarlo";
			break;
		}
	}
}

int main()
{
    menu();
}