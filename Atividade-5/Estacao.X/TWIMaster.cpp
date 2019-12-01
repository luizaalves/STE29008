/* 
 * File:   TWIMaster.cpp
 * Author: marcone
 * 
 * Created on 30 de Outubro de 2019, 08:36
 */

#include "TWIMaster.h"

TWIMaster::TWIMaster(unsigned long freq) {  // speed, modo (leitura/ escrita), quantidade de escravos, e array de endere�os de escravos
    TWBR = ((F_CPU/freq)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1)))));
}
TWIMaster::~TWIMaster() {
}
uint8_t TWIMaster::Start(char write_address){				/* TWI start function */
	uint8_t status;											/* Declarar vari�vel */
	TWCR = (1<<TWSTA)|(1<<TWEN)|(1<<TWINT);					/* Ative o TWI, gere condi��o de in�cio e limpe o sinalizador de interrup��o */
	while (!(TWCR & (1<<TWINT)));							/* Aguarde at� que o TWI termine seu trabalho atual (condi��o inicial) */
	status = TWSR & 0xF8;									/* Leia o registro de status TWI com mascaramento de tr�s bits inferiores */
	if (status != 0x08){									/* Verificar a condi��o de in�cio foi transmitida com sucesso ou n�o? */
        return 0;											/* Caso contr�rio, retorne 0 para indicar falha na condi��o de in�cio */
	}
    TWDR = write_address;									/* Se sim, escreva SLA + W no registro de dados TWI */
	TWCR = (1<<TWEN)|(1<<TWINT);							/* Ative o TWI e limpe o sinalizador de interrup��o */
	while (!(TWCR & (1<<TWINT)));							/* Aguarde at� o TWI concluir seu trabalho atual (opera��o de grava��o) */
	status = TWSR & 0xF8;									/* Leia o registro de status TWI com mascaramento de tr�s bits inferiores */	
	if (status == 0x18){									/* Verifique se o SLA + W foi transmitido e ack recebido ou n�o?  */
        return 1;											/* Se sim, retorne 1 para indicar a confirma��o recebida, ou seja, pronto para aceitar o byte de dados */
	}
    if (status == 0x20){									/* Verifique o SLA + W foi transmitido e o nack recebido ou n�o? */
        return 2;											/* Se sim, retorne 2 para indicar o nack recebido, ou seja, o dispositivo est� ocupado */
	}else
        return 3;											/* Caso contr�rio, retorne 3 para indicar falha no SLA + W */
}

/*IN�CIO REPETIDO(Sr)
    - Condi��o START REPETIDA emitida pelo mestre.
    - � gerado emitindo outra condi��o START para iniciar uma nova transmiss�o.
    - A condi��o START REPEATED com endere�o de dispositivo escravo (SLA) � emitida entre a condi��o START e STOP
    Fun��o Repeated_Start - gera a condi��o REPEATED START para opera��o de leitura.
    Argumento de entrada: - possui argumento de entrada do endere�o de leitura do dispositivo escravo (SLA + R).
    Retorno: - retorna o status do evento.
 */
uint8_t TWIMaster::Repeated_Start(char read_address){				/* TWI repeated start function */
	uint8_t status;											/* Declarar vari�vel */
	TWCR = (1<<TWSTA)|(1<<TWEN)|(1<<TWINT);					/* Ative o TWI, gere condi��o de in�cio e limpe o sinalizador de interrup��o */
	while (!(TWCR & (1<<TWINT)));							/* Aguarde at� que o TWI termine seu trabalho atual (condi��o inicial) */
	status = TWSR & 0xF8;									/* Leia o registro de status TWI com mascaramento de tr�s bits inferiores */
	if (status != 0x10){									/* Verifique a condi��o de in�cio repetido foi transmitida com sucesso ou n�o? */
        return 0;											/* Se n�o, retorne 0 para indicar falha de condi��o de in�cio repetida */
	}
    TWDR = read_address;									/* Se sim, escreva SLA + R no registro de dados TWI */
	TWCR = (1<<TWEN)|(1<<TWINT);							/* Ative o TWI e limpe o sinalizador de interrup��o */
	while (!(TWCR & (1<<TWINT)));							/* Aguarde at� o TWI concluir seu trabalho atual (opera��o de grava��o) */
	status = TWSR & 0xF8;									/* Leia o registro de status TWI com mascaramento de tr�s bits inferiores */
	if (status == 0x40){									/* Verifique se o SLA + R foi transmitido e ack aceito ou n�o? */
        return 1;											/* Se sim, retorne 1 para indicar a confirma��o recebida */ 
	}
    if (status == 0x20){									/* Verificar SLA + R foi transmitido e nack recebido ou n�o? */
        return 2;											/* Se sim, retorne 2 para indicar o nack recebido, ou seja, o dispositivo est� ocupado */
	}else
        return 3;											/* Outro retorno 3 para indicar falha no SLA + R */
}

/*PARAR(P)
    - Evento STOP emitido pelo mestre para indicar que ele deve parar.
    - � gerado pela transi��o Baixa para Alta no SDA enquanto o SCL � Alto.
    Fun��o Stop - inicia a condi��o STOP
    Argumento de entrada: - n�o possui argumento de entrada.
    Retorno: - n�o retorna nenhum tipo de dado.
 */
void TWIMaster::Stop(){											/* TWI stop function */
	TWCR=(1<<TWSTO)|(1<<TWINT)|(1<<TWEN);					/* Ative o TWI, gere a condi��o de parada e limpe o sinalizador de interrup��o */
	while(TWCR & (1<<TWSTO));								/* Aguarde at� a execu��o da condi��o de parada */
}

