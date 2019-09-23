/* 
 * File:   fila.cpp
 * Author: felipe
 * 
 * Created on 22 de Setembro de 2019, 14:04
 */

#include "fila.h"

template <typename T> Fila<T>::Fila(unsigned int max_itens) {
    _cap = max_itens;
    _N = 0;
    _inicio = 0;
    _fim = 0;
    _buffer = new T[_cap];
   
}

template <typename T> Fila<T>::~Fila() {
    delete[] _buffer;
}

template <typename T> void Fila<T>::push(const T& data) {
    if(this->cheia()) throw -1;
    _buffer[_fim] = data;
    _N++;
    _fim++;
    if(_fim == _cap) _fim = 0;      
}

template <typename T> T Fila<T>::pop() {
    if(this->empty()) throw -1;
    T temp=_buffer[_inicio];
    _N--;
    _inicio++;
    if(_inicio == _cap) _inicio=0;
    return temp;
}

template <typename T> bool Fila<T>::empty() const {
    return (_N == 0);
}

template <typename T> bool Fila<T>::cheia() const {
    return (_N == _cap);
}

template <typename T> unsigned int Fila<T>::size() const {
    return _N;
}
