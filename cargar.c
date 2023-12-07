#include <stdio.h>
#include <string.h>
#include "battleship.h"

// Función para guardar la partida en un archivo de texto
void guardar_partida(PLAYER jugador1, PLAYER jugador2, int tipo_partida)
{
    char nombreArchivo[256] = "save.txt";
    // Abre el archivo en modo de escritura de texto ("w")
    FILE *archivo = fopen(nombreArchivo, "w");

    // Verifica si el archivo se abrió correctamente
    if (archivo != NULL)
    {
        // Leer tipo de partida
        fprintf(archivo, "%d\n", tipo_partida);
        // DATOS DE JUGADOR 1
        //  Escribe cada campo de la estructura en una línea separada
        fprintf(archivo, "%s\n", jugador1.nombre);
        fprintf(archivo, "%d\n", jugador1.num);
        fprintf(archivo, "%d\n", jugador1.mina);
        fprintf(archivo, "%d\n", jugador1.mina_viva);
        fprintf(archivo, "%d\n", jugador1.mina_x);
        fprintf(archivo, "%d\n", jugador1.mina_y);
        fprintf(archivo, "%d\n", jugador1.mina_mapa);

        // Escribe el tablero de defensa en líneas separadas
        for (int i = 0; i < TAB_SIZE; i++)
        {
            for (int j = 0; j < TAB_SIZE; j++)
            {
                fprintf(archivo, "%d ", jugador1.tablero_defensa[i][j]);
            }
            fprintf(archivo, "\n");
        }

        // Escribe el tablero de ataque en líneas separadas
        for (int i = 0; i < TAB_SIZE; i++)
        {
            for (int j = 0; j < TAB_SIZE; j++)
            {
                fprintf(archivo, "%d ", jugador1.tablero_ataque[i][j]);
            }
            fprintf(archivo, "\n");
        }

        // DATOS DE JUGADOR 2
        //  Escribe cada campo de la estructura en una línea separada
        fprintf(archivo, "%s\n", jugador2.nombre);
        fprintf(archivo, "%d\n", jugador2.num);
        fprintf(archivo, "%d\n", jugador2.mina);
        fprintf(archivo, "%d\n", jugador2.mina_viva);
        fprintf(archivo, "%d\n", jugador2.mina_x);
        fprintf(archivo, "%d\n", jugador2.mina_y);
        fprintf(archivo, "%d\n", jugador2.mina_mapa);

        // Escribe el tablero de defensa en líneas separadas
        for (int i = 0; i < TAB_SIZE; i++)
        {
            for (int j = 0; j < TAB_SIZE; j++)
            {
                fprintf(archivo, "%d ", jugador2.tablero_defensa[i][j]);
            }
            fprintf(archivo, "\n");
        }

        // Escribe el tablero de ataque en líneas separadas
        for (int i = 0; i < TAB_SIZE; i++)
        {
            for (int j = 0; j < TAB_SIZE; j++)
            {
                fprintf(archivo, "%d ", jugador2.tablero_ataque[i][j]);
            }
            fprintf(archivo, "\n");
        }

        // Cierra el archivo después de la escritura
        fclose(archivo);
    }
    else
    {
        // Maneja el error si no se puede abrir el archivo
        perror("Error al abrir el archivo para escritura");
    }
}

// Función para cargar la partida desde un archivo de texto
void cargar_datos__partida(PLAYER *jugador1, PLAYER *jugador2, int *tipo_partida)
{
    char nombreArchivo[256] = "save.txt";
    // Abre el archivo en modo de lectura de texto ("r")
    FILE *archivo = fopen(nombreArchivo, "r");

    // Verifica si el archivo se abrió correctamente
    if (archivo != NULL)
    {
        // Lee el tipo de partida
        fscanf(archivo, "%d", &tipo_partida);

        // DATOS DE JUGADOR 1
        // Lee cada campo de la estructura desde una línea separada
        fscanf(archivo, "%s", &jugador1->nombre);
        fscanf(archivo, "%d", &jugador1->num);
        fscanf(archivo, "%d", &jugador1->mina);
        fscanf(archivo, "%d", &jugador1->mina_viva);
        fscanf(archivo, "%d", &jugador1->mina_x);
        fscanf(archivo, "%d", &jugador1->mina_y);
        fscanf(archivo, "%d", &jugador1->mina_mapa);

        // Lee el tablero de defensa desde líneas separadas
        for (int i = 0; i < TAB_SIZE; i++)
        {
            for (int j = 0; j < TAB_SIZE; j++)
            {
                fscanf(archivo, "%d", &jugador1->tablero_defensa[i][j]);
            }
        }

        // Lee el tablero de ataque desde líneas separadas
        for (int i = 0; i < TAB_SIZE; i++)
        {
            for (int j = 0; j < TAB_SIZE; j++)
            {
                fscanf(archivo, "%d", &jugador1->tablero_ataque[i][j]);
            }
        }

        // DATOS DE JUGADOR 2
        // Lee cada campo de la estructura desde una línea separada
        fscanf(archivo, "%s", &jugador2->nombre);
        fscanf(archivo, "%d", &jugador2->num);
        fscanf(archivo, "%d", &jugador2->mina);
        fscanf(archivo, "%d", &jugador2->mina_viva);
        fscanf(archivo, "%d", &jugador2->mina_x);
        fscanf(archivo, "%d", &jugador2->mina_y);
        fscanf(archivo, "%d", &jugador2->mina_mapa);

        // Lee el tablero de defensa desde líneas separadas
        for (int i = 0; i < TAB_SIZE; i++)
        {
            for (int j = 0; j < TAB_SIZE; j++)
            {
                fscanf(archivo, "%d", &jugador2->tablero_defensa[i][j]);
            }
        }
        // Cierra el archivo después de la lectura
        fclose(archivo);
    }
    else
    {
        // Maneja el error si no se puede abrir el archivo
        perror("Error al abrir el archivo para lectura");
    }
}
