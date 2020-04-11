#include "Alumno.h"

#include <string>

using namespace std;

Alumno::Alumno()
{
	P1 = 0;
	p2 = 0;
	p3 = 0;
	tareas = 0;
	prom = 0;
	minimo = -1;
}

Alumno::Alumno(int p1, int p2, int p3, int tareas, string nombre, int asistencias)
{
	P1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->tareas = tareas;
	this->nombre = nombre;
	this->asistencias = asistencias;
	minimo = 10000;
	Prom();
}

void Alumno::Prom(void) {
	P1 = P1 * 0.25;
	p2 = p2 * 0.25;
	p3 = p3 * 0.25;
	tareas = tareas * 0.25;
	prom = P1 + p2 + p3 + tareas;
}

void Alumno::SetProms(int p1, int p2, int p3, int tareas)
{
	P1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->tareas = tareas;
}

int Alumno::getP1(void)
{
	return P1;
}

int Alumno::getP2(void)
{
	return p2;
}

int Alumno::getP3(void)
{
	return p3;
}

int Alumno::gettareas(void)
{
	return tareas;
}

int Alumno::getProm(void)
{
	return prom;
}

string Alumno::getNombre(void)
{
	return nombre;
}

int Alumno::getCluster(void)
{
	return cluster;
}

void Alumno::SetCluster(int cls)
{
	cluster = cls;
}

int Alumno::getMinimo(void)
{
	return minimo;
}

void Alumno::setMinimo(int minimmo)
{
	this->minimo = minimmo;
}

int Alumno::getAsistencias(void)
{
	return asistencias;
}

ostream& operator <<(ostream& os, Alumno p) {
	os << "Nombre: " << p.getNombre() << "  Promedio 1: " << p.getP1() << "  Promedio2: " << p.getP2() << "  Promedio3: " << p.getP3() << "  Tareas: " << p.gettareas() << "  Promedio Total: " << p.getProm() << " asistencias: " << p.getAsistencias() << " en cluster de Id: " << p.getCluster() << endl;
	return os;
}

int Alumno::calcMin(int clust) //No entiendo este metodo
{
	int minico = 0;
	minico = prom - clust;
	if (minico < 0)
		minico *= -1;
	minimo = minico;
	return minico;
}
//
//int Alumno::setMin(int c1, int c2, int c3)
//{
//	int m1, m2, m3;
//	m1 = m2 = m3 = 0;
//	m1 = c1;
//	m2 = c2; //Cambie esto, no entendi muy bien el objetivo de este metodo y calcMin
//	m3 = c3;
//	if (m1 < m2)
//	{
//		if (m1 < m3)
//			return c1;
//		else
//			return c3;
//	}
//	else
//	{
//		if (m2 < m3)
//			return c2;
//		else
//			return c3;
//	}
//}

Alumno::~Alumno()
{
}
