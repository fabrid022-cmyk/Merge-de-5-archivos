#ifndef ESTUDIANTES_H_INCLUDED
#define ESTUDIANTES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <time.h>

#define MAX_REG 10
#define MAX_REG_MEM 12
#define MAX_DIG_EST 2

typedef struct
{
    unsigned long long dni;
    unsigned long long fechaDeInscripcion;
    char nombreYApellido[30];
    float promedio;
}tEstudiante;

void fusionar_estudiantes(const char *path_est1,const char *path_est2,const char *path_est,void (*modo_fusion)(FILE*,FILE*,FILE*));

void fusionar_Todo(FILE*, FILE*, FILE*);

void mostrarArchivo(const char* pathE);

void avanzarArch(char *);

#endif // ESTUDIANTES_H_INCLUDED
