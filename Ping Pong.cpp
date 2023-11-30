/*
Palomino Castelan Josmar Gustavo
Juego Basico "Ping Pong"
1CM11
*/

#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#define Arriba 72
#define Abajo 80
#define ESC 27

void Menu_Principal();//Funcion que permite imprimir la presentacion del juego el titulo
void Caracter_Cuadro();//Funcion que permite imprimir un caracter
void Caracter_Malla();//Funcion que permite imprimir un caracter
void Marco();//Funcion que permite imprimir el marco de las partidas
void Mover_Jugador1();//Funcion que permite mover al jugador dependiendo de las teclas que toque
void Borrar_Jugador1(int,int);//Funcion que permite borrar la barra del jugador
void Pintar_Jugador1(int,int);//Funcion que permite imprimir la barra del jugador
void Borrar_Jugador2(int,int);//Funcion que permite borrar la barra del jugador
void Pintar_Jugador2(int,int);//Funcion que permite imprimir la barra del jugador
void Jugador_vs_Jugador();//Funcion que permite interactuar con ambos jugadores
void Jugador_vs_IA();//Funcion que permite interactuar entre IA y jugador
void Intrucciones_Reglas();//Funcion que permite imprimir un menu de reglas e instrucciones del juego
void Pantalla_Final();//Funcion que permite imprimir pantalla de despedida al usuario del juego 
void Pantalla_Perdedor();//Funcion que permite imprimir pantalla de quien perdio durante la partida
char Personalizar_Partida();//Funcion que permite al usuario cambiar de color las partidas
void Pantalla_Inicio();//Funcion que permite dar la bienvenida al minijuego de Ping Pong

//Inicio mi menu principal
main()
{
	char menu,Color;
	time_t inicio;
	inicio=time(NULL);
	
	Pantalla_Inicio();
	sleep(3);
	system("cls");
	do
	{
		switch(Color)
		{
			case '0':
				system("Color 0");
			break;
			case '1':
				system("Color 1");
			break;
			case '2':
				system("Color 2");
			break;
			case '3':
				system("Color 3");
			break;
			case '4':
				system("Color 4");
			break;
			case '5':
				system("Color 5");
			break;
			case '6':
				system("Color 6");
			break;
			case '7':
				system("Color 7");
			break;
			case '8':
				system("Color 8");
			break;
			case '9':
				system("Color 9");
			break;
			case 'A':
			case 'a':
				system("Color A");
			break;
			case 'B':
			case 'b':
				system("Color B");
			break;
			case 'C':
			case 'c':
				system("Color C");
			break;
			case 'D':
			case 'd':
				system("Color D");
			break;
			case 'E':
			case 'e':
				system("Color E");
			break;
			case 'F':
			case 'f':
				system("Color F");
			break;	
		}
		Menu_Principal();
		menu=getch();
		switch(menu)
		{	
			case '1':
				system("cls");
				Jugador_vs_IA();
			break;
			case '2':
				system("cls");
				Jugador_vs_Jugador();				
			break;
			case '3':
				system("cls");
				Intrucciones_Reglas();
			break;
			case '4':
				Color=Personalizar_Partida();
			break;
			case '5':
				system("cls");
				system("Color A");
				Pantalla_Final();
				sleep(4);
			break;
			default:
				printf("Dame un dato correcto...");
		}
		sleep(1);
		system("cls");
	}while(!(menu=='5'));
	system("Color 0F");
}

//Se crea la funcion gotoxy para poder usar las coordenadas
void gotoxy (int x, int y)
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon,dwPos);
}

//Inicio funcion Marco que permite imprimir los limites del mapa
void Marco()
{
	int x,y;
	
	for(x=0;x<120;x=x+1)
	{
		gotoxy(x,0);
		printf("%c",219);		
	}
	for(y=1;y<28;y=y+1)
	{
		gotoxy(0,y);
		Caracter_Cuadro();
	}
	for(x=0;x<120;x=x+1)
	{
		gotoxy(x,28);
		printf("%c",219);		
	}
	for(y=1;y<28;y=y+1)
	{
		gotoxy(118,y);
		Caracter_Cuadro();
	}
	for(x=2;x<118;x=x+1)
	{
		gotoxy(x,3);
		printf("=");
	}
	gotoxy(45,1);
	printf("<<<<<< Ping Pong >>>>>>");
	gotoxy(119,28);
	printf("\n");
}

//Inicio de funcion Intrucciones_Reglas que permite imprimir como se puede jugar
void Intrucciones_Reglas()
{
	char menu;
	
	do
	{
		gotoxy(25,4);
		printf("<<<<<<  Bienvenido al menu de intrucciones y reglas del juego  >>>>>>");
		gotoxy(12,7);
		printf("1) Intrucciones para jugar contra la computadora (IA): \n");
		gotoxy(12,9);
		printf("2) Intrucciones para jugar contra otro jugador (1VS1): \n");
		gotoxy(12,11);
		printf("3) Reglas del juego: \n");
		gotoxy(12,13);
		printf("4) Creditos: \n");
		gotoxy(12,15);
		printf("5) Salir al menu principal del juego: \n");
		gotoxy(45,22);
		printf("Que deseas hacer? \n");
		gotoxy(45,24);
		menu=getch();
		switch (menu)
		{
			case '1':
				system("cls");
				gotoxy(25,4);
				printf("<<<<<<  Intrucciones para jugar contra la computadora (IA)  >>>>>>");
				gotoxy(12,7);
				printf("1) La barra de la izquierda seras tu: ");
				gotoxy(12,9);
				printf("2) Te podras mover con las teclas w (arriba) y s (abajo): ");				
				gotoxy(12,11);
				printf("3) La barra de la derecha sera tu oponente la computadora (IA): ");
				gotoxy(12,13);
				printf("4) La computadora hara sus movimientos de manera automatica: ");
				gotoxy(12,15);
				printf("5) Cada 10 puntos de Score el nivel de dificultad aumentara: ");
				gotoxy(12,17);
				printf("6) Este nivel sera para ver tu destreza en el juego intenta resistir el mayor tiempo posible ");
				gotoxy(12,19);
				printf("7) Recuerda no bajar la guardia porque a medida que va subiendo el nivel la computadora se hara mas inteligente a tal punto que mejorara sus movimientos: ");
				gotoxy(35,24);
				system("pause");
			break;
			case '2':
				system("cls");
				gotoxy(25,4);
				printf("<<<<<<  Intrucciones para jugar contra otro jugador (1vs1)  >>>>>>");
				gotoxy(12,7);
				printf("1) La barra de la izquierda sera el jugador 1: " );			
				gotoxy(12,9);
				printf("2) Tu como jugador 1 te moveras con las teclas de w (arriba) y s (abajo):");				
				gotoxy(12,11);
				printf("3) La barra de la derecha sera el jugador 2: ");				
				gotoxy(12,13);
				printf("4) Tu como jugador 2 te moveras con las flechas de la computadora: ");
				gotoxy(12,15);
				printf("5) A medida que vayan acumulando puntos (Cada 10 puntos) se aumentara la dificultad: ");
				gotoxy(12,17);
				printf("6) Gana aquel jugador que acierte un gool: ");
				gotoxy(12,19);
				printf("7) Te deseo lo mejor y que la suerte este siempre de tu lado: ");
				gotoxy(35,24);
				system("pause");
			break;
			case '3':
				system("cls");
				gotoxy(40,4);
				printf("<<<<<<  Reglas del juego  >>>>>>");
				gotoxy(12,7);
				printf("1) Si deseas salir de cualquier partida pulsa la tecla ESC: ");				
				gotoxy(12,9);
				printf("2) Si deseas poner pausa al juego pulsa la tecla P: ");				
				gotoxy(12,11);
				printf("3) Deberas resistir el mayor tiempo posible: ");
				gotoxy(12,13);
				printf("4) Para poder ganar debes anotar un gool: ");
				gotoxy(12,15);
				printf("5) Si quieres ser un perdedor dejate anotar un gool: ");
				gotoxy(12,17);
				printf("6) Recuerda lo mas importante, diviertete: ");
				gotoxy(12,19);
				printf("7) Si encuentras un error puedes reportar para ser arreglado: ");
				gotoxy(12,21);
				printf("Gracias por jugar Ping Pong ojala ganes :D");
				gotoxy(35,26);
				system("pause");
			break;
			case '4':
				system("cls");
				gotoxy(25,4);
				printf("<<<<<< Creditos  >>>>>>");
				gotoxy(12,7);
				printf("Desarollo del juego: Josmar Gustavo Palomino Castelan ");
				gotoxy(12,9);
				printf("Diseño del juego: Josmar Gustavo Palomino Castelan ");
				gotoxy(35,4);
				system("pause");
			break;
			case '5':
			break;
			default:
				printf("Dame una opcion que sea valida.... ");
		}
		sleep(1.5);
		system("cls");
	}while(!(menu=='5'));
}

//Inicio Funcion Mover_Jugador que permite mover la barra del jugador 1
void Mover_Jugador1()
{
	int x1=4,y1=12,borrar;
	int menu=0;

	while(menu==0)
	{	
		if(kbhit())
		{
			Borrar_Jugador1(x1,y1);
			
			char tecla = getch();
			switch(tecla)
			{
				case Abajo:
					if(y1<22)
					{
						y1=y1+1;
					}
				break;
				case Arriba:
					if(y1>4)
					{
						y1=y1-1;
					}
				break;
				case ESC:
					menu=1;
				break;
				//case 'P':
				case 'p':
					gotoxy(30,2);
					system("pause");
					for(borrar=30;borrar<70;borrar=borrar+1)
					{
						gotoxy(borrar,2);
						printf(" ");
					}
				break;
			}
			Pintar_Jugador1(x1,y1);
		}
	}
	system("pause");
	system("cls");
}

