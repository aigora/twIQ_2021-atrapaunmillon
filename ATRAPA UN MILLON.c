//ATRAPA UN MILLÓN
#include<stdio.h>
#include<string.h>//Funciones de las cadenas
#define MAX_USUARIOS 100

struct usuario{

	char nombreUsuario[100];
	char contrasena[200];
};

do{	
	system("cls");//Borrar pantalla	
	printf("Atrapa Un Millon\n Bienvenido al menu opciones:\n ");
	printf("Introduce la opcion:\n");
	printf("-----------------------\n");
	printf("a-Iniciar sesion para jugar\n");
	printf("b-Registrarse\n");
	printf("c-Intrucciones\n");
	printf("d-Salir\n");
	printf("-----------------------\n");
