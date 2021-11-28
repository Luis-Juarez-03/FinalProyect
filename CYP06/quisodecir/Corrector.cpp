/*****************************************************************************************************************
	UNIVERSIDAD NACIONAL AUTONOMA DE MEXICO
	FACULTAD DE ESTUDIOS SUPERIORES -ARAGON-

	Computadoras y programacion. 
	Juarez Sanchez Luis Angel 319286333
	
	Quiso decir: Programa principal de la aplicacion de la distancia de Levenstein.
	
******************************************************************************************************************/


#include "stdafx.h"
#include <string.h>
#include "corrector.h"


//funciones
//long long int c1 = 0, c2, c /*calph, c1alph, c2alph*/;
//int iNumT, i, ii, letras, nLetras/* cialph, ciialph, limABC, iii*/;
//const char noValid[] = "(,.;:)";
//int nV = strlen(noValid);
//char mayus[] = "ABCDEFGHIJKLMNÑOPQRSTVWXYZ";
//char lttr; 
//char limboszPalabras[TAMTOKEN];
//char limbo2szPalabras[TAMTOKEN];
//Funciones publicas del proyecto
/*****************************************************************************************************************
	DICCIONARIO: Esta funcion crea el diccionario completo
	char *	szNombre				:	Nombre del archivo de donde se sacaran las palabras del diccionario	
	char	szPalabras[][TAMTOKEN]	:	Arreglo con las palabras completas del diccionario
	int		iEstadisticas[]			:	Arreglo con el numero de veces que aparecen las palabras en el diccionario
	int &	iNumElementos			:	Numero de elementos en el diccionario
******************************************************************************************************************/
void	Diccionario(char* szNombre, char szPalabras[][TAMTOKEN], int iEstadisticas[], int& iNumElementos)
{
	FILE* stream;
	char szRecibePalabras[NUMPALABRAS][TAMTOKEN];
	char szControl[TAMTOKEN];
	int  szCaracter, i, j, iSegurofin, iControl;
	fopen_s(&stream, szNombre, "r");
	if (stream == NULL)
		return;

	iNumElementos = 0; j = 0;
	szCaracter = fgetc(stream);
	while (feof(stream) == 0)
	{
		if (!((szCaracter == 9) || (szCaracter == 10) || (szCaracter == 13) || (szCaracter == 32) || (szCaracter == 41) || (szCaracter == 44) || (szCaracter == 46) || (szCaracter == 59) || (szCaracter == 40)))
		{
			szRecibePalabras[iNumElementos][j] = towlower((char)szCaracter);
			szCaracter = fgetc(stream);
			j++;

		}
		else
		{
			if (j > 0)
			{
				szRecibePalabras[iNumElementos][j] = '\0';
				iEstadisticas[iNumElementos] = 1;

				if (iNumElementos > 0)
				{
					for (i = 0; i < iNumElementos; i++)
						if (strcmp(szRecibePalabras[i], szRecibePalabras[iNumElementos]) == 0)
						{
							iEstadisticas[i] = iEstadisticas[i] + 1;
							i = iNumElementos;
							iNumElementos = iNumElementos - 1;
						}
				}

				iNumElementos++;
				j = 0;
			}
			szCaracter = fgetc(stream);
		}
	}
	fclose(stream);

	szRecibePalabras[iNumElementos][j] = '\0';
	iEstadisticas[iNumElementos] = 1;

	for (i = 0; i < iNumElementos; i++)
		if (strcmp(szRecibePalabras[i], szRecibePalabras[iNumElementos]) == 0)
		{
			iEstadisticas[i] = iEstadisticas[i] + 1;
			strcpy_s(szRecibePalabras[iNumElementos], "");
			i = iNumElementos;
		}

	for (i = 0; i < iNumElementos; i++)
	{
		iSegurofin = 0;
		for (j = 0; j < iNumElementos; j++)
		{
			if (strcmp(szRecibePalabras[j + 1], szRecibePalabras[j]) < 0)
			{
				strcpy_s(szControl, szRecibePalabras[j]);
				iControl = iEstadisticas[j];
				strcpy_s(szRecibePalabras[j], szRecibePalabras[j + 1]);
				iEstadisticas[j] = iEstadisticas[j + 1];
				strcpy_s(szRecibePalabras[j + 1], szControl);
				iEstadisticas[j + 1] = iControl;
			}
			else
				iSegurofin += 1;
		}
		if (iSegurofin == iNumElementos)
			i = iNumElementos;
	}

	if (strcmp(szRecibePalabras[0], "") == 0)
	{
		for (i = 0; i < iNumElementos; i++)
		{
			strcpy_s(szPalabras[i], szRecibePalabras[i + 1]);
			iEstadisticas[i] = iEstadisticas[i + 1];
		}
		iEstadisticas[i] = '\0';
	}
	else
	{
		iNumElementos++;
		for (i = 0; i < iNumElementos; i++)
			strcpy_s(szPalabras[i], szRecibePalabras[i]);
	}
}
	// -----------------------------------------------------------------------MIO
	//long long int c1 = 0, c2, c /*calph, c1alph, c2alph*/;
	//int iNumT, i, ii, letras, nLetras/* cialph, ciialph, limABC, iii*/;
	//const char noValid[] = "(,.;:)";
	//int nV = strlen(noValid);
	//char mayus[] = "ABCDEFGHIJKLMNÑOPQRSTVWXYZ";
	//char lttr;

	//Abrir Archivo
	//FILE* file; 
	//fopen_s(&file, szNombre, "r");
	
	//Control de FILE
	//if (file == NULL)
	//{
	//	return;
	//}

	//// long abecedario
	////limABC = strlen(mayus);


	////Leer Archivo
	//while (!feof(file))
	//{

	//	fscanf_s(file, "%49s", szPalabras[c1], TAMTOKEN);
	//	//fscanf_s(file, "%[A-Za-z]", szPalabras[c1++], TAMTOKEN);
	//	iNumElementos++;
	//	nLetras = strlen(szPalabras[c1]);
	//	//tolower()
	//	i = 0;
	//	for (ii = 0; nLetras > ii; ii++)
	//	{
	//	szPalabras[c1][ii] = towlower(szPalabras[c1][ii]);
	//	}

		//Break limite palabras
		//if(c1 == )
		//{
			//break;
		//}
		//int iii, npi;

	/*	c1++;
	}
	fclose(file);*/

	
	//Quitar signos no validos
	//int limValid = strlen(noValid), iii, il/*, ni*/;
	//char limboni[TAMTOKEN] = "v";
	//char limbonii[TAMTOKEN] = "v";
	//for (i = 0; i < iNumElementos; i++)
	//{
	//	nLetras = strlen(szPalabras[i]);
	//	for (ii = 0; ii < limValid; ii++)
	//	{
	//		for (iii = 0; iii < nLetras; iii++)
	//		{
	//			if (szPalabras[i][iii] == noValid[ii])
	//			{
	//				for (il = iii; il < nLetras; il++)
	//				{
	//					szPalabras[i][il] = szPalabras[i][il + 1];
	//				}
	//				iii--;
	//				nLetras--;
	//			}
	//		}
	//	}
	//}

	//Arreglo Estadisticas
	/*for (c1 = 0; c1 < iNumElementos; c1++)
		iEstadisticas[c1] = 1;*/

	//Quitar registros Repetidos
	//iNumT = iNumElementos;
	//c1 = 0;
	//while (iNumT > c1) 
	//{
	//	for (c2 = c1 + 1; c2 <= iNumElementos; c2++)
	//	{
	//		if (strcmp(szPalabras[c1], szPalabras[c2]) == 0)
	//		{
	//			iEstadisticas[c1]++;
	//			for (c = c2; c < iNumT; c++)
	//			{
	//				//szPalabras[c] = szPalabras[c + 1];
	//				strcpy_s(szPalabras[c], szPalabras[c + 1]);
	//				iEstadisticas[c] = iEstadisticas[c + 1];
	//			}
	//			iNumElementos--;
	//			c2--;
	//			//iEstadisticas[i]++; arriba del for para evitar cosas raras
	//		}
	//	}
	//	c1++;
	//}

	//Ordenar de Forma alfabetica
	//int limbo1, limbo2;
	//char limboc1[TAMTOKEN], limboc2[TAMTOKEN];
	////iii = 0;
	//ii = 0;
	//i = 0;
	//while (iNumElementos > i)
	//{
	//	for (ii = i + 1; ii < iNumElementos; ii = ii + 1)
	//	{
	//		if (strcmp(szPalabras[i], szPalabras[ii]) > 0)
	//		{
	//			limbo1 = iEstadisticas[i];
	//			limbo2 = iEstadisticas[ii];
	//			strcpy_s(limboc1, szPalabras[i]);
	//			strcpy_s(limboc2, szPalabras[ii]);
	//			//limboc1[] = szPalabras[i];
	//			//limboc2[] = szPalabras[ii];

	//			iEstadisticas[i] = limbo2;
	//			iEstadisticas[ii] = limbo1;
	//			strcpy_s(szPalabras[i], limboc2);
	//			strcpy_s(szPalabras[ii], limboc1);
	//			//aCalifAlm[i] = limboc2;
	//			//aCalifAlm[ii] = limboc1;
	//			//limboi = ii;
	//		}
	//	}
	//	i++;
	//}

	////Quitar blancos
	//for (Ni = 0; Ni < iNumElementos; Ni++)
	//{
	//	nletrasSzP = strlen(szPalabras[Ni]);
	//	if (szPalabras[Ni][0] == '\0')
	//	{
	//		strcpy_s(szPalabras[Ni], szPalabras[Ni + 1]);
	//		iEstadisticas[c] = iEstadisticas[c + 1];
	//	}
	//}

	 

