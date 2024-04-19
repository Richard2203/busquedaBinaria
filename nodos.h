#ifndef NODOS_H
#define NODOS_H

// NODO
typedef struct Node {
    int indice;
    struct Node* next;
} Node;

// Prototipos de las funciones NODO
void agregarNodo(Node** head, int indice);
void imprimirLista(Node* head);
void limpiarLista(Node** head);
void obtenerIndMatriz(Node* head);

#endif
