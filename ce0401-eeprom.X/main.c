/*
 * File:   main.c
 * Author: curtaeletronica
 *
 * Created on 10 de Janeiro de 2010, 16:23
 * 
 * IDE:         MPLAB X IDE v3.15
 * Compiler:    XC8 v1.45
 * OS:          Deepin 15.11 X86_64
 * Kernel:      4.15.0-30deepin-generic
 * 
 * Objetivo: 
 *      Apresentar mensagens em display LCD através de barramento de 8 vias.
 * 
 * Pinos    |nº     |Conexão
 *  VDD     |11,32  | Alimentação (Vcc/+5V)
 *  VSS     |12,31  | Alimentação (GND/0V)
 *  RD0     |19     | LCD_D4 (LCD_Data 4)
 *  RD1     |20     | LCD_D5
 *  RD2     |21     | LCD_D6
 *  RD3     |22     | LCD_D7
 *  RD4     |27     | LCD_RS
 *  RD5     |28     | LCD_EN
 *  RD6     |29     | LCD_B0
 *  RD7     |30     | LCD_B1
 * 
*/

//***************** Bibliotecas
#include <xc.h>
#include "config.h"
#include "lcd4bitBus.h"
#include "eeprom.h"

void delay( long t )
{
    while( t )
    {
        __delay_ms(1);
        --t;
    }
}

//***************** Programa Principal
void main(void)
{
    char vetor[10] = "         ";
    delay(1000);
    initLCD();
    delay(1000);
    lcd(0,0,"     EEPROM     ");
    lcd(0,1,"Curta Eletronica");


    vetor[0] = EEPROM_read(0);
    vetor[1] = EEPROM_read(1);
    vetor[2] = EEPROM_read(2);
    vetor[3] = EEPROM_read(3);
    lcd(0,1, vetor );

    delay(5000);

    
    EEPROM_write(0,'1');
    EEPROM_write(1,'2');
    EEPROM_write(2,'3');
    EEPROM_write(3,'4');
    
    vetor[0] = EEPROM_read(0);
    vetor[1] = EEPROM_read(1);
    vetor[2] = EEPROM_read(2);
    vetor[3] = EEPROM_read(3);
    lcd(0,1, vetor );
    while( 1 )                      // Laço de repetição infinita.
    {
        
    }
    return;
}
//***************** Fim do Programa Principal