//Inicio de funcion Pintar_Jugador que permite ir dibujando la barra del jugador
void Pintar_Jugador1(int x1, int y1)
{
		gotoxy(x1,y1);
		Caracter_Cuadro();
		gotoxy(x1,y1+1);
		Caracter_Cuadro();
		gotoxy(x1,y1+2);
		Caracter_Cuadro();
		gotoxy(x1,y1+3);
		Caracter_Cuadro();
		gotoxy(x1,y1+4);
		Caracter_Cuadro();
		gotoxy(x1,y1+5);
		Caracter_Cuadro();
}

//Inicio de funcion Borrar_Jugador permite borrar los datos de la barra
void Borrar_Jugador1(int x1, int y1)
{
		gotoxy(x1,y1);
		printf("  ");
		gotoxy(x1,y1+1);
		printf("  ");
		gotoxy(x1,y1+2);
		printf("  ");
		gotoxy(x1,y1+3);
		printf("  ");
		gotoxy(x1,y1+4);
		printf("  ");
		gotoxy(x1,y1+5);
		printf("  ");
}

//Funcion que permite pintar al jugador 2 en las partidas
void Pintar_Jugador2(int x2, int y2)
{
		gotoxy(x2,y2);
		Caracter_Cuadro();
		gotoxy(x2,y2+1);
		Caracter_Cuadro();
		gotoxy(x2,y2+2);
		Caracter_Cuadro();
		gotoxy(x2,y2+3);
		Caracter_Cuadro();
		gotoxy(x2,y2+4);
		Caracter_Cuadro();
		gotoxy(x2,y2+5);
		Caracter_Cuadro();
}

//Funcion que permite borrar los rastros de las partidas del jugador 2
void Borrar_Jugador2(int x2, int y2)
{
		gotoxy(x2,y2);
		printf("  ");
		gotoxy(x2,y2+1);
		printf("  ");
		gotoxy(x2,y2+2);
		printf("  ");
		gotoxy(x2,y2+3);
		printf("  ");
		gotoxy(x2,y2+4);
		printf("  ");
		gotoxy(x2,y2+5);
		printf("  ");
}

//inicio de funcion Jugador_vs_Jugador que permite interactuar con dos personas
void Jugador_vs_Jugador()
{
	int x=56,y=14;
	int x2=114,y2=12;
	int x1=4,y1=12;
	int menu=1,borrar,mover,inicio,Aux,cont,Cont,Score=0,perdedor;
	char tecla;
	
	Aux=1;
	inicio=rand()%1;
	Marco();	
	Pintar_Jugador1(x1,y1);
	Pintar_Jugador2(x2,y2);
	while(menu==1)
	{	
		gotoxy(x,y);
		printf("0");
		Sleep(100);
		gotoxy(x,y);
		printf(" ");
		if(Aux==1)
		{
			switch(inicio)
			{
				case 0:
					x=x+1;
					y=y+1;
					if(y>=27)
					{
						Aux=0;
						Cont=1;
					}
				break;
				case 1:
					x=x-1;
					y=y-1;
					if(y<=3)
					{
						Aux=0;
						cont=1;
					}				
				break;
				case 2:
					x=x+1;
					y=y-1;
					if(y<=3)
					{
						Aux=0;
						cont=1;
					}
				break;
				case 3:
					x=x-1;
					y=y+1;
					if(y>=27)
					{
						Aux=0;
						Cont=1;
					}
				break;
			}
		if(cont==1)
		{
			y=y+1;
			if(y<=27)
			{
				y=y+1;
				Aux=1;
				if(y>=27)
				{
					cont=0;
				}				
			}
		}
		if(Cont==1)
		{
			y=y-1;
			if(y>=4)
			{
				y=y-1;
				Aux=1;
				if(y<=4)
				{
					Cont=0;
				}
			}
		}		
		if(x==x1+2 && (y==y1 || y==y1+1 || y==y1+2 || y==y1+3 || y==y1+4 || y==y1+5))
		{
			mover=rand()%2;
			Score=Score+1;
			switch(mover)
			{
				case 0:
					inicio=0;
				break;
				case 1:
					inicio=2;					
				break;
			}
		}
		if(x==x2-2 && (y==y2 || y==y2+1 || y==y2+2 || y==y2+3 || y==y2+4 || y==y2+5))
		{
			mover=rand()%2;
			Score=Score+1;
			switch(mover)
			{
				case 0:
					inicio=1;				
				break;
				case 1:
					inicio=3;
				break;
			}
		}
		if(x==1 || x==118)
		{
			menu=0;
			gotoxy(50,15);
			printf("Tu Score Es De: %d",Score);
			sleep(3);
			system("cls");
			for(perdedor=0;perdedor<31;perdedor=perdedor+1)
			{
				switch(perdedor)
				{
					case 0:
					case 6:
					case 12:
					case 18:
					case 24:
						system("Color 0A");
					break;
					case 1:
					case 7:
					case 13:
					case 19:
					case 25:
						system("Color 0B");
					break;
					case 2:
					case 8:
					case 14:
					case 20:
					case 26:
					case 30:
						system("Color 0C");
					break;
					case 3:
					case 9:
					case 15:
					case 21:
					case 27:
						system("Color 0D");
					break;
					case 4:
					case 10:
					case 16:
					case 22:
					case 28:
						system("Color 0E");
					break;
					case 5:
					case 11:
					case 17:
					case 23:
					case 29:
						system("Color 0F");
					break;
				}
				Pantalla_Perdedor();
				sleep(0.5);
				system("Color 0F");
			}
			sleep(3);
		}	
		if(kbhit())
		{
			Borrar_Jugador2(x2,y2);
			Borrar_Jugador1(x1,y1);
			tecla=getch();
			switch(tecla)
			{
				case 'w':
				if(y1>4)
				{
					y1=y1-1;
				}
				break;
				case 'W':
					if(y1>4)
					{
						y1=y1-1;
					}
				break;
				case Arriba:
					if(y2>4)
					{
						y2=y2-1;
					}	
				break;				
				case 's':
					if(y1<22)
					{
						y1=y1+1;
					}
				break;
				case 'S':
					if(y1<22)
					{
						y1=y1+1;
					}
				break;
				case Abajo:
					if(y2<22)
					{
						y2=y2+1;
					}
				break;
				case 'p':
					gotoxy(30,2);
					system("pause");
					for(borrar=30;borrar<70;borrar=borrar+1)
					{
						gotoxy(borrar,2);
						printf(" ");
					}
				break;
				case ESC:
					menu=0;
				break;
			}
			Pintar_Jugador2(x2,y2);
			Pintar_Jugador1(x1,y1);
		}
		}
	gotoxy(52,2);
	printf("SCORE : %d",Score);
	}
}

//Inicio Jugador_vs_IA permite interactuar con un jugador y la computadora
void Jugador_vs_IA()
{
	int x=56,y=14;
	int x2=114,y2=12;
	int x1=4,y1=12;
	int menu=1,borrar,mover,inicio,Aux,cont,Cont,Score=0,raqueta,perdedor;
	char tecla;
	
	Aux=1;
	inicio=rand()%1;	
	Marco();
	Pintar_Jugador2(x2,y2);
	Pintar_Jugador1(x1,y1);
	while(menu==1)
	{
		if(x>=90)
		{
			Borrar_Jugador2(x2,y2);
			y2=y-2;
			if(y2<4)
			{
				y2=4;
			}
			if(y2>22)
			{
				y2=22;
			}
			Pintar_Jugador2(x2,y2);
		}
		gotoxy(x,y);
		printf("0");
		Sleep(100);
		gotoxy(x,y);
		printf(" ");
		if(Aux==1)
		{
			switch(inicio)
			{
				case 0:
					x=x+1;
					y=y+1;
					if(y>=27)
					{
						Aux=0;
						Cont=1;
					}
				break;
				case 1:
					x=x-1;
					y=y-1;
					if(y<=3)
					{
						Aux=0;
						cont=1;
					}				
				break;
				case 2:
					x=x+1;
					y=y-1;
					if(y<=3)
					{
						Aux=0;
						cont=1;
					}
				break;
				case 3:
					x=x-1;
					y=y+1;
					if(y>=27)
					{
						Aux=0;
						Cont=1;
					}
				break;
			}
		if(cont==1)
		{
			y=y+1;
			if(y<=27)
			{
				y=y+1;
				Aux=1;
				if(y>=27)
				{
					cont=0;
				}				
			}
		}
		if(Cont==1)
		{
			y=y-1;
			if(y>=4)
			{
				y=y-1;
				Aux=1;
				if(y<=4)
				{
					Cont=0;
				}
			}
		}		
		if(x==x1+2 && (y==y1 || y==y1+1 || y==y1+2 || y==y1+3 || y==y1+4 || y==y1+5))
		{
			mover=rand()%2;
			Score=Score+1;
			switch(mover)
			{
				case 0:
					inicio=0;
				break;
				case 1:
					inicio=2;					
				break;
			}
		}
		if(x==x2-2 && (y==y2 || y==y2+1 || y==y2+2 || y==y2+3 || y==y2+4 || y==y2+5))
		{
			mover=rand()%2;
			Score=Score+1;
			switch(mover)
			{
				case 0:
					inicio=1;			
				break;
				case 1:
					inicio=3;
				break;
			}
		}
		if(x==1 || x==118)
		{
			menu=0;
			gotoxy(50,15);
			printf("Tu Score Es De: %d",Score);
			sleep(3);
			system("cls");
			for(perdedor=0;perdedor<31;perdedor=perdedor+1)
			{
				switch(perdedor)
				{
					case 0:
					case 6:
					case 12:
					case 18:
					case 24:
						system("Color 0A");
					break;
					case 1:
					case 7:
					case 13:
					case 19:
					case 25:
						system("Color 0B");
					break;
					case 2:
					case 8:
					case 14:
					case 20:
					case 26:
					case 30:
						system("Color 0C");
					break;
					case 3:
					case 9:
					case 15:
					case 21:
					case 27:
						system("Color 0D");
					break;
					case 4:
					case 10:
					case 16:
					case 22:
					case 28:
						system("Color 0E");
					break;
					case 5:
					case 11:
					case 17:
					case 23:
					case 29:
						system("Color 0F");
					break;
				}
				Pantalla_Perdedor();
				sleep(0.5);
				system("Color 0F");
			}
			sleep(3);
		}	
		if(kbhit())
		{
			Borrar_Jugador1(x1,y1);
			tecla=getch();
			switch(tecla)
			{
				case 'w':
				if(y1>4)
				{
					y1=y1-1;
				}
				break;
				case 'W':
					if(y1>4)
					{
						y1=y1-1;
					}
				break;				
				case 's':
					if(y1<22)
					{
						y1=y1+1;
					}
				break;
				case 'S':
					if(y1<22)
					{
						y1=y1+1;
					}
				break;
				case 'p':
					gotoxy(30,2);
					system("pause");
					for(borrar=30;borrar<70;borrar=borrar+1)
					{
						gotoxy(borrar,2);
						printf(" ");
					}
				break;
				case ESC:
					menu=0;
				break;
			}
			Pintar_Jugador1(x1,y1);
		}
		}
	gotoxy(52,2);
	printf("SCORE : %d",Score);
	}
}

