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
    char vetor[11] = "          ";
    char i;
    
    initLCD();

    lcd(0,0,"Curta Eletronica");
    lcd(0,1,"          EEPROM");

    if( EEPROM_read(0) == 255 )
        for( i=0; i<10; i++ )
            EEPROM_write(i,i+'0' );
        
    for( i=0; i<10; i++ )
        vetor[i] = EEPROM_read(i);

    lcd(0,1, vetor );

    delay(5000);
    
    for( i=0; i<10; i++ )
       EEPROM_write(i,vetor[(i+1)%10] );

    for( i=0; i<10; i++ )
       vetor[i] = EEPROM_read(i);

    lcd(0,1, vetor );

    while( 1 )                      // Laço de repetição infinita.
    {
        
    }
    return;
}
//***************** Fim do Programa Principal
