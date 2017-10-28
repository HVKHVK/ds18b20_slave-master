/*
 *HVKHVK
 */
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#include "ds18b20.h"
#include "usitwislave.h"

#define DEVICE_ID 0x0B
int16_t temp;
int8_t result;
int8_t tempreturn;

static void twi_callback(uint8_t input_buffer_length, const uint8_t *input_buffer,
                         uint8_t *output_buffer_length, uint8_t *output_buffer)
{
    if(input_buffer_length > 0){
        temp = 0;
        
        ds18b20convert( &PORTB, &DDRB, &PINB, ( 1 << 4 ), NULL );
        
        _delay_ms( 1000 );
        
        ds18b20read( &PORTB, &DDRB, &PINB, ( 1 << 4 ), NULL, &temp );
        
        temp = (temp & 0x0FF0);
        tempreturn = (int8_t)(temp >> 4);
        result = tempreturn;
        
    }else{
        *output_buffer_length = 8;
        *output_buffer = result;
    }
}

int main( )
{
    usi_twi_slave(DEVICE_ID, 1, *twi_callback, 0);
	return 0;
}
