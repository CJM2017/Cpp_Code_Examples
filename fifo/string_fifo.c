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

void put_fifo(fifo_t *F, char *msg) {
    if (((F->wptr + 1) % MAXINFO) != F->rptr) {
        F->messages[F->wptr] = msg;
        F->wptr = (F->wptr + 1) % MAXINFO; 
    }
}

char* get_fifo(fifo_t *F) {
    char * msg;
    if (F->rptr != F->wptr) {
        msg = F->messages[F->rptr];
        F->rptr = (F->rptr + 1) % MAXINFO;
        return msg;
    }
    return "None";
}

unsigned fifo_size(fifo_t *F) {
    if (F->wptr >= F->rptr) {
        return F->wptr - F->rptr + 1;
    }
    else {
        return MAXINFO - (F->rptr - F->wptr);
    }
}
//
//          **_INIT_**
//     0    1    2    3    4 
//  ---------------------------
//  | W,R |    |    |    |    |
//  ---------------------------
//
//           **_PUT_**
//
//     0    1    2    3    4 
//  --------------------------
//  | R  | W  |    |    |    |
//  --------------------------
//
//           **_PUT_**
//
//     0    1    2    3    4 
//  --------------------------
//  | R  |    | W  |    |    |
//  --------------------------
//
//           **_PUT_**
//
//     0    1    2    3    4 
//  --------------------------
//  | R  |    |    | W  |    |
//  --------------------------
//
//           **_PUT_**
//
//     0    1    2    3    4 
//  --------------------------
//  | R  |    |    |    | W  |
//  --------------------------
//
// Cannot put beyond this







