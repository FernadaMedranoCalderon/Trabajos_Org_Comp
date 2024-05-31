//El funcionamiento del programa es el siguiente:

//Se define una función invertir_bits que invierte todos los bits de un número binario.
//Se define una función sumar_uno que suma 1 al número binario dado.
//Se define una función complemento_a_dos que primero invierte los bits del número binario y luego le suma 1.
//En la función principal main, el usuario ingresa un número binario.
//Se llama a la función complemento_a_dos para obtener el complemento a dos del número binario ingresado.
//Se muestra el complemento a dos resultante

#include <stdio.h>
#include <string.h>

// Funcion para invertir los bits de un numero binario
void invertir_bits(char *binario) {
    int longitud = strlen(binario);
    for (int i = 0; i < longitud; i++) {
        binario[i] = (binario[i] == '0') ? '1' : '0';
    }
}

// Funcion para sumar 1 a un numero binario
void sumar_uno(char *binario) {
    int carry = 1;
    int longitud = strlen(binario);
    for (int i = longitud - 1; i >= 0; i--) {
        if (carry == 0) {
            break;
        }
        if (binario[i] == '0') {
            binario[i] = '1';
            carry = 0;
        } else {
            binario[i] = '0';
            carry = 1;
        }
    }
}

// Funcion para convertir un numero binario a su complemento a dos
void complemento_a_dos(char *binario) {
    invertir_bits(binario);
    sumar_uno(binario);
}

int main() {
    char binario[100];
    
    printf("Ingrese un número binario: ");
    scanf("%s", binario);
    
    complemento_a_dos(binario);
    
    printf("El complemento a dos es: %s\n", binario);

    return 0;
}
