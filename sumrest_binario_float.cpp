//El funcionamiento del programa es el siguiente:

//Se definen estructuras y funciones para realizar operaciones con números binarios con punto flotante.
//Se ingresan dos números binarios con punto flotante, cada uno representado por una parte entera, una parte fraccionaria y un exponente.
//Se realizan las operaciones de suma y resta, ajustando los exponentes si es necesario.
//Se imprime el resultado de las operaciones en forma de número flotante.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BITS 32 // Maximo de bits para la parte entera y la parte fraccionaria

// Estructura para representar numeros binarios con punto flotante
typedef struct {
    char entero[MAX_BITS];
    char fraccionario[MAX_BITS];
    int exponente;
} BinarioFlotante;

// Funcion para convertir un numero binario en un numero entero
int binario_a_entero(char *binario) {
    int entero = 0;
    int longitud = strlen(binario);
    for (int i = 0; i < longitud; i++) {
        if (binario[i] == '1') {
            entero += 1 << (longitud - i - 1);
        }
    }
    return entero;
}

// Funcion para convertir un numero entero en binario
char *entero_a_binario(int entero, int longitud) {
    char *binario = (char *)malloc(longitud + 1);
    for (int i = longitud - 1; i >= 0; i--) {
        binario[i] = (entero & 1) + '0';
        entero >>= 1;
    }
    binario[longitud] = '\0';
    return binario;
}

// Funcion para convertir un numero binario con punto flotante en un numero flotante
float binario_a_flotante(BinarioFlotante binario) {
    int parte_entera = binario_a_entero(binario.entero);
    float parte_fraccionaria = 0;
    int longitud_fraccionaria = strlen(binario.fraccionario);
    for (int i = 0; i < longitud_fraccionaria; i++) {
        if (binario.fraccionario[i] == '1') {
            parte_fraccionaria += 1.0 / pow(2, i + 1);
        }
    }
    float resultado = parte_entera + parte_fraccionaria;
    if (binario.entero[0] == '1') {
        resultado *= -1;
    }
    return resultado * pow(2, binario.exponente);
}

// Funcion para sumar dos numeros binarios con punto flotante
BinarioFlotante sumar_binarios_flotantes(BinarioFlotante binario1, BinarioFlotante binario2) {
    // Se igualan los exponentes
    while (binario1.exponente < binario2.exponente) {
        strcpy(binario1.entero + 1, binario1.entero);
        binario1.entero[0] = '0';
        binario1.exponente++;
    }
    while (binario2.exponente < binario1.exponente) {
        strcpy(binario2.entero + 1, binario2.entero);
        binario2.entero[0] = '0';
        binario2.exponente++;
    }
    
    // Se suma la parte entera
    int entero1 = binario_a_entero(binario1.entero);
    int entero2 = binario_a_entero(binario2.entero);
    int suma_enteros = entero1 + entero2;

    // Se suma la parte fraccionaria
    int fraccionaria1 = binario_a_entero(binario1.fraccionario);
    int fraccionaria2 = binario_a_entero(binario2.fraccionario);
    int suma_fraccionaria = fraccionaria1 + fraccionaria2;

    // Se normaliza la suma de la parte fraccionaria
    while (suma_fraccionaria >= 2) {
        suma_enteros++;
        suma_fraccionaria -= 2;
    }

    // Se convierte la suma de nuevo a binario con punto flotante
    BinarioFlotante resultado;
    strcpy(resultado.entero, entero_a_binario(suma_enteros, strlen(binario1.entero)));
    strcpy(resultado.fraccionario, entero_a_binario(suma_fraccionaria, strlen(binario1.fraccionario)));
    resultado.exponente = binario1.exponente;

    return resultado;
}

// Funcion para restar dos numeros binarios con punto flotante
BinarioFlotante restar_binarios_flotantes(BinarioFlotante binario1, BinarioFlotante binario2) {
    // Negamos el segundo numero y lo sumamos
    binario2.entero[0] = (binario2.entero[0] == '0') ? '1' : '0';
    binario2.fraccionario[0] = (binario2.fraccionario[0] == '0') ? '1' : '0';
    BinarioFlotante resultado = sumar_binarios_flotantes(binario1, binario2);
    return resultado;
}

int main() {
    BinarioFlotante binario1, binario2, resultado;

    printf("Ingrese el primer numero binario con punto flotante (entero.fraccionario): ");
    scanf("%s.%s %d", binario1.entero, binario1.fraccionario, &binario1.exponente);

    printf("Ingrese el segundo numero binario con punto flotante (entero.fraccionario): ");
    scanf("%s.%s %d", binario2.entero, binario2.fraccionario, &binario2.exponente);

    resultado = sumar_binarios_flotantes(binario1, binario2);
    printf("Suma: %.6f\n", binario_a_flotante(resultado));

    resultado = restar_binarios_flotantes(binario1, binario2);
    printf("Resta: %.6f\n", binario_a_flotante(resultado));

    return 0;
}
