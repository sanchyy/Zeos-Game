#include <buffer.h>
#include <errno.h>

r_p = 0;
w_p = 0;

int read_buffer(char *c) {
    if (r_p == w_p)  // No queden variables per llegir
       return 0;
    if (w_p == BS-1) return -1;
    copy_to_user(&c_buff[r_p++], c, 1);
    //*c = c_buff[r_p++];
    return 1;
}

void write_buffer(char c) {
    if (w_p == BS-1) return -1;
    c_buff[w_p++] = c;
}
