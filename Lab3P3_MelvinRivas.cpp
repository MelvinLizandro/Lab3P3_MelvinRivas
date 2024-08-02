#include <iostream>
using namespace std;
#include <stdio.h>     
#include <stdlib.h>    
#include <time.h>  
#include <math.h>   

int factorial(int numero)
{
	// funcion encargada de ir sacando el factorial acumulandose
	//  para sacar el resultado final hasta que el valor llegue a ser menor que 2
	if (numero < 2) {
		return 1;
	}
	else {
		// formula de factorial
		return numero * factorial(numero - 1);
	}
}

int codigo(int n, int r)
{
	if (r == 1) {
		return n;
	}
	else if (n == r) {
			return 1;
		}
		else
		{
		/*
		formula:	 n!
				--------------
				(n! * (n! -r))
		*/
			return factorial(n) / (factorial(r) * factorial(n - r));
	}
}

void triangulo_pascal(int rango) {
	// le quitamos uno para que lo imprima bien
	rango--;
	// for para salto de linea 
	for (int i = 0; i <= rango; i++)
	{
		// for de impresion de numeros mas el espacio de separaciob
		for (int j = 0; j < i; j++) {
			cout << codigo(i, j) << " " ;
		}
		// imprime en duro el uno porque no puede hacerlo de otra forma
			cout << "1" << endl;
	}
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
		//llena los arreglos con numeros ramdoms
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
	//los imprime
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
	//consigue la posicion que solicita el usuario
	int punto1 = 1, punto2 = 2;
	do {
		cout << "Ingrese la posicion del punto 1: ";
		cin >> punto1;
	} while (punto1 < 0 || punto1 > tamano);
	do {
		cout << "Ingrese la posicion del punto 2: ";
		cin >> punto2;
	} while (punto2 < 0 || punto2 > tamano);
	//les resta una ya que el arreglo empieza desde 0
	punto1 = punto1 - 1;
	punto2 = punto2 - 1;
	cout << "Punto 1: " <<"(" << arreglo1[punto1] << " , " << arreglo2[punto1] << ")" << endl;
	cout << "Punto 2: " << "(" << arreglo1[punto2] << " , " << arreglo2[punto2] << ")" << endl;
	double resultado;
	//formula para para calcular resultado
	resultado = (arreglo2[punto2] - arreglo2[punto1]) / (arreglo1[punto2] - arreglo1[punto1]);
	cout << "La ecuacion de la recta que pasa por los 2 puntos es m = " << resultado << endl;
	delete[] arreglo1;
	delete[] arreglo2;
}

void suma_vectores() {
	//inicia ramdom
	srand(time(NULL));
	int tamano = 2;
	do {
		cout << "Ingrese el tamano del arreglo que quiere generar: ";
		cin >> tamano;
		if (tamano < 2)
		{
			cout << "Cuidado no puede ser menor que 2" << endl;
		}
		//inicia vector
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
	// imprime vector
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
	// vector donde se sumara los resultados
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

	int *opciones = new int;
	*opciones = 1;
	while (*opciones != 3)
	{
		cout << "---- MENU ----" << endl << "1. Triangulo de Pascal " << endl <<
			"2. Operaciones de numero" << endl << "3. Salir" << endl <<
			"Cual desea elegir: ";
		cin >> *opciones;
		cout << endl;
		switch (*opciones)
		{
		case 1: {
			int filas;
			cout << "Ingrese el numero de filas para el triangulo de pascal: ";
			cin >> filas;
			triangulo_pascal(filas);
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
	delete opciones;
}

int main()
{
    menu();
}