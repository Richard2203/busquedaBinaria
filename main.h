#ifndef MAIN_H
#define MAIN_H

// Constantes
#define tamanoArray 10000
#define tamanoFila 100
#define tamanoColumna 100

// Prototipos de funciones
void llenarArregloSecuencial(int *arreglo, int tamano);
void llenarMatrizSecuencial(int matriz[][tamanoColumna], int filas, int columnas);
int busquedaBinariaArreglo(int arreglo[], int dato, int inicio, int fin);
int busquedaBinariaMatriz(int matriz[][tamanoColumna], int filas, int columnas, int dato);

#endif