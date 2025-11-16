# Merge-de-5-archivos
Integra cinco archivos del proyecto estudiantes en C, utiliza tEstudiante.  Cambios principales:  Se implementa la struct tEstudiante con campos: dni, fechaDeInscripcion (milisegundos UTC), nombreYApellido y promedio.  Se actualizan las funciones de lectura y visualización de archivos para mostrar fechaDeInscripcion en formato DD/MM/YYYY. 

# 📂 Gestión de Estudiantes en C

[![MIT License](https://img.shields.io/badge/license-MIT-green)](LICENSE)  
[![C](https://img.shields.io/badge/language-C-blue)](https://github.com/TU_USUARIO/gestion-estudiantes)  

Proyecto en **C** que gestiona estudiantes, unificando varios módulos en una sola estructura `tEstudiante`. Permite leer, almacenar y mostrar datos de estudiantes, incluyendo **fecha de inscripción en formato DD/MM/YYYY**.

Repositorio: [https://github.com/TU_USUARIO/gestion-estudiantes](https://github.com/TU_USUARIO/gestion-estudiantes)

---

## 📖 Descripción
Este proyecto integra **5 estudiantes almacenados en `archivo.dat`**, y los siguientes archivos de código:

- **`struct tEstudiante`**:
  - `dni` → Identificador único (`unsigned long long`)  
  - `fechaDeInscripcion` → Tiempo en milisegundos desde epoch (UTC)  
  - `nombreYApellido` → Cadena de hasta 30 caracteres  
  - `promedio` → Promedio numérico  

- Funciones de lectura de archivos binarios y visualización de estudiantes.  
- Conversión de `fechaDeInscripcion` a **DD/MM/YYYY** para salida legible.  
- Uso de `PRIu64` para impresión segura de enteros de 64 bits.  
- Compatible con compilación en **Windows y Linux**.

---

## 📂 Estructura del proyecto

- **src/** – Código fuente
  - `main.c` → Entrada principal del programa  
  - `estudiantes.c` → Funciones de lectura, escritura y visualización  
  - `estudiantes.h` → Header con `struct tEstudiante` y prototipos  
- **project/** – Archivos de proyecto Code::Blocks
  - `estudiantes.cbp`  
  - `estudiantes.layout`  
  - `estudiantes.depend`   
- **data/** – Archivos de datos
  - `archivo.dat` → Archivo con los 5 estudiantes  
- `.gitignore` – Archivos y carpetas ignoradas por Git  

---

## 🛠 Requisitos
- Compilador **C** (GCC / MinGW)  
- **Code::Blocks** (opcional)  

---

## 💻 Compilación y ejecución
---

<details>
<summary>🖥️ Windows (MinGW / Code::Blocks)</summary>

### Compilación en Code::Blocks
1. Abrir **Code::Blocks** y cargar el archivo de proyecto `estudiantes.cbp`.
2. Configurar el compilador si es necesario (MinGW es lo habitual).
3. Usar **Build & Run** (o presionar `F9`) para compilar y ejecutar el programa.

### Compilación desde terminal
gcc src/main.c src/estudiantes.c -o gestionEstudiantes.exe

Ejecutar
./gestionEstudiantes.exe
</details>

<details> <summary>🐧 Linux</summary>

Compilación desde terminal
gcc src/main.c src/estudiantes.c -o gestionEstudiantes

Ejecutar
./gestionEstudiantes
</details>
🎮 Uso
Ejecutar el programa.

Leer los datos desde data/archivo.dat.

Mostrar los estudiantes con fechas legibles en DD/MM/YYYY.

✅ Ejemplo de salida:

123456789012345 15/11/2025 Fabrizio Del Vecchio 9.75
987654321098765 01/07/2024 Juan Pérez 8.50
📝 Licencia
MIT License © 2025 Fabrizio Del Vecchio

Se permite usar, modificar y redistribuir, siempre mencionando al autor.
