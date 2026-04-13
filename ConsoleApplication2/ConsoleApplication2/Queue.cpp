#include "Queue.h"
#include <iostream>
using namespace std;
#define MAX_SIZE 256 /* capacidad máxima */
typedef char almacen[MAX_SIZE];

int cabeza; /* puntero de lectura */
int cola; /* puntero de escritura */
int ITEMS; /* número de elementos en la lista */
int ITEMSIZE; /* tamaño de cada elemento */
almacen alma; /* el almacen */

// constructor
Queue::Queue() {
    cabeza = 0;
    cola = 0;
    ITEMS = 0;
    ITEMSIZE = 1;
}

// destructor
Queue::~Queue() {}

// regresa 1 (true) si la lista está vacia
int Queue::empty() { return ITEMS == 0; }

// insertar elemento a la lista
int Queue::put(int d)
{
    if (ITEMS == MAX_SIZE) return -1;
    if (cola >= MAX_SIZE) { cola = 0; }
    alma[cola] = d;
    cola++;
    ITEMS++;
    return d;
}

// retirar elemento de la lista
int Queue::get()
{
    char d;
    if (empty()) return -1;
    if (cabeza >= MAX_SIZE) { cabeza = 0; }
    d = alma[cabeza];
    cabeza++;
    ITEMS--;
    return d;
}

// regresa el n£mero de elementos en lista
int Queue::size() { return ITEMS; }