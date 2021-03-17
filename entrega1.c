#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <string.h>


typedef struct{
	char jugador1[20];
	char jugador2[20];
	int puntosjugador1;
	int puntosjugador2;
	char lugar[25];
}Partida;

typedef struct{
	Partida partida[100];
	int num;
}ListaPartidas;
void Perdedores (ListaPartidas lista, char nombre[20])
{
	int puntosganador;
	int puntosperdedor;
	int i=0;
	while(i<lista.num)
	{
		if((strcmp(lista.partida[i].jugador1,nombre))==0)
		{
			if(lista.partida[i].puntosjugador1>lista.partida[i].puntosjugador2)
			{
				printf("Ganaste a: %s\n",lista.partida[i].jugador2 );
			}
		}
		
		if((strcmp(lista.partida[i].jugador2,nombre))==0)
		{
			if(lista.partida[i].puntosjugador2>lista.partida[i].puntosjugador1)
			{
				printf("Ganaste a: %s\n",lista.partida[i].jugador1 );
			}
		}
		i=i+1;
		
	}
}
int GanadorBarcelona (ListaPartidas lista){
	int i=0;
	int encontrado=0;
	int puntos;
	while(i<lista.num && encontrado==0){
		if((strcmp(lista.partida[i].lugar,"Barcelona"))==0){
			if(lista.partida[i].puntosjugador1>lista.partida[i].puntosjugador2)
			{
				puntos=lista.partida[i].puntosjugador1;
			}
			else{
				puntos=lista.partida[i].puntosjugador2;
			}
			encontrado=1;
		}
		i=i+1;
	}
	if(encontrado=1){
		return puntos;
	}
	else {
		return -1;
	}
}
int JugadorMasPuntos(ListaPartidas *lista, char nombre[100]){
	int i=0;
	int puntos=0;
	while(i<lista->num){
		if(lista->partida[i].puntosjugador1>lista->partida[i].puntosjugador2)
		{
			if(lista->partida[i].puntosjugador1>puntos){
				sprintf(nombre,"%s",lista->partida[i].jugador1);
				puntos=lista->partida[i].puntosjugador1;
			}
		}
		else{
			if(lista->partida[i].puntosjugador2>puntos){
				sprintf(nombre,"%s",lista->partida[i].jugador2);
				puntos=lista->partida[i].puntosjugador2;
			}
			
		}
		i=i+1;
		
		
	}
	return puntos;
}
int PerdedoresLista(ListaPartidas *lista, char ganador[20], char nombres[100]){
	
}
int main(int argc, char *argv[]) {
	ListaPartidas lista;
	strcpy(lista.partida[0].jugador1,"Juan");
	strcpy(lista.partida[0].jugador2,"Luis");
	lista.partida[0].puntosjugador1=25;
	lista.partida[0].puntosjugador2=15;
	strcpy(lista.partida[0].lugar,"Barcelona");
	strcpy(lista.partida[1].jugador1,"Juan");
	strcpy(lista.partida[1].jugador2,"Luis");
	lista.partida[1].puntosjugador1=35;
	lista.partida[1].puntosjugador2=25;
	strcpy(lista.partida[1].lugar,"Madrid");
	strcpy(lista.partida[2].jugador1,"Ana");
	strcpy(lista.partida[2].jugador2,"Luis");
	lista.partida[2].puntosjugador1=28;
	lista.partida[2].puntosjugador2=20;
	strcpy(lista.partida[2].lugar,"Madrid");
	lista.num=3;
	Perdedores(lista,"Ana");
	GanadorBarcelona(lista);
	char JugadorConMasPuntos[100];
	printf("El jugador con mas puntos es %s con %d puntos\n ", 
		   JugadorConMasPuntos,JugadorMasPuntos(&lista, JugadorConMasPuntos));
	char JugadoresPerdieron[100];
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
	
	
				
				
