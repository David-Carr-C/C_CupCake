#include <stdio.h>
#include <string.h>
#include <stdbool.h> //para habilitar "bool a;"
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

void signup() {
    FILE *areUNew = fopen("Count.txt","r"); //Un archivo para contar el numero de usuarios que hay se leera
    //Si este no existe, entonces entraremos a la sentencia if, para asi crear el archivo
    if (areUNew == NULL) {
        FILE *create = fopen("Count.txt","w");//Se crea el archivo, para despues dar a conocer que se creo un usuario
        printf("--Creando un nuevo usuario--\n");
        printf("Por favor, introduzca un nombre de usuario: ");//Datos del usuario
        char username[20];
        fgets(username,20,stdin);//Usando la mejor forma de obtener una string
        printf("Introduzca su contraseña: ");
        char password[20];//Lo bueno de usar una funcion para el login es que despues la variable se va a destruir
        fgets(password,20,stdin);//Espero que esto sea muy safe

        FILE *data = fopen("Data.txt","a+");//Se crea un pointer para crear el archivo y meter los datos del usuario
        fprintf(data,"%s%s\n",username,password);//Se graban en el archivo los datos
        //Vamos a combinar las contraseñas, para que asi no pueda confundirse el nombre-contraseña de alguien mas
        //para que no le pueda acertar a la contraseña de alguien mas y loggearse
        printf("Registro Completado!, vuelva a abrir el programa\n");
        //El registro ha sido completado, se procede a cerrar los files
        fprintf(create,"%d",1);//Y se añade a 1 el file contador para saber que minimo hay 1 usuario registrado ya
        fclose(data);
        fclose(create);
        //fclose(areUNew); <- El archivo no abrio, asi que no se puede cerrar
        exit(0);//Podemos seguir con el programa, el que no se lea un archivo no quiere decir que sea un error
                        // INCLUSO! COMO ES DENTRO DE UNA FUNCION LOS PUNTEROS Y DATOS SE ELIMINARAN
        //Pero es mejor salir del programa, por si acaso tener un puntero = NULL causa algo...
    }
    fclose(areUNew);//Casi lo olvido!, si el archivo existe este ya se tiene que cerrar!
}

void createUser() {

}

void login() {
    char name[20], userPass[20]; //datos desde usuario
    char username[20], password[20]; //Datos desde files
    FILE *login = fopen("Data.txt", "r");//Podemos poner la apertura del file fuera del while para
            //Que no se este abriendo cada vez que se falla el login
    fscanf(login, "%s\n%s", username, password);//Obtener los datos

    int fail = 0;//Numero de fallas soportadas
    do {
        //char name[20], userPass[20]; <- No se puede usar en las operaciones booleanas del while
        printf("Nombre de usuario: ");
        fgets(name, 20, stdin);
        printf("Contraseña: ");
        fgets(userPass, 20, stdin);
        for (int  i = 0;  i <20 ; ++ i) { //Limpiar el fgets... dado a que tambien absorbe el '\n'
            if (userPass[i]=='\n') { //La string adquiere el \n asi que hay que vaciarselo
                userPass[i] = '\0';
            }

            if (userPass[i]=='\n') { //fgets no es la mejor idea?
                name[i] = '\0';
            }
        }
        //FILE *login = fopen("Data.txt", "r"); <- no quiero que se este declarando cada vez
        //char username[20], password[20]; <- No se puede usar en las operaciones booleanas del while
        //fscanf(login, "%s\n%s", username, password); <- muy interesante pero no hace falta que este leyendolo en cada vuelta



        if (fail>=3) { //Si se equivoca bastantes veces, el programa le pedira registrarse
            createUser();//Continuar...
        }
        fail++;

    } while (  ((strcmp(name,username))!=0)  &&  ((strcmp(password,userPass))!=0)  ); //Cuidado con el scope
    fclose(login);
}

