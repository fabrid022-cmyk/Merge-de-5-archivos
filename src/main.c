#include "estudiantes.h"

int main()
{
    const char pathE[]="archivos/estudiantes.dat";
    char pathE1[]="archivos/estudiantes1.dat";
    char pathE2[]="archivos/estudiantes2.dat";

    printf("ARCHIVO 1\n");
    mostrarArchivo("archivos/estudiantes1.dat");
    printf("\n-------\n");

    printf("ARCHIVO 2\n");
    mostrarArchivo("archivos/estudiantes2.dat");
    printf("\n-------\n");

    printf("ARCHIVO 3\n");
    mostrarArchivo("archivos/estudiantes3.dat");
    printf("\n-------\n");

    printf("ARCHIVO 4\n");
    mostrarArchivo("archivos/estudiantes4.dat");
    printf("\n-------\n");

    printf("ARCHIVO 5\n");
    mostrarArchivo("archivos/estudiantes5.dat");
    printf("\n-------\n");

    printf("FUSION ARCHIVOS 1 Y 2\n");
    fusionar_estudiantes(pathE1,pathE2,pathE, fusionar_Todo);
    mostrarArchivo(pathE);
    rename(pathE,"archivos/estudiantes1a2.dat");

    printf("\n-------\n");

    printf("FUSION ARCHIVOS 1, 2 Y 3\n");
    memcpy(pathE1,"archivos/estudiantes1a2.dat",sizeof(char));
    avanzarArch(pathE2);
    fusionar_estudiantes(pathE1,pathE2,pathE, fusionar_Todo);
    mostrarArchivo(pathE);
    rename(pathE,"archivos/estudiantes1a3.dat");

    printf("\n-------\n");

    printf("FUSION ARCHIVOS 1, 2, 3 Y 4\n");
    memcpy(pathE1,"archivos/estudiantes1a3.dat",sizeof(char));
    avanzarArch(pathE2);
    fusionar_estudiantes(pathE1,pathE2,pathE, fusionar_Todo);
    mostrarArchivo(pathE);
    rename(pathE,"archivos/estudiantes1a4.dat");

    printf("\n-------\n");

    printf("FUSION ARCHIVOS 1, 2, 3, 4 Y 5\n");
    memcpy(pathE1,"archivos/estudiantes1a4.dat",sizeof(char));
    avanzarArch(pathE2);
    fusionar_estudiantes(pathE1,pathE2,pathE, fusionar_Todo);
    mostrarArchivo(pathE);
    rename(pathE,"archivos/estudiantes.dat");

    mostrarArchivo(pathE);

    return 0;
}
