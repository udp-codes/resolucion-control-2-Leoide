//
// Created by Leonardo Romero Aguilera on 07-04-16.
//

#ifndef CONTROL2_CPP_CONTROL2_HPP
#define CONTROL2_CPP_CONTROL2_HPP

#include <iostream>
using namespace std;

//PROBLEMA 1

class Data{
public:
    int    m_number;
    Data*  m_next;

    Data(int number){
        m_number = number;
        m_next = nullptr;
    }

};

class TDAconjunto{
public:
    Data* m_head;

    TDAconjunto(){m_head = nullptr}

    void insert(int x){
        Data* aux = new Data(x);
        aux->m_next = m_head;
        m_head = aux;
    }
    void agregar(int x){
        insert(x);
    }
    bool isEmpty(){
        return m_head == nullptr;
    }
    int Delete(){
        if(isEmpty())
            return nullptr;
        Data* aux = m_head;
        int x = aux->m_number;
        m_head = m_head->m_next;
        delete aux;
        return x;
    }
    int sacar(){
        int r = Delete();
        return r;
    }
    bool estaVacio(){
        if(isEmpty())
            return true;
    }
    bool pertenece(int x){
        Data* aux = m_head;

        while(aux->m_next != nullptr){
            if(aux->m_number ==x)
                return true;
            aux = aux->m_next;
        }
    }
    TDAconjunto interseccion(TDAconjunto x){
        Data* aux = m_head;
        Data* aux2 = x.m_head;
        Data* aux3 = aux2;
        TDAconjunto auxiliar;

        while(aux != nullptr){
            aux2 = aux3;
            while (aux2 != nullptr){
                if(aux == aux2)
                    auxiliar.agregar(aux->m_number);
                aux2 = aux2->m_next;
            }
            aux = aux->m_next;
        }
        return auxiliar;
    }
    TDAconjunto unirr(TDAconjunto x){
        Data* aux = m_head;
        Data* aux2 = x.m_head;
        Data* aux3 = aux2;
        TDAconjunto auxiliar;

        while(aux != nullptr){
            aux2 = aux3;
            while (aux2 != nullptr){
                if(aux != aux2)
                    auxiliar.agregar(aux->m_number);
                aux2 = aux2->m_next;
            }
            aux = aux->m_next;
        }
        return auxiliar;
    }
    void interseccionElimina(TDAconjunto x){
        TDAconjunto AUX = interseccion(x);

        Data* aux = m_head;
        Data* aux2 = AUX.m_head;
        Data* aux3 = aux2;
        Data* aux4 = aux;
        int k=0;
        while(aux != nullptr){
            aux2 = aux3;
            while (aux2 != nullptr){
                if(aux == aux2)
                    k++;
                aux2 = aux2->m_next;
            }
            if(k==0) {
                m_head = aux->m_next;
                aux4 = aux;
                delete aux4;
                aux = m_head;
            }
            else
                aux = aux->m_next;
        }
    }
    //bonus
    void unirrEliminar(TDAconjunto x){


        TDAconjunto AUX = unirr(x);
        Data* aux = m_head;
        Data* aux2 = AUX.m_head;
        Data* aux3 = aux2;
        Data* aux4 = aux;
        int k=0;
        while(aux != nullptr){
            aux2 = aux3;
            while (aux2 != nullptr){
                if(aux == aux2)
                    k++;
                aux2 = aux2->m_next;
            }
            if(k==0) {
                m_head = aux->m_next;
                aux4 = aux;
                delete aux4;
                aux = m_head;
            }
            else
                aux = aux->m_next;
        }
    }

};



#endif //CONTROL2_CPP_CONTROL2_HPP
