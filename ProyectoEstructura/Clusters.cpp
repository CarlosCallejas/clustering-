#include "Clusters.h"
#include <iostream>

using namespace std;

Clusters::Clusters()
{
}

Clusters::Clusters(int id)
{
	identificador = id;
	setMaximoInicial(identificador);
}




void Clusters::CalcuMax()
{
}




int Clusters::getIdentificador(void)
{
	return identificador;
}

int Clusters::GetMaximo(void)
{
	return maximo;
}

int Clusters::GetAsistencias(void)
{
	return asistencias;
}

float Clusters::actualizaCentroide(int x, int y) //ACTUALICE this->maximo = x     por this->maximo = x2
{
	if (x > 0 && y > 0) {
		int x2 = maximo - x; //movimiento en x (promedio)
		int y2 = asistencias - y; //movimiento en y (asistencias)
		/*if (x2 < 0)
			x2 *= -1;
		if (y2 < 0)
			y2 *= -1;*/
		this->maximo = x; //actualiza la posicion en x (promedio)
		this->asistencias = y; //actualiza la posicion en y (asistencias)
		return ((x2 + y2) / 2); //regresa el promedio del movimiento del centroide
	}
	else
	{
		return 0;
	}
}

void Clusters::setMaximoInicial(int tipo)
{
	if (tipo == 1) {
		this->maximo = 62;
		asistencias = 7;
	}
	else if (tipo == 2) {
		this->maximo = 83;
		asistencias = 3;
	}
	else {
		this->maximo = 97;
		asistencias = 1;
	}
}


ostream& operator <<(ostream& os, Clusters c) {
	os << "Maximo: " << c.GetMaximo() << "  Asistencias: " << c.GetAsistencias();
	return os;
}


//
//ostream& operator <<(ostream& os, Clusters p) {
//	os << " los alumnos: "; p.GetCantidadAlumnos(); cout << " estan en el cluster de: " << p.getIdentificador() << endl;
//	
//	return os;
//}



Clusters::~Clusters()
{
}
