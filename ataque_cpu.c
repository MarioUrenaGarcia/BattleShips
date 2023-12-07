/*
El puntero de dirección (*direccion_cpu) se utiliza para recordar la última dirección en la que la CPU realizó un disparo exitoso. Esta información se almacena para que en el siguiente turno, la CPU pueda realizar disparos adyacentes a la posición anterior, imitando un comportamiento más inteligente.
En la parte del código donde la CPU ha acertado en el último disparo, se guarda la dirección seleccionada en la variable "direccion" en el puntero "*direccion_cpu". Luego, en el siguiente turno, cuando la CPU debe elegir una nueva dirección, se toma en cuenta esta última dirección exitosa. Esto significa que la CPU tratará de disparar en una casilla adyacente a la última casilla exitosa, replicando un comportamiento más estratégico.
Esencialmente, el puntero de dirección ayuda a la CPU a recordar y utilizar información sobre su comportamiento pasado para mejorar su lógica de ataque. Si la CPU ha acertado recientemente, intentará disparar en una dirección cercana a la última posición exitosa.
*/

void ataque_azar(int tablero_victima[][TAB_SIZE], int *acertado, int *acertado_cpu, int casilla_disparada[2], int *direccion_cpu)
{
    int x, y; // Variables que representarán las coordenadas de un ataque en el juego de batalla naval.
    int valido = 0; // Variable que se utilizará para verificar si las casillas adyacentes a la casilla anteriormente disparada son válidas.
    int direccion; // Variable para almacenar la dirección de ataque
    int adyacentes = 0; // Esta variable se usará para determinar si hay casillas adyacentes válidas a la casilla anteriormente disparada.

    // Establecer las coordenadas basadas en la dirección seleccionada
    x = casilla_disparada[1];
    y = casilla_disparada[0];

    // Ver si las casillas adyacentes a la casilla anteriormente disparada son válidas
    if ((x + 1 >= TAB_SIZE || tablero_victima[y][x + 1] == 2 || tablero_victima[y][x + 1] == 3) && (x - 1 < 0 || tablero_victima[y][x - 1] == 2 || tablero_victima[y][x - 1] == 3) && (y + 1 >= TAB_SIZE || tablero_victima[y + 1][x] == 2 || tablero_victima[y + 1][x] == 3) && (y - 1 < 0 || tablero_victima[y - 1][x] == 2 || tablero_victima[y - 1][x] == 3))
    {
        adyacentes = 0;
    }
    else
    {
        adyacentes = 1;
    }
/*
Verifica si las casillas adyacentes a la casilla disparada son válidas. 
Si lo son, adyacentes se establece en 1; de lo contrario, se establece en 0.
*/
    if (*acertado_cpu == 1)
    {
        do
        {
            // Seleccionar una dirección aleatoria: 0 = arriba, 1 = abajo, 2 = izquierda, 3 = derecha
            direccion = generar_numero(4);

            if (direccion == 0 && y > 0)
                y--;
            else if (direccion == 1 && y < TAB_SIZE - 1)
                y++;
            else if (direccion == 2 && x > 0)
                x--;
            else if (direccion == 3 && x < TAB_SIZE - 1)
                x++;

            // Verificar que la casilla no haya sido atacada antes
            if (tablero_victima[y][x] != 2 && tablero_victima[y][x] != 3)
            {
                valido = 1;
            }
        } while (valido == 0);

        *direccion_cpu = direccion;
    }
    else
    {
        // Si no acertó en el último disparo, elegir una casilla al azar
        do
        {
            x = generar_numero(TAB_SIZE);
            y = generar_numero(TAB_SIZE);
        } while (tablero_victima[y][x] == 2 || tablero_victima[y][x] == 3); // Evitar casillas ya atacadas
    
    *direccion_cpu = -1;
    }
    /*
    Si el CPU ha acertado en el último disparo, elige una dirección de ataque aleatoria
     y verifica que la casilla no haya sido atacada antes. Si no acertó, elige una casilla al azar evitando las casillas ya atacadas.
    */
    

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
        // En caso de que el disparo pasado haya sido un acierto, se marca la casilla como fallida , sin embargo, no se cambia el valor de acertado_cpu, para que en el siguiente turno se dispare en una casilla adyacente a la original
        if (*acertado_cpu == 1)
        {
            tablero_victima[y][x] = 2;
            *acertado = 0;
            *acertado_cpu = 1;
        }
        else if (*acertado_cpu == 1 && adyacentes == 0) // En caso de que cpu ya haya intentado con todas las casillas adyacentes, entonces ahora si se cambia el valor de acertado_cpu a 0, para que en el siguiente turno se dispare en una casilla aleatoria
        {
            tablero_victima[y][x] = 2;
            *acertado = 0;
            *acertado_cpu = 0;

            // Actualizar la última casilla disparada
            
            casilla_disparada[0] = y;
            casilla_disparada[1] = x;

    /*
    Realiza el ataque en la casilla determinada por las coordenadas x e y. 
    Actualiza el tablero y algunas variables según el resultado del ataque (acierto, fallo).
    */


        }
    }
}