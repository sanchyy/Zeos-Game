#include <libc.h>
#include <types.h>

//-------------------------- EL JUEGO: SNAKE  + juego muchos tics------------------
//Sirve para ámbos juegos de pruebas. En este caso limitamos con un módulo cada cuantos ticks de reloj queremos haya entre 2 frames.

/*

//pantalla i key premuda
char pantalla[25][80];
char *p_pantalla = &pantalla[0][0];
char c;
char *c_pointer = &c;

//SNAKE
int pos_x_nau = 40;
int pos_y_nau = 20;
int llargada = 0;
int cos[][2];

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
	put_screen(pantalla);
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
					++llargada;
					itoa(puntuacio_r, puntuacio);
					fruita_menjada = 1;
					
				}
				pintar_pantalla(--pos_x_nau, pos_y_nau);
				put_screen(pantalla);
			}		
		}
		else if(a %100 == 0 && direccio == 2){ //w
			if(pos_y_nau != 0 && *(p_pantalla+(pos_y_nau-1)*80 + pos_x_nau) != 'X'){
				if(*(p_pantalla+(pos_y_nau-1)*80 + pos_x_nau) == '*') {
					++puntuacio_r;
					++llargada;
					itoa(puntuacio_r, puntuacio);
					fruita_menjada = 1;
					
				}
				pintar_pantalla(pos_x_nau, --pos_y_nau);
				put_screen(pantalla);
			}
		}
		else if(a %100 == 0 && direccio == 3){ //d
			if(pos_x_nau != 79 && *(p_pantalla+pos_y_nau*80 + pos_x_nau + 1) != 'X'){
				if(*(p_pantalla+pos_y_nau*80 + pos_x_nau + 1) == '*') {
					++puntuacio_r;
					++llargada;
					itoa(puntuacio_r, puntuacio);
					fruita_menjada = 1;
				}
				pintar_pantalla(++pos_x_nau, pos_y_nau);
				put_screen(pantalla);
			}			
		}
		else if(a %100 == 0 && direccio == 4){ //s
			if(pos_y_nau != 24 && *(p_pantalla+(pos_y_nau+1)*80 + pos_x_nau) != 'X'){
				if(*(p_pantalla+(pos_y_nau+1)*80 + pos_x_nau) == '*') {
					++puntuacio_r;
					++llargada;
					itoa(puntuacio_r, puntuacio);
					fruita_menjada = 1;
				}
				pintar_pantalla(pos_x_nau, ++pos_y_nau);
				put_screen(pantalla);
			}
		}
	}
}

void actualitza_cos()
{
	int i;
	for ( i = 0; i < llargada; ++i) pantalla[cos[i][1]][cos[i][0]] = 'O';
	//Comput nou cos
	for (i = llargada-1; i >= 0; ++i) {
		cos[i][0] = cos[i-1][0];
		cos[i][1] = cos[i-1][1];
	}
	cos[0][0] = pos_x_nau;
	cos[0][1] = pos_y_nau;
}


void pintar_pantalla(int x, int y){
	int i, j;
	for(i = 0; i < 25; i++){
		for (j = 0; j < 80; j++){
			
			// parets fetes amb moduls 
			if((i % 13 == 4 || i % 13 == 5 || i % 13 == 6 || i % 13 == 7) && ( j % 15 == 5 || j % 15 == 6 || j % 15 == 7)) pantalla[i][j] = 'X';
			
			//marcador
			else if (i == 0 && j >= 76 && j < 79) pantalla[i][j] = puntuacio[j-76];
			
			//cap de la serp
			else if(i == y && j == x) {
				pantalla[i][j] = 'O'; //posicio del cap de la serp
			}
			
			//pantalla normal per defecte
			else pantalla[i][j] = ' ';
			
			//ubicació fruita
			if (!fruita_menjada){ pantalla[y_fruita][x_fruita] = '*'; //fer aixo
			}else {
				x_fruita = a % 79;
				y_fruita = a % 24;
				pantalla[y_fruita][x_fruita] = '*';
				fruita_menjada = 0;
			}
		}
	}

	actualitza_cos();
}
*/
//-----------------------------------------------------------------------------------------

//----------------- JUEGO DE PRUEBAS POCOS TICKS --------------------------------------
int __attribute__ ((__section__(".text.main")))
  main(void)
{
	int a = fork();
	if(a = 0){
//todos los hijos tienen prioridad 1, así que se la tenemos que cambiar.
	change_priority(0); //Al tener ahora prioridad 0 se provoca starvation del proceso hijo.
	while(1){};
	}
	else{
		while(1){};	

		//ahora el padre tiene todos los recursos
	}
	
	
}
//-------------------------------------------------------------------------------