//Inicio de funcion PErsonalizar_Partida permite cambiar colores de la partida
char Personalizar_Partida()
{
	char Color,menu;
	int i;
	
	do
	{
		system("cls");
		gotoxy(40,2);
		printf("<<<<<< Menu De Personalizacion Tablero >>>>>>");
		gotoxy(14,4);
		printf("0) Tablero Color Blanco");
		gotoxy(14,5);
		printf("1) Tablero Color Azul");
		gotoxy(14,6);
		printf("2) Tablero Color Verde");
		gotoxy(14,7);
		printf("3) Tablero Color AguaMarina");
		gotoxy(14,8);
		printf("4) Tablero Color Rojo");
		gotoxy(14,9);
		printf("5) Tablero Color Purpura");
		gotoxy(14,10);
		printf("6) Tablero Color Amarillo");
		gotoxy(14,11);
		printf("7) Tablero Color Blanco");
		gotoxy(14,12);
		printf("8) Tablero Color Gris");
		gotoxy(14,13);
		printf("9) Tablero Color Azul Claro");
		gotoxy(14,14);
		printf("A) Tablero Color Verde Claro");
		gotoxy(14,15);
		printf("B) Tablero Color Aguamarina Claro");
		gotoxy(14,16);
		printf("C) Tablero Color Rojo Claro");
		gotoxy(14,17);
		printf("D) Tablero Purpura claro");
		gotoxy(14,18);
		printf("E) Tablero Amarillo Claro");
		gotoxy(14,19);
		printf("F) Tablero Blanco Brillante");
		gotoxy(14,20);
		printf("s) Salir Al Menu Principal");
		gotoxy(78,10);
		Caracter_Cuadro();
		gotoxy(78,11);
		Caracter_Cuadro();
		gotoxy(84,10);
		Caracter_Cuadro();
		gotoxy(84,11);
		Caracter_Cuadro();
		gotoxy(74,13);
		Caracter_Cuadro();
		gotoxy(76,14);
		for(i=0;i<6;i=i+1)
		{
			Caracter_Cuadro();
		}
		gotoxy(88,13);
		Caracter_Cuadro();
		gotoxy(50,25);
		printf("Dame la opcion que deseas hacer: ");
		Color=getch();
		switch(Color)
		{
			case '0':
				system("Color 0");
			break;
			case '1':
				system("Color 1");
			break;
			case '2':
				system("Color 2");
			break;
			case '3':
				system("Color 3");
			break;
			case '4':
				system("Color 4");
			break;
			case '5':
				system("Color 5");
			break;
			case '6':
				system("Color 6");
			break;
			case '7':
				system("Color 7");
			break;
			case '8':
				system("Color 8");
			break;
			case '9':
				system("Color 9");
			break;
			case 'A':
			case 'a':
				system("Color A");
			break;
			case 'B':
			case 'b':
				system("Color B");
			break;
			case 'C':
			case 'c':
				system("Color C");
			break;
			case 'D':
			case 'd':
				system("Color D");
			break;
			case 'E':
			case 'e':
				system("Color E");
			break;
			case 'F':
			case 'f':
				system("Color F");
			break;
			defaul:;
				printf("Dame una opcion que sea valida...");
		}
		menu=getch();
	}while(!(menu=='s' || menu=='S'));
	return Color;
}

//Inicio Funcion Caracter_Cuadro permite imprimir el caracter numerpo 219
void Caracter_Cuadro()
{
		printf("%c%c",219,219);
}

//Inicio de funcion Caracter_Malla que permite imprimir el caracter 117
void Caracter_Malla()
{
		printf("%c",176);
}

