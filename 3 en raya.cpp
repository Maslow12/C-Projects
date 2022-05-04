//3 en raya 

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <windows.h>

using namespace std;

//Prototipos
void loop( int **matriz, int f, int c, int *k, int *op);
void matriz_f(int f, int c);
void teclado( int **matriz, int f, int c, int *k);
void imprimir(int **matriz_f, int f, int c);
void cambio(int *k);
void filas(int **matriz, int f, int c, int *op);
//void diagonales( int **matriz );
//void perder(int **matriz, int f, int c);

int **matriz;

int main(){
	
	int f = 3;
	int c = 3;
	int k = 1;
	
	int op = 0;
	
	matriz_f(f,c);
	loop(matriz,f,c,&k,&op);
	
	system("pause");
	return 0;
}

void loop( int **matriz, int f, int c, int *k, int *op){
	do{
		imprimir(matriz,f,c);
		teclado(matriz,f,c,k);
		filas(matriz,f,c,op);
		//diagonales(matriz);
		//perder(matriz,f,c);
	
		Sleep(10);
		system("cls");
	}while( 0 == 0 );
}

void matriz_f(int f, int c){
	int aux = 0;
	
	matriz = new int *[f];
	for( int i = 0; i < f; i++){
		matriz[i] = new int [c];
	}
	
	for(int i=0; i<f; i++){
		for(int j = 0; j < c; j++ ){
			aux = 0;
			*(*(matriz+i)+j) = aux;
		}
	}
}

void imprimir(int **matriz, int f, int c){
	
	for(int i = 0; i < f; i++){
		for(int j = 0; j < c; j++ ){
			cout << *(*(matriz+i)+j);
		}
		cout << "\n";
	}
	
}

void teclado( int **matriz, int f, int c, int *k){
	char key;
	if( kbhit() != 0 ){
		key = getch();
		if( key == '1' ){
			if( *(*(matriz+0)+0) == 0 ){
				*(*(matriz+0)+0) = *k;
				if( *k == 1 ){
						*k = 2;
					}else if ( *k == 2 ){
						*k = 1;
					} 
			}
		}
		else if( key == '2' ){
			if( *(*(matriz+0)+1) == 0 ){
				*(*(matriz+0)+1) = *k;
				if( *k == 1 ){
						*k = 2;
					}else if ( *k == 2 ){
						*k = 1;
					} 
			}
		}
		else if( key == '3' ){
			if( *(*(matriz+0)+2) == 0 ){
				*(*(matriz+0)+2) = *k;
				if( *k == 1 ){
						*k = 2;
					}else if ( *k == 2 ){
						*k = 1;
					} 
			}
		}
		else if( key == '4' ){
			if( *(*(matriz+1)+0) == 0 ){
				*(*(matriz+1)+0) = *k;
				if( *k == 1 ){
						*k = 2;
					}else if ( *k == 2 ){
						*k = 1;
					} 
			}
		}
		else if( key == '5' ){
			if( *(*(matriz+1)+1) == 0 ){
				*(*(matriz+1)+1) = *k;
				if( *k == 1 ){
						*k = 2;
					}else if ( *k == 2 ){
						*k = 1;
					} 
			}
		}
		else if( key == '6' ){
			if( *(*(matriz+1)+2) == 0 ){
				*(*(matriz+1)+2) = *k;
				if( *k == 1 ){
						*k = 2;
					}else if ( *k == 2 ){
						*k = 1;
					} 
			}
		}
		else if( key == '7' ){
			if( *(*(matriz+2)+0) == 0 ){
				*(*(matriz+2)+0) = *k;
				if( *k == 1 ){
						*k = 2;
					}else if ( *k == 2 ){
						*k = 1;
					} 
			}
		}
		else if( key == '8' ){
			if( *(*(matriz+2)+1) == 0 ){
				*(*(matriz+2)+1) = *k;
				if( *k == 1 ){
						*k = 2;
					}else if ( *k == 2 ){
						*k = 1;
					} 
			}
		}
		else if( key == '9' ){
			if( *(*(matriz+2)+2) == 0 ){
				*(*(matriz+2)+2) = *k;
				if( *k == 1 ){
						*k = 2;
					}else if ( *k == 2 ){
						*k = 1;
					} 
			}
			}
	}
}



void filas(int **matriz, int f, int c, int *op){
	int aux,a,b;
	a = 0;
	b = 0;
	aux = 0;
		//-----------------------------------------------------------------------------------------------------------------------
		/*for( int i = 0; i < f; i++ ){
			a = i+1;
			b = i+2;
			if( *(*(matriz+i)+0) == *(*(matriz+a)+0) && *(*(matriz+i)+0) != 0 && *(*(matriz+b)+0) == *(*(matriz+i)+0)){
				aux = *(*(matriz+i)+0);
			}//Linea lateral izq. vertical
			
			else if( *(*(matriz+i)+1) == *(*(matriz+i+1)+1) && *(*(matriz+i)+1) != 0 && *(*(matriz+i+2)+1) == *(*(matriz+i)+1)){
				aux = *(*(matriz+i)+1);
			}//Linea del medio vertical
			
			else if( *(*(matriz+i)+2) == *(*(matriz+i+1)+2) && *(*(matriz+i)+2) != 0 && *(*(matriz+i+2)+2) == *(*(matriz+i)+2)){
				aux = *(*(matriz+i)+2);
			}//Linea lateral derecha vertical
		}*/
		//----------------------------------------------------------------------------------------------
		for( int j = 0; j < c; j++ ){
			if( *(*(matriz+0)+j) == *(*(matriz+0)+j+1) && *(*(matriz+0)+j) != 0 && *(*(matriz+0)+j+2) == *(*(matriz+0)+j)){
				aux = *(*(matriz+0)+j);
			}//Linea superior horizontal
			
			else if( *(*(matriz+1)+j) == *(*(matriz+1)+j+1) && *(*(matriz+1)+j) != 0 && *(*(matriz+1)+j+2) == *(*(matriz+1)+j)){
				aux = *(*(matriz+1)+j);
			}//linea del medio horizontal
			
			else if( *(*(matriz+2)+j) == *(*(matriz+2)+j+1) && *(*(matriz+2)+j) != 0 && *(*(matriz+2)+j+2) == *(*(matriz+2)+j)){
				aux = *(*(matriz+2)+j);
			}//Linea abajo horizontal
		}
}

/*void diagonales( int **matriz ){
	int aux = 0;
	if( *(*(matriz+0)+0) == *(*(matriz+1)+1) && *(*(matriz+0)+0) != 0 && *(*(matriz+2)+2) == *(*(matriz+0)+0) ){
		aux = *(*(matriz+0)+0);
		printf("Ganaste %i", aux);
	}else if( *(*(matriz+0)+2) == *(*(matriz+1)+1) && *(*(matriz+0)+2) != 0 && *(*(matriz+2)+0) == *(*(matriz+0)+2) ){
		aux = *(*(matriz+0)+2);
		printf("Ganaste %i", aux);
	}
}

void perder(int **matriz, int f, int c){
	for(int i = 0; i < f; i++){
		for(int j = 0; j < c; j++){
			if( *(*(matriz+i)+j) == *(*(matriz+i+1)+j+1) && *(*(matriz+i)+j) != 0 && *(*(matriz+i+2)+j+2) == *(*(matriz+i)+j)){
				cout << "Fin.";
			}
		}
	}
}*/


