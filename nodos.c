#include <stdio.h>
#include <stdlib.h>
#include "nodos.h"


void agregarNodo(Node** head, int indice) {
    // Crear nuevo nodo
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Error de asignación de memoria.\n");
        exit(EXIT_FAILURE);
    }
    newNode->indice = indice;
    newNode->next = NULL;

    // Asignacion de primer nodo
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Buscando y encontrando el último nodo de la lista
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Enlazando nodos
    temp->next = newNode;
}

void imprimirLista(Node* head) {
    while (head != NULL) {
        printf("%d ", head->indice);
        head = head->next;
    }
    printf("\n");
}

void limpiarLista(Node** head) {
  Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void obtenerIndMatriz(Node* head) {
    while (head != NULL) {
        printf("[%d][%d], ", head->indice/100,head->indice%100);
        head = head->next;
    }
    printf("\n");
}