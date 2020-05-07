#include <libc.h>

char buff[24];

int pid;

unsigned char c;

int __attribute__ ((__section__(".text.main")))
  main(void)
{
    /* Next line, tries to move value 0 to CR3 register. This register is a privileged one, and so it will raise an exception */
     /* __asm__ __volatile__ ("mov %0, %%cr3"::"r" (0) ); */
     

  while(1) {
	  if(get_key(&c)){
		  itoa(c, buff);
			write(1, buff, 4);
//		if (*c == "c") write(1, "\nOK!", 3);
	}
	   }
}
