#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "afinador.h"

void notacion (int not)
{
    if (not==1)
    {
        printf("\n1- Mi.\n");
        printf("\n2- La.\n");
        printf("\n3- Re.\n");
        printf("\n4- Sol.\n");
        printf("\n5- Si.\n");
        printf("\n6- Mi.\n");

        printf("\n\n7- Consejos de afinaci%cn.",162);
        printf("\n8- Salir.\n");
    }
    else if (not==2)
    {
        printf("\n1- E.\n");
        printf("\n2- A.\n");
        printf("\n3- D.\n");
        printf("\n4- G.\n");
        printf("\n5- B.\n");
        printf("\n6- E.\n");

        printf("\n\n7- Consejos de afinaci%cn.",162);
        printf("\n8- Salir.\n");
    }
}

void instrucciones ()
{
    printf("\n\nInstrucciones:\n");
    printf("1- Inserte su nombre para poder ingresar al afinador.\n");
    printf("2- Inserte el valor de la cuerda a evaluar para reproducir\n");
    printf("   el sonido al que la cuerda debe llegar.\n");
    printf("3- Afine la guitarra comparando los sonidos del programa con\n");
    printf("   los de su guitarra.\n");
    printf("4- Por cada reproducci%cn de sonido, el programa aumentar%c la\n",162,160);
    printf("   cantidad de intentos con los que se est%c afinando la guitarra.\n",160);
    printf("5- El programa guardar%c la cantidad de intentos m%cnima por usuario.\n",160,161);
    printf("   Esto estimular%c al usuario a querer afinarla cada vez con menos\n",160);
    printf("   intentos.\n");
}

void consejos ()
{
    printf("\nConsejo de afinaci%cn:\n\n",162);
    printf("1- Verifique que la 1ra cuerda afinada y al aire suene como la\n");
    printf("   3ra cuerda en el quinto traste.\n");
    printf("2- Verifique que la 2da cuerda al aire suene como la 3ra cuerda.\n");
    printf("   en el 4to traste.\n");
    printf("3- Verifique que la 3ra cuerda al aire suene como la 4ta cuerda.\n");
    printf("   en el 5to traste.\n");
    printf("4- Verifique que la 4ta cuerda al aire suene como la 5ta cuerda.\n");
    printf("   en el 5to traste.\n");
    printf("5- Verifique que la 5ta cuerda al aire suene como la 6ta cuerda.\n");
    printf("   en el 5to traste.\n\n");
}

void crear_archivo_nuevo (char *nombre_archivo, char *numero_archivo)
{
    int i=(strlen(nombre_archivo))-5;
    char j,*nombre;
    FILE *usuario,*numero;
    numero=fopen(numero_archivo,"r+");
    j=fgetc(numero);
    j++;
    rewind(numero);
    fputc(j,numero);
    fclose(numero);
    nombre_archivo[i]=j;
    usuario=fopen(nombre_archivo,"w");
    printf("Introduzca su nombre: ");
    nombre=leer();
    almacenamiento_usuarios(nombre);
    fprintf(usuario,nombre);
    fprintf(usuario,"-");
    fprintf(usuario,"100");
    fprintf(usuario,"\n");

    fclose(usuario);
}

char * leer()
{
    char c, *prt;
    int i=0;
    prt = (char *) malloc(1 * sizeof(char));
    *prt = '\0';
    while ((c=getch())!='\r')
    {
        prt = (char *) realloc(prt, (i + 2) * sizeof(char));
        prt[i++] = c;
        putchar(c);
        prt[i] = '\0';
    }
    return prt;
}

user datos_del_usuario (char *nombre_archivo)
{
    user estructura;
    FILE *archivo_de_datos;
    char *cant_min_de_intentos=(char*)malloc(20*sizeof(char));
    char *nom_usuario=(char*)malloc(20*sizeof(char));
    archivo_de_datos=fopen(nombre_archivo,"r");
    int i=0;
    char *c;
    while((c=fgetc(archivo_de_datos))!='-')
        nom_usuario[i++]=c;
    nom_usuario[i]='\0';
    estructura.usuario=(char*)malloc(20*sizeof(char));
    strcpy(estructura.usuario,nom_usuario);
    fgets(cant_min_de_intentos,20,archivo_de_datos);
    estructura.cantidad_intentos=atoi(cant_min_de_intentos);
    free(nom_usuario);
    free(cant_min_de_intentos);
    free(estructura.usuario);
    fclose(archivo_de_datos);
    return estructura;
}

int comparacion_puntuacion_minima(char *nombre_archivo, int cantidad)
{
    FILE *archivo;
    archivo=fopen(nombre_archivo,"r+");
    if (archivo==NULL)
    {
        printf("No se ha podido abrir.");
        exit(1);
    }

    int i,l=0,cont=0;
    char inten[10],min[10],aux;
    aux='0';
    for (i=0; aux!='-'; i++)
    {
        aux=fgetc(archivo);
        if (aux!='-')
        {
            continue;
        }
    }
    cont=i;
    i=0;
    while(((aux=fgetc(archivo))!='\n'))
    {
        inten[i]=aux;
        i++;
    }
    int k=strlen(inten);
    int intentos=atoi(inten);

    if (cantidad<intentos)
    {
        for(l=0; l<k; l++)
        {
            fseek(archivo,cont+l,SEEK_SET);
            fputc('\0',archivo);
        }

        fseek(archivo,-l,SEEK_CUR);
        itoa(cantidad,min,10);
        fputs(min,archivo);
        fputc('\n',archivo);

    }
    fclose(archivo);
    if (cantidad<intentos)
        return cantidad;
    return 0;
}

int numero_usuarios (char *numero_archivo)
{
    FILE *cantidad,*personas;
    char usuarios[2];
    cantidad=fopen(numero_archivo,"r");
    personas=fopen("C:\\Users\\Dhayanna\\Desktop\\afinador_de_guitarra\\Usuarios\\Nombres_de_usuario.txt","r");
    fgets(usuarios,2,cantidad);
    int num_us=atoi(usuarios);
    fclose(cantidad);
    return num_us;
}

void abrir_historial(char *numero_archivo)
{

    FILE *cantidad,*personas;
    int j;
    char usuarios[2];
    cantidad=fopen(numero_archivo,"r");
    personas=fopen("C:\\Users\\Dhayanna\\Desktop\\afinador_de_guitarra\\Usuarios\\Nombres_de_usuario.txt","r");
    fgets(usuarios,2,cantidad);
    int us=atoi(usuarios);
    for(j=1; j<=us; j++)
    {
        char buffer[15];
        fgets(buffer,15,personas);
        printf("%d- %s",j,buffer);
    }
}

void almacenamiento_usuarios(char *nombre)
{
    FILE *nombres;
    nombres=fopen("C:\\Users\\Dhayanna\\Desktop\\afinador_de_guitarra\\Usuarios\\Nombres_de_usuario.txt","a+");
    fputs(nombre,nombres);
    fputc('\n',nombres);
    fclose(nombres);
}