//Inicio de funcion Menu_Principal que permite dar la presentacion del juego
void Menu_Principal()
{
	int menu; 
	
	gotoxy(6,2);//Inicio de letra P
	Caracter_Cuadro();
	gotoxy(5,3);
	Caracter_Cuadro();
	gotoxy(5,4);
	Caracter_Cuadro();
	gotoxy(5,5);
	Caracter_Cuadro();
	gotoxy(5,6);
	Caracter_Cuadro();
	gotoxy(5,7);
	Caracter_Cuadro();
	gotoxy(5,8);
	Caracter_Cuadro();
	gotoxy(5,9);
	Caracter_Cuadro();
	gotoxy(5,10);
	Caracter_Cuadro();
	gotoxy(5,11);
	Caracter_Cuadro();
	gotoxy(5,12);
	Caracter_Cuadro();
	gotoxy(7,2);
	Caracter_Cuadro();
	gotoxy(9,2);
	Caracter_Cuadro();
	gotoxy(11,2);
	Caracter_Cuadro();
	gotoxy(13,2);
	Caracter_Cuadro();
	gotoxy(14,2);
	Caracter_Cuadro();
	gotoxy(15,3);
	Caracter_Cuadro();
	gotoxy(15,4);
	Caracter_Cuadro();
	gotoxy(15,5);
	Caracter_Cuadro();
	gotoxy(14,6);
	Caracter_Cuadro();
	gotoxy(13,6);
	Caracter_Cuadro();
	gotoxy(11,6);
	Caracter_Cuadro();
	gotoxy(9,6);
	Caracter_Cuadro();
	gotoxy(7,6);
	Caracter_Cuadro();
	gotoxy(4,3);//Sobra
	Caracter_Malla();
	gotoxy(5,2);
	Caracter_Malla();
	gotoxy(4,4);
	Caracter_Malla();
	gotoxy(4,5);
	Caracter_Malla();
	gotoxy(4,6);
	Caracter_Malla();
	gotoxy(4,7);
	Caracter_Malla();
	gotoxy(4,8);
	Caracter_Malla();
	gotoxy(4,9);
	Caracter_Malla();
	gotoxy(4,10);
	Caracter_Malla();
	gotoxy(4,11);
	Caracter_Malla();
	gotoxy(4,12);
	Caracter_Malla();
	gotoxy(14,5);
	Caracter_Malla();
	gotoxy(14,4);
	Caracter_Malla();
	gotoxy(14,3);
	Caracter_Malla();
	gotoxy(20,12);//Inicio De Letra I
	Caracter_Cuadro();
	gotoxy(22,12);
	Caracter_Cuadro();
	gotoxy(24,12);
	Caracter_Cuadro();
	gotoxy(26,12);
	Caracter_Cuadro();
	gotoxy(28,12);
	Caracter_Cuadro();
	gotoxy(30,12);
	Caracter_Cuadro();
	gotoxy(25,11);
	Caracter_Cuadro();
	gotoxy(25,10);
	Caracter_Cuadro();
	gotoxy(25,9);
	Caracter_Cuadro();
	gotoxy(25,8);
	Caracter_Cuadro();
	gotoxy(25,7);
	Caracter_Cuadro();
	gotoxy(25,6);
	Caracter_Cuadro();
	gotoxy(25,5);
	Caracter_Cuadro();
	gotoxy(25,4);
	Caracter_Cuadro();
	gotoxy(25,3);
	Caracter_Cuadro();
	gotoxy(20,2);
	Caracter_Cuadro();
	gotoxy(22,2);
	Caracter_Cuadro();
	gotoxy(24,2);
	Caracter_Cuadro();
	gotoxy(26,2);
	Caracter_Cuadro();
	gotoxy(28,2);
	Caracter_Cuadro();
	gotoxy(30,2);
	Caracter_Cuadro();
	gotoxy(20,2);//Sobra
	Caracter_Malla();
	gotoxy(24,3);
	Caracter_Malla();
	gotoxy(24,4);
	Caracter_Malla();
	gotoxy(24,5);
	Caracter_Malla();
	gotoxy(24,6);
	Caracter_Malla();
	gotoxy(24,7);
	Caracter_Malla();
	gotoxy(24,8);
	Caracter_Malla();
	gotoxy(24,9);
	Caracter_Malla();
	gotoxy(24,10);
	Caracter_Malla();
	gotoxy(24,11);
	Caracter_Malla();
	gotoxy(20,12);
	Caracter_Malla();
	gotoxy(35,12);//Imnicio de letra N
	Caracter_Cuadro();
	gotoxy(35,11);
	Caracter_Cuadro();
	gotoxy(35,10);
	Caracter_Cuadro();
	gotoxy(35,9);
	Caracter_Cuadro();
	gotoxy(35,8);
	Caracter_Cuadro();
	gotoxy(35,7);
	Caracter_Cuadro();
	gotoxy(35,6);
	Caracter_Cuadro();
	gotoxy(35,5);
	Caracter_Cuadro();
	gotoxy(35,4);
	Caracter_Cuadro();
	gotoxy(35,3);
	Caracter_Cuadro();
	gotoxy(35,2);
	Caracter_Cuadro();
	gotoxy(37,2);
	Caracter_Cuadro();
	gotoxy(38,3);
	Caracter_Cuadro();
	gotoxy(39,4);
	Caracter_Cuadro();
	gotoxy(40,5);
	Caracter_Cuadro();
	gotoxy(41,6);
	Caracter_Cuadro();
	gotoxy(42,7);
	Caracter_Cuadro();
	gotoxy(43,8);
	Caracter_Cuadro();
	gotoxy(44,9);
	Caracter_Cuadro();
	gotoxy(45,10);
	Caracter_Cuadro();
	gotoxy(46,11);
	Caracter_Cuadro();
	gotoxy(47,12);
	Caracter_Cuadro();
	gotoxy(49,12);
	Caracter_Cuadro();
	gotoxy(49,11);
	Caracter_Cuadro();
	gotoxy(49,10);
	Caracter_Cuadro();
	gotoxy(49,9);
	Caracter_Cuadro();
	gotoxy(49,8);
	Caracter_Cuadro();
	gotoxy(49,7);
	Caracter_Cuadro();
	gotoxy(49,6);
	Caracter_Cuadro();
	gotoxy(49,5);
	Caracter_Cuadro();
	gotoxy(49,4);
	Caracter_Cuadro();
	gotoxy(49,3);
	Caracter_Cuadro();
	gotoxy(49,2);
	Caracter_Cuadro();
	gotoxy(34,2);//Sombr<a
	Caracter_Malla();
	gotoxy(34,3);
	Caracter_Malla();
	gotoxy(34,4);
	Caracter_Malla();
	gotoxy(34,5);
	Caracter_Malla();
	gotoxy(34,6);
	Caracter_Malla();
	gotoxy(34,7);
	Caracter_Malla();
	gotoxy(34,8);
	Caracter_Malla();
	gotoxy(34,9);
	Caracter_Malla();
	gotoxy(34,10);
	Caracter_Malla();
	gotoxy(34,11);
	Caracter_Malla();
	gotoxy(34,12);
	Caracter_Malla();
	gotoxy(48,2);
	Caracter_Malla();
	gotoxy(48,3);
	Caracter_Malla();
	gotoxy(48,4);
	Caracter_Malla();
	gotoxy(48,5);
	Caracter_Malla();
	gotoxy(48,6);
	Caracter_Malla();
	gotoxy(48,7);
	Caracter_Malla();
	gotoxy(48,8);
	Caracter_Malla();
	gotoxy(48,9);
	Caracter_Malla();
	gotoxy(48,10);
	Caracter_Malla();
	gotoxy(48,11);
	Caracter_Malla();
	gotoxy(37,3);
	Caracter_Malla();
	gotoxy(38,4);
	Caracter_Malla();
	gotoxy(39,5);
	Caracter_Malla();
	gotoxy(40,6);
	Caracter_Malla();
	gotoxy(41,7);
	Caracter_Malla();
	gotoxy(42,8);
	Caracter_Malla();
	gotoxy(43,9);
	Caracter_Malla();
	gotoxy(44,10);
	Caracter_Malla();
	gotoxy(45,11);
	Caracter_Malla();
	gotoxy(46,12);
	Caracter_Malla();
	gotoxy(56,2);//Inicio de letra G
	Caracter_Cuadro();
	gotoxy(58,2);
	Caracter_Cuadro();
	gotoxy(60,2);
	Caracter_Cuadro();
	gotoxy(62,2);
	Caracter_Cuadro();
	gotoxy(64,2);
	Caracter_Cuadro();
	gotoxy(66,2);
	Caracter_Cuadro();
	gotoxy(67,3);
	Caracter_Cuadro();
	gotoxy(55,3);
	Caracter_Cuadro();
	gotoxy(54,4);
	Caracter_Cuadro();
	gotoxy(54,5);
	Caracter_Cuadro();
	gotoxy(54,6);
	Caracter_Cuadro();
	gotoxy(54,7);
	Caracter_Cuadro();
	gotoxy(54,8);
	Caracter_Cuadro();
	gotoxy(54,9);
	Caracter_Cuadro();
	gotoxy(54,10);
	Caracter_Cuadro();
	gotoxy(55,11);
	Caracter_Cuadro();
	gotoxy(56,12);
	Caracter_Cuadro();
	gotoxy(58,12);
	Caracter_Cuadro();
	gotoxy(60,12);
	Caracter_Cuadro();
	gotoxy(62,12);
	Caracter_Cuadro();
	gotoxy(64,12);
	Caracter_Cuadro();
	gotoxy(66,12);
	Caracter_Cuadro();
	gotoxy(67,11);
	Caracter_Cuadro();
	gotoxy(68,10);
	Caracter_Cuadro();
	gotoxy(68,9);
	Caracter_Cuadro();
	gotoxy(68,8);
	Caracter_Cuadro();
	gotoxy(67,7);
	Caracter_Cuadro();
	gotoxy(65,7);
	Caracter_Cuadro();
	gotoxy(63,7);
	Caracter_Cuadro();
	gotoxy(55,2);//Sobra
	Caracter_Malla();
	gotoxy(54,3);
	Caracter_Malla();
	gotoxy(53,4);
	Caracter_Malla();
	gotoxy(53,5);
	Caracter_Malla();
	gotoxy(53,6);
	Caracter_Malla();
	gotoxy(53,7);
	Caracter_Malla();
	gotoxy(53,8);
	Caracter_Malla();
	gotoxy(53,9);
	Caracter_Malla();
	gotoxy(53,10);
	Caracter_Malla();
	gotoxy(54,11);
	Caracter_Malla();
	gotoxy(55,12);
	Caracter_Malla();
	gotoxy(66,11);
	Caracter_Malla();
	gotoxy(67,10);
	Caracter_Malla();
	gotoxy(67,9);
	Caracter_Malla();
	gotoxy(67,8);
	Caracter_Malla();
	gotoxy(63,7);
	Caracter_Malla();
	gotoxy(66,3);
	Caracter_Malla();
	gotoxy(21,16);//Inicio de letra P
	Caracter_Cuadro();
	gotoxy(20,17);
	Caracter_Cuadro();
	gotoxy(20,18);
	Caracter_Cuadro();
	gotoxy(20,19);
	Caracter_Cuadro();
	gotoxy(20,20);
	Caracter_Cuadro();
	gotoxy(20,21);
	Caracter_Cuadro();
	gotoxy(20,22);
	Caracter_Cuadro();
	gotoxy(20,23);
	Caracter_Cuadro();
	gotoxy(20,24);
	Caracter_Cuadro();
	gotoxy(20,25);
	Caracter_Cuadro();
	gotoxy(20,26);
	Caracter_Cuadro();
	gotoxy(22,16);
	Caracter_Cuadro();
	gotoxy(24,16);
	Caracter_Cuadro();
	gotoxy(26,16);
	Caracter_Cuadro();
	gotoxy(28,16);
	Caracter_Cuadro();
	gotoxy(29,16);
	Caracter_Cuadro();
	gotoxy(30,17);
	Caracter_Cuadro();
	gotoxy(30,18);
	Caracter_Cuadro();
	gotoxy(30,19);
	Caracter_Cuadro();
	gotoxy(29,20);
	Caracter_Cuadro();
	gotoxy(28,20);
	Caracter_Cuadro();
	gotoxy(26,20);
	Caracter_Cuadro();
	gotoxy(24,20);
	Caracter_Cuadro();
	gotoxy(22,20);
	Caracter_Cuadro();
	gotoxy(19,26);//Sombra
	Caracter_Malla();
	gotoxy(19,25);
	Caracter_Malla();
	gotoxy(19,24);
	Caracter_Malla();
	gotoxy(19,23);
	Caracter_Malla();
	gotoxy(19,22);
	Caracter_Malla();
	gotoxy(19,21);
	Caracter_Malla();
	gotoxy(19,20);
	Caracter_Malla();
	gotoxy(19,19);
	Caracter_Malla();
	gotoxy(19,18);
	Caracter_Malla();
	gotoxy(19,17);
	Caracter_Malla();
	gotoxy(20,16);
	Caracter_Malla();
	gotoxy(29,17);
	Caracter_Malla();
	gotoxy(29,18);
	Caracter_Malla();
	gotoxy(29,19);
	Caracter_Malla();
	gotoxy(35,24);//Inicio de letra O
	Caracter_Cuadro();
	gotoxy(36,25);
	Caracter_Cuadro();
	gotoxy(37,26);
	Caracter_Cuadro();
	gotoxy(39,26);
	Caracter_Cuadro();
	gotoxy(41,26);
	Caracter_Cuadro();
	gotoxy(42,26);
	Caracter_Cuadro();
	gotoxy(43,26);
	Caracter_Cuadro();
	gotoxy(45,26);
	Caracter_Cuadro();
	gotoxy(46,25);
	Caracter_Cuadro();
	gotoxy(47,24);
	Caracter_Cuadro();
	gotoxy(47,23);
	Caracter_Cuadro();
	gotoxy(47,22);
	Caracter_Cuadro();
	gotoxy(47,21);
	Caracter_Cuadro();
	gotoxy(47,20);
	Caracter_Cuadro();
	gotoxy(47,19);
	Caracter_Cuadro();
	gotoxy(47,18);
	Caracter_Cuadro();
	gotoxy(46,17);
	Caracter_Cuadro();
	gotoxy(45,16);
	Caracter_Cuadro();
	gotoxy(43,16);
	Caracter_Cuadro();
	gotoxy(41,16);
	Caracter_Cuadro();
	gotoxy(39,16);
	Caracter_Cuadro();
	gotoxy(37,16);
	Caracter_Cuadro();
	gotoxy(36,17);
	Caracter_Cuadro();
	gotoxy(35,18);
	Caracter_Cuadro();
	gotoxy(35,19);
	Caracter_Cuadro();
	gotoxy(35,20);
	Caracter_Cuadro();
	gotoxy(35,21);
	Caracter_Cuadro();
	gotoxy(35,22);
	Caracter_Cuadro();
	gotoxy(35,23);
	Caracter_Cuadro();
	gotoxy(36,16);//Sombra
	Caracter_Malla();
	gotoxy(35,17);
	Caracter_Malla();
	gotoxy(34,18);
	Caracter_Malla();
	gotoxy(34,19);
	Caracter_Malla();
	gotoxy(34,20);
	Caracter_Malla();
	gotoxy(34,21);
	Caracter_Malla();
	gotoxy(34,22);
	Caracter_Malla();
	gotoxy(34,23);
	Caracter_Malla();
	gotoxy(34,24);
	Caracter_Malla();
	gotoxy(35,25);
	Caracter_Malla();
	gotoxy(36,26);
	Caracter_Malla();
	gotoxy(45,25);
	Caracter_Malla();
	gotoxy(46,24);
	Caracter_Malla();
	gotoxy(46,23);
	Caracter_Malla();
	gotoxy(46,22);
	Caracter_Malla();
	gotoxy(46,21);
	Caracter_Malla();
	gotoxy(46,20);
	Caracter_Malla();
	gotoxy(46,19);
	Caracter_Malla();
	gotoxy(46,18);
	Caracter_Malla();
	gotoxy(45,17);
	Caracter_Malla();
	gotoxy(52,26);//Imnicio de letra N
	Caracter_Cuadro();
	gotoxy(52,25);
	Caracter_Cuadro();
	gotoxy(52,24);
	Caracter_Cuadro();
	gotoxy(52,23);
	Caracter_Cuadro();
	gotoxy(52,22);
	Caracter_Cuadro();
	gotoxy(52,21);
	Caracter_Cuadro();
	gotoxy(52,20);
	Caracter_Cuadro();
	gotoxy(52,19);
	Caracter_Cuadro();
	gotoxy(52,18);
	Caracter_Cuadro();
	gotoxy(52,17);
	Caracter_Cuadro();
	gotoxy(52,16);
	Caracter_Cuadro();
	gotoxy(54,16);
	Caracter_Cuadro();
	gotoxy(55,17);
	Caracter_Cuadro();
	gotoxy(56,18);
	Caracter_Cuadro();
	gotoxy(57,19);
	Caracter_Cuadro();
	gotoxy(58,20);
	Caracter_Cuadro();
	gotoxy(59,21);
	Caracter_Cuadro();
	gotoxy(60,22);
	Caracter_Cuadro();
	gotoxy(61,23);
	Caracter_Cuadro();
	gotoxy(62,24);
	Caracter_Cuadro();
	gotoxy(63,25);
	Caracter_Cuadro();
	gotoxy(64,26);
	Caracter_Cuadro();
	gotoxy(66,26);
	Caracter_Cuadro();
	gotoxy(66,25);
	Caracter_Cuadro();
	gotoxy(66,24);
	Caracter_Cuadro();
	gotoxy(66,23);
	Caracter_Cuadro();
	gotoxy(66,22);
	Caracter_Cuadro();
	gotoxy(66,21);
	Caracter_Cuadro();
	gotoxy(66,20);
	Caracter_Cuadro();
	gotoxy(66,19);
	Caracter_Cuadro();
	gotoxy(66,18);
	Caracter_Cuadro();
	gotoxy(66,17);
	Caracter_Cuadro();
	gotoxy(66,16);
	Caracter_Cuadro();
	gotoxy(51,16);//Sombra
	Caracter_Malla();
	gotoxy(51,17);
	Caracter_Malla();
	gotoxy(51,18);
	Caracter_Malla();
	gotoxy(51,19);
	Caracter_Malla();
	gotoxy(51,20);
	Caracter_Malla();
	gotoxy(51,21);
	Caracter_Malla();
	gotoxy(51,22);
	Caracter_Malla();
	gotoxy(51,23);
	Caracter_Malla();
	gotoxy(51,24);
	Caracter_Malla();
	gotoxy(51,25);
	Caracter_Malla();
	gotoxy(51,26);
	Caracter_Malla();
	gotoxy(63,26);
	Caracter_Malla();
	gotoxy(62,25);
	Caracter_Malla();
	gotoxy(61,24);
	Caracter_Malla();
	gotoxy(60,23);
	Caracter_Malla();
	gotoxy(59,22);
	Caracter_Malla();
	gotoxy(58,21);
	Caracter_Malla();
	gotoxy(57,20);
	Caracter_Malla();
	gotoxy(56,19);
	Caracter_Malla();
	gotoxy(55,18);
	Caracter_Malla();
	gotoxy(54,17);
	Caracter_Malla();
	gotoxy(65,16);
	Caracter_Malla();
	gotoxy(65,17);
	Caracter_Malla();
	gotoxy(65,18);
	Caracter_Malla();
	gotoxy(65,19);
	Caracter_Malla();
	gotoxy(65,20);
	Caracter_Malla();
	gotoxy(65,21);
	Caracter_Malla();
	gotoxy(65,22);
	Caracter_Malla();
	gotoxy(65,23);
	Caracter_Malla();
	gotoxy(65,24);
	Caracter_Malla();
	gotoxy(65,25);
	Caracter_Malla();
	gotoxy(73,16);//Inicio de letra G
	Caracter_Cuadro();
	gotoxy(75,16);
	Caracter_Cuadro();
	gotoxy(77,16);
	Caracter_Cuadro();
	gotoxy(79,16);
	Caracter_Cuadro();
	gotoxy(81,16);
	Caracter_Cuadro();
	gotoxy(83,16);
	Caracter_Cuadro();
	gotoxy(84,17);
	Caracter_Cuadro();
	gotoxy(72,17);
	Caracter_Cuadro();
	gotoxy(71,18);
	Caracter_Cuadro();
	gotoxy(71,19);
	Caracter_Cuadro();
	gotoxy(71,20);
	Caracter_Cuadro();
	gotoxy(71,21);
	Caracter_Cuadro();
	gotoxy(71,22);
	Caracter_Cuadro();
	gotoxy(71,23);
	Caracter_Cuadro();
	gotoxy(71,24);
	Caracter_Cuadro();
	gotoxy(72,25);
	Caracter_Cuadro();
	gotoxy(73,26);
	Caracter_Cuadro();
	gotoxy(75,26);
	Caracter_Cuadro();
	gotoxy(77,26);
	Caracter_Cuadro();
	gotoxy(79,26);
	Caracter_Cuadro();
	gotoxy(81,26);
	Caracter_Cuadro();
	gotoxy(83,26);
	Caracter_Cuadro();
	gotoxy(84,25);
	Caracter_Cuadro();
	gotoxy(85,24);
	Caracter_Cuadro();
	gotoxy(85,23);
	Caracter_Cuadro();
	gotoxy(85,22);
	Caracter_Cuadro();
	gotoxy(84,21);
	Caracter_Cuadro();
	gotoxy(82,21);
	Caracter_Cuadro();
	gotoxy(80,21);
	Caracter_Cuadro();
	gotoxy(72,16);//Sombra
	Caracter_Malla();
	gotoxy(71,17);
	Caracter_Malla();
	gotoxy(70,18);
	Caracter_Malla();
	gotoxy(70,19);
	Caracter_Malla();
	gotoxy(70,20);
	Caracter_Malla();
	gotoxy(70,21);
	Caracter_Malla();
	gotoxy(70,22);
	Caracter_Malla();
	gotoxy(70,23);
	Caracter_Malla();
	gotoxy(70,24);
	Caracter_Malla();
	gotoxy(71,25);
	Caracter_Malla();
	gotoxy(72,26);
	Caracter_Malla();
	gotoxy(83,25);
	Caracter_Malla();
	gotoxy(84,24);
	Caracter_Malla();
	gotoxy(84,23);
	Caracter_Malla();
	gotoxy(84,22);
	Caracter_Malla();
	gotoxy(83,17);
	Caracter_Malla();
	gotoxy(80,21);
	Caracter_Malla();
	gotoxy(80,3);
	printf("1) Jugar contra la computadora: ");
	gotoxy(80,5);
	printf("2) Jugar contra otro jugador: ");
	gotoxy(80,7);
	printf("3) Instrucciones y reglas del juego: ");
	gotoxy(80,9);
	printf("4) Personalizar colores de partida: ");	
	gotoxy(80,11);
	printf("5) Salir del juego: ");	
	gotoxy(45,28);
	printf("Dame la opcion que deseas hacer: ");
}

