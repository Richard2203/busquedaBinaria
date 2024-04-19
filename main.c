#include <stdio.h>
#include <time.h>
#include "main.h"
#include "nodos.h"

int main() {

    //LISTAS DE ELEMENTOS REPETIDOS
    //  Array
    Node* listaRE_array= NULL;

    //  Matriz
    Node* listaRE_matriz = NULL;

    int array[tamanoArray];
    int matriz[tamanoFila][tamanoColumna];
    
    llenarArreglo(array, tamanoArray);
    array[498]=500;
    array[499]=500;
    array[500]=500;
    array[501]=500;
    llenarMatriz(matriz, tamanoFila, tamanoColumna);
    matriz[4][99]=500;
    matriz[5][0]=500;
    matriz[5][1]=500;
    matriz[5][2]=500;


    int datoABuscar = 0;
    printf("Ingrese el elemento del arreglo a buscar: ");
    scanf("%d", &datoABuscar);

    
    //------------------------------- ARREGLO ---------------------------------
    clock_t tempInicioArreglo = clock();
    int posicionArreglo = busquedaBinariaArreglo(array, datoABuscar, 0, tamanoArray - 1);
    clock_t tempFinArreglo = clock();
    double tiempoArreglo = (double)(tempFinArreglo - tempInicioArreglo) / CLOCKS_PER_SEC;

    printf("El dato %d se encuentra en el índice (arreglo): %d\n", datoABuscar, posicionArreglo);
    printf("Tiempo de búsqueda en el arreglo: %.6f segundos\n", tiempoArreglo);
    buscarReArreglo(listaRE_array, array, tamanoArray, posicionArreglo);
    imprimirLista(listaRE_array);

    //--------------------------------- MATRIZ -------------------------------------------------
    clock_t tempInicioMatriz = clock();
    int posicionMatriz = busquedaBinariaMatriz(matriz, tamanoFila, tamanoColumna, datoABuscar);
    clock_t tempFinMatriz = clock();
    double tiempoMatriz = (double)(tempFinMatriz - tempInicioMatriz) / CLOCKS_PER_SEC;

    printf("El dato %d se encuentra en la fila y columna (matriz): [%d][%d]\n", 
        datoABuscar, 
        posicionMatriz / tamanoColumna, 
        posicionMatriz % tamanoColumna
    );
    printf("Tiempo de búsqueda en la matriz: %.6f segundos\n", tiempoMatriz);
    buscarReMatriz(
        listaRE_matriz, 
        matriz,
        tamanoFila,
        tamanoColumna, 
        posicionMatriz / tamanoColumna, 
        posicionMatriz % tamanoColumna
    );
    imprimirLista(listaRE_matriz);
    return 0;
}


// ---------------------- LLENADO DE VECTORES --------------------------------
void llenarArreglo(int *arreglo, int tamano) {
    for (int i = 0, incremento=0; i < tamano; i++){ 
        //arreglo[i] = incremento+2;
        arreglo[i] = i;
    }
}

void llenarMatriz(int matriz[][tamanoColumna], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            //matriz[i][j] = 2 * (i * columnas + j);
            matriz[i][j]=(i * columnas + j);
        }
    }
}


// ---------------------  BUSQUEDA BINARIA ---------------------------------
int busquedaBinariaArreglo(int arreglo[], int dato, int inicio, int fin) {
    if (inicio > fin) return -1;  
    
    int mitad = (inicio + fin) / 2;

    if (arreglo[mitad] == dato) return mitad;

    return (dato < arreglo[mitad])
        ? busquedaBinariaArreglo(arreglo, dato, inicio, mitad - 1)
        : busquedaBinariaArreglo(arreglo, dato, mitad + 1, fin);
}

int busquedaBinariaMatriz(int matriz[][tamanoColumna], int filas, int columnas, int dato) {
    int inicio = 0;
    int fin = filas * columnas - 1;

    while (inicio <= fin) {
        int mitad = (inicio + fin) / 2;
        int fila = mitad / columnas;
        int columna = mitad % columnas;
        
        if (matriz[fila][columna] == dato) {
            return mitad;
        } else if (matriz[fila][columna] < dato) {
            inicio = mitad + 1;
        } else {
            fin = mitad - 1;
        }
    }

    return -1;
}


//-------------------------Elementos Repetidos------------------------------
// -Array
void buscarReArreglo(Node* head, int arreglo[], int longitud, int indice) {
    int elemento = arreglo[indice];

    // Lado izquierdo
    for (int i = indice - 1; i >= 0; i--) {
        if (arreglo[i] == elemento) 
            agregarNodo(&head, i);
        else break; 
    }

    // Lado derecho
    for (int i = indice + 1; i < longitud; i++) {
        if (arreglo[i] == elemento) 
            agregarNodo(&head, i); 
        else break; 
    }
    printf("Indices de lo elementos repetidos en el arreglo: ");
    imprimirLista(head);
}

// -Matriz
void buscarReMatriz(Node* head, int matriz[][tamanoColumna], int filas, int columnas, int fila, int columna) {
    int elemento = matriz[fila][columna];

    // En la fila de arriba
    for (int i = fila - 1, columAux=99; matriz[i][columAux] == elemento; columAux--) 
        agregarNodo(&head, (i*100)+columAux);
    
    // en la fila de abajo
    for (int i = fila + 1, columAux; matriz[i][columAux] == elemento; columAux) 
        agregarNodo(&head, (i*100)+columAux);

    // Lado izquierdo
    for (int j = columna - 1; j >= 0 && matriz[fila][j] == elemento; j--) 
        agregarNodo(&head, (fila*100)+j);

    // Lado derecho
    for (int j = columna + 1; j < columnas && matriz[fila][j] == elemento; j++) 
        agregarNodo(&head, (fila*100)+j);

    
    printf("Indices de lo elementos repetidos en la matriz: ");
    obtenerIndMatriz(head);
}