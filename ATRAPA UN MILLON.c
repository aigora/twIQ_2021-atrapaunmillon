//ATRAPA UN MILLÓN
#include<stdio.h>
#include<string.h>//Funciones de las cadenas
#define MAX_USUARIOS 100

struct usuario{

	char nombreUsuario[100];
	char contrasena[200];
};

int main(){
	int respuesta;
printf("BIENVENIDO A ATRAPA UN MILLÓN)
//A continuación aparecerá en pantalla un menú con 3 opciones que el usuario tendrá que elegir:
printf("A.Registrarse\n");
printf("B.Iniciar sesión\n");
printf("C.Salir\n");
       scanf("%d", respuesta);


