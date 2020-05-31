#include <buffer.h>
#include <errno.h>

r_p = 0;
w_p = 0;
count = 0;

int read_buffer(char *c) {
	if(count == 0) return 0;// No queden variables per llegir, buffer buit
    copy_to_user(&c_buff[r_p++], c, 1);
    --count;
    return 1;
}

int write_buffer(char c) {
	if(count >= 256) return 0; //no hay espacio en el buffer. Buffer ple
    c_buff[w_p++ % BS] = c;
    ++count;
    return 1;
}
