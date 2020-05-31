#include <buffer.h>
#include <errno.h>

r_p = 0;
w_p = 0;
count = 0;

void read_buffer(char *c) {
	if(count == 0) return -EAGAIN;// No queden variables per llegir, buffer buit
    copy_to_user(&c_buff[r_p++%BS], c, 1);
    --count;
    return 1;
}

void write_buffer(char c) {
	if(count >= 256) return -ENOMEM
    c_buff[w_p++%BS] = c;
    ++count;
}
