#include <buffer.h>

r_p = 0;
w_p = 0;

int read_buffer(char *c) {
    if (r_p == w_p)  // No queden variables per llegir
       return 0;
    copy_to_user(c_buff[r_p++ % BS], c, 1);
    //*c = c_buff[r_p++ % BS];
    return 1;
}

void write_buffer(char c) {
    c_buff[w_p++ % BS] = c;
}
