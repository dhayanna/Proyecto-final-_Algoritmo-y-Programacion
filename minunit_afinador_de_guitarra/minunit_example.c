#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../afinador_de_guitarra/afinador.h"
#include "minunit.h"

user prueba1=datos_del_usuario("C:\\Users\\Dhayanna\\Desktop\\afinador_de_guitarra\\Usuarios\\Usuario1.txt");
user prueba2=datos_del_usuario("C:\\Users\\Dhayanna\\Desktop\\afinador_de_guitarra\\Usuarios\\Usuario2.txt");
user prueba3=datos_del_usuario("C:\\Users\\Dhayanna\\Desktop\\afinador_de_guitarra\\Usuarios\\Usuario3.txt");

MU_TEST(test_assert_int_eq) {
    mu_assert_int_eq(3, numero_usuarios("C:\\Users\\Dhayanna\\Desktop\\afinador_de_guitarra\\Usuarios\\Numero_usuario.txt"));
    mu_assert_int_eq(0, comparacion_puntuacion_minima("C:\\Users\\Dhayanna\\Desktop\\afinador_de_guitarra\\Usuarios\\Usuario1.txt", 18));
    mu_assert_int_eq(9, comparacion_puntuacion_minima("C:\\Users\\Dhayanna\\Desktop\\afinador_de_guitarra\\Usuarios\\Usuario1.txt", 9));
    mu_assert_int_eq(0, comparacion_puntuacion_minima("C:\\Users\\Dhayanna\\Desktop\\afinador_de_guitarra\\Usuarios\\Usuario2.txt", 15));
    mu_assert_int_eq(7, comparacion_puntuacion_minima("C:\\Users\\Dhayanna\\Desktop\\afinador_de_guitarra\\Usuarios\\Usuario2.txt", 7));
    mu_assert_int_eq(0, comparacion_puntuacion_minima("C:\\Users\\Dhayanna\\Desktop\\afinador_de_guitarra\\Usuarios\\Usuario3.txt", 6));
    mu_assert_int_eq(3, comparacion_puntuacion_minima("C:\\Users\\Dhayanna\\Desktop\\afinador_de_guitarra\\Usuarios\\Usuario3.txt", 3));
    mu_assert_int_eq(18, prueba1.cantidad_intentos);
    mu_assert_int_eq(12, prueba2.cantidad_intentos);
    mu_assert_int_eq(6, prueba3.cantidad_intentos);
}

MU_TEST_SUITE(test_suite) {
	//MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(test_assert_int_eq);

}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}

