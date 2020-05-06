#include <buffer.h>

int read_buffer(char *c) {
    if (r_p == w_p)  // No queden variables per llegir
        return 0;
    *c = c_buff[r_p++ % BS];
    return 1;
}

int write_buffer(char c) {
    if (w_p == r_p) // hem omplert el buffer
        return 0;
    c_buff[w_p++ % BS] = c;
    return 1;
}