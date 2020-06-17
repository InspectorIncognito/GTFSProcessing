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

#include <map>
#include <cstdlib>
#include <string>
#include <iostream>
#include <limits>
#include <regex>
#include "../FuenteDatos.h"

using namespace std;

/**
* Title: TablaServicios
* Description:	Clase para construir tabla de de informacion agregada por servicio sentido
* Copyright:  Pragxis (c) 2016
* Date: 18-06-2016
* @author Mauricio Zuñiga G. <mzuniga@pragxis.cl>
* @version 0.0
*/
class TablaServiciosPorParadasPorSecuencia{
	public:
		/**
		* Estructura para los datos
		*/
		struct busStopSequence {
			string servicio;
			string sentido;
			string tipodia;
			string color;
			string horario;
			string nombre;
			string paradas;
			string destino;

			string shape_id;
			string modo;
		};
		map< string, busStopSequence> secuenciasPorHorario;
		map< string, busStopSequence>::iterator itseq;

		/**
		* Constructor
		*/
		TablaServiciosPorParadasPorSecuencia(FuenteDatos *fdd);
		/**
		* Destructor
		*/
		~TablaServiciosPorParadasPorSecuencia();

		///Referencia a la fuente de datos
		FuenteDatos *fdd_;

		/**
		* Metodo que construye e imprime la tabla
		* @param transacciones referencia al conjunto de transacciones del sistema con subida estimada
		*/
		void Crear();

		void buildSequenceByScheduleFrequencies();

		void buildSequenceByScheduleItinerary();

		string EliminaCadenasBlancos(string in);

		string toCamelCase(string in);

		string corrigeArticulos(string in);
};
