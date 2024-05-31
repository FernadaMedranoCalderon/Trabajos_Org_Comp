//El funcionamiento del programa es el siguiente:

//Se definen funciones para convertir números binarios a decimales y viceversa.
//Se definen funciones para realizar operaciones aritmeticas (suma, resta, multiplicacion y division) en numeros binarios.
//En la funcion principal main, el usuario ingresa dos numeros binarios.
//Se realizan las cuatro operaciones (suma, resta, multiplicacion y division) utilizando las funciones definidas anteriormente.
//Se muestra el resultado de cada operacion en forma de numero binario.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funcion para convertir un numero binario en entero
int binario_a_decimal(char *binario)
{
    int decimal = 0;
    int longitud = strlen(binario);
    for (int i = 0; i < longitud; i++)
    {
        if (binario[i] == '1')
        {
            decimal += 1 << (longitud - i - 1);
        }
    }
    return decimal;
}

// Funcion para convertir un entero en numero binario
char *decimal_a_binario(int decimal)
{
    int longitud = snprintf(NULL, 0, "%d", decimal);
    char *binario = (char *)malloc(longitud + 1);
    sprintf(binario, "%d", decimal);
    return binario;
}

// Funcion para sumar dos numeros binarios
char *sumar_binarios(char *binario1, char *binario2)
{
    int decimal1 = binario_a_decimal(binario1);
    int decimal2 = binario_a_decimal(binario2);
    int suma = decimal1 + decimal2;
    return decimal_a_binario(suma);
}

// Funcion para restar dos numeros binarios
char *restar_binarios(char *binario1, char *binario2)
{
    int decimal1 = binario_a_decimal(binario1);
    int decimal2 = binario_a_decimal(binario2);
    int resta = decimal1 - decimal2;
    return decimal_a_binario(resta);
}

// Funcion para multiplicar dos numeros binarios
char *multiplicar_binarios(char *binario1, char *binario2)
{
    int decimal1 = binario_a_decimal(binario1);
    int decimal2 = binario_a_decimal(binario2);
    int producto = decimal1 * decimal2;
    return decimal_a_binario(producto);
}

// Funcion para dividir dos numeros binarios
char *dividir_binarios(char *binario1, char *binario2)
{
    int decimal1 = binario_a_decimal(binario1);
    int decimal2 = binario_a_decimal(binario2);
    if (decimal2 == 0)
    {
        printf("Error: Division por cero.\n");
        exit(EXIT_FAILURE);
    }
    int division = decimal1 / decimal2;
    return decimal_a_binario(division);
}

int main()
{
    char binario1[100], binario2[100];

    printf("Ingrese el primer numero binario: ");
    scanf("%s", binario1);

    printf("Ingrese el segundo numero binario: ");
    scanf("%s", binario2);

    printf("Suma: %s\n", sumar_binarios(binario1, binario2));
    printf("Resta: %s\n", restar_binarios(binario1, binario2));
    printf("Multiplicacion: %s\n", multiplicar_binarios(binario1, binario2));
    printf("Division: %s\n", dividir_binarios(binario1, binario2));

    return 0;
}