void resumen(bool a,bool b,bool c,bool d,bool e,bool f,bool g,bool h, float contador) {
    printf("Usted ha elegido: \n");//Usar los booleanos para displayear las opciones que ha elegido, y tal vez escribir esto en files
    if (a==true) {
        printf("Mantenimiento Preventivo\n");
    }
    if (b==true) {
        printf("Reparacion de Motor\n");
    }
    if (c==true) {
        printf("Carga de Bateria\n");
    }
    if (d==true) {
        printf("Reparacion de Aire acondicionado\n");
    }
    if (e==true) {
        printf("Reparacion de Discos de frenado\n");
    }
    if (f==true) {
        printf("Cambio de Liquido de frenos\n");
    }
    if (g==true) {
        printf("Cambio de Ruedas\n");
    }
    if (h==true) {
        printf("Reparacion de Limpiaparabrisas\n");
    }
    //si tu le diste SI que te muestre el total a pagar, si tu pusiste NO, que no te lo muestre
    printf("Total a pagar: %.2f",contador);
}

int main()
{
    signup();
    login();
    char nombre[50], direccion[50], placa[20], modelo[20], anio[20], pais[20]; //Las string que ocuparemos para guardar los datos del usuario
    char trabajo[2]; //string para la validacion y saber si se procede el trabajo
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
    bool a = false, b = false, c = false, d = false, e = false, f = false, g = false, h = false; //booleanos para saber si la reparacion ha sido tomada o no
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
                if (a!=true) {
                    //Esto es una opcion que podria ser mostrada en el menu
                    printf("El costo del \"Mantenimiento Preventivo\" es de: $1250 (pesos mexicanos)\n");
                    getchar();//Si es que se salta opciones/lecturas, habra que usar esto como flush
                    printf("Usted desea realizar este mantenimiento? (S/n): ");
                    char askmantenimiento;
                    scanf("%c",&askmantenimiento);
                    if (askmantenimiento=='S') {
                        printf("Gracias por elegir este mantenimiento!\n");
                        a = true;
                        contador = contador + 1250; //tambien se puede usar contador+=1250
                    }
                    else {
                        printf("No se preocupe, siga eligiendo sin problemas\n");
                    }
                    //este flush ya no hace falta dado al flush del inicio del do while//getchar();//flushea el scanf <-
                    printf("Siga eligiendo las reparaciones o mantenimientos que va a necesitar, o de \"Validar\" para proceder con el trabajo\n");//cambiar "ticket" a algo mas
                }
                else {
                    printf("Usted ya ha elegido esta opcion\n");
                }
                break;

            case 'b':
                if (b!=true) {
                    //Esto es una opcion que podria ser mostrada en el menu
                    printf("El costo de la \"Reparacion de Motor\" es de: $5000 (pesos mexicanos)\n");
                    getchar();//Si es que se salta opciones/lecturas, habra que usar esto como flush
                    printf("Usted desea realizar esta reparacion? (S/n): ");
                    char askreparacion;
                    scanf("%c",&askreparacion);
                    if (askreparacion=='S') {
                        printf("Gracias por elegir esta reparacion!\n");
                        b = true;
                        contador = contador + 5000; //tambien se puede usar contador+=1250
                    }
                    else {
                        printf("No se preocupe, siga eligiendo sin problemas\n");
                    }
                    //este flush ya no hace falta dado al flush del inicio del do while//getchar();//flushea el scanf <-
                    printf("Siga eligiendo las reparaciones o mantenimientos que va a necesitar, o de \"Validar\" para proceder con el trabajo\n");//cambiar "ticket" a algo mas
                }
                else {
                    printf("Usted ya ha elegido esta opcion\n");
                }
                break;

            case 'c':
                if (c!=true) {
                    //Esto es una opcion que podria ser mostrada en el menu
                    printf("El costo de la \"Carga de Bateria\" es de: $750.99 (pesos mexicanos)\n");
                    getchar();//Si es que se salta opciones/lecturas, habra que usar esto como flush
                    printf("Usted desea realizar este mantenimiento? (S/n): ");
                    char askbateria;
                    scanf("%c",&askbateria);
                    if (askbateria=='S') {
                        printf("Gracias por elegir este mantenimiento!\n");
                        c = true;
                        contador = contador + 750.99f; //tambien se puede usar contador+=1250
                    }
                    else {
                        printf("No se preocupe, siga eligiendo sin problemas\n");
                    }
                    //este flush ya no hace falta dado al flush del inicio del do while//getchar();//flushea el scanf <-
                    printf("Siga eligiendo las reparaciones o mantenimientos que va a necesitar, o de \"Validar\" para proceder con el trabajo\n");//cambiar "ticket" a algo mas
                }
                else {
                    printf("Usted ya ha elegido esta opcion\n");
                }

                break;

            case 'd':
                if (d!=true) {
                    //Esto es una opcion que podria ser mostrada en el menu
                    printf("El costo de la \"Reparacion de Aire acondicionado\" es de: $500.75 (pesos mexicanos)\n");
                    getchar();//Si es que se salta opciones/lecturas, habra que usar esto como flush
                    printf("Usted desea realizar esta reparacion? (S/n): ");
                    char askaire;
                    scanf("%c",&askaire);
                    if (askaire=='S') {
                        printf("Gracias por elegir esta reparacion!\n");
                        d = true;
                        contador = contador + 500.75f; //tambien se puede usar contador+=1250
                    }
                    else {
                        printf("No se preocupe, siga eligiendo sin problemas\n");
                    }
                    //este flush ya no hace falta dado al flush del inicio del do while//getchar();//flushea el scanf <-
                    printf("Siga eligiendo las reparaciones o mantenimientos que va a necesitar, o de \"Validar\" para proceder con el trabajo\n");//cambiar "ticket" a algo mas
                }
                else {
                    printf("Usted ya ha elegido esta opcion\n");
                }
                break;

            case 'e':
                if (e!=true) {
                    //Esto es una opcion que podria ser mostrada en el menu
                    printf("El costo de la \"Reparacion de Discos de frenado\" es de: $1050.22 (pesos mexicanos)\n");
                    getchar();//Si es que se salta opciones/lecturas, habra que usar esto como flush
                    printf("Usted desea realizar esta reparacion? (S/n): ");
                    char askdiscos;
                    scanf("%c",&askdiscos);
                    if (askdiscos=='S') {
                        printf("Gracias por elegir esta reparacion!\n");
                        e = true;
                        contador = contador + 1050.22f; //tambien se puede usar contador+=1250
                    }
                    else {
                        printf("No se preocupe, siga eligiendo sin problemas\n");
                    }
                    //este flush ya no hace falta dado al flush del inicio del do while//getchar();//flushea el scanf <-
                    printf("Siga eligiendo las reparaciones o mantenimientos que va a necesitar, o de \"Validar\" para proceder con el trabajo\n");//cambiar "ticket" a algo mas
                }
                else {
                    printf("Usted ya ha elegido esta opcion\n");
                }
                break;

            case 'f':
                if (f!=true) {
                    //Esto es una opcion que podria ser mostrada en el menu
                    printf("El costo del \"Cambio de Liquido de frenos\" es de: $250 (pesos mexicanos)\n");
                    getchar();//Si es que se salta opciones/lecturas, habra que usar esto como flush
                    printf("Usted desea realizar este mantenimiento? (S/n): ");
                    char askfrenos;
                    scanf("%c",&askfrenos);
                    if (askfrenos=='S') {
                        printf("Gracias por elegir este mantenimiento!\n");
                        f = true;
                        contador = contador + 250; //tambien se puede usar contador+=1250
                    }
                    else {
                        printf("No se preocupe, siga eligiendo sin problemas\n");
                    }
                    //este flush ya no hace falta dado al flush del inicio del do while//getchar();//flushea el scanf <-
                    printf("Siga eligiendo las reparaciones o mantenimientos que va a necesitar, o de \"Validar\" para proceder con el trabajo\n");//cambiar "ticket" a algo mas
                }
                else {
                    printf("Usted ya ha elegido esta opcion\n");
                }
                break;

            case 'g':
                if (g!=true) {
                    //Esto es una opcion que podria ser mostrada en el menu
                    printf("El costo del \"Cambio de Ruedas\" es de: $1780 (pesos mexicanos)\n");
                    getchar();//Si es que se salta opciones/lecturas, habra que usar esto como flush
                    printf("Usted desea realizar este mantenimiento? (S/n): ");
                    char askruedas;
                    scanf("%c",&askruedas);
                    if (askruedas=='S') {
                        printf("Gracias por elegir este mantenimiento!\n");
                        g = true;
                        contador = contador + 1780; //tambien se puede usar contador+=1250
                    }
                    else {
                        printf("No se preocupe, siga eligiendo sin problemas\n");
                    }
                    //este flush ya no hace falta dado al flush del inicio del do while//getchar();//flushea el scanf <-
                    printf("Siga eligiendo las reparaciones o mantenimientos que va a necesitar, o de \"Validar\" para proceder con el trabajo\n");//cambiar "ticket" a algo mas
                }
                else {
                    printf("Usted ya ha elegido esta opcion\n");
                }
                break;

            case 'h':
                if (h!=true) {
                    //Esto es una opcion que podria ser mostrada en el menu
                    printf("El costo del \"Reparacion de Limpiaparabrisas\" es de: $777 (pesos mexicanos)\n");
                    getchar();//Si es que se salta opciones/lecturas, habra que usar esto como flush
                    printf("Usted desea realizar esta reparacion? (S/n): ");
                    char askparabrisas;
                    scanf("%c",&askparabrisas);
                    if (askparabrisas=='S') {
                        printf("Gracias por elegir este mantenimiento!\n");
                        h = true;
                        contador = contador + 777; //tambien se puede usar contador+=1250
                    }
                    else {
                        printf("No se preocupe, siga eligiendo sin problemas\n");
                    }
                    //este flush ya no hace falta dado al flush del inicio del do while//getchar();//flushea el scanf <-
                    printf("Siga eligiendo las reparaciones o mantenimientos que va a necesitar, o de \"Validar\" para proceder con el trabajo\n");//cambiar "ticket" a algo mas
                }
                else {
                    printf("Usted ya ha elegido esta opcion\n");
                }
                break;

            case 'i':
                getchar();//clean as fflush
                printf("Se procede con el trabajo? (SI/NO): "); //printf("Deseas salir de la aplicacion? (S/n): ");
                scanf("%s",trabajo); //cargara una string dado a que el profe menciono "SI" or "NO"
                if ((strcmp(trabajo,"SI"))==0) {
                    printf("Creando ticket...\n");
                    exit = 'S';
                }
                else if ((strcmp(trabajo,"NO"))==0){
                    printf("Resumen: Cargando...\n");
                    exit = 'S';
                }
                else {
                    printf("Elija una opcion correcta\n");
                    exit = 'n';
                }
                //scanf("%c",&exit);
                // interesante... aprender goto -> goto end;
                break; //este break solo libera el switch, lo demas no
                //return 0; esto sirve, pero no creo que sea muy buena opcion o que la quieran ver

            default:
                printf("Seleccione una opcion correcta\n");
                break;
        }
        // getchar(); //no sirve este getchar, solo buguea//este getchar sirve?
        // poner un if para evitar que se vuelva a escribir el codigo de abajito? if
        if (exit!='S') {
            printf("Total a pagar: %.2f\n",contador); //El .2 displayear solo 2 decimales //El .4 es para displayear solo 4 decimales
        }
    } while (exit!='S');
    //interesante... que es "end:"?
    if ((strcmp(trabajo,"SI"))==0) { //Conecta con el case 'i'
        printf("Creando ticket...\n");
        resumen(a,b,c,d,e,f,g,h,contador);
        //ADSASDASDSADSADADASDASDSADSAD
    }
    else if ((strcmp(trabajo,"NO"))==0){ //Conecta con el case 'i'
        printf("Resumen: Cargando...\n");
        resumen(a,b,c,d,e,f,g,h,contador);
        printf("Vuelva pronto!\n");
    }


    return 0;
}
//agregar base de datos?