//Inicio de funcion Pantala_Perdedor permite imprimir cuando se pierde la partida
void Pantalla_Perdedor()
{
	gotoxy(36,2);//Inicio de letra Y
	Caracter_Cuadro();
	gotoxy(36,3);
	Caracter_Cuadro();
	gotoxy(36,4);
	Caracter_Cuadro();
	gotoxy(36,5);
	Caracter_Cuadro();
	gotoxy(36,6);
	Caracter_Cuadro();
	gotoxy(37,7);
	Caracter_Cuadro();
	gotoxy(38,8);
	Caracter_Cuadro();
	gotoxy(40,8);
	Caracter_Cuadro();
	gotoxy(42,8);
	Caracter_Cuadro();
	gotoxy(44,8);
	Caracter_Cuadro();
	gotoxy(46,8);
	Caracter_Cuadro();
	gotoxy(47,7);
	Caracter_Cuadro();
	gotoxy(48,6);
	Caracter_Cuadro();
	gotoxy(48,5);
	Caracter_Cuadro();
	gotoxy(48,4);
	Caracter_Cuadro();
	gotoxy(48,3);
	Caracter_Cuadro();
	gotoxy(48,2);
	Caracter_Cuadro();
	gotoxy(42,9);
	Caracter_Cuadro();
	gotoxy(42,10);
	Caracter_Cuadro();
	gotoxy(42,11);
	Caracter_Cuadro();
	gotoxy(42,12);
	Caracter_Cuadro();
	gotoxy(42,13);
	Caracter_Cuadro();
	gotoxy(42,14);
	Caracter_Cuadro();
	gotoxy(60,2);//Inicio de letra O
	Caracter_Cuadro();
	gotoxy(58,2);
	Caracter_Cuadro();
	gotoxy(56,2);
	Caracter_Cuadro();
	gotoxy(62,2);
	Caracter_Cuadro();
	gotoxy(64,2);
	Caracter_Cuadro();
	gotoxy(65,3);
	Caracter_Cuadro();
	gotoxy(66,4);
	Caracter_Cuadro();
	gotoxy(66,5);
	Caracter_Cuadro();
	gotoxy(66,6);
	Caracter_Cuadro();
	gotoxy(66,7);
	Caracter_Cuadro();
	gotoxy(66,8);
	Caracter_Cuadro();
	gotoxy(66,9);
	Caracter_Cuadro();
	gotoxy(66,10);
	Caracter_Cuadro();
	gotoxy(66,11);
	Caracter_Cuadro();
	gotoxy(66,12);
	Caracter_Cuadro();
	gotoxy(65,13);
	Caracter_Cuadro();
	gotoxy(64,14);
	Caracter_Cuadro();
	gotoxy(62,14);
	Caracter_Cuadro();
	gotoxy(60,14);
	Caracter_Cuadro();
	gotoxy(58,14);
	Caracter_Cuadro();
	gotoxy(56,14);
	Caracter_Cuadro();
	gotoxy(55,13);
	Caracter_Cuadro();
	gotoxy(54,12);
	Caracter_Cuadro();
	gotoxy(54,11);
	Caracter_Cuadro();
	gotoxy(54,10);
	Caracter_Cuadro();
	gotoxy(54,9);
	Caracter_Cuadro();
	gotoxy(54,8);
	Caracter_Cuadro();
	gotoxy(54,7);
	Caracter_Cuadro();
	gotoxy(54,6);
	Caracter_Cuadro();
	gotoxy(54,5);
	Caracter_Cuadro();
	gotoxy(54,4);
	Caracter_Cuadro();
	gotoxy(55,3);
	Caracter_Cuadro();
	gotoxy(72,2);//Inicio de letra U
	Caracter_Cuadro();
	gotoxy(72,3);
	Caracter_Cuadro();
	gotoxy(72,4);
	Caracter_Cuadro();
	gotoxy(72,5);
	Caracter_Cuadro();
	gotoxy(72,6);
	Caracter_Cuadro();
	gotoxy(72,7);
	Caracter_Cuadro();
	gotoxy(72,8);
	Caracter_Cuadro();
	gotoxy(72,9);
	Caracter_Cuadro();
	gotoxy(72,10);
	Caracter_Cuadro();
	gotoxy(72,11);
	Caracter_Cuadro();
	gotoxy(72,12);
	Caracter_Cuadro();
	gotoxy(73,13);
	Caracter_Cuadro();
	gotoxy(74,14);
	Caracter_Cuadro();
	gotoxy(76,14);
	Caracter_Cuadro();
	gotoxy(78,14);
	Caracter_Cuadro();
	gotoxy(80,14);
	Caracter_Cuadro();
	gotoxy(82,14);
	Caracter_Cuadro();
	gotoxy(83,13);
	Caracter_Cuadro();
	gotoxy(84,12);
	Caracter_Cuadro();
	gotoxy(84,11);
	Caracter_Cuadro();
	gotoxy(84,10);
	Caracter_Cuadro();
	gotoxy(84,9);
	Caracter_Cuadro();
	gotoxy(84,8);
	Caracter_Cuadro();
	gotoxy(84,7);
	Caracter_Cuadro();
	gotoxy(84,6);
	Caracter_Cuadro();
	gotoxy(84,5);
	Caracter_Cuadro();
	gotoxy(84,4);
	Caracter_Cuadro();
	gotoxy(84,3);
	Caracter_Cuadro();
	gotoxy(84,2);
	Caracter_Cuadro();
	gotoxy(30,27);//Inicio de letra L
	Caracter_Cuadro();
	gotoxy(28,27);
	Caracter_Cuadro();
	gotoxy(26,27);
	Caracter_Cuadro();
	gotoxy(24,27);
	Caracter_Cuadro();
	gotoxy(22,27);
	Caracter_Cuadro();
	gotoxy(20,27);
	Caracter_Cuadro();
	gotoxy(19,27);
	Caracter_Cuadro();
	gotoxy(18,26);
	Caracter_Cuadro();
	gotoxy(18,25);
	Caracter_Cuadro();
	gotoxy(18,24);
	Caracter_Cuadro();
	gotoxy(18,23);
	Caracter_Cuadro();
	gotoxy(18,22);
	Caracter_Cuadro();
	gotoxy(18,21);
	Caracter_Cuadro();
	gotoxy(18,20);
	Caracter_Cuadro();
	gotoxy(18,19);
	Caracter_Cuadro();
	gotoxy(18,18);
	Caracter_Cuadro();
	gotoxy(18,17);
	Caracter_Cuadro();
	gotoxy(48,19);//Inicio de letra O
	Caracter_Cuadro();
	gotoxy(48,20);
	Caracter_Cuadro();
	gotoxy(48,21);
	Caracter_Cuadro();
	gotoxy(48,22);
	Caracter_Cuadro();
	gotoxy(48,23);
	Caracter_Cuadro();
	gotoxy(48,24);
	Caracter_Cuadro();
	gotoxy(48,25);
	Caracter_Cuadro();
	gotoxy(47,26);
	Caracter_Cuadro();
	gotoxy(46,27);
	Caracter_Cuadro();
	gotoxy(44,27);
	Caracter_Cuadro();
	gotoxy(42,27);
	Caracter_Cuadro();
	gotoxy(40,27);
	Caracter_Cuadro();
	gotoxy(38,27);
	Caracter_Cuadro();
	gotoxy(37,26);
	Caracter_Cuadro();
	gotoxy(36,25);
	Caracter_Cuadro();
	gotoxy(36,24);
	Caracter_Cuadro();
	gotoxy(36,23);
	Caracter_Cuadro();
	gotoxy(36,22);
	Caracter_Cuadro();
	gotoxy(36,21);
	Caracter_Cuadro();
	gotoxy(36,20);
	Caracter_Cuadro();
	gotoxy(36,19);
	Caracter_Cuadro();
	gotoxy(37,18);
	Caracter_Cuadro();
	gotoxy(38,17);
	Caracter_Cuadro();
	gotoxy(40,17);
	Caracter_Cuadro();
	gotoxy(42,17);
	Caracter_Cuadro();
	gotoxy(44,17);
	Caracter_Cuadro();
	gotoxy(46,17);
	Caracter_Cuadro();
	gotoxy(47,18);
	Caracter_Cuadro();
	gotoxy(60,17);//Inicio de letra S
	Caracter_Cuadro();
	gotoxy(62,17);
	Caracter_Cuadro();
	gotoxy(64,17);
	Caracter_Cuadro();
	gotoxy(65,17);
	Caracter_Cuadro();
	gotoxy(66,18);
	Caracter_Cuadro();
	gotoxy(58,17);
	Caracter_Cuadro();
	gotoxy(56,17);
	Caracter_Cuadro();
	gotoxy(55,18);
	Caracter_Cuadro();
	gotoxy(54,19);
	Caracter_Cuadro();
	gotoxy(54,20);
	Caracter_Cuadro();
	gotoxy(55,21);
	Caracter_Cuadro();
	gotoxy(56,22);
	Caracter_Cuadro();
	gotoxy(57,22);
	Caracter_Cuadro();
	gotoxy(59,22);
	Caracter_Cuadro();
	gotoxy(61,22);
	Caracter_Cuadro();
	gotoxy(63,22);
	Caracter_Cuadro();
	gotoxy(64,22);
	Caracter_Cuadro();
	gotoxy(65,23);
	Caracter_Cuadro();
	gotoxy(66,24);
	Caracter_Cuadro();
	gotoxy(66,25);
	Caracter_Cuadro();
	gotoxy(65,26);
	Caracter_Cuadro();
	gotoxy(64,27);
	Caracter_Cuadro();
	gotoxy(62,27);
	Caracter_Cuadro();
	gotoxy(60,27);
	Caracter_Cuadro();
	gotoxy(58,27);
	Caracter_Cuadro();
	gotoxy(56,27);
	Caracter_Cuadro();
	gotoxy(55,27);
	Caracter_Cuadro();
	gotoxy(54,26);
	Caracter_Cuadro();
	gotoxy(73,17);//Inicio de letra E
	Caracter_Cuadro();
	gotoxy(75,17);
	Caracter_Cuadro();
	gotoxy(77,17);
	Caracter_Cuadro();
	gotoxy(79,17);
	Caracter_Cuadro();
	gotoxy(81,17);
	Caracter_Cuadro();
	gotoxy(83,17);
	Caracter_Cuadro();
	gotoxy(84,17);
	Caracter_Cuadro();
	gotoxy(72,18);
	Caracter_Cuadro();
	gotoxy(72,19);
	Caracter_Cuadro();
	gotoxy(72,20);
	Caracter_Cuadro();
	gotoxy(72,21);
	Caracter_Cuadro();
	gotoxy(72,22);
	Caracter_Cuadro();
	gotoxy(72,23);
	Caracter_Cuadro();
	gotoxy(72,24);
	Caracter_Cuadro();
	gotoxy(72,25);
	Caracter_Cuadro();
	gotoxy(72,26);
	Caracter_Cuadro();
	gotoxy(73,27);
	Caracter_Cuadro();
	gotoxy(75,27);
	Caracter_Cuadro();
	gotoxy(77,27);
	Caracter_Cuadro();
	gotoxy(79,27);
	Caracter_Cuadro();
	gotoxy(81,27);
	Caracter_Cuadro();
	gotoxy(83,27);
	Caracter_Cuadro();
	gotoxy(84,27);
	Caracter_Cuadro();
	gotoxy(74,22);
	Caracter_Cuadro();
	gotoxy(76,22);
	Caracter_Cuadro();
	gotoxy(78,22);
	Caracter_Cuadro();
	gotoxy(80,22);
	Caracter_Cuadro();
	gotoxy(82,22);
	Caracter_Cuadro();
	gotoxy(84,22);
	Caracter_Cuadro();
	gotoxy(91,17);//Inicio de letra R
	Caracter_Cuadro();
	gotoxy(90,18);
	Caracter_Cuadro();
	gotoxy(90,19);
	Caracter_Cuadro();
	gotoxy(90,20);
	Caracter_Cuadro();
	gotoxy(90,21);
	Caracter_Cuadro();
	gotoxy(90,22);
	Caracter_Cuadro();
	gotoxy(90,23);
	Caracter_Cuadro();
	gotoxy(90,24);
	Caracter_Cuadro();
	gotoxy(90,25);
	Caracter_Cuadro();
	gotoxy(90,26);
	Caracter_Cuadro();
	gotoxy(90,27);
	Caracter_Cuadro();
	gotoxy(93,17);
	Caracter_Cuadro();
	gotoxy(95,17);
	Caracter_Cuadro();
	gotoxy(97,17);
	Caracter_Cuadro();
	gotoxy(99,17);
	Caracter_Cuadro();
	gotoxy(100,17);
	Caracter_Cuadro();
	gotoxy(101,18);
	Caracter_Cuadro();
	gotoxy(102,19);
	Caracter_Cuadro();
	gotoxy(102,20);
	Caracter_Cuadro();
	gotoxy(101,21);
	Caracter_Cuadro();
	gotoxy(100,22);
	Caracter_Cuadro();
	gotoxy(98,22);
	Caracter_Cuadro();
	gotoxy(96,22);
	Caracter_Cuadro();
	gotoxy(94,22);
	Caracter_Cuadro();
	gotoxy(92,22);
	Caracter_Cuadro();
	gotoxy(94,23);
	Caracter_Cuadro();
	gotoxy(96,24);
	Caracter_Cuadro();
	gotoxy(98,25);
	Caracter_Cuadro();
	gotoxy(100,26);
	Caracter_Cuadro();
	gotoxy(102,27);
	Caracter_Cuadro();
	gotoxy(45,29);
}

