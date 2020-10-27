/*
 * File:   floatToHEX32.c
 * Author: dylan
 *
 * Created on 26 October 2020, 3:17 PM
 */


#include "xc.h"
#include <stdint.h>
#include <stdio.h>

float myFloat = 68.420;
char data[64];

//Function inputs float(input) and returns 32bit HEX
uint32_t floatToHEX32(float input){
  //Union for converting float to bytes
  union {
    float   conFloat;
    uint8_t conBytes[4];
  } con;
  
  con.conFloat = input;
  
  return  ((uint32_t)con.conBytes[3] << 24) | 
          ((uint32_t)con.conBytes[2] << 16) | 
          ((uint32_t)con.conBytes[1] << 8) | 
          con.conBytes[0];
}

int main(void) {
    sprintf(data, "%8lX,%8lX,%8lX,%8lX,%8lX,%8lX", 
            floatToHEX32(1), 
            floatToHEX32(2), 
            floatToHEX32(3), 
            floatToHEX32(-69), 
            floatToHEX32(0.0000235), 
            floatToHEX32(45));
    return 0;
}
