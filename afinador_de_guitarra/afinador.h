#ifndef AFINADOR_H

typedef struct
{
    char *usuario;
    int cantidad_intentos;
} user;

void almacenamiento_usuarios(char *nombre);
void abrir_historial(char *numero_archivo);
int numero_usuarios (char *numero_archivo);
int comparacion_puntuacion_minima(char *nombre_archivo, int cantidad);
user datos_del_usuario (char *nombre_archivo);
char * leer();
void crear_archivo_nuevo (char *nombre_archivo, char *numero_archivo);
void consejos ();
void instrucciones ();
void notacion (int not);

#endif // AFINADOR_H
