void ataque_azar(int tablero_victima[][TAB_SIZE], int *acertado, int *acertado_cpu, int casilla_disparada[2])
{
    int x, y; // Coordenadas del ataque en el juego de batalla naval.
    int valido = 0; // Verifica si las casillas adyacentes son válidas.
    int direccion; // Almacena la dirección de ataque
    int adyacentes = 0; // Determina si hay casillas adyacentes válidas.

    // Establecer las coordenadas basadas en la dirección seleccionada
    x = casilla_disparada[1];
    y = casilla_disparada[0];

    // Verificar si las casillas adyacentes a la casilla disparada son válidas
    if ((x + 1 >= TAB_SIZE || tablero_victima[y][x + 1] == 2 || tablero_victima[y][x + 1] == 3) &&
        (x - 1 < 0 || tablero_victima[y][x - 1] == 2 || tablero_victima[y][x - 1] == 3) &&
        (y + 1 >= TAB_SIZE || tablero_victima[y + 1][x] == 2 || tablero_victima[y + 1][x] == 3) &&
        (y - 1 < 0 || tablero_victima[y - 1][x] == 2 || tablero_victima[y - 1][x] == 3))
    {
        adyacentes = 0;
    }
    else
    {
        adyacentes = 1;
    }

    if (*acertado_cpu == 1)
    {
        // Si acertó en el último disparo, intentar hundir el barco en todas las direcciones
        for (direccion = 0; direccion < 4; ++direccion)
        {
            int temp_x = x;
            int temp_y = y;

            // Probar cada dirección
            switch (direccion)
            {
            case 0: // Arriba
                temp_y--;
                break;
            case 1: // Abajo
                temp_y++;
                break;
            case 2: // Izquierda
                temp_x--;
                break;
            case 3: // Derecha
                temp_x++;
                break;
            }

            // Verificar que la casilla no haya sido atacada antes
            if (temp_x >= 0 && temp_x < TAB_SIZE && temp_y >= 0 && temp_y < TAB_SIZE &&
                tablero_victima[temp_y][temp_x] != 2 && tablero_victima[temp_y][temp_x] != 3)
            {
                valido = 1;
                x = temp_x;
                y = temp_y;
                break; // Salir del bucle una vez que se encuentre una dirección válida
            }
        }

        if (valido == 0)
        {
            // Si no se encontró una dirección válida, cambiar a una casilla aleatoria
            do
            {
                x = generar_numero(TAB_SIZE);
                y = generar_numero(TAB_SIZE);
            } while (tablero_victima[y][x] == 2 || tablero_victima[y][x] == 3);
        }
    }
    else
    {
        // Si no acertó en el último disparo, elegir una casilla al azar
        do
        {
            x = generar_numero(TAB_SIZE);
            y = generar_numero(TAB_SIZE);
        } while (tablero_victima[y][x] == 2 || tablero_victima[y][x] == 3);
    }

    // Realizar el ataque
    if (tablero_victima[y][x] == 1)
    {
        tablero_victima[y][x] = 3;
        *acertado = 1;
        *acertado_cpu = 1;
        casilla_disparada[0] = y;
        casilla_disparada[1] = x;
    }
    else if (tablero_victima[y][x] == 0)
    {
        if (*acertado_cpu == 1)
        {
            tablero_victima[y][x] = 2;
            *acertado = 0;
            *acertado_cpu = 1;
        }
        else if (*acertado_cpu == 1 && adyacentes == 0)
        {
            tablero_victima[y][x] = 2;
            *acertado = 0;
            *acertado_cpu = 0;

            casilla_disparada[0] = y;
            casilla_disparada[1] = x;
        }
    }
}