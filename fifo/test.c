// 
//  Project : Fifo Queue for Strings 
//  Author  : Connor McCann 
//  Date    : 17 Jun 2017
//
#include <stdio.h>
#include "string_fifo.h"


int main(void) {
    fifo_t F;
    init_fifo(&F, 3);
    put_fifo(&F, "Hello");
    put_fifo(&F, "cruel");
    put_fifo(&F, "world!!!!");

    char *msg1 = get_fifo(&F);
    char *msg2 = get_fifo(&F);
    char *msg3 = get_fifo(&F);
    printf("%s\n", msg3);
    printf("%d\n",fifo_size(&F));
    return 0;
}