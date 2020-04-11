#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Alumno.h"
#include <math.h>
using namespace std;

class Clusters
{
	int identificador;
	int maximo, asistencias;
public:
	Clusters();
	Clusters(int id);
	//hace la raiz cuadrada de la sumatoria al cuadrado de las diferencias entre min y max (distancia ecludiana)
	void CalcuMax(void); //de vector de alumnos sacar vector de minimos 
						 //sobrecarga de operador <<
						 //friend ostream& operator <<(ostream& out, Clusters p);

						 ///accesores
	int getIdentificador(void);
	int GetMaximo(void);
	int GetAsistencias(void);
	//actualiza la posicion del centroide y regresa cuanto se movio
	float actualizaCentroide(int x, int y);
	friend ostream& operator <<(ostream& out, Clusters c);
	~Clusters();

private:
	void setMaximoInicial(int tipo);
};

