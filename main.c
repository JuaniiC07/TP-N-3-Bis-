#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandomNumber();
int mayorDeLos3(int primerNumero, int segundoNumero, int tercerNumero, int *menor, int *mayor);
int sumaEnterosPositivosMenoresQueN(int n);
void tablaDeMultiplicar(int n);
int sumar(int a, int b);
int restar(int a, int b);
int multiplicar(int a, int b);
float dividir(int a, int b);
void cambiarSigno(int* numero6);
void cargarNumeros(int *num1, int *num2);



int main()
{
    srand(time(NULL));
    int primerNumeroMayor, segundoNumeroMayor, tercerNumeroMayor;
    int randNumber;
    int option;
    int mayorYMenorResultado;
    int menor, mayor;
    int invalid = 0;
    int n;
    int resultado;
    int numero;
    int opcion, a, b, resultado2;
    float resultadoDiv;
    int numero6;
    int numero1, numero2;
    do{
        invalid = 0;
        printf("\nHola! Vamos a ejecutar alguna de los siguientes casos:\n");
        printf("\n********************\n");
        printf("1- Devuelve un numero aleatorio del 0 al 100 \n");
        printf("2- Devuelve el mayor de los 3 \n");
        printf("3- Devuelve los numeroes enteros menores al numero ingresado \n");
        printf("4- Devuelve la tabla de multiplicar del numero ingresado \n");
        printf("5- Calculadora \n");
        printf("6- Devuelve el negativo de un numero positivo \n");
        printf("7- Devuelve 2 numeros que fueron cargados por el usuario en la funcion \n");
        printf("\n********************\n");
        printf("Tu eleccion: ");

        scanf("%i", &option);
        switch(option){
            case 1:
                randNumber = getRandomNumber();
                printf("%i", randNumber);
                break;
            case 2:

                printf("\nIntroduce el primer numero: ");
                scanf("%i", &primerNumeroMayor);

                printf("\nAhora el segundo: ");
                scanf("%i", &segundoNumeroMayor);

                printf("\nEl tercero: ");
                scanf("%i", &tercerNumeroMayor);

                mayorYMenorResultado = mayorDeLos3(primerNumeroMayor, segundoNumeroMayor, tercerNumeroMayor, &menor, &mayor);
                printf("\nEl mayor es: %i\n", mayor);
                printf("\nEl menor es: %i\n", menor);
                break;
            case 3:
                printf("Ingresa un numero entero positivo: ");
                scanf("%d", &n);
                resultado = sumaEnterosPositivosMenoresQueN(n);
                printf("La suma de los numeros enteros positivos menores que %d es %d.\n", n, resultado);
                return 0;
            case 4:
                printf("Ingrese un numero entero: ");
                scanf("%d", &numero);
                tablaDeMultiplicar(numero);
                return 0;
            case 5:
                printf("Bienvenido a mi calculadora!\n");
                printf("Por favor, seleccione una operacion:\n");
                printf("1. Suma\n");
                printf("2. Resta\n");
                printf("3. Multiplicacion\n");
                printf("4. Division\n");
                printf("Opcion: ");
                scanf("%d", &opcion);
                printf("Ingrese dos numeros separados por un espacio: ");
                scanf("%d %d", &a, &b);
                if(opcion == 1) {
                    resultado2 = sumar(a, b);
                    printf("El resultado de la suma es: %d\n", resultado2);
                }
                else if(opcion == 2) {
                    resultado2 = restar(a, b);
                    printf("El resultado de la resta es: %d\n", resultado2);
                }
                else if(opcion == 3) {
                    resultado2 = multiplicar(a, b);
                    printf("El resultado de la multiplicacion es: %d\n", resultado2);
                }
                else if(opcion == 4) {
                    resultadoDiv = dividir(a, b);
                    printf("El resultado de la division es: %f\n", resultadoDiv);
                }
                break;
            case 6:
                printf("Ingrese un numero positivo para cambiarlo a negativo: \n");
                scanf("%d", &numero6);
                printf("Antes de la funcion: %d\n", numero6);
                cambiarSigno(&numero6);
                printf("Despues de la funcion: %d\n", numero6);
                break;
            case 7:
                cargarNumeros(&numero1, &numero2);
                printf("Los numeros ingresados son: %d y %d\n", numero1, numero2);
                break;
        default:
                printf("\n\nLa tecla que presionanste no es valida. Por favor, intenta de nuevo\n\n");
                invalid = 1;
                break;
        }
    if(invalid == 0){
          printf("\nQuieres seguir ejecutando? Presiona 0 para salir.\n");
    }
    }
    while(option != 0);
    return 0;
}

/// Funciones

// Funcion 1

int getRandomNumber(){
    int random_number = rand()%101;
    return random_number;
}

// Funcion 2

int mayorDeLos3(int primerNumero, int segundoNumero, int tercerNumero, int *menor, int *mayor){
    *mayor = primerNumero;
    *menor = primerNumero;

    if(segundoNumero > *mayor ){
        *mayor = segundoNumero;
    }
    else{
        *menor = segundoNumero;
    }
    if(tercerNumero > *mayor){
        *mayor = tercerNumero;
    }
    else if(tercerNumero < *menor){
        *menor = tercerNumero;

    }
}

// Funcion 3

int sumaEnterosPositivosMenoresQueN(int n) {
    int suma = 0;
    for (int i = 1; i < n; i++) {
        if (i > 0) {
            suma += i;
        }
    }
    return suma;
}

// Funcion 4

void tablaDeMultiplicar(int n) {
    printf("Tabla de multiplicar del %d:\n", n);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", n, i, n * i);
    }
}

// Funcion 5

int sumar(int a, int b) {
    return a + b;
}

int restar(int a, int b) {
    return a - b;
}

int multiplicar(int a, int b) {
    return a * b;
}

float dividir(int a, int b) {
    return (float)a / b;
}

// Funcion 6

void cambiarSigno(int* numero6) {
    *numero6 = -(*numero6);
}

// Funcion 7

void cargarNumeros(int *num1, int *num2) {
    printf("Ingrese el primer numero: ");
    scanf("%d", num1);

    printf("Ingrese el segundo numero: ");
    scanf("%d", num2);
}