//---------------- JUEGO DE PRUEBAS DIFERENTES ESCENARIOS - NIVEL 2 ------------------------------
//Si se comenta sbrk da page fault porque se pasa de las 20 páginas de datos que tiene el proceso.
//En cambio con sbrk, reservando más espacio, funciona
/*
int retorn;
char vector[41][25][80];
char result;
int __attribute__ ((__section__(".text.main")))
  main(void)
{
	retorn = sbrk(4096);
	for(int i = 0; i < 41; ++i){
		for(int j = 0;j < 25; ++j){
			for(int k = 0; k < 80; ++k) vector[i][j][k] = 'X';
			}
		}
	while(1){};
}
*/
//--------------------------------------------------------------------------------------


//---------------- JUEGO DE PRUEBAS sbrk(int incr) -----------------------------
/*
int retorn;
char buffer[7];

int __attribute__ ((__section__(".text.main")))
  main(void)
{
	// sbrk con valor de parámetro negativo - error 11
	retorn = sbrk(-3);
	perror();
	
	write(1,"\n", 1);
	
	// sbrk con valor de parámetro demasiado grande - error 12
	retorn = sbrk(20000000000000000000);
	perror();

	write(1,"\n", 1);
	
	// sbrk con valor de 0 -> el siguiente sbrk tiene que devolver la misma dirección de memoria
	retorn = sbrk(0);
	itoa(retorn, buffer);
	write(1, buffer, 7);
	
	write(1,"\n", 1);
	
	// sbrk con valor de menos de una página -> el siguiente sbrk tiene que devolver otro valor
	retorn = sbrk(2048);
	itoa(retorn, buffer);
	write(1, buffer, 7);
	
	write(1,"\n", 1);
	
	// sbrk con valor de mas de una página -> el siguiente sbrk tiene que devolver otro valor
	retorn = sbrk(7000);
	itoa(retorn, buffer);
	write(1, buffer, 7);
	
	write(1,"\n", 1);
	
	// sbrk para comprovar el valor anterior. (Si se cambia el valor de retorno de sbrk  en todas las llamadas anteriores
	// para que devuelva las páginas se verán las que se reservan)
	retorn = sbrk(512);
	itoa(retorn, buffer);
	write(1, buffer, 7);
	while(1) {}
}
*/
// -----------------------------------------------------------------------------------------



//------------- JUEGO DE PRUEBAS NAVE put_screen(char *s) + get_key(char *c) - NIVEL 1------------
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
//Para probar las diferentes situaciones que comprueba el juego de pruebas se tienen que comentar/descomentar algunas líneas
char pantalla[25][80];
char *p_pantalla = &pantalla[0][0];
char c;
char *c_pointer = &c;

int __attribute__ ((__section__(".text.main")))
  main(void)
{

	//creamos la matriz
	int i, j;
	for(i = 0; i < 25; i++){
		for (j = 0; j < 80; j++){
			pantalla[i][j] = 'X';
		}
	}
	put_screen de una matriz de forma correcta
	put_screen(p_pantalla);
	
	//put_screen con un valor de parámetro no correcto. Comprobamos perror antes y después.
	//perror();
	//put_screen(0x300000);
	//perror();
	while(1) {}
}
*/
//---------------------------------------------------------------



 //------------- JUEGO DE PRUEBAS get_key(char *c) + buffer circular ---------------
//Para probar las diferentes situaciones que comprueba el juego de pruebas se tienen que comentar/descomentar algunas líneas
/*
char c;
char *c_pointer = &c;
char *c_pointer2 = 0x300000; //posición fuera del rango de memoria, ya que no hemos ampliado el heap
char *r;
int count = 1;
int __attribute__ ((__section__(".text.main")))		
  main(void)
{
		
	while(1) { 
		
		//captura una tecla y printa algo por pantalla - uso normal
		if(get_key(c_pointer)) {
			if (*c_pointer == 'c') write(1, c_pointer, strlen(c_pointer));
			}
		
		
		//caso en que se le pasa un puntero que apunta a una posición no valida
		//if(get_key(c_pointer2)) if (errno > 0)perror(); //devuelve error gracias al access_ok()
		
		//caso en el que no hay ningún valor para leer en el buffer
		//if(get_key(r)) perror();
	}
}
*/
//--------------------------------------------------------------
