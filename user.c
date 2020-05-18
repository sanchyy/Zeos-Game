#include <libc.h>

//-------------------------- JUEGO DE PRUEBAS FRUTA ------------------
/*
//pantalla i key premuda
char pantalla[25][80];
char *p_pantalla = &pantalla[0][0];
char c;
char *c_pointer = &c;

//posicio inicial de la nau
int pos_x_nau = 40;
int pos_y_nau = 20;

//marcador
char puntuacio[3];
int puntuacio_r = 0;

//fruites
int fruita_menjada = 0;
int a;
int y_fruita = 10, x_fruita = 30;

//direcions
int direccio;

//sbrk
int *retorn;
char buffer[5];

int __attribute__ ((__section__(".text.main")))
  main(void)
{	
	direccio = 1;
	pintar_pantalla(pos_x_nau,pos_y_nau);
	put_screen(p_pantalla);
	puntuacio[0] = '0';
	a = 0;
	while(1) {
		a = gettime();
		if(get_key(c_pointer)){
			if (*c_pointer == 'a') direccio = 1;
			if (*c_pointer == 's') direccio = 4;
			if (*c_pointer == 'd') direccio = 3;
			if (*c_pointer == 'w') direccio = 2;
		}
		
		if(a %100 == 0 && direccio == 1){ //a
			if(pos_x_nau != 0 && *(p_pantalla+pos_y_nau*80 + pos_x_nau -1) != 'X'){
				if(*(p_pantalla+pos_y_nau*80 + pos_x_nau -1) == '*') {
					++puntuacio_r;
					itoa(puntuacio_r, puntuacio);
					fruita_menjada = 1;
				}
				pintar_pantalla(--pos_x_nau, pos_y_nau);
				put_screen(p_pantalla);
			}		
		}
		else if(a %100 == 0 && direccio == 2){ //w
			if(pos_y_nau != 0 && *(p_pantalla+(pos_y_nau-1)*80 + pos_x_nau) != 'X'){
				if(*(p_pantalla+(pos_y_nau-1)*80 + pos_x_nau) == '*') {
					++puntuacio_r;
					itoa(puntuacio_r, puntuacio);
					fruita_menjada = 1;
				}
				pintar_pantalla(pos_x_nau, --pos_y_nau);
				put_screen(p_pantalla);
			}
		}
		else if(a %100 == 0 && direccio == 3){ //d
			if(pos_x_nau != 79 && *(p_pantalla+pos_y_nau*80 + pos_x_nau + 1) != 'X'){
				if(*(p_pantalla+pos_y_nau*80 + pos_x_nau + 1) == '*') {
					++puntuacio_r;
					itoa(puntuacio_r, puntuacio);
					fruita_menjada = 1;
				}
				pintar_pantalla(++pos_x_nau, pos_y_nau);
				put_screen(p_pantalla);
			}			
		}
		else if(a %100 == 0 && direccio == 4){ //s
			if(pos_y_nau != 24 && *(p_pantalla+(pos_y_nau+1)*80 + pos_x_nau) != 'X'){
				if(*(p_pantalla+(pos_y_nau+1)*80 + pos_x_nau) == '*') {
					++puntuacio_r;
					itoa(puntuacio_r, puntuacio);
					fruita_menjada = 1;
				}
				pintar_pantalla(pos_x_nau, ++pos_y_nau);
				put_screen(p_pantalla);
			}
		}
	}
}

void pintar_pantalla(int x, int y){
	int i, j;
	for(i = 0; i < 25; i++){
		for (j = 0; j < 80; j++){
			if((i % 13 == 4 || i % 13 == 5 || i % 13 == 6 || i % 13 == 7) && ( j % 15 == 5 || j % 15 == 6 || j % 15 == 7))pantalla[i][j] = 'X'; //parets fetes amb moduls
			else if (i == 0 && j >= 76 && j < 79) pantalla[i][j] = puntuacio[j-76]; //marcador de puntuacio
			else if(i == y && j == x) pantalla[i][j] = 'O'; //posicio de la nau
			else pantalla[i][j] = ' '; //pantalla normal per defecte
			
			if (!fruita_menjada){ pantalla[y_fruita][x_fruita] = '*'; //fer aixo
			}else {
				x_fruita = a % 79;
				y_fruita = a % 24;
				pantalla[y_fruita][x_fruita] = '*';
				fruita_menjada = 0;
			}
		}
	}
}

*/
//-----------------------------------------------------------------------------------------

//---------------- JUEGO DE PRUEBAS sbrk(int incr) + exit() -----------------------------
/*
int *retorn;
char buffer[5];

int __attribute__ ((__section__(".text.main")))
  main(void)
{
	retorn = sbrk(25);
	itoa(*retorn, buffer); //ha de retornar 0x11C
	write(1, buffer, 5);
	retorn = sbrk(2000);
	itoa(*retorn, buffer);
	write(1, buffer, 5);
	while(1) {}
}
*/
// -----------------------------------------------------------------------------------------



//------------- JUEGO DE PRUEBAS NAVE put_screen(char *s) + get_key(char *c) ------------

/*
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
 
 */
 //--------------------------------------------------------------------



 //------------- JUEGO DE PRUEBAS put_screen(char *s) ------------
/* 
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
*/
//---------------------------------------------------------------



 //------------- JUEGO DE PRUEBAS get_key(char *c) ---------------


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

//--------------------------------------------------------------