void TWIMaster::Start_Wait(char write_address){					/* I2C start wait function */
	uint8_t status;											/* Declarar vari�vel */
	while (1)
	{
		TWCR = (1<<TWSTA)|(1<<TWEN)|(1<<TWINT);				/* Ative o TWI, gere condi��o de in�cio e limpe o sinalizador de interrup��o */
		while (!(TWCR & (1<<TWINT)));						/* Aguarde at� que o TWI termine seu trabalho atual (condi��o inicial) */
		status = TWSR & 0xF8;								/* Leia o registro de status TWI com mascaramento de tr�s bits inferiores */
		if (status != 0x08){								/* Verifique se a condi��o de in�cio foi transmitida com sucesso ou n�o? */
            continue;										/* Se n�o, continue com o loop inicial novamente */
		}
        TWDR = write_address;								/* Se sim, escreva SLA + W no registro de dados TWI */
		TWCR = (1<<TWEN)|(1<<TWINT);						/* Ative o TWI e limpe o sinalizador de interrup��o */
		while (!(TWCR & (1<<TWINT)));						/* Aguarde at� o TWI concluir seu trabalho atual (opera��o de grava��o) */
		status = TWSR & 0xF8;								/* Leia o registro de status TWI com mascaramento de tr�s bits inferiores */
		if (status != 0x18 ){								/* Verifique se o SLA + W foi transmitido e o ack recebido ou n�o? */
			Stop();                                         /* Caso contr�rio, gere a condi��o de parada */
			continue;										/* Continue com o loop inicial novamente */
		}
		break;												/* Se sim, interrompa o loop */
	}
}

/*ESCREVA(W)
    - O evento WRITE data / address � emitido pelo mestre ap�s o reconhecimento bem-sucedido do START recebido do dispositivo escravo.
    Fun��o Write - grava dados/endere�o no barramento
    Argumento de entrada: - possui argumento de entrada de dados / endere�o.
    Retorno: - retorna o status do evento.
 */
uint8_t TWIMaster::Write(char data){								/* TWI write function */
	uint8_t status;											/* Declarar vari�vel */
	TWDR = data;											/* Copiar dados no registro de dados TWI */
	TWCR = (1<<TWEN)|(1<<TWINT);							/* Ative o TWI e limpe o sinalizador de interrup��o */
	while (!(TWCR & (1<<TWINT)));							/* Aguarde at� o TWI concluir seu trabalho atual (opera��o de grava��o) */
	status = TWSR & 0xF8;									/* Leia o registro de status TWI com mascaramento de tr�s bits inferiores */
	if (status == 0x28){									/* Verifique se os dados foram transmitidos e ack recebido ou n�o? */
        return 0;											/* Se sim, retorne 0 para indicar que a confirma��o foi recebida */
	}
    if (status == 0x30){									/* Verificar se os dados foram transmitidos e nack recebido ou n�o? */
        return 1;											/* Se sim, retorne 1 para indicar nack recebido */
	}else
        return 2;											/* Outro retorno 2 para indicar falha na transmiss�o de dados */
}

/*LER(R)
    - O evento de leitura de dados � emitido pelo mestre ap�s a condi��o REPEATED START bem-sucedida.
    Fun��o Read_Ack - l� dados dispon�veis na linha SDA e retorna ao dispositivo escravo a confirma��o sobre a leitura bem-sucedida dos dados,
    e tamb�m informa ao escravo para transmitir outros dados.
    Argumento de entrada: - n�o possui argumento de entrada.
    Retorno: - retorna dados recebidos.
 */
char TWIMaster::Read_Ack(){										/* TWI read ack function */
	TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);					/* Ativar TWI, gerar o ack e limpar o sinalizador de interrup��o */
	while (!(TWCR & (1<<TWINT)));							/* Aguarde at� o TWI concluir seu trabalho atual (opera��o de leitura) */
	return TWDR;											/* Retornar dados recebidos */
}	

/*Fun��o Read_Nack - l� o �ltimo byte de dados necess�rio dispon�vel na linha SDA,mas n�o retorna o reconhecimento. 
    - Indica ao escravo que o mestre n�o deseja os pr�ximos dados e deseja interromper a comunica��o.
    Argumento de entrada: - n�o possui argumento de entrada.
    Retorno: - retorna os dados recebidos.
 */

char TWIMaster::Read_Nack(){										/* TWI read nack function */
	TWCR=(1<<TWEN)|(1<<TWINT);								/* Ative o TWI e limpe o sinalizador de interrup��o */
	while (!(TWCR & (1<<TWINT)));							/* Aguarde at� o TWI concluir seu trabalho atual (opera��o de leitura) */
	return TWDR;											/* Retornar dados recebidos */
}	
void TWIMaster::write(const char* data,uint8_t bytes, uint8_t addr,uint8_t reg) {
    Start_Wait(addr & ~1);              /* Inicia o I2C com o endere�o de grava��o do dispositivo */   
    Write(reg);                         /* Endere�o de mem�ria inicial para grava��o de dados */
    for (int i = 0; i<bytes; i++){      /* Escrevendo array de dados */
        Write(data[i]); 
    }
    Stop();
}

void TWIMaster::receive(char* data,uint8_t bytes, uint8_t addr,uint8_t reg) {
    
    Start_Wait(addr & ~1);                   /* Inicia o I2C com o endere�o de grava��o do dispositivo */   
    Write(reg);                         /* Endere�o de mem�ria inicial para grava��o de dados */
    Repeated_Start(addr | 1);
    for (int i = 0; i< bytes; i++){     /* Lendo os dados com ack */
        if(i == bytes -1){
            data[i] = Read_Nack();                        /* Lendo os dados com nack */
        }else{
            data[i] = Read_Ack();
        }
    }
    Stop();
}