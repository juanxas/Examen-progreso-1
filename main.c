#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//usuarios y contraseñas 
#define max_usuario 3
#define max_longitud_user 20
#define max_longitud_contra 20


int Login(){ //se ingresa la funcion login para el usuario y contraseña
    char users[max_usuario][max_longitud_user];// se elimina los usucario largos JUAN DAVID
    char passwords[max_usuario][max_longitud_contra];
    int intentos = 0;
    int i;

//SE ESTABLECEN LOS USUARIOS Y CONTRAÑAS juan david
    strcpy(users[0], "juanolas");
    strcpy(passwords[0], "salchi");
    strcpy(users[1], "steve");
    strcpy(passwords[1], "holiwis");
    strcpy(users[2], "febras");
    strcpy(passwords[2], "cafeconpan");

    while (intentos < 3){  // Bucle de intentos
        char usuario [max_longitud_user];
        char password [max_longitud_contra];
        printf("\nIngrese su Usuario: ");
        scanf("%s", usuario);
        printf("\nIngrese su Contrasena: ");
        scanf("%s", password);

        for (i=0; i < max_usuario; i++){
            if (strcmp(usuario, users[i]) == 0 && strcmp(password, passwords[i]) == 0) {
                printf("Inicio de sesion exitoso. \n");
                return 0;
            }
        }
        intentos++;
        printf("Usuario o Contrasena incorrectos. Intento #%d \n", intentos);
    }
    printf("Ingreso Denegado. Se alcanzo el numero maximo de intentos.\n");
    return 1;
}



float calcularPrecioRuta(int rutas,float km){
    float calcularRuta;
    switch (rutas)
    {
    case 1 :
        calcularRuta= km*0.10;
        break;
    case 2 :
        calcularRuta= km *0.15;
        break;
    case 3 :
        calcularRuta= km * 0.20;
        break;
    
    default:
        printf("\nOpcion invalida");
        break;
    }
    return calcularRuta;
}

void redSocial(){
    int NOTICIAS; 
    int EVENTOS;
    int PREGUNTAS;
    char mensajes[50];
    int categorias;
    for (int i = 0; i < 5; i++)
    {
        printf("mensaje %d:", i);
        printf("Ingresar el mensaje que desea insertar");
        scanf("%s",mensajes);
        printf("\n1.NOTICIAS\n");
        printf("2. EVENTOS\n");
        printf("3.PREGUNTAS\n");
        scanf("%d", &categorias);
        switch (categorias){
          
                case 1:
                    printf("Mensaje clasificado como NOTICIAS\n");
                    NOTICIAS++;
                    break;
                case 2:
                    printf("Mensaje clasificado como EVENTOS\n");
                    EVENTOS++;
                    break;
                case 3:
                    printf("Mensaje clasificado como PREGUNTAS\n");
                    PREGUNTAS++;
                    break;
                default:
                    printf("Categoría no válida\n");
        }  
    }
        

    printf("Resumen de publicaciones:\n");
    printf("Noticias: %d\n", NOTICIAS);
    printf("Eventos: %d\n", EVENTOS);
    printf("Preguntas: %d\n", PREGUNTAS);
}



float calcularDescuento(float tarifa, float km){
    float calculareldescuento;
    if (km<50){
        calculareldescuento=0;
    }else if(km>=50 && km<100){
        calculareldescuento = tarifa *0.05;
    }else if(km>=100 && km<500){
        calculareldescuento = tarifa * 0.10;
    }else if(km>500);{ 
        calculareldescuento = tarifa * 0.20;
    }
    return calculareldescuento;
}
void operacionTransporte(){
    int rutas;
    float km, tarifa;
    float descuento;
    float precioTotal;
	for(int i=1; i<=5 ; i++){
		printf ("\n1.Urbana");
        printf ("\n2.Interurbana");
        printf ("\n3.Internacional");
        printf ("\nIngrese la ruta que desea (1-3)");
        scanf ("%d", &rutas);
        printf ("\nIngrese los kilometros a recorrer");
        scanf ("%f", &km);
        tarifa=calcularPrecioRuta(rutas,km);
        descuento=calcularDescuento(tarifa,km);
        printf ("subtotales %f", tarifa );
        printf ("descuento %f", descuento);
        precioTotal=tarifa-descuento;
        printf ("precio total %f", precioTotal); 
	}
	
}
void menu(){
	int opc;
    printf("\n BIENVENIDOS A TU TRANSPORTE \n");
    do{
	
    printf("1. Operaciones de transporte\n");
    printf("2. Interactuar en la red social\n");
    printf("3. Salir\n");
    printf("\n Ingrese una opcion:");
    scanf("%d",&opc);
    switch(opc){
    	case 1:
    		operacionTransporte();
    		break;
    	case 2:
            redSocial();
    		break;
    	case 3:
    		printf("saliendo del programa");
    		break;
    	default:
            printf("Opción no válida\n");
            break;
	}
    }while(opc != 3);
}


int main() {
    // Código para el login y operaciones de transporte
    // ...
    // Si el usuario elige interactuar en la red social
    int a;
    a = Login();
    if (a==1){
    	menu();
	}
	return 0;
}

