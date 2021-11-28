/*****************************************************************************************************************
	UNIVERSIDAD NACIONAL AUTONOMA DE MEXICO
	FACULTAD DE ESTUDIOS SUPERIORES -ARAGON-

	Computadoras y programacion. 
	(c) Ernesto Peñaloza Romero 2015
	
	Quiso decir: Programa principal de la aplicacion de la distancia de Levenstein.

	NO MODIFIQUE ESTE ARCHIVO
	
******************************************************************************************************************/

#define TAMTOKEN	50						//tamaño maximo de cada palabra
#define NUMPALABRAS 70000					//Numero maximo de palabras


//Funciones publicas para el proyecto
void 	Diccionario(
	char *szNombre, 	 					//Nombre del archivo, desde donde se lee el diccionario
	char szPalabras[][TAMTOKEN],  			//Lista de palabras del diccionario
	int iEstadisticas[], 					//Numero de veces que aparece la palabra en el archivo
	int &iNumElementos);					//Numero de elementos en el diccionario

void	ClonaPalabras(
	char *szPalabraLeida,					// Palabra a clonar
	char szPalabrasSugeridas[][TAMTOKEN],	//Lista de palabras clonadas
	int &iNumSugeridas);					//Numero de elementos en la lista

void	ListaCandidatas		(
	char szPalabrasSugeridas[][TAMTOKEN],	//Lista de palabras clonadas
	int iNumSugeridas,						//Lista de palabras clonadas
	char szPalabras[][TAMTOKEN],			//Lista de palabras del diccionario
	int iEstadisticas[],					//Lista de las frecuencias de las palabras
	int iNumElementos,						//Numero de elementos en el diccionario
	char szListaFinal[][TAMTOKEN],			//Lista final de palabras a sugerir
	int  iPeso[],							//Peso de las palabras en la lista final
	int &iNumLista);						//Numero de elementos en la szListaFinal