//Inicio de Funcion Pantalla_Final permite despedir al usuario del juego
void Pantalla_Final()
{
	int x,y;
	
	gotoxy(4,2);//Inicio de letra T
	Caracter_Cuadro();
	gotoxy(6,2);
	Caracter_Cuadro();
	gotoxy(8,2);
	Caracter_Cuadro();
	gotoxy(10,2);
	Caracter_Cuadro();
	gotoxy(12,2);
	Caracter_Cuadro();
	gotoxy(14,2);
	Caracter_Cuadro();
	gotoxy(9,3);
	Caracter_Cuadro();
	gotoxy(9,4);
	Caracter_Cuadro();
	gotoxy(9,5);
	Caracter_Cuadro();
	gotoxy(9,6);
	Caracter_Cuadro();
	gotoxy(9,7);
	Caracter_Cuadro();
	gotoxy(9,8);
	Caracter_Cuadro();
	gotoxy(9,9);
	Caracter_Cuadro();
	gotoxy(9,10);
	Caracter_Cuadro();
	for(y=2;y<11;y=y+1)
	{
		gotoxy(18,y);
		Caracter_Cuadro();
	}
	gotoxy(20,6);
	Caracter_Cuadro();
	gotoxy(22,6);
	Caracter_Cuadro();
	gotoxy(24,6);
	Caracter_Cuadro();
	gotoxy(26,6);
	Caracter_Cuadro();
	for(y=2;y<11;y=y+1)
	{
		gotoxy(28,y);
		Caracter_Cuadro();
	}
	gotoxy(32,10);//Inicio de letra A
	Caracter_Cuadro();
	gotoxy(32,9);
	Caracter_Cuadro();
	gotoxy(33,8);
	Caracter_Cuadro();
	gotoxy(33,7);
	Caracter_Cuadro();
	gotoxy(34,6);
	Caracter_Cuadro();
	gotoxy(34,5);
	Caracter_Cuadro();
	gotoxy(35,4);
	Caracter_Cuadro();
	gotoxy(35,3);
	Caracter_Cuadro();
	gotoxy(36,2);
	Caracter_Cuadro();
	gotoxy(38,2);
	Caracter_Cuadro();
	gotoxy(39,3);
	Caracter_Cuadro();
	gotoxy(39,4);
	Caracter_Cuadro();
	gotoxy(40,5);
	Caracter_Cuadro();
	gotoxy(40,6);
	Caracter_Cuadro();
	gotoxy(41,7);
	Caracter_Cuadro();
	gotoxy(41,8);
	Caracter_Cuadro();
	gotoxy(42,9);
	Caracter_Cuadro();
	gotoxy(42,10);
	Caracter_Cuadro();
	gotoxy(36,6);
	Caracter_Cuadro();
	gotoxy(38,6);
	Caracter_Cuadro();
	for (y=2;y<11;y=y+1)//Inicio de letra N
	{
		gotoxy(46,y);
		Caracter_Cuadro();
	}
	gotoxy(48,3);
	Caracter_Cuadro();
	gotoxy(49,4);
	Caracter_Cuadro();
	gotoxy(50,5);
	Caracter_Cuadro();
	gotoxy(51,6);
	Caracter_Cuadro();
	gotoxy(52,7);
	Caracter_Cuadro();
	gotoxy(53,8);
	Caracter_Cuadro();
	gotoxy(54,9);
	Caracter_Cuadro();
	for(y=2;y<11;y=y+1)
	{
		gotoxy(56,y);
		Caracter_Cuadro();
	}
	for(y=2;y<11;y=y+1)//Inicio de letra K
	{
		gotoxy(60,y);
		Caracter_Cuadro();
	}
	gotoxy(62,6);
	Caracter_Cuadro();
	gotoxy(64,5);
	Caracter_Cuadro();
	gotoxy(66,4);
	Caracter_Cuadro();
	gotoxy(68,3);
	Caracter_Cuadro();
	gotoxy(70,2);
	Caracter_Cuadro();
	gotoxy(64,7);
	Caracter_Cuadro();
	gotoxy(66,8);
	Caracter_Cuadro();
	gotoxy(68,9);
	Caracter_Cuadro();
	gotoxy(70,10);
	Caracter_Cuadro();
	gotoxy(74,9);//Inicio letra S
	Caracter_Cuadro();
	gotoxy(75,10);
	Caracter_Cuadro();
	gotoxy(77,10);
	Caracter_Cuadro();
	gotoxy(79,10);
	Caracter_Cuadro();
	gotoxy(81,10);
	Caracter_Cuadro();
	gotoxy(82,10);
	Caracter_Cuadro();
	gotoxy(83,9);
	Caracter_Cuadro();
	gotoxy(84,8);
	Caracter_Cuadro();
	gotoxy(83,7);
	Caracter_Cuadro();
	gotoxy(82,6);
	Caracter_Cuadro();
	gotoxy(80,6);
	Caracter_Cuadro();
	gotoxy(78,6);
	Caracter_Cuadro();
	gotoxy(76,6);
	Caracter_Cuadro();
	gotoxy(75,5);
	Caracter_Cuadro();
	gotoxy(74,4);
	Caracter_Cuadro();
	gotoxy(75,3);
	Caracter_Cuadro();
	gotoxy(76,2);
	Caracter_Cuadro();
	gotoxy(78,2);
	Caracter_Cuadro();
	gotoxy(80,2);
	Caracter_Cuadro();
	gotoxy(82,2);
	Caracter_Cuadro();
	gotoxy(83,2);
	Caracter_Cuadro();
	gotoxy(84,3);
	Caracter_Cuadro();
	for(y=13;y<17;y=y+1)//Inicio de letra F
	{
		gotoxy(35,y);
		Caracter_Cuadro();
	}
	gotoxy(36,12);
	Caracter_Cuadro();
	gotoxy(37,12);
	Caracter_Cuadro();
	gotoxy(39,12);
	Caracter_Cuadro();
	gotoxy(37,14);
	Caracter_Cuadro();
	for(x=44;x<48;x=x+1)//Inicio letra O
	{
		gotoxy(x,12);
		Caracter_Cuadro();
		gotoxy(x,16);
		Caracter_Cuadro();
	}
	for(y=13;y<16;y=y+1)
	{
		gotoxy(43,y);
		Caracter_Cuadro();
		gotoxy(48,y);
		Caracter_Cuadro();
	}
	for(y=13;y<17;y=y+1)//Inicio de letra R
	{
		gotoxy(52,y);
		Caracter_Cuadro();
	}
	for(x=53;x<56;x=x+1)
	{
		gotoxy(x,12);
		Caracter_Cuadro();
		gotoxy(x,14);
		Caracter_Cuadro();
	}
	gotoxy(56,13);
	Caracter_Cuadro();
	gotoxy(55,15);
	printf("%c",219);
	gotoxy(56,16);
	printf("%c",219);
	for(y=19;y<29;y=y+1)//Inicio de letra P
	{
		gotoxy(4,y);
		Caracter_Cuadro();
	}
	for(x=5;x<14;x=x+1)
	{
		gotoxy(x,18);
		Caracter_Cuadro();
	}
	for(y=19;y<23;y=y+1)
	{
		gotoxy(14,y);
		Caracter_Cuadro();
	}
	for(x=5;x<14;x=x+1)
	{
		gotoxy(x,23);
		Caracter_Cuadro();
	}
	for(y=18;y<29;y=y+1)//Inicio de letra L
	{
		gotoxy(18,y);
		Caracter_Cuadro();
	}
	for(x=18;x<29;x=x+1)
	{
		gotoxy(x,28);
		Caracter_Cuadro();
	}
	gotoxy(32,28);//Inicio letra A
	Caracter_Cuadro();
	gotoxy(32,27);
	Caracter_Cuadro();
	gotoxy(33,26);
	Caracter_Cuadro();
	gotoxy(33,25);
	Caracter_Cuadro();
	gotoxy(34,24);
	Caracter_Cuadro();
	gotoxy(34,23);
	Caracter_Cuadro();
	gotoxy(35,22);
	Caracter_Cuadro();
	gotoxy(35,21);
	Caracter_Cuadro();
	gotoxy(36,20);
	Caracter_Cuadro();
	gotoxy(36,19);
	Caracter_Cuadro();
	gotoxy(37,18);
	Caracter_Cuadro();
	gotoxy(39,18);
	Caracter_Cuadro();
	gotoxy(40,19);
	Caracter_Cuadro();
	gotoxy(40,20);
	Caracter_Cuadro();
	gotoxy(41,21);
	Caracter_Cuadro();
	gotoxy(41,22);
	Caracter_Cuadro();
	gotoxy(42,23);
	Caracter_Cuadro();
	gotoxy(42,24);
	Caracter_Cuadro();
	gotoxy(43,25);
	Caracter_Cuadro();
	gotoxy(43,26);
	Caracter_Cuadro();
	gotoxy(44,27);
	Caracter_Cuadro();
	gotoxy(44,28);
	Caracter_Cuadro();
	for(x=36;x<41;x=x+1)
	{
		gotoxy(x,23);
		Caracter_Cuadro();
	}
	gotoxy(48,18);//Inicio de letra Y
	Caracter_Cuadro();
	gotoxy(48,19);
	Caracter_Cuadro();
	gotoxy(49,20);
	Caracter_Cuadro();
	gotoxy(49,21);
	Caracter_Cuadro();
	gotoxy(50,22);
	Caracter_Cuadro();
	gotoxy(50,23);
	Caracter_Cuadro();
	for(x=51;x<54;x=x+1)
	{
		gotoxy(x,23);
		Caracter_Cuadro();
	}
	gotoxy(54,23);
	Caracter_Cuadro();
	gotoxy(54,22);
	Caracter_Cuadro();
	gotoxy(55,21);
	Caracter_Cuadro();
	gotoxy(55,20);
	Caracter_Cuadro();
	gotoxy(56,19);
	Caracter_Cuadro();
	gotoxy(56,18);
	Caracter_Cuadro();
	for(y=24;y<29;y=y+1)
	{
		gotoxy(52,y);
		Caracter_Cuadro();
	}
	for(x=60;x<71;x=x+1)//Inicio de letra N
	{
		gotoxy(x,18);
		Caracter_Cuadro();
		gotoxy(x,28);
		Caracter_Cuadro();
	}
	for(y=18;y<29;y=y+1)
	{
		gotoxy(65,y);
		Caracter_Cuadro();
	}
	for(y=18;y<29;y=y+1)
	{
		gotoxy(74,y);
		Caracter_Cuadro();
		gotoxy(84,y);
		Caracter_Cuadro();
	}
	gotoxy(76,19);
	Caracter_Cuadro();
	gotoxy(76,20);
	Caracter_Cuadro();
	gotoxy(77,21);
	Caracter_Cuadro();
	gotoxy(77,22);
	Caracter_Cuadro();
	gotoxy(78,22);
	Caracter_Cuadro();
	gotoxy(78,23);
	Caracter_Cuadro();
	gotoxy(79,23);
	Caracter_Cuadro();
	gotoxy(80,24);
	Caracter_Cuadro();
	gotoxy(81,24);
	Caracter_Cuadro();
	gotoxy(81,25);
	Caracter_Cuadro();
	gotoxy(82,26);
	Caracter_Cuadro();
	gotoxy(82,27);
	Caracter_Cuadro();
	for(y=20;y<27;y=y+1)
	{
		gotoxy(88,y);
		Caracter_Cuadro();
	}
	gotoxy(89,19);
	Caracter_Cuadro();
	for(x=90;x<97;x=x+1)
	{
		gotoxy(x,18);
		Caracter_Cuadro();
		gotoxy(x,28);
		Caracter_Cuadro();
	}
	gotoxy(89,27);
	Caracter_Cuadro();
	gotoxy(97,27);
	Caracter_Cuadro();
	for(y=24;y<27;y=y+1)
	{
		gotoxy(98,y);
		Caracter_Cuadro();
	}
	for(x=95;x<98;x=x+1)
	{
		gotoxy(x,23);
		Caracter_Cuadro();
	}
	gotoxy(97,19);
	Caracter_Cuadro();
}

