#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "afinador.h"

int main()
{
    char *numero_archivo="C:\\Users\\Dhayanna\\Desktop\\afinador_de_guitarra\\Usuarios\\Numero_usuario.txt";
    char c, nombre_archivo[]= {'C',':','\\','U','s','e','r','s','\\','D','h','a','y','a','n','n','a','\\','D','e','s','k','t','o','p','\\','a','f','i','n','a','d','o','r','_','d','e','_','g','u','i','t','a','r','r','a','\\','U','s','u','a','r','i','o','s','\\','U','s','u','a','r','i','o','1','.','t','x','t','\0'};
    int cond, cond2, cond3, not, cuerda,cont=0, vox;
    char *nombre_archivo2;
    user persona;
    SAMPLE *cuerda1,*cuerda2,*cuerda3,*cuerda4,*cuerda5,*cuerda6;

    cuerda1 = load_wav("C:\\Users\\Dhayanna\\Desktop\\afinador_de_guitarra\\Cuerdas\\1ra_cuerda.wav");
    cuerda2 = load_wav("C:\\Users\\Dhayanna\\Desktop\\afinador_de_guitarra\\Cuerdas\\2da_cuerda.wav");
    cuerda3 = load_wav("C:\\Users\\Dhayanna\\Desktop\\afinador_de_guitarra\\Cuerdas\\3ra_cuerda.wav");
    cuerda4 = load_wav("C:\\Users\\Dhayanna\\Desktop\\afinador_de_guitarra\\Cuerdas\\4ta_cuerda.wav");
    cuerda5 = load_wav("C:\\Users\\Dhayanna\\Desktop\\afinador_de_guitarra\\Cuerdas\\5ta_cuerda.wav");
    cuerda6 = load_wav("C:\\Users\\Dhayanna\\Desktop\\afinador_de_guitarra\\Cuerdas\\6ta_cuerda.wav");


    SAMPLE *audio;

    // Inicializa la librería de Allegro  "liballeg.so.4.4.2"  :
    if (install_allegro(SYSTEM_AUTODETECT, NULL, NULL)!= 0)
    {
        allegro_exit();
        printf("Error: no se puede inicializar la librería ''allegro' !");
        exit(-1);
    }

    // Instala el modulo de sonido:
    if (install_sound(DIGI_AUTODETECT, MIDI_NONE, NULL)!= 0)
    {
        allegro_exit();
        printf("Error: imposible la instalación del módulo de sonido !");
        exit(-1);
    }

    printf("                        \\\\~ Afinador de guitarra ~//\n\n");
    printf("                    %cDesea leer las instrucciones de uso?\n",168);
    printf("                            1- S%c, deseo leerlas.\n",161);
    printf("                        2- No, prosiga con el programa.\n\n");
    printf("                    Inserte el n%cmero de su respuesta: ",163);

    do
    {
        scanf("%d",&cond);
        if (cond==1)
        {
            instrucciones();
        }
        else if (cond!=2&&cond!=1)
        {
            printf("\n                     Elija una opci%cn v%clida (1 o 2): ",162,160);
        }
    }
    while(cond!=2&&cond!=1);

    printf("\n                        Pulse \"Enter\" para continuar.\n");
    c=getchar();
    system("pause");
    system("cls");


    printf("1- Nuevo usuario.");
    printf("\n2- Usuario registrado.\n");
    scanf("%d",&cond2);
    if(cond2==1)
    {
        char *n=(char*)malloc(sizeof(char));
        crear_archivo_nuevo(nombre_archivo, numero_archivo);
        int m=numero_usuarios(numero_archivo);
        itoa(m,n,10);
        int q=(strlen(nombre_archivo))-5;
        nombre_archivo[q]=*n;
        nombre_archivo2=nombre_archivo;
    }
    else if((cond2==2)&&(numero_usuarios(numero_archivo)!=0))
    {
        system("cls");
        abrir_historial(numero_archivo);
        int m=numero_usuarios(numero_archivo);
        do
        {
            printf("\n\nElija su usuario: ");
            scanf("%d",&cond3);
            if(cond3>m||cond3<0) printf("\nSeleccione un valor v%clido.",160);
        }
        while(cond3>m||cond3<0);
        switch(cond3)
        {
        case 1:
            nombre_archivo[(strlen(nombre_archivo))-5]='1';
            nombre_archivo2=nombre_archivo;
            break;
        case 2:
            nombre_archivo[(strlen(nombre_archivo))-5]='2';
            nombre_archivo2=nombre_archivo;
            break;
        case 3:
            nombre_archivo[(strlen(nombre_archivo))-5]='3';
            nombre_archivo2=nombre_archivo;
            break;
        case 4:
            nombre_archivo[(strlen(nombre_archivo))-5]='4';
            nombre_archivo2=nombre_archivo;
            break;
        case 5:
            nombre_archivo[(strlen(nombre_archivo))-5]='5';
            nombre_archivo2=nombre_archivo;
            break;
        case 6:
            nombre_archivo[(strlen(nombre_archivo))-5]='6';
            nombre_archivo2=nombre_archivo;
            break;
        case 7:
            nombre_archivo[(strlen(nombre_archivo))-5]='7';
            nombre_archivo2=nombre_archivo;
            break;
        case 8:
            nombre_archivo[(strlen(nombre_archivo))-5]='8';
            nombre_archivo2=nombre_archivo;
            break;
        case 9:
            nombre_archivo[(strlen(nombre_archivo))-5]='9';
            nombre_archivo2=nombre_archivo;
            break;
        }
    }
    persona=datos_del_usuario(nombre_archivo2);

    system("cls");
    printf("%cBienvenido, %s! La cantidad de intentos m%cnima que ha hecho es de %d\n\n",173,persona.usuario,161,persona.cantidad_intentos);
    printf("                %cQu%c tipo de notaci%cn musical prefiere leer?\n",168,130,162);
    printf("                    1- Notaci%cn normal (Do, Re, Mi...).\n",162);
    printf("                    2- Notaci%cn anglosajona (C, D, E...).\n",162);

    do
    {
        scanf("%d",&not);
        if (not!=1&&not!=2)
        {
            printf("\n                  Escoja una opci%n v%lida (1 o 2)",162,160);
        }
    }
    while(not!=1&&not!=2);
    system("cls");


    while(cuerda!=8)
    {
        notacion(not);
        printf("\n\nDigite el n%cmero de la cuerda a evaluar: ",163);
        scanf("%d",&cuerda);
        switch(cuerda)
        {
        case 1:
            vox = play_sample(cuerda1, 255, 128, 1000, 0);
            cont++;
            system("cls");
            break;
        case 2:
            vox = play_sample(cuerda2, 255, 128, 1000, 0);
            cont++;
            system("cls");
            break;
        case 3:
            vox = play_sample(cuerda3, 255, 128, 1000, 0);
            cont++;
            system("cls");
            break;
        case 4:
            vox = play_sample(cuerda4, 255, 128, 1000, 0);
            cont++;
            system("cls");
            break;
        case 5:
            vox = play_sample(cuerda5, 255, 128, 1000, 0);
            cont++;
            system("cls");
            break;
        case 6:
            vox = play_sample(cuerda6, 255, 128, 1000, 0);
            cont++;
            system("cls");
            break;
        case 7:
            system("cls");
            consejos();
            system("pause");
            system("cls");
            break;
        case 8:
            system("cls");
            int o= comparacion_puntuacion_minima(nombre_archivo2, cont);
            if (o!=0)
            {
                printf("\n\n\n\n\n\n\n\n\n\n\n\n          %cFelicidades! Su cantidad m%cnima de intentos ahora es de %d.\n\n\n\n\n\n\n\n\n\n\n\n",173,161,o);
            }
            else
            {
                printf("\n\n\n\n\n\n\n\n\n\n\n\n                     %cMuy buen intento! %cHora de tocar!\n\n\n\n\n\n\n\n\n\n\n\n",173,173);
            }
            break;
        default:
            system("cls");
            break;
        }
    }

    destroy_sample(cuerda1);
    destroy_sample(cuerda2);
    destroy_sample(cuerda3);
    destroy_sample(cuerda4);
    destroy_sample(cuerda5);
    destroy_sample(cuerda6);
    remove_sound();

    return 0;
}
END_OF_MAIN();
