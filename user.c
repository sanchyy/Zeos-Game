#include <libc.h>

char pantalla[25][80];
char *p_pantalla = &pantalla[0][0];
char c;
char *c_pointer = &c;

int __attribute__ ((__section__(".text.main")))
  main(void)
{


/* Omplim pantalla*/
int i, j;
	for(i = 0; i < 25; i++){
		for (j = 0; j < 80; j++){
			pantalla[i][j] = 'X';
		}
	}
	
	while(1) {
		if(get_key(c_pointer)){
			if (*c_pointer == 'c') put_screen(p_pantalla);
		}
	}
}

/*------------- JUEGO DE PRUEBAS get_key(char *c) ---------------
char c;
char *c_pointer = &c;

int __attribute__ ((__section__(".text.main")))
  main(void)
{

  while(1) {
	  if(get_key(c_pointer)){
		if (*c_pointer == 'c') write(1, "OK!", 3);
	}
	   }
}
--------------------------------------------------------------*/
