/**
* Project: "proceGTFS".
* Package:
* Class:
* Created by: Mauricio Zuñiga G. <mzuniga@pragxis.cl>
* Terms: These coded instructions, statements, and computer programs are
* produced as part of a software project. They contain unpublished
* propietary information and are protected by copyright law. They may
* not be disclosed to third parties or copied or duplicated in any form,
* in whole or in part, without the prior written consent of Pragxis SpA.
* Copyright:  Pragxis (c) 2016
* Last modified : Mauricio Zuñiga 18-06-2016
*/
#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <locale>
#include <regex>
#include <algorithm>
#include "Parametros.h"
#include "ReporteFuenteDatos.h"
#include "../Utilidades/StringFunctions.h"
#include "../Utilidades/ConvertCoordinate.h"
#include "../Utilidades/Cronometro.h"
#include "../Transporte/Servicios/Servicio.h"
#include "../Transporte/Paraderos/SecuenciaParaderos.h"
#include "../Transporte/Paraderos/RedParadas.h"
#include "../Transporte/Rutas/Rutas.h"
#include "../Transporte/Grid/Grid.h"
#include "../Transporte/CargaBip/PuntoBip.h"
#include "../Transporte/Diccionarios/DiccionarioServicios.h"


using namespace std;

/**
* Title: FuenteDatos
* Description:	Clase contenedora de los datos de entrada, tiene estructuras y los metodos 
* 		de lectura de estos especificos de Transantiago.
* Copyright: Pragxis (c) 2016
* Date: 18-06-2016
* @author Mauricio Zuñiga
* @version 0.0
*/
class FuenteDatos{
  public:
	/**
	*	Constructor de la clase
	*	@param file nombre del archivo de parametros externos 
	*/
	FuenteDatos(const char *file);
	/**
	 * Constructor por defecto
	 */
	FuenteDatos(void);
	/**
	 * Destructor por defecto
	 */
	~FuenteDatos(void);
    
	///Parametros externos, nombres de archivo, indices de columnas parametros para el proceso...
	Parametros* parametros;

	///Referencia a reporte de la lectura de los datos de entrada
	ReporteFuenteDatos* reporte;

	///Estructura de diccionario de codigos servicio-sentido
	DiccionarioServicios dicSS;

	///Estructura  de las rutas
	Rutas rutas;

	///Estructura con la red de paraderos
	RedParadas redParaderos;

	///Estructura de secuencia de paraderos
	SecuenciaParaderos secParaderos;

	///Estructura de secuencia de paraderos
	SecuenciaParaderos secParaderosTODOS;

	///Estructura de secuencia de paraderos
	SecuenciaParaderos secParaderosDTPM;

	///Estructura de servicios
	map<string, Servicio> servicios;

	///Estructura con la red de puntos de carga bip
	map<int, PuntoBip> puntosDeCargaBip;

	///Grilla para ordenar informacion geograficamente
	Grid grid;

	///Archivo para parametros variados de salida
	ofstream outParameters;

	///StopsTimes
	struct Secuencia
	{
		map<int, string> paradas;
		string hora_ini = string("-");
		string hora_fin = string("-");
		string nombre = string("-");
		string version = string("-");
		string codigo = string("-");
		int headway = -1;
		string shape_id = string("-");
	};

	map<string, Secuencia > secuencias;
	map<string, Secuencia >::iterator isec;

	///Instancia de clase para manejo de tiempo
	TimeStampHandler tsh;

	/**
	* Metodo de lectura de datos para estandarizar la codificacion de servicio-sentido
	* @return referencia a objeto con los distintos diccionarios de servicio-sentido
	*/
	void leeDiccionarioServicios();

	/**
	* Metodo de lectura de la rutas
	* @return referencia a objeto con el conjunto de rutas del sistema
	*/
	void leeRutas();

	/**
	* Metodo para leer la red de paradas
	* @return referencia o puntero a objeto tipo Paraderos con el conjunto de paradas de la red
	*/
	void leeRedDeParadas();
	void CorrigeParadasMismaPosicion();

	/**
	* Metodo de lectura de datos de secuencia de paraderos
	* @return referencia a objeto con el conjunto de paraderos del sistema
	*/
	void leeSecuenciaDeParadas();
	//void leeSecuenciaDeParadasDTPM();
	void readStopTimes();

	/**
	*	Metodo que lee un archivo de horarios, el metodo permite la no existencia del archivo
	*   En caso de no existencia los horarios quedaran nulos con un guion (-)
	*   El metodo necesita tener ya leido la lista de servicios del diccionario
	*/
	//void leeHorarios();

	/**
	*	Metodo que lee un archivo de horarios, el metodo permite la no existencia del archivo
	*   En caso de no existencia los horarios quedaran nulos con un guion (-)
	*   El metodo necesita tener ya leido la lista de servicios del diccionario
	*/
	void leePuntosDeCargaBip();

	/**
	*
	*/
	//void readScheduleMetro();

	/**
	* Metodo que chequea si un par coordenada esta fuera de la zona de Santiago
	*/
	bool estaEnSantiago(int x_, int y_);

	//string toCamelCase(string in);
};
