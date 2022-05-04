//Snake interfaz
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define H 100
#define K 26

#define N 20
using namespace std;

//Prototipos
void gotoxy(int x, int y);
void loop( int a, int b, int c_1, int c_2 );
void campo();
void impacto(int *a, int *b,int *c_1, int *c_2);
void teclado( int *c_1, int *c_2 );
void incremento( int *a, int *b, int *c_1, int *c_2 );
void serpiente( int *a, int *b );
//void raton();

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
	
	int c_1 = -1;
	int c_2 = -1;
	
	loop(a,b,c_1,c_2);
	
	cout << "\n";
	system("pause");
	return 0;
}

void loop( int a, int b, int c_1, int c_2 ){
	
	do{
		campo();
		impacto(&a,&b,&c_1,&c_2);
		teclado(&c_1,&c_2);
		incremento(&a,&b,&c_1,&c_2);
		serpiente(&a,&b);
		//raton();
		Sleep(100);
	}while( 1 == 1 );
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

void impacto(int *a, int *b,int *c_1, int *c_2){
	char key;
	
	if( *a == 1 || *a == H-2 ){
		exit(1);
	}else if( *b == 1 || *b == K-2 ){
		exit(1);
	}
	
}

void teclado( int *c_1, int *c_2 ){
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
}

void incremento( int *a, int *b, int *c_1, int *c_2 ){
	*a += *c_1;
	*b += *c_2;
}

void serpiente( int *a, int *b){
	char snk[3][3];
	
	//cuerpo
	/*for( int i=1; i < 4; i++ ){
		gotoxy(*a+i,*b);
		cout << "X";
	}*/
	
	gotoxy(*a,*b); //Cabeza
	cout << "0";
}

/*void raton(){
	srand(time(NULL));
	gotoxy(rand()%H-4 + 2,rand()%K-4 + 2);
	cout << "Y";
}*/