//Inicio de funcion Pantalla_Inicio permite imprimir un pequeño letrero
void Pantalla_Inicio()
{
	int x,y;
	
	gotoxy(2,6);//Inicio de letra W
	Caracter_Cuadro();
	gotoxy(2,7);
	Caracter_Cuadro();
	gotoxy(3,8);
	Caracter_Cuadro();
	gotoxy(3,9);
	Caracter_Cuadro();
	gotoxy(4,10);
	Caracter_Cuadro();
	gotoxy(4,11);
	Caracter_Cuadro();
	gotoxy(5,12);
	Caracter_Cuadro();
	gotoxy(5,13);
	Caracter_Cuadro();
	gotoxy(6,14);
	Caracter_Cuadro();
	gotoxy(8,14);
	Caracter_Cuadro();
	gotoxy(9,13);
	Caracter_Cuadro();
	gotoxy(9,12);
	Caracter_Cuadro();
	gotoxy(10,11);
	Caracter_Cuadro();
	gotoxy(11,11);
	Caracter_Cuadro();
	gotoxy(12,12);
	Caracter_Cuadro();
	gotoxy(12,13);
	Caracter_Cuadro();
	gotoxy(13,14);
	Caracter_Cuadro();
	gotoxy(15,14);
	Caracter_Cuadro();
	gotoxy(16,13);
	Caracter_Cuadro();
	gotoxy(16,12);
	Caracter_Cuadro();
	gotoxy(17,11);
	Caracter_Cuadro();
	gotoxy(17,10);
	Caracter_Cuadro();
	gotoxy(18,9);
	Caracter_Cuadro();
	gotoxy(18,8);
	Caracter_Cuadro();
	gotoxy(19,7);
	Caracter_Cuadro();
	gotoxy(19,6);
	Caracter_Cuadro();
	for(y=7;y<14;y=y+1)//Inicio letra E
	{
		gotoxy(23,y);
		Caracter_Cuadro();
	}
	for(x=24;x<32;x=x+1)
	{
		gotoxy(x,6);
		Caracter_Cuadro();
		gotoxy(x,14);
		Caracter_Cuadro();
	}
	for(x=24;x<28;x=x+1)
	{
		gotoxy(x,10);
		Caracter_Cuadro();
	}
	for(y=6;y<15;y=y+1)//Inicio de letra L
	{
		gotoxy(35,y);
		Caracter_Cuadro();
	}
	for(x=36;x<44;x=x+1)
	{
		gotoxy(x,14);
		Caracter_Cuadro();
	}
	gotoxy(48,13);//Inicio de letra C
	Caracter_Cuadro();
	for(x=49;x<59;x=x+1)
	{
		gotoxy(x,14);
		Caracter_Cuadro();
		gotoxy(x,6);
		Caracter_Cuadro();
	}
	for(y=8;y<13;y=y+1)
	{
		gotoxy(47,y);
		Caracter_Cuadro();
	}
	gotoxy(48,7);
	Caracter_Cuadro();
	gotoxy(59,7);
	Caracter_Cuadro();
	gotoxy(59,13);
	Caracter_Cuadro();
	for(x=65;x<75;x=x+1)//Inicio letra O
	{
		gotoxy(x,6);
		Caracter_Cuadro();
		gotoxy(x,14);
		Caracter_Cuadro();
	}
	for(y=8;y<13;y=y+1)
	{
		gotoxy(63,y);
		Caracter_Cuadro();
		gotoxy(76,y);
		Caracter_Cuadro();
	}
	gotoxy(64,7);
	Caracter_Cuadro();
	gotoxy(64,13);
	Caracter_Cuadro();
	gotoxy(75,7);
	Caracter_Cuadro();
	gotoxy(75,13);
	Caracter_Cuadro();
	for(y=6;y<15;y=y+1)//Iniico de letra M
	{
		gotoxy(80,y);
		Caracter_Cuadro();
		gotoxy(89,y);
		Caracter_Cuadro();
	}
	gotoxy(82,7);
	Caracter_Cuadro();
	gotoxy(83,8);
	Caracter_Cuadro();
	gotoxy(84,9);
	Caracter_Cuadro();
	gotoxy(85,9);
	Caracter_Cuadro();
	gotoxy(86,8);
	Caracter_Cuadro();
	gotoxy(87,7);
	Caracter_Cuadro();
	for(y=7;y<14;y=y+1)//Inicio de letra E
	{
		gotoxy(93,y);
		Caracter_Cuadro();
	}
	for(x=94;x<102;x=x+1)
	{
		gotoxy(x,6);
		Caracter_Cuadro();
		gotoxy(x,14);
		Caracter_Cuadro();
	}
	for(x=94;x<98;x=x+1)
	{
		gotoxy(x,10);
		Caracter_Cuadro();
	}
}
