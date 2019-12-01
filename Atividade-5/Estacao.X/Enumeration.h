/* 
 * File:   Principal.h
 * Author: felipe
 *
 * Created on 30 de Novembro de 2019, 23:28
 */

#ifndef ENUMERATION_H
#define	ENUMERATION_H

enum EVENT_t {
    READ_ATUAL = 1,
    CONFIG = 2,
    TIMEOUT_MEDIDA = 3,
    MAX_MEDIDAS = 4,
    READ_OK = 5,
    WRITE_OK = 6,
    SINC_OK = 7,
    UP_OK = 8,
    TIMEOUT = 9,
    SET_INTERVAL = 10
};

enum STATE_t {
    IDLE = 1,
    READ_1 = 2,
    READ_2 = 3,
    WRITE = 4,
    WAIT_CONFIG = 5,
    UPLOAD = 6,
    SINC = 7
};

#endif	/* ENUMERATION_H */

