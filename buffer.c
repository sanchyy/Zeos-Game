#include <buffer.h>

r_p = 0;
w_p = 0;

int read_buffer(char *c) {
    if (r_p == w_p)  // No queden variables per llegir
       return 0;
    if (w_p == BS-1) return -ENOBUFS;
    copy_to_user(c_buff[r_p++], c, 1);
    return 1;
}

void write_buffer(char c) {
    if (w_p == BS-1) return -ENOBUFS;
    c_buff[w_p++] = c;
}
