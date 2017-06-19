// 
//  Project : Fifo Queue for Strings 
//  Author  : Connor McCann 
//  Date    : 17 Jun 2017
//
#include "string_fifo.h"

void init_fifo(fifo_t *F) {
    // Put both pointers at 0th position
    F->wptr = 0;
    F->rptr = 0;
    return;
}