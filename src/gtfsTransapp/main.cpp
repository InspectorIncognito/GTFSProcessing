#include <iostream>
#include "Utilidades/Cronometro.h"
#include "IO/FuenteDatos.h"
#include "Transporte/Rutas/ProcesaRutas.h"
#include "Transporte/Paraderos/ProcesaParadas.h"
#include "Transporte/Grid/GridProcess.h"
#include "IO/Visualizacion/Visualizaciones.h"
#include "IO/Tablas/TablaDistanciaEnRutaParadas.h"
#include "IO/Tablas/TablaServicios.h"
#include "IO/Tablas/TablaServiciosPorParada.h"
#include "IO/Tablas/TablaParadas.h"
#include "IO/Tablas/TablaRutasTramadas.h"
#include "IO/Tablas/TablaPuntoCarga.h"
#include "IO/Tablas/TablaRutasSimplificadas.h"
#include "IO/Tablas/TablaServiciosPorParadaParaAndriod.h"
#include "IO/Tablas/TablaServiciosParaAndroid.h"
#include "IO/Tablas/TablaServiciosPorParadasPorSecuencia.h"
#include "IO/Tablas/TablaGrilla.h"

using namespace std;


int main(int argc, char **argv) {

	int nTimeStart = Cronometro::GetMilliCount();

    ///Referencia a estructura que almacena todos los datos externos
 	FuenteDatos *fdd = new FuenteDatos(argv[1]);
 
	///Procesado de rutas
	ProcesaRutas *pr = new ProcesaRutas(fdd);
 
	///Procesado de paraderos
	ProcesaParadas *pp = new ProcesaParadas(fdd);

	///Procesando grilla
	GridProcess *pg = new GridProcess(fdd);

	///Tabla de paradas
	TablaParadas *tparadas = new TablaParadas(fdd);

	///Tabla de servicios
	TablaServicios *tservicios = new TablaServicios(fdd);

	///Tabla de servicios por parada
	TablaServiciosPorParada *tserviciosPorParada = new TablaServiciosPorParada(fdd);

	///Tabla de distancias de paradas en ruta
	TablaDistanciaEnRutaParadas *tdistanciasParadas = new TablaDistanciaEnRutaParadas(fdd);

	///Tabla con el tramado de las rutas
	TablaRutasTramadas *tRutasTramadas = new TablaRutasTramadas(fdd);

	///Tabla con las rutas simplificadas
	TablaRutasSimplificadas *tRutasSimplificadas = new TablaRutasSimplificadas(fdd);

	//Tabla de paradas para Android
	TablaServiciosPorParadaParaAndriod *tParadasParaAndriod = new TablaServiciosPorParadaParaAndriod(fdd);

	///Tabla de servicios para Android
	//TablaServiciosParaAndroid *tServiciosParaAndroid = new TablaServiciosParaAndroid(fdd);

	///Tabla de puntos de carga
	//TablaPuntoCarga *tPuntosDecarga = new TablaPuntoCarga(fdd);

	///Tabla de grilla
	TablaGrilla *tGrilla = new TablaGrilla(fdd);

	///Tabla de secuencias, con variantes
	TablaServiciosPorParadasPorSecuencia *tSpPpS = new TablaServiciosPorParadasPorSecuencia(fdd);

	/////Construccion de visualizacion
	Visualizaciones *visual = new Visualizaciones(fdd);
	visual->DibujaGoogleEarth();

	fdd->outParameters.close();

	cout << "Tiempo Total: " << Cronometro::GetMilliSpan( nTimeStart )/60000.0 << "(min)" << endl;

	return 0;
}
