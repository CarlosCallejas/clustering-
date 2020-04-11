#pragma once
#include <iostream>
#include <string>

using namespace std;

class Alumno
{
	int P1, p2, p3, tareas, prom, asistencias;
	string nombre; int  cluster;
	int minimo;
public:
	//crea al alumno con los valores iniciales
	Alumno(int  p1, int p2, int p3, int tareas, string nombre, int asistencias);
	//crea al alumno sin valores
	Alumno();
	//saca el promedio de las calificaciones y tareas
	void Prom(void);
	//asigna las calificaciones a las variables correctas (accesor por si acaso)
	void SetProms(int p1, int p2, int p3, int tareas);
	//sobre carga de <<
	friend ostream& operator <<(ostream& out, Alumno p);
	//encuentra la distancia entre el promedio y el valor de el cluster
	int calcMin(int clust);
	//setea el minimo a la distancia menor y regresa el valor del maximo 
	int setMin(int c1, int c2, int c3); //esta parte no se necesita
										//manda a pantalla el alumno 
										//void MandaPantalla(void);
										///accesores de datos 
	int getProm(void);
	string getNombre(void);
	int getCluster(void);
	void SetCluster(int cls);
	int getMinimo(void);
	void setMinimo(int minimmo);
	int getAsistencias(void);
	~Alumno();
private:
	int getP1(void);
	int getP2(void);
	int getP3(void);
	int gettareas(void);


};
