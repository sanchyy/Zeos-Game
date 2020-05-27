#include <buffer.h>

char c_buff[BS];
int r_p = 0; // read pointer
int w_p = 0; // write pointer

int read_buffer(char *c) {
    if (r_p == w_p)  // No queden variables per llegir
       return 0;
    copy_to_user(c_buff[r_p++ % BS], c, 1);
    return 1;
}

void write_buffer(char c) {
    c_buff[w_p++ % BS] = c;
}
