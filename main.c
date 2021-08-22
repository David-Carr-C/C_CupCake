#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
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
        printf("d) Reparacion de Aire acondicionado\ne) Reparacion de Discos de frenado\nf) Cambio de liquido de frenos\n"); //estetica, aunque asi queda -
        printf("g) Cambio de ruedas\nh) Reparacion de limpiaparabrisas\ni) Validar\n"); //bien ^
        getchar();//Si, si es importante este getchar dado a que resetea el \n de la ultima string de arriba, y las futuras \n, al ser un ciclo ->0 este tambien lee el \n del scanf de abajito //este getchar sirve?
        //fflush, tiene que estar detras del scan f
        scanf("%c",&select);
        switch (select)
        {
            case 'a':
                printf("Hola\n");
                break;

            case 'b':
                printf("Holaa\n");
                break;

            case 'c':
                printf("xxddxd\n");
                break;

            case 'd':
                printf("Holsa\n");
                break;

            case 'e':
                printf("Holsab\n");
                break;

            case 'f':
                printf("Hosla\n");
                break;

            case 'g':
                printf("Haola\n");
                break;

            case 'h':
                printf("Hosla\n");
                break;

            case 'i':
                getchar();//clean as fflush
                printf("Deseas salir de la aplicacion? (S/n): ");
                scanf("%c",&exit);
                return 0;

            default:
                printf("Seleccione una opcion correcta\n");
                // interesante... aprender goto -> goto end;
                break; //este break libera el switch y el do while
        }
        // getchar(); //no sirve este getchar, solo buguea//este getchar sirve?
        printf("Total a pagar: %.4f",contador); //El .4 es para displayear solo 4 decimales
    } while (exit!='S');
    //interesante... que es "end:"?
    return 0;
}
