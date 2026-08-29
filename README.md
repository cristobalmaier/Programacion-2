# 💻 Programación II

<p align="center">
  <img src="https://img.shields.io/badge/Lenguaje-C-blue.svg?style=for-the-badge&logo=c" alt="Lenguaje C">
  <img src="https://img.shields.io/badge/Compilador-GCC-yellow.svg?style=for-the-badge&logo=gnu" alt="Compilador GCC">
  <img src="https://img.shields.io/badge/Estado-En_Desarrollo-green.svg?style=for-the-badge" alt="Estado">
</p>

Repositorio con los ejercicios prácticos, trabajos de clase y entregas obligatorias de la materia **Programación II**, implementados en lenguaje **C**.

---

## 📌 Tabla de Contenidos

- [📋 Descripción General](#-descripción-general)
- [📂 Estructura del Repositorio](#-estructura-del-repositorio)
- [📚 Contenidos y Módulos](#-contenidos-y-módulos)
  - [Unidad 3: Matrices y Vectores](#unidad-3-matrices-y-vectores)
  - [Unidad 4: Manejo de Caracteres y Cadenas](#unidad-4-manejo-de-caracteres-y-cadenas)
  - [Unidad 5: Recursividad](#unidad-5-recursividad)
  - [Trabajos Obligatorios / Entregables](#trabajos-obligatorios--entregables)
- [🛠️ Requisitos y Compilación](#️-requisitos-y-compilación)
  - [Prerrequisitos](#prerrequisitos)
  - [Instrucciones de Compilación y Ejecución](#instrucciones-de-compilación-y-ejecución)
- [👤 Autor](#-autor)

---

## 📋 Descripción General

Este repositorio contiene código fuente modular y estructurado orientado al aprendizaje de conceptos fundamentales y avanzados de programación en C, tales como:

- Manejo de arreglos unidimensionales y bidimensionales (vectores y matrices).
- Procesamiento de secuencias de caracteres y manipulación de strings (`<string.h>`, `getchar`, `putchar`).
- Algoritmos recursivos (casos base, casos generales, recursión simple y sobre estructuras de datos).
- Modularización de código mediante funciones y paso de parámetros.

---

## 📂 Estructura del Repositorio

```plaintext
Programacion-2/
│
├── 3 - Matrices/                               # Ejercicios y ejemplos de matrices y vectores
│   ├── ejercicio_clase.c                       # Procesamiento de vectores y cálculo estadístico
│   └── matriz_simple.c                         # Carga y visualización de matrices 3x3
│
├── 4 - Caracteres/                             # Manejo de caracteres y flujos de entrada/salida
│   ├── ejemplo_caracteres.c                    # Manejo de arreglos de cadenas y comparación (strcmp, strcpy)
│   ├── ejercicio_caracter_letras.c             # Alternancia mayúsculas/minúsculas y formateo de espacios
│   └── ejercicio_contar_constantes.c           # Conteo de consonantes en oraciones
│
├── 5 - Recursividad/                           # Algoritmos recursivos
│   ├── recursividad_acumular_pares.c           # Suma recursiva de números pares
│   ├── recursividad_dec_bin.c                  # Conversión recursiva de base decimal a binario
│   ├── recursividad_ejemplo_factorial.c        # Cálculo del factorial
│   ├── recursividad_matriz.c                   # Carga y suma de diagonal principal mediante recursión
│   └── recursividad_sumar_cifras.c             # Suma recursiva de cifras de un número
│
├── Ejercicios - Obligatorios - Entregables/     # Trabajos prácticos evaluativos
│   ├── 1 - Calculadora.c                       # Calculadora por consola con validación de operadores
│   ├── 2 - Matriz.c                            # Operaciones avanzadas sobre matrices (filas, columnas, diagonales)
│   ├── 3 - Caracteres.c                        # Procesamiento de texto y análisis de secuencias
│   └── 4 - Recursividad.c                      # Entrega del módulo de recursión
│
└── README.md
```

---

## 📚 Contenidos y Módulos

### Unidad 3: Matrices y Vectores
* **`matriz_simple.c`**: Carga y recorrido bidimensional para impresión tabular en consola.
* **`ejercicio_clase.c`**: Carga condicional en vectores, sumatoria en posiciones impares, productoria condicional y búsqueda de valores mínimos e índices.

### Unidad 4: Manejo de Caracteres y Cadenas
* **`ejemplo_caracteres.c`**: Arreglos bidimensionales de caracteres, almacenamiento de nombres y notas, uso de `strcpy` y `strcmp`.
* **`ejercicio_caracter_letras.c`**: Procesamiento caracter a caracter con `getchar()` / `putchar()`, normalización de espacios repetidos y cambio dinámico entre mayúsculas y minúsculas.
* **`ejercicio_contar_constantes.c`**: Filtrado y conteo de caracteres consonantes en una oración finalizada por salto de línea.

### Unidad 5: Recursividad
* **`recursividad_ejemplo_factorial.c`**: Definición clásica de caso base ($n = 0$) y caso general ($n \times \text{fact}(n - 1)$).
* **`recursividad_dec_bin.c`**: Descomposición recursiva sucesiva por división para imprimir la representación binaria.
* **`recursividad_acumular_pares.c`**: Acumulación descendente recursiva de enteros pares hasta cero.
* **`recursividad_sumar_cifras.c`**: Descomposición decimal recursiva sumando `num % 10` y reduciendo `num / 10`.
* **`recursividad_matriz.c`**: Algoritmos recursivos aplicados a matrices multidimensionales (carga por índices $i, j$ y cálculo de la traza/diagonal principal).

### Trabajos Obligatorios / Entregables
1. **Calculadora (`1 - Calculadora.c`)**:
   - Operaciones aritméticas básicas (`+`, `-`, `*`, `/`).
   - Validación robusta de operadores y control de división por cero.
   - Ciclo interactivo con condición de salida `(0, 0)`.

2. **Matriz Completa (`2 - Matriz.c`)**:
   - Carga y visualización de matrices $3 \times 3$.
   - Sumatoria de fila específica y búsqueda del elemento máximo en una columna.
   - Promedio de valores múltiplos de 5.
   - Suma de elementos de la diagonal principal.
   - Cálculo del mínimo por cada fila.
   - Extracción y muestra de elementos de la diagonal secundaria.

3. **Procesamiento de Caracteres (`3 - Caracteres.c`)**:
   - Conteo de vocales en posiciones pares.
   - Transformación de pares de caracteres específicos (ej. `as` $\rightarrow$ `AS`).
   - Formateo y espaciado adaptativo de texto.

4. **Recursividad (`4 - Recursividad.c`)**:
   - Ejercicio integrador de algoritmos recursivos.

---

## 🛠️ Requisitos y Compilación

### Prerrequisitos
Para compilar y ejecutar cualquiera de los programas necesitas un compilador de C estándar, como **GCC** o **Clang**:

* **Linux (Ubuntu/Debian)**:
  ```bash
  sudo apt update && sudo apt install build-essential
  ```
* **macOS**:
  ```bash
  xcode-select --install
  ```
* **Windows**:
  Instalar [MinGW-w64](https://www.mingw-w64.org/) o utilizar [WSL](https://learn.microsoft.com/es-es/windows/wsl/).

### Instrucciones de Compilación y Ejecución

Para compilar cualquier archivo individual, abre una terminal en la raíz del repositorio o dentro de la carpeta correspondiente y ejecuta:

```bash
# Ejemplo: Compilar un ejercicio de la carpeta de matrices
gcc "3 - Matrices/matriz_simple.c" -o matriz_simple

# Ejecutar el programa compilado
./matriz_simple
```

Para compilar los ejercicios entregables:

```bash
# Compilar la calculadora
gcc "Ejercicios - Obligatorios - Entregables/1 - Calculadora.c" -o calculadora

# Ejecutar
./calculadora
```

---

## 👤 Autor

* **Cristobal Maier** - [cristobalmaier](https://github.com/cristobalmaier)