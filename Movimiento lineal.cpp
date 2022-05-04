//Movimiento sencillo lineal de una particula

#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <conio.h>

#define H 100
#define K 26

using namespace std;

//Prototipos
void gotoxy(int x, int y);
void loop( int a, int b, int c_1, int c_2, int c, int d, int d_1, int d_2 );
void campo();

void impacto(int *a, int *b, int *c_1, int *c_2);

void impacto_2( int *c, int *d, int *d_1, int *d_2 );

//void teclado( int *c_1, int *c_2 );

//------------------------------------------------------
void incremento( int *a, int *b, int *c_1, int *c_2 );
void incremento_2( int *c, int *d, int *d_1, int *d_2 );
//------------------------------------------------------
//------------------------------------------------------
void particula( int *a, int *b );
void particula_2( int *c, int *d );
//------------------------------------------------------

void gotoxy( int x, int y){
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}

int main(){
	//Variables
	int a = 50; 
	int b = 13;
	int c = 45;
	int d = 13;
	
	int c_1 = -1;
	int c_2 = -1;
	int d_1 = 1;
	int d_2 = 1;
	campo();
	loop(a,b,c_1,c_2,c,d,d_1,d_2);
	
	cout << "\n";
	system("pause");
	return 0;
}

void loop( int a, int b, int c_1, int c_2, int c, int d, int d_1, int d_2 ){
	
	while( 1 == 1 ){
		//campo();
		impacto(&a,&b,&c_1,&c_2);
		impacto_2(&c,&d,&d_1,&d_2);
		incremento(&a,&b,&c_1,&c_2);
		incremento_2(&c,&d,&d_1,&d_2);
		particula(&a,&b);
		particula_2(&c,&d);
		Sleep(100);
		system("cls");
	}
}

void campo(){
	for( int i = 0; i < H; i++ ){
		for( int j = 0; j < K; j++ ){
			if( j == 0 ){
				gotoxy(i,0);
				cout << "X";
			}
			else if ( j == K-1 ){
				gotoxy(i,K-1);
				cout << "X";
			}
			else if ( i == 0 ){
				gotoxy(0,j);
				cout << "X";
			}
			else if ( i == H-1 ){
				gotoxy(H-1,j);
				cout << "X";
			}else{
				gotoxy(i,j);
				cout << " ";
			}
		}
	}
}

void impacto(int *a, int *b, int *c_1, int *c_2){
	
	if( *a == 1 || *a == H-2 ){
		*c_1 *= -1;
	}else if( *b == 1 || *b == K-2 ){
		*c_2 *= -1;
	}
}

void impacto_2( int *c, int *d, int *d_1, int *d_2 ){
	if( *c == 1 || *c == H-2 ){
		*d_1 *= -1;
	}else if( *d == 1 || *d == K-2 ){
		*d_2 *= -1;
	}
}

/*void teclado( int *c_1, int *c_2 ){
	char key;
	if( kbhit() != 0 ){
		key = getch();
		if( key == 'a' ){
			*c_1 = -1; //<-- Izquierda
			*c_2 = 0;
		}else if ( key == 'w' ){
			*c_1 = 0; // Arriba
			*c_2 = -1; 
		}else if ( key == 'd'){
			*c_1 = 1;
			*c_2 = 0;
		}else if ( key == 's'){
			*c_1 = 0;
			*c_2 = 1;
		}
	}
}*/

void incremento( int *a, int *b, int *c_1, int *c_2 ){
	*a += *c_1;
	*b += *c_2;
}

void particula( int *a, int *b){
	gotoxy(*a,*b);
	cout << "1";
}

void incremento_2( int *c, int *d, int *d_1, int *d_2 ){
	*c += *d_1;
	*d += *d_2;
}

void particula_2( int *c, int *d ){
	gotoxy(*c ,*d);
	cout<<"2";
}


