#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "Nodo.h"
using namespace std;


template <typename Tipo>
class Lista
{
public:
    Nodo<Tipo>* inicio;

    Lista()
    {
        inicio = NULL;
    }

    void imprimir()
    {
        for(Nodo<Tipo>* temp = inicio; temp!=NULL; temp = temp->sig)
        {
            cout<<temp->num<<endl;
        }
    }

    void agregarAlInicio(Tipo valor_nuevo)
    {
        Nodo<Tipo> *nuevo = new Nodo<Tipo>(valor_nuevo);

        if(inicio == NULL)
        {
            inicio = nuevo;
        }else
        {
            nuevo->sig = inicio;
            inicio = nuevo;
        }
    }

    void agregarAlFinal(Tipo valor_nuevo)
    {
        Nodo<Tipo> *nuevo = new Nodo<Tipo>(valor_nuevo);

        if(inicio == NULL)
        {
            inicio = nuevo;
        }else
        {
            Nodo<Tipo>*temp = inicio;
            while(temp->sig!=NULL)
            {
                temp=temp->sig;
            }
            temp->sig = nuevo;
        }
    }

    void borrar(Tipo valor_a_borrar)
    {
        if(inicio->num == valor_a_borrar)
        {
            Nodo<Tipo>* borrar = inicio;
            inicio = inicio->sig;
            delete borrar;
        }else
        {
            Nodo<Tipo>* temp = inicio;
            while(temp->sig->num!=valor_a_borrar)
            {
                temp=temp->sig;
                if(temp->sig==NULL)
                    return;
            }
            Nodo<Tipo>* borrar = temp->sig;
            temp->sig = temp->sig->sig;
            delete temp->sig;
        }
    }

    //Devuelve true si la lista esta vacia, de lo contrario devuelve false
    bool estaVacia()
    {
        if(inicio == NULL) //Si en inicio no hay valores existentes entonces es igual a null y resulta afirmativo la condicion
        return true; //Retorna true si es afirmativo
        return false; //De lo contrario devuelve false
    }

    //Devuelve el valor almacenado en el primer nodo de la lista
    Tipo obtenerPrimerValor()
    {
         return inicio->valor;  //Devuelve el valor con el contenido de inicio
    }

    //Devuelve el valor almacenado en el ultimo nodo de la lista
    Tipo obtenerUltimoValor()
    {
        Nodo<Tipo>*temp=NULL;  //Nodo temporal para el ciclo
        for(temp=inicio; temp->sig!=NULL; temp=temp->sig)//ciclo para recorrer la lista de nodos
        {
          //Recorre todo el ciclo for hasta llegar al ultimo
        }
        return temp->valor;  //Devuelve el valor del nodo temporal
    }

    //Devuelve el valor mayor almacenado en la lista
    Tipo obtenerMayor()
    {
     Tipo mayor=0;  //Variable para almacenar el mayor inicializado en 0
     for(Nodo<Tipo>* temp=inicio; temp!=NULL; temp = temp->sig) //Ciclo para recorrer la lista de nodos temporal
            if((temp->valor)>mayor) //condicion: si el valor de temp es mayor a la variable "mayor"
                mayor=temp->valor;  //Si es afirmativo se agrega el valor de temp a la variable mayor
     return mayor; //Devuelve el valor mayor del ciclo

    }
};
#endif // LISTA_H
