#include <stdio.h>
#include <stdlib.h>
 
 
float sumar(float a, float b) {
	return a + b;
}
 
 
float restar(float a, float b) {
	return a - b;
}
 
 
float multiplicar(float a, float b) {
	return a * b;
}
 
 
float dividir(float a, float b) {
	if (b == 0) {
		printf("Error! No se puede dividir por cero");
		return 0;
	}
	return a / b;
}
 
 
int validar_operador(char op) {
	if (op == '+' || op == '-' || op == '*' || op == '/') {
		return 1;
	}
	return 0;
}
 
 
int main() {
	float num1, num2, resultado;
	char operador;
 
 
	while (1) {
		printf("Ingrese el primer numero: ");
		scanf("%f", &num1);
 
 
		printf("Ingrese el segundo numero: ");
		scanf("%f", &num2);
 
 
		if (num1 == 0 && num2 == 0) {
			printf("Fin del programa");
			break;
		}
 
 
		do {
			printf("Ingrese el operador (+, -, *, /): ");
			scanf(" %c", &operador);
 
 
			if (!validar_operador(operador)) {
				printf("Operador invalido\n");
			}
		} while (!validar_operador(operador));
 
 
		if (operador == '+') {
			resultado = sumar(num1, num2);
			printf("Resultado: %.2f\n", resultado);
		} else if (operador == '-') {
			resultado = restar(num1, num2);
			printf("Resultado: %.2f\n", resultado);
		} else if (operador == '*') {
			resultado = multiplicar(num1, num2);
			printf("Resultado: %.2f\n", resultado);
		} else if (operador == '/') {
			if (num2 != 0) {
				resultado = dividir(num1, num2);
				printf("Resultado: %.2f\n", resultado);
			} else {
				dividir(num1, num2);
			}
		}
	}
 
 
	return 0;
}