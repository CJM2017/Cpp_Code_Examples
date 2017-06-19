// 
//  Project : Fifo Queue for Strings 
//  Author  : Connor McCann 
//  Date    : 17 Jun 2017
//
#include <stdio.h>
#include "string_fifo.h"


int main(void) {
    fifo_t F;
    init_fifo(&F);
    F.messages[0] = "hello";
    printf("%s\n", F.messages[0]);
    return 0;
}