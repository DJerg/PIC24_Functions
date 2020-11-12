#include <stdint.h>
#include <stdarg.h>
#include "floatHEX.h"

char nibToHEX(uint8_t nib){
    nib &= 0x0F;                    //Only accept a nib
    if(nib < 10){                   //If number add number to 0x30
        return 0x30 + nib;          //0x30 is "0" in ASCII
    }
                                    //If letter add the letter number to 0x41
    return 0x41 + (nib-0x0A);       //0x41 is "A" in ASCII
}

void sFHexString(float _float, char *output, uint8_t addComma){
    uint8_t _i = 0;
    
    union {
        float   Float;
        uint8_t Bytes[4];
    } CON;
    CON.Float = _float;
    
    for(_i = 0;_i<4;_i++){
        output[(_i)*2]      = nibToHEX((CON.Bytes[3-_i] & 0xF0) >> 4);
        output[((_i)*2)+1]  = nibToHEX(CON.Bytes[3-_i] & 0x0F);
    }
    
    output[8] = addComma*',';
}


/* Creates string of HEX values split with ','s of any amount
 * Inputs:
 *  *buffer     => Your out put char array
 *  number      => Number of floats expected
 *  ...         => All float separated by ','s
 * 
 * Example:
 *  fHexString(myCharArray, 2, 3.1415926, 2.7182818);
 * myCharArray:
 *  40490FDA,402DF854
 */
void fHexString(char *buffer, uint16_t number, ...){
    va_list arg;
    va_start(arg, number);
    uint16_t _i = 0;
    for(_i=0;_i<number;_i++){
        sFHexString(va_arg(arg, float),&buffer[_i*9],(_i==number-1?0:1));
    }
    va_end(arg);
}

/*  */
void sLDHexString(long double _ldouble, char *output, uint8_t addComma){
    uint8_t _i = 0;
    
    union {
        long double     LDouble;
        uint8_t         Bytes[8];
    } CON;
    CON.LDouble = _ldouble;
    
    for(_i = 0;_i<8;_i++){
        output[(_i)*2]      = nibToHEX((CON.Bytes[7-_i] & 0xF0) >> 4);
        output[((_i)*2)+1]  = nibToHEX(CON.Bytes[7-_i] & 0x0F);
    }
    
    output[16] = addComma*',';
}

/* Creates string of HEX values split with ','s of any amount
 * Inputs:
 *  *buffer     => Your out put char array
 *  number      => Number of long doubles expected
 *  ...         => All float separated by ','s
 * 
 * Example:
 *  ldHexString(myCharArray, 2, 3.141592653589793l, 2.718281828459045l);
 * myCharArray:
 *  400921FB54442D18,4005BF0A8B145769
 */
void ldHexString(char *buffer, uint16_t number, ...){
    va_list arg;
    va_start(arg, number);
    uint16_t _i = 0;
    for(_i=0;_i<number;_i++){
        sLDHexString(va_arg(arg, long double),&buffer[_i*17],(_i==number-1?0:1));
    }
    va_end(arg);
}
