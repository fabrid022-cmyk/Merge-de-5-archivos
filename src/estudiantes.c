#include "estudiantes.h"

void fusionar_estudiantes(const char *path_est1,const char *path_est2,const char *path_est,void (*modo_fusion)(FILE*,FILE*,FILE*))
{
    FILE* pfE;
    FILE* pfE1;
    FILE* pfE2;

    pfE1=fopen(path_est1,"rb");

    if( !pfE1 )
        return;

    pfE2=fopen(path_est2,"rb");

    if( !pfE2 )
    {
        fclose(pfE1);
        return;
    }

    pfE=fopen(path_est,"wb");

    if( !pfE )
    {
        fclose(pfE1);
        fclose(pfE2);
    }

    (*modo_fusion)(pfE1,pfE2,pfE);

    fclose(pfE1);
    fclose(pfE2);
    fclose(pfE);
}

void fusionar_Todo(FILE* pfE1, FILE* pfE2, FILE* pfE)
{
    tEstudiante e1,e2;

    fread(&e1,sizeof(tEstudiante),1,pfE1);
    fread(&e2,sizeof(tEstudiante),1,pfE2);
    while( !feof(pfE1) && !feof(pfE2) )
    {
        if( e1.fechaDeInscripcion<e2.fechaDeInscripcion )
        {
            fwrite(&e1,sizeof(tEstudiante),1,pfE);
            fread(&e1,sizeof(tEstudiante),1,pfE1);
        }

        if( e1.fechaDeInscripcion>e2.fechaDeInscripcion )
        {
            fwrite(&e2,sizeof(tEstudiante),1,pfE);
            fread(&e2,sizeof(tEstudiante),1,pfE2);
        }

        if( e1.fechaDeInscripcion==e2.fechaDeInscripcion )
        {
            fwrite(&e1,sizeof(tEstudiante),1,pfE);
            fread(&e1,sizeof(tEstudiante),1,pfE1);

            fwrite(&e2,sizeof(tEstudiante),1,pfE);
            fread(&e2,sizeof(tEstudiante),1,pfE2);
        }
    }

    while( !feof(pfE1) )
    {
        fwrite(&e1,sizeof(tEstudiante),1,pfE);
        fread(&e1,sizeof(tEstudiante),1,pfE1);
    }

    while( !feof(pfE2) )
    {
        fwrite(&e2,sizeof(tEstudiante),1,pfE);
        fread(&e2,sizeof(tEstudiante),1,pfE2);
    }
}

void mostrarArchivo(const char* pathE)
{
    FILE* pf;
    tEstudiante e;

    pf = fopen(pathE, "rb");
    if(!pf)
        return;

    while(fread(&e, sizeof(tEstudiante), 1, pf) == 1)
    {
        // convertir milisegundos a segundos
        time_t tiempo = (time_t)(e.fechaDeInscripcion / 1000);

        // convertir a estructura de fecha y hora UTC
        struct tm* fecha = gmtime(&tiempo);

        printf("%" PRIu64 " %02d/%02d/%04d %s %.2f\n",
               (uint64_t)e.dni,
               fecha->tm_mday,
               fecha->tm_mon + 1,  // tm_mon va de 0 a 11
               fecha->tm_year + 1900,
               e.nombreYApellido,
               e.promedio);
    }

    fclose(pf);
}


void avanzarArch(char *pathE2)
{
    char aux[MAX_DIG_EST];
    int num;
    sscanf((pathE2+20),"%1s",aux);
    num=atoi(aux);
    num++;

    *(pathE2+20)='\0';

    sprintf(aux,"%d",num);
    strcat(pathE2,aux);
    strcat(pathE2,".dat");
}
