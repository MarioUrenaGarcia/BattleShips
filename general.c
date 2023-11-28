#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "battleship.h"

/**
 * Genera un número aleatorio para decidir qué jugador comienza.
 * @return Retorna un número entero aleatorio.
 */

int generar_numero(int limite)
{
    int semilla;
    int numero;

    srand(time(NULL));

    numero = rand() % limite;

    return numero;
}

void mostrar_barra_carga(int paso, int total)
{
    int porcentaje = (paso * 100) / total;
    printf("\rEspera, estoy pensando... [");
    for (int i = 0; i < 100; i += 5) // Aumenta en incrementos de 10% para simplificar
    {
        if (i < porcentaje)
        {
            printf(YELLOW "/" RESET); // Carácter para la barra de carga
        }
        else
        {
            printf(" "); // Espacio para la parte no completada
        }
    }
    printf("] %d%%", porcentaje);
    fflush(stdout); // Asegurarse de que se imprima inmediatamente
}

char conv_mayus(char letra)
{
    if (letra >= 97 && letra <= 122)
    {
        letra -= 32;
    }
    return letra;
}

/**
 * limpiarBuffer
 *
 * Descripción:
 *   Esta función se utiliza para limpiar el buffer de entrada del teclado.
 *   Es especialmente útil después de leer datos con scanf, ya que scanf deja
 *   el carácter de nueva línea (enter) en el buffer, lo que puede causar problemas
 *   en lecturas subsiguientes. La función lee y descarta caracteres hasta que
 *   encuentra un salto de línea (nueva línea) o el final del archivo (EOF).
 *
 * Uso:
 *   Llamar a esta función inmediatamente antes/después de leer una entrada con scanf
 *   para evitar que el carácter de nueva línea no consumido afecte a lecturas
 *   futuras.
 *
 * Ejemplo:
 *   scanf("%d", &numero);
 *   limpiarBuffer();
 */
void limpiar_buffer()
{
    int c; // Variable para almacenar temporalmente cada carácter leído

    // Ciclo que continúa hasta que se encuentra un salto de línea o EOF
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // El cuerpo del ciclo está vacío porque simplemente estamos descartando
        // los caracteres hasta llegar al final de la línea actual de entrada
    }
}
