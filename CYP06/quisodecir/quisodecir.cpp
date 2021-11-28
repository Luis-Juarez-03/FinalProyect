/*****************************************************************************************************************
	UNIVERSIDAD NACIONAL AUTONOMA DE MEXICO
	FACULTAD DE ESTUDIOS SUPERIORES -ARAGON-

	Computadoras y programacion. 
	(c) Ernesto Peñaloza Romero 2015-2020
	
	Quiso decir: Programa principal de la aplicacion de la distancia de Levenstein.
	
******************************************************************************************************************/
// quisodecir.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <string.h>
#include "corrector.h"



int _tmain(int argc, _TCHAR* argv[])
{
	char	szNombre[50];
	char	szPalabras[NUMPALABRAS][TAMTOKEN];
	int		iEstadisticas[NUMPALABRAS];
	int		i;
	int		iNumElementos;
	int		iNumSugeridas;
	char	szPalabraLeida[TAMTOKEN];
	char	szPalabrasSugeridas[3300][TAMTOKEN];
	char	szListaFinal[3300][TAMTOKEN];
	int		iPeso[3300]; //son 66 combinaciones por letra, mas o menos 3300 para 50 letras
	int		iNumLista;

	//Inicia el arreglo de estadisticas
	for (i = 0; i < NUMPALABRAS; i++)
		iEstadisticas[i] = 0;

	//strcpy_s(szNombre, "anita.txt");
	printf("Archivo para el diccionario: ");
	scanf_s("%s", szNombre, 50);

	Diccionario(szNombre, szPalabras, iEstadisticas, iNumElementos);

	for (int j = 0; j < iNumElementos; j++)
		printf("%-12s %i\n", szPalabras[j], iEstadisticas[j]);

	printf("Numero de elementos en la lista: %i\n", iNumElementos);
	strcpy_s(szPalabraLeida, "");
	while (strcmp(szPalabraLeida, "fin"))
	{
		printf("\nDigite una palabra o 'fin' para terminar: ");
		scanf_s("%s", szPalabraLeida, TAMTOKEN);
		_strlwr_s(szPalabraLeida);
		ClonaPalabras(szPalabraLeida, szPalabrasSugeridas, iNumSugeridas);

		for (int j = 0; j < iNumSugeridas - 1; j++)
			printf("%s\n", szPalabrasSugeridas[j]);
		printf("Numero de elementos en la lista de clonacion: %i\n", iNumSugeridas);

		ListaCandidatas(szPalabrasSugeridas, iNumSugeridas, szPalabras, iEstadisticas, iNumElementos,
			szListaFinal, iPeso, iNumLista);
		printf("\n\nTal vez ud quiso decir:\npalabra\t frecuencia\n");
		printf("=======\t ==========\n");
		if (iNumLista > 0)
		{

			for (int j = 0; j < iNumLista; j++)
				printf("%s\t%i\n", szListaFinal[j], iPeso[j]);
			printf("Numero de elementos en la lista de opciones: %i\n", iNumLista);
		}
		else
			printf("\n\nSin opciones que mostrar\n");
	}

	return 0;
}