/*****************************************************************************************************************
	ListaCandidatas: Esta funcion recupera desde el diccionario las palabras validas y su peso
	Regresa las palabras ordenadas por su peso
	char	szPalabrasSugeridas[][TAMTOKEN],	//Lista de palabras clonadas
	int		iNumSugeridas,						//Lista de palabras clonadas
	char	szPalabras[][TAMTOKEN],				//Lista de palabras del diccionario
	int		iEstadisticas[],					//Lista de las frecuencias de las palabras
	int		iNumElementos,						//Numero de elementos en el diccionario
	char	szListaFinal[][TAMTOKEN],			//Lista final de palabras a sugerir
	int		iPeso[],							//Peso de las palabras en la lista final
	int &	iNumLista)							//Numero de elementos en la szListaFinal
******************************************************************************************************************/
void	ListaCandidatas		(
	char	szPalabrasSugeridas[][TAMTOKEN],	//Lista de palabras clonadas
	int		iNumSugeridas,						//Lista de palabras clonadas
	char	szPalabras[][TAMTOKEN],				//Lista de palabras del diccionario
	int		iEstadisticas[],					//Lista de las frecuencias de las palabras
	int		iNumElementos,						//Numero de elementos en el diccionario
	char	szListaFinal[][TAMTOKEN],			//Lista final de palabras a sugerir
	int		iPeso[],							//Peso de las palabras en la lista final
	int &	iNumLista)							//Numero de elementos en la szListaFinal
{
	//Implementar codigo para quitar repetidos
	int ci, cii;
	//Hace el array szListaFinal | iPeso
	iNumLista = 0;
	for (ci = 0; ci < iNumSugeridas; ci++)
	{
		for (cii = 0; cii < iNumElementos; cii++)
		{
			if (strcmp(szPalabrasSugeridas[ci], szPalabras[cii]) == 0)
			{
				strcpy_s(szListaFinal[iNumLista], szPalabras[cii]);
				iPeso[iNumLista++] = iEstadisticas[cii];
			}
		}
	}


	//Acomoda de maypr a menor
	int limbo1, limbo2;
	char limboc1[TAMTOKEN], limboc2[TAMTOKEN];
	//iii = 0;
	//ii = 0;
	ci = 0;
	while (iNumLista > ci)
	{
		for (cii = ci + 1; cii < iNumLista; cii = cii + 1)
		{
			if (iPeso[ci] < iPeso[cii])
			{
				limbo1 = iPeso[ci];
				limbo2 = iPeso[cii];
				strcpy_s(limboc1, szListaFinal[ci]);
				strcpy_s(limboc2, szListaFinal[cii]);
				//limboc1[] = szPalabras[i];
				//limboc2[] = szPalabras[ii];

				iPeso[ci] = limbo2;
				iPeso[cii] = limbo1;
				strcpy_s(szListaFinal[ci], limboc2);
				strcpy_s(szListaFinal[cii], limboc1);
				//aCalifAlm[i] = limboc2;
				//aCalifAlm[ii] = limboc1;
				//limboi = ii;
			}
		}
		ci++;
	}
	//Quita repetidos.
	int nSug = iNumLista, iii, iNumT = iNumElementos;
	ci = 0;
	while (nSug > ci)
	{
		for (cii = ci + 1; cii <= nSug; cii++)
		{
			if (strcmp(szListaFinal[ci],szListaFinal[cii]) == 0)
			{
				for (iii = cii; iii < iNumT; iii++)
				{
					//szPalabras[c] = szPalabras[c + 1];
					strcpy_s(szListaFinal[iii], szListaFinal[iii + 1]);
					iPeso[iii] = iPeso[iii +1];
				}
				nSug--;
				cii--;
				//iEstadisticas[i]++; arriba del for para evitar cosas raras
			}
		}
		ci++;
	}
	iNumLista = nSug;
}

