#include <string>
#include <iostream>
#include <vector>
#include "Alumno.h"
#include "Clusters.h"
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

///Proyecto Final	Estructura de Datos
///Maestra Monica Larre Bolaños

///Enrique Favila	A01422478
///Carlos Callejas  A01423262

//regresa el cuadrado de la diferencia de distancias en x
int CalcularSumatoriaX(int Cprom, int prom){
	int c = Cprom - prom;
	if (c < 1)
		c *= -1;
	return c;//pow(Cprom - prom, 2);
}
//regresa el cuadrado de la diferencia de distancias en y
int CalcularSumatoriaY(int Cprom, int prom){
	int c = Cprom - prom;
		if (c < 1)
			c *= -1;
	return c;//pow(Cprom - prom, 2);
}

//Cambie algunos nombres de variables para hacerlos intuitivos.
//Metodo calcMin y setMin de Alumno.cpp también les movi un poco, pero esos no estoy seguro de haberlo hecho bien, no les entendi.
int main()
{
	ifstream archivo;
	string laLinea;
	vector<Alumno> NoMover;
	vector<Alumno> Alumnos;

	archivo.open("Alumnos2.txt", ios::in);
	while (!archivo.eof())
	{
		string tipo2 = "";
		int l = 1, promedio1 = 0, promedio2 = 0, promedio3 = 0, tareas = 0, asistencia = 0; //para que es int l = 1?
		string nombre;
		getline(archivo, laLinea);
		istringstream isstream(laLinea);
		string tempStr;

		//Asignacion de valores del archivo de texto a las variables
		isstream >> tempStr;
		nombre = tempStr;

		isstream >> tempStr;
		stringstream numero(tempStr);
		numero >> promedio1;

		isstream >> tempStr;
		stringstream numero2(tempStr);
		numero2 >> promedio2;

		isstream >> tempStr;
		stringstream numero3(tempStr);
		numero3 >> promedio3;

		isstream >> tempStr;
		stringstream numero4(tempStr);
		numero4 >> tareas;

		isstream >> tempStr;
		stringstream numero5(tempStr);
		numero5 >> asistencia;

		//Se agregan todos los alumnos del texto al vector de alumnos
		Alumno nuevoAlumno(promedio1, promedio2, promedio3, tareas, nombre, asistencia);
		Alumnos.push_back(nuevoAlumno);
	}
	archivo.close();
	Clusters centroideReprobados(1), centroideAprobados(2), centroideCrema(3);//centroides
	float promMovCentroides = 10; //promedio de movimiento de todos los centroides
	float sumaReproX, sumaReproY, sumaAprobX, sumaAprobY, sumaCremaX, sumaCremaY, cont1, cont2, cont3; //variales para promedios de cada centroide
	sumaReproX = sumaReproY = sumaAprobX = sumaAprobY = sumaCremaX = sumaCremaY = cont1 = cont2 = cont3 = 0.0;
	int c = 0;
	cout << "Id: 1 Centroide reprobados inicial:\n" << centroideReprobados << endl << endl;
	cout << "Id: 2 Centroide aprobados inicial:\n" << centroideAprobados << endl << endl;
	cout << "Id: 3 Centroide CREMA inicial:\n" << centroideCrema << endl << endl;
	system("pause");
	while (promMovCentroides>1)
	{
		for (int x = 0; x < Alumnos.size(); x++)
		{
			if (Alumnos[x].getMinimo() > 5) {
				//distancias ecludianas de todos los centroides con cada uno de los alumnos 
				int distTempReprob = sqrt(CalcularSumatoriaX(centroideReprobados.GetMaximo(), Alumnos[x].getProm()) + CalcularSumatoriaY(centroideReprobados.GetAsistencias(), Alumnos[x].getAsistencias()));
				int distTempAprob = sqrt(CalcularSumatoriaX(centroideAprobados.GetMaximo(), Alumnos[x].getProm()) + CalcularSumatoriaY(centroideAprobados.GetAsistencias(), Alumnos[x].getAsistencias()));
				int distTempCrema = sqrt(CalcularSumatoriaX(centroideCrema.GetMaximo(), Alumnos[x].getProm()) + CalcularSumatoriaY(centroideCrema.GetAsistencias(), Alumnos[x].getAsistencias()));

				if (distTempReprob < distTempAprob) { //si la distancia de reprobados es menor de aprobados				crema -> aprob
					if (distTempReprob < distTempCrema) { //si la distancia de reprobados es menor que de crema			aprob-> reprob
						Alumnos[x].SetCluster(1); //se le asigna el cluster reprobado al alumno
						sumaReproX += CalcularSumatoriaX(centroideReprobados.GetMaximo(), Alumnos[x].getProm()); //saca la sumatoria de las distancias entre centroide y alumno de promedios
						sumaReproY += CalcularSumatoriaY(centroideReprobados.GetAsistencias(), Alumnos[x].getAsistencias()); //saca la sumatoria de las distancias entre centroide y alumno de asistencias
						Alumnos[x].setMinimo(distTempReprob);
						cont1++;//cuenta la cantidad de valores en este centroide
					}
					else { //																							se queda en aprob
						Alumnos[x].SetCluster(3);//se le asigna el cluster aprobado al alumno
						sumaCremaX += CalcularSumatoriaX(centroideCrema.GetMaximo(), Alumnos[x].getProm());
						sumaCremaY += CalcularSumatoriaY(centroideCrema.GetAsistencias(), Alumnos[x].getAsistencias());
						Alumnos[x].setMinimo(distTempCrema);

						cont3++;//saca la sumatoria de las distancias entre centroide y alumno de asistencias
					}
				}
				else if (distTempAprob < distTempCrema) { //																	Reprob -> Aprob
					Alumnos[x].SetCluster(2);//se le asigna el cluster aprobado al alumno
					sumaAprobX += CalcularSumatoriaX(centroideAprobados.GetMaximo(), Alumnos[x].getProm());
					sumaAprobY += CalcularSumatoriaY(centroideAprobados.GetAsistencias(), Alumnos[x].getAsistencias());
					Alumnos[x].setMinimo(distTempAprob);

					cont2++;//saca la sumatoria de las distancias entre centroide y alumno de asistencias
				}
				else
				{
					Alumnos[x].SetCluster(3);//se le asigna el cluster aprobado al alumno
					sumaCremaX += CalcularSumatoriaX(centroideCrema.GetMaximo(), Alumnos[x].getProm());
					sumaCremaY += CalcularSumatoriaY(centroideCrema.GetAsistencias(), Alumnos[x].getAsistencias());
					Alumnos[x].setMinimo(distTempCrema);

					cont3++;//saca la sumatoria de las distancias entre centroide y alumno de asistencias
				}
			}
			c++;
		}
		sumaReproX / cont1; //promedio de distancias de promedio
		//sumaReproX = sqrt(sumaReproX);
		sumaReproY / cont1; //promedio de distancias de asistencias 
		//sumaReproY = sqrt(sumaReproY);

		sumaAprobX / cont2;
		sumaAprobY / cont2;
		//sumaAprobX = sqrt(sumaAprobX);
		//sumaAprobY = sqrt(sumaAprobY);

		sumaCremaX / cont3;
		sumaCremaY / cont3;
		//sumaCremaX = sqrt(sumaCremaX);
		//sumaCremaY = sqrt(sumaCremaY);


		float mov1 = centroideReprobados.actualizaCentroide(sumaReproX, sumaReproY); //actuliza la posicion de los centroides y guarda cuanto se movio
		float mov2 = centroideAprobados.actualizaCentroide(sumaAprobX, sumaAprobY);
		float mov3 = centroideCrema.actualizaCentroide(sumaCremaX, sumaCremaY); 
		promMovCentroides = ((mov1 + mov2 + mov3) / 3); //saca el promedio de cuanto se movieron los 3 centroides juntos
		sumaReproX = sumaReproY = sumaAprobX = sumaAprobY = sumaCremaX = sumaCremaY = cont1 = cont2 = cont3 = 0.0;

	}
	//Los resultados a desplegar son cuales? la posicion final de los centroides?
	cout << endl << endl << "___________________________________________________________________" << endl << endl;
	cout << "Id: 1 Centroide reprobados final:\n" << centroideReprobados << endl << endl;
	cout << "Id: 2 Centroide aprobados final:\n" << centroideAprobados << endl << endl;
	cout << "Id: 3 Centroide CREMA final:\n" << centroideCrema << endl << endl;
	//se despliegan resultados de todo
	cout << endl << endl;
	for (int x = 0; x < Alumnos.size(); x++) {
		cout << Alumnos[x];
	}
	cout << endl << "pasadas " << c << endl;
	system("pause");
	return 0;
}