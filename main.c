#include <stdio.h>
#include <time.h> // Para la función clock()
#include "main.h"

int main() {
    int array_secuencial[tamanoArray];
    int matriz_secuencial[tamanoFila][tamanoColumna];
    
    llenarArregloSecuencial(array_secuencial, tamanoArray);
    llenarMatrizSecuencial(matriz_secuencial, tamanoFila, tamanoColumna);
    
    int datoABuscar = 0;
    printf("Ingrese el elemento del arreglo a buscar: ");
    scanf("%d", &datoABuscar);

    
    clock_t tempInicioArreglo = clock();
    int posicionArreglo = busquedaBinariaArreglo(array_secuencial, datoABuscar, 0, tamanoArray - 1);
    clock_t tempFinArreglo = clock();
    double tiempoArreglo = (double)(tempFinArreglo - tempInicioArreglo) / CLOCKS_PER_SEC;

    printf("El dato %d se encuentra en el índice (arreglo): %d\n", datoABuscar, posicionArreglo);
    printf("Tiempo de búsqueda en el arreglo: %.6f segundos\n", tiempoArreglo);
    
    
    clock_t tempInicioMatriz = clock();
    int posicionMatriz = busquedaBinariaMatriz(matriz_secuencial, tamanoFila, tamanoColumna, datoABuscar);
    clock_t tempFinMatriz = clock();
    double tiempoMatriz = (double)(tempFinMatriz - tempInicioMatriz) / CLOCKS_PER_SEC;

    printf("El dato %d se encuentra en la fila y columna (matriz): [%d][%d]\n", datoABuscar, posicionMatriz / tamanoColumna, posicionMatriz % tamanoColumna);
    printf("Tiempo de búsqueda en la matriz: %.6f segundos\n", tiempoMatriz);
    
    return 0;
}


// ---------------------- LLENADO DE VECTORES --------------------------------
void llenarArregloSecuencial(int *arreglo, int tamano) {
    for (int i = 0; i < tamano; i++) arreglo[i] = i;
}

void llenarMatrizSecuencial(int matriz[][tamanoColumna], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = i * columnas + j;
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
