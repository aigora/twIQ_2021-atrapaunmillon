//ATRAPA UN MILLÓN
#include<stdio.h>
#include<string.h>
#define N 150

struct usuario{

	char nombreUsuario[200];
	char contrasena[200];
};

void imprimirPregunta (int n, char pregunta[], char respuestaA[], char respuestaB[], char respuestaC[]) {
	printf("\n**PREGUNTA %d**\n", n);
	printf("%s\n", pregunta);
	printf("OPCION A: %s \n", respuestaA);
	printf("OPCION B: %s \n", respuestaB);
	printf("OPCION C: %s \n", respuestaC);
}

struct preguntas {
	char pregunta[N];
	char respuestaA[N];
	char respuestaB[N];
	char respuestaC[N];
};

struct apuestas {
	int apuestaA;
	int apuestaB;
	int apuestaC;
};

int main(){
	char respuesta,info;
	int i, igual=0;
	char userName[200];
	char password;
	int copia=0;
	int numUsuario;
	struct usuario u[i];
	FILE * aumfichero;
	
	int dinero=1000000;
	struct apuestas apuestaPregunta1;
	struct preguntas pregunta1={"¿Que es un crotalo", "Un lagarto", "Un pajaro", "Una serpiente"};
	struct apuestas apuestaPregunta2;
	struct preguntas pregunta2={"¿Quien escribio El Principito?", "Antoine de Saint-Exupery", "Jorge-Luis Borges", "Victor Hugo"};
	struct apuestas apuestaPregunta3;
	struct preguntas pregunta3={"¿Cual era la capital del Imperio Inca?", "Lima", "Cuzco", "Macchu Picchu"};
	struct apuestas apuestaPregunta4;
	struct preguntas pregunta4={"¿Quien es el autor de La divina comedia?", "Dante", "Maquiavelo", "Petrarca"};
	struct apuestas apuestaPregunta5;
	struct preguntas pregunta5={"La columna mas a la derecha de la tabla periodica esta compuesta por:", "Haluros", "Alcalinos", "Gases nobles"};
	struct apuestas apuestaPregunta6;
	struct preguntas pregunta6={"¿Cual es la capital de Canada?", "Toronto", "Ottawa", "Vancouver"};
	struct apuestas apuestaPregunta7;
	struct preguntas pregunta7={"¿Quien era el dios romano de la guerra?", "Ares", "Marte", "Belerofonte"};
	struct apuestas apuestaPregunta8;
	struct preguntas pregunta8={"¿En que comunidad autonoma nace el rio Ebro?", "Cantabria", "Aragon", "La Rioja"};
	
	do{
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
					while(fscanf(aumfichero,"%s %s",u[i].nombreUsuario ,u[i].contrasena)!=EOF){
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
								
				}while(info!='c');
				
					break;
					
			case 'd':printf("¡Nos vemos otro dia!");
					break;
		
			default: 
					printf("Opcion incorrecta\n");
					break;
		}
	
	if(respuesta=='a' || respuesta=='b'){
		printf("Ya puede empezar a jugar¡Suerte!\n");

		// Hacemos la primera pregunta
		imprimirPregunta (1,pregunta1.pregunta, pregunta1.respuestaA, pregunta1.respuestaB, pregunta1.respuestaC);

		printf("Tienes %d euros\n", dinero);
		do {
			printf("¿Cuanto apuestas por la opcion A? (Tiene que ser divisible por 1000)\n");
			do {
				scanf("%d", &apuestaPregunta1.apuestaA);
			} while (apuestaPregunta1.apuestaA % 1000 != 0);

			printf("¿Cuanto apuestas por la opcion B? (Tiene que ser divisible por 1000)\n");
			do {
				scanf("%d", &apuestaPregunta1.apuestaB);
			} while (apuestaPregunta1.apuestaB % 1000 != 0);

			printf("¿Cuanto apuestas por la opcion C? (Tiene que ser divisible por 1000)\n");
			do {
				scanf("%d", &apuestaPregunta1.apuestaC);
			} while (apuestaPregunta1.apuestaC % 1000 != 0);
		} while (apuestaPregunta1.apuestaA + apuestaPregunta1.apuestaB + apuestaPregunta1.apuestaC != dinero);
		dinero= apuestaPregunta1.apuestaC;
		if (dinero!=0)  {
			printf("La opcion correcta es la C. Te quedan %d euros\n", dinero);

			//segunda pregunta
			imprimirPregunta (2,pregunta2.pregunta, pregunta2.respuestaA, pregunta2.respuestaB, pregunta2.respuestaC);

			printf("Tienes %d euros\n", dinero);
			do {
				printf("¿Cuanto apuestas por la opcion A? (Tiene que ser divisible por 1000)\n");
				do {
					scanf("%d", &apuestaPregunta2.apuestaA);
				} while (apuestaPregunta2.apuestaA % 1000 != 0);

				printf("¿Cuanto apuestas por la opcion B? (Tiene que ser divisible por 1000)\n");
				do {
					scanf("%d", &apuestaPregunta2.apuestaB);
				} while (apuestaPregunta2.apuestaB % 1000 != 0);

				printf("¿Cuanto apuestas por la opcion C? (Tiene que ser divisible por 1000)\n");
				do {
					scanf("%d", &apuestaPregunta2.apuestaC);
				} while (apuestaPregunta2.apuestaC % 1000 != 0);
			} while (apuestaPregunta2.apuestaA + apuestaPregunta2.apuestaB + apuestaPregunta2.apuestaC != dinero);
			dinero= apuestaPregunta2.apuestaA;
			if (dinero!=0)  {
				printf("La opcion correcta es la A. Te quedan %d euros\n", dinero);

				//tercera pregunta
				imprimirPregunta (3,pregunta3.pregunta, pregunta3.respuestaA, pregunta3.respuestaB, pregunta3.respuestaC);

				printf("Tienes %d euros\n", dinero);
				do {
					printf("¿Cuanto apuestas por la opcion A? (Tiene que ser divisible por 1000)\n");
					do {
						scanf("%d", &apuestaPregunta3.apuestaA);
					} while (apuestaPregunta3.apuestaA % 1000 != 0);

					printf("¿Cuanto apuestas por la opcion B? (Tiene que ser divisible por 1000)\n");
					do {
						scanf("%d", &apuestaPregunta3.apuestaB);
					} while (apuestaPregunta3.apuestaB % 1000 != 0);

					printf("¿Cuanto apuestas por la opcion C? (Tiene que ser divisible por 1000)\n");
					do {
						scanf("%d", &apuestaPregunta3.apuestaC);
					} while (apuestaPregunta3.apuestaC % 1000 != 0);
				} while (apuestaPregunta3.apuestaA + apuestaPregunta3.apuestaB + apuestaPregunta3.apuestaC != dinero);
				dinero= apuestaPregunta3.apuestaB;
				if (dinero!=0)  {
					printf("La opcion correcta es la B. Te quedan %d euros\n", dinero);

					//cuarta pregunta
					imprimirPregunta (4,pregunta4.pregunta, pregunta4.respuestaA, pregunta4.respuestaB, pregunta4.respuestaC);

					printf("Tienes %d euros\n", dinero);
					do {
						printf("¿Cuanto apuestas por la opcion A? (Tiene que ser divisible por 1000)\n");
						do {
							scanf("%d", &apuestaPregunta4.apuestaA);
						} while (apuestaPregunta4.apuestaA % 1000 != 0);

						printf("¿Cuanto apuestas por la opcion B? (Tiene que ser divisible por 1000)\n");
						do {
							scanf("%d", &apuestaPregunta4.apuestaB);
						} while (apuestaPregunta4.apuestaB % 1000 != 0);

						printf("¿Cuanto apuestas por la opcion C? (Tiene que ser divisible por 1000)\n");
						do {
							scanf("%d", &apuestaPregunta4.apuestaC);
						} while (apuestaPregunta4.apuestaC % 1000 != 0);
					} while (apuestaPregunta4.apuestaA + apuestaPregunta4.apuestaB + apuestaPregunta4.apuestaC != dinero);
					dinero= apuestaPregunta4.apuestaA;
					if (dinero!=0)  {
						printf("La opcion correcta es la A. Te quedan %d euros\n", dinero);

						//quinta pregunta
						imprimirPregunta (5,pregunta5.pregunta, pregunta5.respuestaA, pregunta5.respuestaB, pregunta5.respuestaC);

						printf("Tienes %d euros\n", dinero);
						do {
							printf("¿Cuanto apuestas por la opcion A? (Tiene que ser divisible por 1000)\n");
							do {
								scanf("%d", &apuestaPregunta5.apuestaA);
							} while (apuestaPregunta5.apuestaA % 1000 != 0);

							printf("¿Cuanto apuestas por la opcion B? (Tiene que ser divisible por 1000)\n");
							do {
								scanf("%d", &apuestaPregunta5.apuestaB);
							} while (apuestaPregunta5.apuestaB % 1000 != 0);

							printf("¿Cuanto apuestas por la opcion C? (Tiene que ser divisible por 1000)\n");
							do {
								scanf("%d", &apuestaPregunta5.apuestaC);
							} while (apuestaPregunta5.apuestaC % 1000 != 0);
						} while (apuestaPregunta5.apuestaA + apuestaPregunta5.apuestaB + apuestaPregunta5.apuestaC != dinero);
						dinero= apuestaPregunta5.apuestaC;
						if (dinero!=0)  {
							printf("La opcion correcta es la C. Te quedan %d euros\n", dinero);

							//sexta pregunta
							imprimirPregunta (6,pregunta6.pregunta, pregunta6.respuestaA, pregunta6.respuestaB, pregunta6.respuestaC);

							printf("Tienes %d euros\n", dinero);
							do {
								printf("¿Cuanto apuestas por la opcion A? (Tiene que ser divisible por 1000)\n");
								do {
									scanf("%d", &apuestaPregunta6.apuestaA);
								} while (apuestaPregunta6.apuestaA % 1000 != 0);

								printf("¿Cuanto apuestas por la opcion B? (Tiene que ser divisible por 1000)\n");
								do {
									scanf("%d", &apuestaPregunta6.apuestaB);
								} while (apuestaPregunta6.apuestaB % 1000 != 0);

								printf("¿Cuanto apuestas por la opcion C? (Tiene que ser divisible por 1000)\n");
								do {
									scanf("%d", &apuestaPregunta6.apuestaC);
								} while (apuestaPregunta6.apuestaC % 1000 != 0);
							} while (apuestaPregunta6.apuestaA + apuestaPregunta6.apuestaB + apuestaPregunta6.apuestaC != dinero);
							dinero= apuestaPregunta6.apuestaB;
							if (dinero!=0)  {
								printf("La opcion correcta es la B. Te quedan %d euros\n", dinero);

								//septima pregunta
								imprimirPregunta (7,pregunta7.pregunta, pregunta7.respuestaA, pregunta7.respuestaB, pregunta7.respuestaC);

								printf("Tienes %d euros\n", dinero);
								do {
									printf("¿Cuanto apuestas por la opcion A? (Tiene que ser divisible por 1000)\n");
									do {
										scanf("%d", &apuestaPregunta7.apuestaA);
									} while (apuestaPregunta7.apuestaA % 1000 != 0);

									printf("¿Cuanto apuestas por la opcion B? (Tiene que ser divisible por 1000)\n");
									do {
										scanf("%d", &apuestaPregunta7.apuestaB);
									} while (apuestaPregunta7.apuestaB % 1000 != 0);

									printf("¿Cuanto apuestas por la opcion C? (Tiene que ser divisible por 1000)\n");
									do {
										scanf("%d", &apuestaPregunta7.apuestaC);
									} while (apuestaPregunta7.apuestaC % 1000 != 0);
								} while (apuestaPregunta7.apuestaA + apuestaPregunta7.apuestaB + apuestaPregunta7.apuestaC != dinero);
								dinero= apuestaPregunta7.apuestaB;
								if (dinero!=0)  {
									printf("La opcion correcta es la B. Te quedan %d euros\n", dinero);

									//octava pregunta
									imprimirPregunta (8,pregunta8.pregunta, pregunta8.respuestaA, pregunta8.respuestaB, pregunta8.respuestaC);

									printf("Tienes %d euros\n", dinero);
									do {
										printf("¿Cuanto apuestas por la opcion A? (Tiene que ser divisible por 1000)\n");
										do {
											scanf("%d", &apuestaPregunta8.apuestaA);
										} while (apuestaPregunta8.apuestaA % 1000 != 0);

										printf("¿Cuanto apuestas por la opcion B? (Tiene que ser divisible por 1000)\n");
										do {
											scanf("%d", &apuestaPregunta8.apuestaB);
										} while (apuestaPregunta8.apuestaB % 1000 != 0);

										printf("¿Cuanto apuestas por la opcion C? (Tiene que ser divisible por 1000)\n");
										do {
											scanf("%d", &apuestaPregunta8.apuestaC);
										} while (apuestaPregunta8.apuestaC % 1000 != 0);
									} while (apuestaPregunta8.apuestaA + apuestaPregunta8.apuestaB + apuestaPregunta8.apuestaC != dinero);
									dinero= apuestaPregunta8.apuestaA;
									if (dinero!=0)  {
										printf("La opcion correcta es la A. Enhorabuena!! Ha conseguido ganar %d euros.", dinero);
									} else {
										printf("Lo sentimos pero se ha quedado sin dinero. Intentelo otra vez. Gracias.\n");
										return 0;
									}
								} else {
									printf("Lo sentimos pero se ha quedado sin dinero. Intentelo otra vez. Gracias.\n");
									return 0;
								}
							} else {
								printf("Lo sentimos pero se ha quedado sin dinero. Intentelo otra vez. Gracias.\n");
								return 0;
							}
						} else {
							printf("Lo sentimos pero se ha quedado sin dinero. Intentelo otra vez. Gracias.\n");
							return 0;
						}
					} else {
						printf("Lo sentimos pero se ha quedado sin dinero. Intentelo otra vez. Gracias.\n");
						return 0;
					}
				} else {
					printf("Lo sentimos pero se ha quedado sin dinero. Intentelo otra vez. Gracias.\n");
					return 0;
				}
			} else {
				printf("Lo sentimos pero se ha quedado sin dinero. Intentelo otra vez. Gracias.\n");
				return 0;
			}
		} else {
			printf("Lo sentimos pero se ha quedado sin dinero. Intentelo otra vez. Gracias.\n");
			return 0;
		}
	}
	}while(respuesta!='d');
}
