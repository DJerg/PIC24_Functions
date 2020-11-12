/* 
 * File:                floatHEX.h
 * Author:              Dylan Jerg
 * Comments:            Fast conversion from floats to HEX for dumping data
 *                      In high speed loops
 * 
 * Time to execute fHexString @16MHz ~= 2.5   + (8.25*number) in us
 * Instructions                      ~= 36    + (134 *number)
 * 
 * Size of buffer required            = (9*number)-1
 * 
 * Revision history:    Added compatibility for long doubles 12-09-2020
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_FLOATHEX_H
#define	XC_FLOATHEX_H

void fHexString(char *buffer, uint16_t number, ...);
void ldHexString(char *buffer, uint16_t number, ...);

#endif	/* XC_FLOATHEX_H */

