#include <stdio.h>
//#include <string.h>
//#include <math.h>
//#include <time.h>
#include <stdlib.h>


//Clean screen in Windows or Linux
#ifdef _WIN32
    #include <windows.h>
#endif
//Librerias arriba para usar windows, y abajo la funcion de clean screen
void limpiarPantalla()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main()
{
    char nombre[50], direccion[50], placa[20], modelo[20], anio[20], pais[20]; //Las string que ocuparemos para guardar los datos del usuario
    limpiarPantalla(); //limpiar pantalla como dice la funcion
    printf("--Bienvenido al Taller Mecanico--\n"); //Mejorar apartado de apariencia //Bienvenida
    printf("Por favor, rellene los siguientes datos\n"); //Pedir los datos del usuario
    printf("Nombre completo: ");
    fgets(nombre,50,stdin); //Se cambio gets por fgets como dice el comentario de la direccion //'tendre que cambiar esto despues
    //printf("%s",nombre); //checar si surgio algun efecto y se hizo bien la lectura de la string con espacio
    printf("Direccion: ");
    fgets(direccion,50,stdin); //Se cambio de gets() a -> fgets() con file "stdin"
    //scanf("%s",direccion); //Por si leer solo una palabra antes del espacio es buena idea en direccion
    //printf("%s",direccion); // si surgio efecto el cambio o si tiene la direccion como debe ser
    printf("*Datos del auto*\n"); //Pedir datos del auto, debere meter fgets para que se metan las strings con espacios abajo o asi esta bien?
    printf("Placa: ");
    scanf("%s",placa);
    printf("Modelo: ");
    scanf("%s",modelo);
    printf("Anio: ");
    scanf("%s",anio);
    printf("Pais de origen: ");
    scanf("%s",pais);
    limpiarPantalla();
    char select, exit; //char para leer la opcion que decidira el usuario y el char para que el usuario logre salir del bucle de menu de opciones
    float contador = 0; //Este sera el contador de los costos que el usuario ira acumulando debido a las reparaciones y opciones que el pide
    //^ Sera bueno usar float or double?
    //printf("Este cambio surgio efecto?\n");
    do
    {
        printf("Seleccione una opcion:\na) Mantenimiento Preventivo\nb) Reparacion de Motor\nc) Carga de Bateria\n");//Poner las opciones de manera -
        printf("d) Reparacion de Aire acondicionado\ne) Reparacion de Discos de frenado\nf) Cambio de Liquido de frenos\n"); //estetica, aunque asi queda -
        printf("g) Cambio de Ruedas\nh) Reparacion de Limpiaparabrisas\ni) Validar\n"); //bien ^
        getchar();//Si, si es importante este getchar dado a que resetea el \n de la ultima string de arriba, y las futuras \n, al ser un ciclo ->0 este tambien lee el \n del scanf de abajito //este getchar sirve?
        //fflush, tiene que estar detras del scan f
        scanf("%c",&select);
        switch (select)
        {
            case 'a':
                //Esto es una opcion que podria ser mostrada en el menu
                printf("El costo del \"Mantenimiento Preventivo\" es de: $1250 (pesos mexicanos)\n");
                getchar();//Si es que se salta opciones/lecturas, habra que usar esto como flush
                printf("Usted desea realizar este mantenimiento? (S/n): ");
                char askmantenimiento;
                scanf("%c",&askmantenimiento);
                if (askmantenimiento=='S') {
                    printf("Gracias por elegir este mantenimiento!\n");
                    contador = contador + 1250; //tambien se puede usar contador+=1250
                }
                else {
                    printf("No se preocupe, siga eligiendo sin problemas\n");
                }
                //este flush ya no hace falta dado al flush del inicio del do while//getchar();//flushea el scanf <-
                printf("Siga eligiendo las reparaciones o mantenimientos que va a necesitar, o de \"Validar\" para proceder con el trabajo\n");//cambiar "ticket" a algo mas
                break;

            case 'b':
                //Esto es una opcion que podria ser mostrada en el menu
                printf("El costo de la \"Reparacion de Motor\" es de: $5000 (pesos mexicanos)\n");
                getchar();//Si es que se salta opciones/lecturas, habra que usar esto como flush
                printf("Usted desea realizar esta reparacion? (S/n): ");
                char askreparacion;
                scanf("%c",&askreparacion);
                if (askreparacion=='S') {
                    printf("Gracias por elegir esta reparacion!\n");
                    contador = contador + 5000; //tambien se puede usar contador+=1250
                }
                else {
                    printf("No se preocupe, siga eligiendo sin problemas\n");
                }
                //este flush ya no hace falta dado al flush del inicio del do while//getchar();//flushea el scanf <-
                printf("Siga eligiendo las reparaciones o mantenimientos que va a necesitar, o de \"Validar\" para proceder con el trabajo\n");//cambiar "ticket" a algo mas
                break;

            case 'c':
                //Esto es una opcion que podria ser mostrada en el menu
                printf("El costo de la \"Carga de Bateria\" es de: $750.99 (pesos mexicanos)\n");
                getchar();//Si es que se salta opciones/lecturas, habra que usar esto como flush
                printf("Usted desea realizar este mantenimiento? (S/n): ");
                char askbateria;
                scanf("%c",&askbateria);
                if (askbateria=='S') {
                    printf("Gracias por elegir este mantenimiento!\n");
                    contador = contador + 750.99f; //tambien se puede usar contador+=1250
                }
                else {
                    printf("No se preocupe, siga eligiendo sin problemas\n");
                }
                //este flush ya no hace falta dado al flush del inicio del do while//getchar();//flushea el scanf <-
                printf("Siga eligiendo las reparaciones o mantenimientos que va a necesitar, o de \"Validar\" para proceder con el trabajo\n");//cambiar "ticket" a algo mas
                break;

            case 'd':
                //Esto es una opcion que podria ser mostrada en el menu
                printf("El costo de la \"Reparacion de Aire acondicionado\" es de: $500.75 (pesos mexicanos)\n");
                getchar();//Si es que se salta opciones/lecturas, habra que usar esto como flush
                printf("Usted desea realizar esta reparacion? (S/n): ");
                char askaire;
                scanf("%c",&askaire);
                if (askaire=='S') {
                    printf("Gracias por elegir esta reparacion!\n");
                    contador = contador + 500.75f; //tambien se puede usar contador+=1250
                }
                else {
                    printf("No se preocupe, siga eligiendo sin problemas\n");
                }
                //este flush ya no hace falta dado al flush del inicio del do while//getchar();//flushea el scanf <-
                printf("Siga eligiendo las reparaciones o mantenimientos que va a necesitar, o de \"Validar\" para proceder con el trabajo\n");//cambiar "ticket" a algo mas
                break;

            case 'e':
                //Esto es una opcion que podria ser mostrada en el menu
                printf("El costo de la \"Reparacion de Discos de frenado\" es de: $1050.22 (pesos mexicanos)\n");
                getchar();//Si es que se salta opciones/lecturas, habra que usar esto como flush
                printf("Usted desea realizar esta reparacion? (S/n): ");
                char askdiscos;
                scanf("%c",&askdiscos);
                if (askdiscos=='S') {
                    printf("Gracias por elegir esta reparacion!\n");
                    contador = contador + 1050.22f; //tambien se puede usar contador+=1250
                }
                else {
                    printf("No se preocupe, siga eligiendo sin problemas\n");
                }
                //este flush ya no hace falta dado al flush del inicio del do while//getchar();//flushea el scanf <-
                printf("Siga eligiendo las reparaciones o mantenimientos que va a necesitar, o de \"Validar\" para proceder con el trabajo\n");//cambiar "ticket" a algo mas
                break;

            case 'f':
                //Esto es una opcion que podria ser mostrada en el menu
                printf("El costo del \"Cambio de Liquido de frenos\" es de: $250 (pesos mexicanos)\n");
                getchar();//Si es que se salta opciones/lecturas, habra que usar esto como flush
                printf("Usted desea realizar este mantenimiento? (S/n): ");
                char askfrenos;
                scanf("%c",&askfrenos);
                if (askfrenos=='S') {
                    printf("Gracias por elegir este mantenimiento!\n");
                    contador = contador + 250; //tambien se puede usar contador+=1250
                }
                else {
                    printf("No se preocupe, siga eligiendo sin problemas\n");
                }
                //este flush ya no hace falta dado al flush del inicio del do while//getchar();//flushea el scanf <-
                printf("Siga eligiendo las reparaciones o mantenimientos que va a necesitar, o de \"Validar\" para proceder con el trabajo\n");//cambiar "ticket" a algo mas
                break;

            case 'g':
                //Esto es una opcion que podria ser mostrada en el menu
                printf("El costo del \"Cambio de Ruedas\" es de: $1780 (pesos mexicanos)\n");
                getchar();//Si es que se salta opciones/lecturas, habra que usar esto como flush
                printf("Usted desea realizar este mantenimiento? (S/n): ");
                char askruedas;
                scanf("%c",&askruedas);
                if (askruedas=='S') {
                    printf("Gracias por elegir este mantenimiento!\n");
                    contador = contador + 1780; //tambien se puede usar contador+=1250
                }
                else {
                    printf("No se preocupe, siga eligiendo sin problemas\n");
                }
                //este flush ya no hace falta dado al flush del inicio del do while//getchar();//flushea el scanf <-
                printf("Siga eligiendo las reparaciones o mantenimientos que va a necesitar, o de \"Validar\" para proceder con el trabajo\n");//cambiar "ticket" a algo mas
                break;

            case 'h':
                //Esto es una opcion que podria ser mostrada en el menu
                printf("El costo del \"Reparacion de Limpiaparabrisas\" es de: $777 (pesos mexicanos)\n");
                getchar();//Si es que se salta opciones/lecturas, habra que usar esto como flush
                printf("Usted desea realizar esta reparacion? (S/n): ");
                char askparabrisas;
                scanf("%c",&askparabrisas);
                if (askparabrisas=='S') {
                    printf("Gracias por elegir este mantenimiento!\n");
                    contador = contador + 777; //tambien se puede usar contador+=1250
                }
                else {
                    printf("No se preocupe, siga eligiendo sin problemas\n");
                }
                //este flush ya no hace falta dado al flush del inicio del do while//getchar();//flushea el scanf <-
                printf("Siga eligiendo las reparaciones o mantenimientos que va a necesitar, o de \"Validar\" para proceder con el trabajo\n");//cambiar "ticket" a algo mas
                break;

            case 'i':
                getchar();//clean as fflush
                printf("Deseas salir de la aplicacion? (S/n): ");
                scanf("%c",&exit);
                // interesante... aprender goto -> goto end;
                break; //este break solo libera el switch, lo demas no
                //return 0; esto sirve, pero no creo que sea muy buena opcion o que la quieran ver

            default:
                printf("Seleccione una opcion correcta\n");
                break;
        }
        // getchar(); //no sirve este getchar, solo buguea//este getchar sirve?
        // poner un if para evitar que se vuelva a escribir el codigo de abajito? if
        printf("Total a pagar: %.4f\n",contador); //El .4 es para displayear solo 4 decimales
    } while (exit!='S');
    //interesante... que es "end:"?
    return 0;
}
//agregar base de datos?