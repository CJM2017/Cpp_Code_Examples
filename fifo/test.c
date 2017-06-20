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
    put_fifo(&F, "Hello");
    put_fifo(&F, "cruel");
    put_fifo(&F, "world");
    char *msg = get_fifo(&F);
    printf("%s\n", msg);
    printf("%d\n",fifo_size(&F));
    return 0;
}