/*
 * File:   eeprom.c
 * Author: curtaeletronica
 *
 * Created on 10 de Janeiro de 2020, 16:34
 */

#include <xc.h>

char EEPROM_read( unsigned char addr )
{
    EEADRH = 0;
    EEADR = addr;
    EECON1bits.EEPGD = 0;
    EECON1bits.RD = 1;
    return( EEDAT );
}

void EEPROM_write( unsigned char addr, unsigned char data )
{
    INTCONbits.GIE = 0;
    EEADR = addr;
    EEDAT = data;
    EECON1bits.EEPGD = 0;
    EECON1bits.WREN = 1;
    EECON2 = 0x55;
    EECON2 = 0xAA;
    EECON1bits.WR = 1;
    while( EECON1bits.WR )
        ;
    EECON1bits.WREN = 0;
    INTCONbits.GIE = 1;
}
