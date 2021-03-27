//ATRAPA UN MILLÓN
#include<stdio.h>
#include<string.h>//Funciones de las cadenas
#define MAX_USUARIOS 200

struct usuario{

	char nombreUsuario[200];
	char contrasena[200];
};

int main(){
	char respuesta,info;
	do{
		system("cls");//Borrar pantalla	
		printf("ATRAPA UN MILLON\n Bienvenido al menu opciones:\n ");
		printf("Introduce la opcion:\n");
		printf("._____________________________.\n");
		printf("|a-Iniciar sesion para jugar  |\n");
		printf("|b-Registrarse                |\n");
		printf("|c-Intrucciones               |\n");
		printf("|d-Salir                      |\n");
		printf("|_____________________________|\n");
	
		fflush(stdin);
		scanf("%c",&respuesta);
	
		switch(respuesta){
			case 'a': printf("INICIAR SESION\n");
					
				//Pedir nombre de usuario+contraseña y buscar en los ficheros guardados
				//Desarrollo del juego
				printf("Ya puede empezar a jugar¡Suerte!");
				break;
				
			case 'b': printf("REGISTRATE\nSigue las instrucciones\n");
					
				//Crear fichero (pedir nombre de usuario+contraseña)	
				break;
					
			case 'c':printf("INSTRUCCIONES:\n");
			
				printf("En este juego deberas responder a las preguntas que se te formulen, apostando tu dinero en la(s) respuesta(s) que creas correctas. Tu objetivo es terminar el juego con la mayor cantidad de dinero posible.\n");
					
				do{
					
					printf("Para mas informacion pulse:\n");
					printf("-----------------------\n");
					printf("a-Tipos de preguntas\n");
					printf("b-Sobre el dinero\n");
					printf("c-Salir de este menu\n");
					printf("-----------------------\n");
					fflush(stdin);
					scanf("%c",&info);
					
						if(info=='a'){
							printf("TIPOS DE PREGUNTAS\n");
							printf("Se te propondran preguntas sobre temas aleatorios\n");
						}else if(info=='b'){
							printf("SOBRE EL DINERO\n");
							printf("El dinero con el que se juega NO es dinero real.\nEl usuario tras cada pregunta podra ver la cantidad de dinero que le queda\nLa suma de dinero apostado debe ser exactamente igual a la que el usuario tiene.\nEl millon de euros con el que el usuario juega se divide en mil fajos de mil euros indivisibles.\n");
						}else if(info=='c'){
							break; 
						}else{
							printf("Opcion no disponible\n");
						}
						
						system("PAUSE");		
					}while(info!='c');
				
					break;
					
			case 'd':printf("Adios");
					break;
		
			default: 
					printf("Opcion incorrecta\n");
					break;
		}
	}while(respuesta!='d');
}
