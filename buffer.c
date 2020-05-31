#include <buffer.h>
#include <errno.h>

r_p = 0;
w_p = 0;
count = 0;

void read_buffer(char *c) {
	if(count == 0) return -EAGAIN;
    if (r_p == w_p) return -EAGAIN;  // No queden variables per llegir
    if (w_p == BS) return -ENOMEM;
    copy_to_user(&c_buff[r_p++], c, 1);
    --count;
    return 1;
}

void write_buffer(char c) {
    if (w_p == BS) return -ENOMEM;
    c_buff[w_p++] = c;
    ++count;
}
