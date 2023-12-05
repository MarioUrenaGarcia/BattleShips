
#include <stdio.h>
#include <string.h>

#define TAB_SIZE 10

typedef struct {
    char nombre[264];
    int tablero_defensa[TAB_SIZE][TAB_SIZE];
    int tablero_ataque[TAB_SIZE][TAB_SIZE];
    int num;
    int mina;
    int mina_viva;
    int mina_x;
    int mina_y;
    int mina_mapa;
    int barcos_restantes;
} PLAYER;

// Función para guardar la partida en un archivo de texto
void guardar_partida(char* nombreArchivo, PLAYER* jugador) {
    // Abre el archivo en modo de escritura de texto ("w")
    FILE* archivo = fopen(nombreArchivo, "w");

    // Verifica si el archivo se abrió correctamente
    if (archivo != NULL) {
        // Escribe cada campo de la estructura en una línea separada
        fprintf(archivo, "%s\n", jugador->nombre);
        fprintf(archivo, "%d\n", jugador->num);
        fprintf(archivo, "%d\n", jugador->mina);
        fprintf(archivo, "%d\n", jugador->mina_viva);
        fprintf(archivo, "%d\n", jugador->mina_x);
        fprintf(archivo, "%d\n", jugador->mina_y);
        fprintf(archivo, "%d\n", jugador->mina_mapa);
        fprintf(archivo, "%d\n", jugador->barcos_restantes);

        // Escribe el tablero de defensa en líneas separadas
        for (int i = 0; i < TAB_SIZE; i++) {
            for (int j = 0; j < TAB_SIZE; j++) {
                fprintf(archivo, "%d ", jugador->tablero_defensa[i][j]);
            }
            fprintf(archivo, "\n");
        }

        // Escribe el tablero de ataque en líneas separadas
        for (int i = 0; i < TAB_SIZE; i++) {
            for (int j = 0; j < TAB_SIZE; j++) {
                fprintf(archivo, "%d ", jugador->tablero_ataque[i][j]);
            }
            fprintf(archivo, "\n");
        }

        // Cierra el archivo después de la escritura
        fclose(archivo);
    } else {
        // Maneja el error si no se puede abrir el archivo
        perror("Error al abrir el archivo para escritura");
    }
}

// Función para cargar la partida desde un archivo de texto
void cargar_partida(char* nombreArchivo, PLAYER* jugador) {
    // Abre el archivo en modo de lectura de texto ("r")
    FILE* archivo = fopen(nombreArchivo, "r");

    // Verifica si el archivo se abrió correctamente
    if (archivo != NULL) {
        // Lee cada campo de la estructura desde una línea separada
        fscanf(archivo, "%s", jugador->nombre);
        fscanf(archivo, "%d", &jugador->num);
        fscanf(archivo, "%d", &jugador->mina);
        fscanf(archivo, "%d", &jugador->mina_viva);
        fscanf(archivo, "%d", &jugador->mina_x);
        fscanf(archivo, "%d", &jugador->mina_y);
        fscanf(archivo, "%d", &jugador->mina_mapa);
        fscanf(archivo, "%d", &jugador->barcos_restantes);

        // Lee el tablero de defensa desde líneas separadas
        for (int i = 0; i < TAB_SIZE; i++) {
            for (int j = 0; j < TAB_SIZE; j++) {
                fscanf(archivo, "%d", &jugador->tablero_defensa[i][j]);
            }
        }

        // Lee el tablero de ataque desde líneas separadas
        for (int i = 0; i < TAB_SIZE; i++) {
            for (int j = 0; j < TAB_SIZE; j++) {
                fscanf(archivo, "%d", &jugador->tablero_ataque[i][j]);
            }
        }

        // Cierra el archivo después de la lectura
        fclose(archivo);
    } else {
        // Maneja el error si no se puede abrir el archivo
        perror("Error al abrir el archivo para lectura");
    }
}
