/* 
 * File:   fila.h
 * Author: felipe
 *
 * Created on 22 de Setembro de 2019, 14:04
 */

#ifndef FILA_H
#define	FILA_H

template <typename T> class Fila {
public:
    Fila(unsigned int max_itens);
    ~Fila();
    void push(const T & data);
    T pop();
    bool empty() const;
    bool cheia() const;
    unsigned int size() const;
private:
    unsigned int _N, _cap;
    T * _buffer;
    unsigned int _inicio, _fim;
};

#endif	/* FILA_H */

