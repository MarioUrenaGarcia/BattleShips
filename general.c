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
    for (int i = 0; i < 100; i += 10) // Aumenta en incrementos de 10% para simplificar
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