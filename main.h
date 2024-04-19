#include "nodos.h"
#ifndef MAIN_H
#define MAIN_H

// Constantes
#define tamanoArray 10000
#define tamanoFila 100
#define tamanoColumna 100

// Prototipos de funciones
void llenarArreglo(int *arreglo, int tamano);
void llenarMatriz(int matriz[][tamanoColumna], int filas, int columnas);
int busquedaBinariaArreglo(int arreglo[], int dato, int inicio, int fin);
int busquedaBinariaMatriz(int matriz[][tamanoColumna], int filas, int columnas, int dato);
void buscarReArreglo(Node* head, int arreglo[], int longitud, int indice); 
void buscarReMatriz(Node* head, int matriz[][tamanoColumna], int filas, int columnas, int fila, int columna);

#endif