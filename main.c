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
    char nombre[50], direccion[50], placa[20], modelo[20], anio[20], pais[20];
    limpiarPantalla();
    printf("--Bienvenido al Taller Mecanico--\n");
    printf("Por favor, rellene los siguientes datos\n");
    printf("Nombre completo: ");
    gets(nombre); //tendre que cambiar esto despues
    //printf("%s",nombre);
    printf("Direccion: ");
    gets(direccion);
    //scanf("%s",direccion);
    printf("*Datos del auto*\n");
    printf("Placa: ");
    scanf("%s",placa);
    printf("Modelo: ");
    scanf("%s",modelo);
    printf("Anio: ");
    scanf("%s",anio);
    printf("Pais de origen: ");
    scanf("%s",pais);
    limpiarPantalla();
    char select, exit;
    int contador = 0;
    do
    {
        printf("Seleccione una opcion:\na) Mantenimiento Preventivo\nb) Reparacion de Motor\nc) Carga de Bateria\n");
        printf("d) Reparacion de Aire acondicionado\ne) Reparacion de Discos de frenado\nf) Cambio de liquido de frenos\n");
        printf("g) Cambio de ruedas\nh) Reparacion de limpiaparabrisas\ni) Validar\n");
        getchar(); //fflush, tiene que estar detras del scan f
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
                break;

            default:
                printf("Seleccione una opcion correcta\n");
                break;
        }
        getchar();
        printf("Total a pagar: %i",contador);
    } while (exit!='S');
    return 0;
}
