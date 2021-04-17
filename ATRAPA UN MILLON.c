//ATRAPA UN MILLÓN
#include<stdio.h>

struct usuario{

	char nombreUsuario[200];
	char contrasena[200];
};

int main(){
	char respuesta,info;
	int i;
	char userName[200];
	char password;
	int copia=0;
	int numUsuario;
	int apuesta1A,apuesta1B,apuesta1C;
	struct usuario u[i];
	FILE * aumfichero;
	
	do{
		system("cls");//Borrar pantalla	
		printf("ATRAPA UN MILLON\n Bienvenido al menu opciones:\n ");
		printf("\nIntroduce la opcion:\n");
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
					
					//Abrimos el fichero
					aumfichero= fopen("datosUsuarios.txt","r");//Modo lectura
					
					//Comprobamos si encuentra el fichero, si no lo encuentra, el resto del programa no funciona
					if(aumfichero==NULL){
					printf("No se ha podido encontrar el fichero\n");
					return 0;
					}
					
					//Mirar cuántos usuarios ya hay en ese fichero y guardar en un vector
					i=0;
					while(fscanf(aumfichero,"%s %s",&u[i].nombreUsuario ,&u[i].contrasena)!=EOF){
						numUsuario++;
						i++;
					}
					printf("Hay %d usuarios registrados\n",numUsuario);
					
					//Cerrar el fichero
					fclose(aumfichero);
				
					//Pedimos los datos para iniciar sesión
				do{
					
					printf("Introduzca  nombre de usuario:\n");
					fflush(stdin);
					scanf("%s",userName);
					printf("Introduzca contrasena:\n");
					fflush(stdin);
					scanf("%s",password);
					
					//¿Existe ese usuario y contraseña?
					for(i=0;i<numUsuario;i++){
							if(strcmp(userName,u[i].nombreUsuario)==0 && strcmp(password,u[i].contrasena)==0){
								igual=1;
								break;
							}else{
								igual=0;
							}
						}
						
						if(igual==0){
							printf("Usuario o contrasena son incorrectos.\n");
						}else{
							printf("Usuario valido\n");
						}
						system("PAUSE");
					}while(igual==0);
				
					
				break;
							
			case 'b': printf("REGISTRATE\nSigue las instrucciones\n");
									
					//Abrimos fichero
					aumfichero= fopen("datosUsuarios.txt","r");
					
					
					//Comprobamos si no existe
					if(aumfichero==NULL){
					printf("No se ha podido encontrar el fichero\n");
					return 0;
					}
					
					//Miramos cuántos usuarios ya hay en el fichero e introducir a un vector
					i=0;
					while(fscanf(vpfichero,"%s %s",u[i].nombreUsuario ,u[i].contrasena)!=EOF){
						numUsuario++;
						i++;
					}
					printf("Hay %d usuarios registrados\n",numUsuario);
					
					//Cerramos el fichero
					fclose(aumfichero);
					
					//Pedimos los datos al usuario y comprobamos si el usuario es correcto y no es el mismo que otro
					do{
						printf("Introduzca  nombre de usuario:\n");
						fflush(stdin);
						scanf("%s",userName);
						for(i=0;i<numUsuario;i++){
							if(strcmp(userName,u[i].nombreUsuario)==0){
								copia=1;
								break;
							}else{
								copia=0;
							}
						}
						if(copia==1){
							printf("Ususario ya existente. Pruebe de nuevo\n");
							//system("PAUSE");
						}else{
							printf("Usuario valido\n");
							
							strcpy(u[numUsuario].nombreUsuario,userName);
						}
						
					}while(copia==1);
					
					printf("Introduzca contrasena:\n");
					fflush(stdin);
					scanf("%s",u[numUsuario].contrasena);
				
					for(i=0;i<=numUsuario;i++){
						printf("%s %s\n",u[i].nombreUsuario,u[i].contrasena);
					}
				
					//Se abre en modo escritura
					aumfichero= fopen("datosUsuarios.txt","w");
					
					
					//Imprimimos los datos al fichero y añadimos los datos
					for(i=0;i<=numUsuario;i++){
				
						fprintf(aumfichero,"%s\n%s\n",u[i].nombreUsuario,u[i].contrasena);
					}
					
					//Cerramos de nuevo el fichero
					fclose(aumfichero);
					system("PAUSE");
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
					
			case 'd':printf("¡Nos vemos otro dia!");
					break;
		
			default: 
					printf("Opcion incorrecta\n");
					break;
		}
	
	if(opcion=='a' || opcion=='b'){
		do{
			printf("Ya puede empezar a jugar¡Suerte!\n");
				
			printf("\n**PREGUNTA 1**\n");
			printf("¿Cuanto es 1+1?\n");
			printf("OPCION A: 1\n");
			printf("OPCION B: 4\n");
			printf("OPCION C: 2\n");
				
			printf("Tienes %d euros\n", dinero);
			do {
				printf("¿Cuanto apuestas por la opcion A?\n");
				do {
					scanf("%d", &apuesta1A);
				} while (apuesta1A % 1000 != 0);
					
				printf("¿Cuanto apuestas por la opcion B?\n");
				do {
					scanf("%d", &apuesta1B);
				} while (apuesta1B % 1000 != 0);
					
				printf("¿Cuanto apuestas por la opcion C?\n");
				do {
					scanf("%d", &apuesta1C);
				} while (apuesta1C % 1000 != 0);
			} while (apuesta1A + apuesta1B + apuesta1C != dinero);
			dinero= apuesta1C;
			printf("La opcion correcta es la C. Te quedan %d euros\n", dinero);
		}
	}
	}while(respuesta!='d');
}
