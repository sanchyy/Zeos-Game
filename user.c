#include <libc.h>

char pantalla[25][80];
char *p_pantalla = &pantalla[0][0];
char c;
char *c_pointer = &c;


//posicio inicial de la nau
pos_x_nau = 40;
pos_y_nau = 20;

int __attribute__ ((__section__(".text.main")))
  main(void)
{
	omplir_pantalla(pos_x_nau,pos_y_nau);
	put_screen(p_pantalla);
	while(1) {
		if(get_key(c_pointer)){
			if (*c_pointer == 'a') {
				omplir_pantalla(--pos_x_nau, pos_y_nau);
				put_screen(p_pantalla);
			}
			if (*c_pointer == 'd'){
				omplir_pantalla(++pos_x_nau, pos_y_nau);
				put_screen(p_pantalla);
			}
		}
	}
}

void omplir_pantalla(int x, int y){
	int i, j;
	for (j = 0; j < 80; j++){
		for(i = 0; i < 25; i++){
			if(i == y && j == x) pantalla[i][j] = 'O';
			else pantalla[i][j] = ' ';
		}
	}
	
}


/* //------------- JUEGO DE PRUEBAS NAVE put_screen(char *s) + get_key(char *c) ------------
 char pantalla[25][80];
char *p_pantalla = &pantalla[0][0];
char c;
char *c_pointer = &c;


//posicio inicial de la nau
pos_x_nau = 40;
pos_y_nau = 20;

int __attribute__ ((__section__(".text.main")))
  main(void)
{
	omplir_pantalla(pos_x_nau,pos_y_nau);
	put_screen(p_pantalla);
	while(1) {
		if(get_key(c_pointer)){
			if (*c_pointer == 'a') {
				omplir_pantalla(--pos_x_nau, pos_y_nau);
				put_screen(p_pantalla);
			}
			if (*c_pointer == 'd'){
				omplir_pantalla(++pos_x_nau, pos_y_nau);
				put_screen(p_pantalla);
			}
		}
	}
}

void omplir_pantalla(int x, int y){
	int i, j;
	for (j = 0; j < 80; j++){
		for(i = 0; i < 25; i++){
			if(i == y && j == x) pantalla[i][j] = 'O';
			else pantalla[i][j] = ' ';
		}
	}
	
}
 
 *///-------------------------------------------------------




/* //------------- JUEGO DE PRUEBAS put_screen(char *s) ------------
 char pantalla[80][25];
char *p_pantalla = &pantalla[0][0];
char c;
char *c_pointer = &c;

int __attribute__ ((__section__(".text.main")))
  main(void)
{


int i, j;
	for(i = 0; i < 80; i++){
		for (j = 0; j < 25; j++){
			pantalla[i][j] = 'X';
		}
	}
	
	while(1) {
		if(get_key(c_pointer)){
			if (*c_pointer == 'c') {
				put_screen(p_pantalla);
			}
		}
	}
}
//---------------------------------------------------------------*/


/* //------------- JUEGO DE PRUEBAS get_key(char *c) ---------------
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
//--------------------------------------------------------------*/