/*****************************************************************************************************************
	ClonaPalabras: toma una palabra y obtiene todas las combinaciones y permutaciones requeridas por el metodo
	char *	szPalabraLeida,						// Palabra a clonar
	char	szPalabrasSugeridas[][TAMTOKEN], 	//Lista de palabras clonadas
	int &	iNumSugeridas)						//Numero de elementos en la lista
******************************************************************************************************************/

int nletrasPLs;
//char PLedit[TAMTOKEN];
void	ClonaPalabras(
	char *	szPalabraLeida,						// Palabra a clonar
	char	szPalabrasSugeridas[][TAMTOKEN], 	//Lista de palabras clonadas
	int &	iNumSugeridas)						//Numero de elementos en la lista
{
	//PLedit acarrea los valores de la palabra anterior y los va juntando empezando un desfase en la palabra clonada
	//Limpirar PLedit
	char PLedit[TAMTOKEN] = "v";
	strnset(PLedit, '\0', TAMTOKEN);
	int i, ii;
	iNumSugeridas = 0;
	nletrasPLs = strlen(szPalabraLeida);
	//strcpy(PLedit, szPalabraLeida);
	
	//Letra eliminada
	for (i = 0; i <= nletrasPLs; i++) //Se cambio < por <=
	{
		//Copia array szPalabraLeida a PLedit(PalabraLeidaEdit)
		for (ii = 0; ii < nletrasPLs; ii++) //nLetras por nLetrasPLs
		{
			PLedit[ii] = szPalabraLeida[ii];
		}

		for (ii = i; ii < nletrasPLs; ii++)
		{
			PLedit[ii] = PLedit[ii + 1];
		}

		if (PLedit[0] != ' ' && PLedit[0] != '\0')
		{
			strcpy_s(szPalabrasSugeridas[iNumSugeridas++], PLedit);
		}
	}

	//Utilizar strchr y strnset para separar arrays

	//Letras intercambiada de izquierda a derecha.
	char limbolizq, limbolder;
	int cizqDer;
	strnset(PLedit, '\0', TAMTOKEN);
	i = 0;
	for (cizqDer = 1; cizqDer < nletrasPLs; cizqDer++) //cambiar < por <=
	{
		//Copia array szPalabraLeida a PLedit(PalabraLeidaEdit)
		for (ii = 0; ii < nletrasPLs; ii++)
		{
			PLedit[ii] = szPalabraLeida[ii];
		}

		limbolizq = szPalabraLeida[i];
		limbolder = szPalabraLeida[i + 1];

		PLedit[i] = limbolder;
		PLedit[i + 1] = limbolizq;
		if (PLedit[0] != ' ' && PLedit[0] != '\0')
		{
			strcpy_s(szPalabrasSugeridas[iNumSugeridas++], PLedit);
		}
		i++;
	}
	
	strnset(PLedit, '\0', TAMTOKEN);

	//Letra sustituida por letra del abc
	char abc[] = "abcdefghijklmnñopqrstuvwxyzáéíóú";
	int longabc = strlen(abc), cCopy;
	for (i = 0; i < nletrasPLs; i++)
	{
		for (ii = 0; ii < longabc; ii++) //no
		{
			//Copia array szPalabraLeida a PLedit(PalabraLeidaEdit)
			for (cCopy = 0; cCopy < nletrasPLs; cCopy++)
			{
				PLedit[cCopy] = szPalabraLeida[cCopy];
			}

			PLedit[i] = abc[ii];
			strcpy_s(szPalabrasSugeridas[iNumSugeridas++], PLedit);
		}
	}

	//insertar abc al principio, y final de cada letra de PalLeida
	strnset(PLedit, '\0', TAMTOKEN);
	//int cialph;
	for (i = 0; i <= nletrasPLs; i++)
	{
		//Copia array szPalabraLeida a PLedit(PalabraLeidaEdit)
		for (ii = 0; ii < nletrasPLs; ii++)
		{
			PLedit[ii] = szPalabraLeida[ii];
		}

		//Recorrer array
		for (ii = nletrasPLs; ii > i; ii--)
		{
			PLedit[ii] = PLedit[ii - 1];
		}

		for (ii = 0; ii < longabc; ii++) //se cambio < por <=
		{
			PLedit[i] = abc[ii];
			if (PLedit[0] != ' ' && PLedit[0] != '\0')
			{
				strcpy_s(szPalabrasSugeridas[iNumSugeridas++], PLedit);
			}
		}
	}

	//Ordenar por orden alfabetico
	char limboc1[TAMTOKEN], limboc2[TAMTOKEN];
	//iii = 0;
	//ii = 0;
	i = 0;
	while (iNumSugeridas > i)
	{
		for (ii = i + 1; ii < iNumSugeridas; ii = ii + 1)
		{
			if (strcmp(szPalabrasSugeridas[i], szPalabrasSugeridas[ii]) > 0)
			{
				//limbo1 = iEstadisticas[i];
				//limbo2 = iEstadisticas[ii];
				strcpy_s(limboc1, szPalabrasSugeridas[i]);
				strcpy_s(limboc2, szPalabrasSugeridas[ii]);
				//limboc1[] = szPalabras[i];
				//limboc2[] = szPalabras[ii];

				//iEstadisticas[i] = limbo2;
				//iEstadisticas[ii] = limbo1;
				strcpy_s(szPalabrasSugeridas[i], limboc2);
				strcpy_s(szPalabrasSugeridas[ii], limboc1);
				//aCalifAlm[i] = limboc2;
				//aCalifAlm[ii] = limboc1;
				//limboi = ii;
			}
		}
		i++;
	}
	strnset(szPalabraLeida, '\0', TAMTOKEN);
}
