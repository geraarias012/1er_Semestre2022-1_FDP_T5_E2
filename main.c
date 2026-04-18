#include <stdio.h>
#include <stdlib.h>
#include <C:\Users\arias\OneDrive\Documentos\Fundamentos de Programacíon\Trabajo 5\cabecera.h>

typedef struct
{
    char nombre_alumno[50];
    int edad;
    char sexo[2];
    char direccion[50];
    char telefono[11];
    char correo[50];
} datos_alumnos;

void registrar_alumno(void);
void consultar_datos(void);
void ordenar_datos(void);
int contar_registro(void);
void promedio_edades(void);

int main()
{
    char op;
    do{
    cabecera();
    printf("\nSELECCIONE UNA DE LAS SIGUIENTES OPCIONES:\n");
    printf("A] DAR DE ALTA UN ALUMNO\n");
    printf("B] CONSULTAR DATOS ALMACENADOS\n");
    printf("C] ORDENAR LOS DATOS\n");
    printf("D] PROMEDIO DE EDADES\n");
    printf("E] SALIR\n");
    printf("\nINTRODUZCA UNA OPCION : ");
    scanf("%s", &op);

    switch(op)
        {
            case 'a':
            case 'A':
                {
                registrar_alumno();
                break;
                }
            case 'b':
            case 'B':
                {
                consultar_datos();
                system("PAUSE");
                break;
                }
            case 'c':
            case 'C':
                {
                ordenar_datos();
                system("PAUSE");
                break;
                }
            case 'd':
            case 'D':
                {
                promedio_edades();
                system("PAUSE");
                break;
                }
            case 'e':
            case 'E':
                break;
            default:
                {
            printf("\nOpcion no valida\n\n");
            system("PAUSE");
            break;
                }
        }
            system("CLS");
        }while(op!='e'&&op!='E');
        printf("\nFINAL DEL PROGRAMA\n");
    return 0;
}

void registrar_alumno(void)
{
    datos_alumnos directorio;
    FILE *puntero_a_archivo;
    int a=1;
    puntero_a_archivo=fopen("DATOS.DAT","ab");
    do
    {
        printf("\nNOMBRE DEL ALUMNO: ");
        fflush(stdin);
        gets(directorio.nombre_alumno);
        printf("EDAD: ");
        scanf("%i", &directorio.edad);
        printf("SEXO(M/F): ");
        fflush(stdin);
        gets(directorio.sexo);
        printf("DIRECCION: ");
        fflush(stdin);
        gets(directorio.direccion);
        printf("TELEFONO: ");
        fflush(stdin);
        gets(directorio.telefono);
        printf("CORREO ELECTRONICO: ");
        fflush(stdin);
        gets(directorio.correo);
        fwrite(&directorio, sizeof(directorio), 1, puntero_a_archivo);
        printf("QUIERES REGISTRAR MAS ALUMNOS?(SI=1/NO=0)");
        scanf("%d",&a);
    }while(a==1);
    fclose(puntero_a_archivo);
}
void consultar_datos(void)
{
    datos_alumnos directorio;
    FILE *puntero_a_archivo;
    puntero_a_archivo=fopen("DATOS.DAT","rb");
    while(fread(&directorio, sizeof(directorio), 1, puntero_a_archivo)==1)
    {
        printf("\nNOMBRE DEL ALUMNO: %s\n", directorio.nombre_alumno);
        printf("EDAD: %i\n", directorio.edad);
        printf("SEXO: %s\n", directorio.sexo);
        printf("DIRECCION: %s\n", directorio.direccion);
        printf("TELEFONO: %s\n", directorio.telefono);
        printf("CORREO ELECTRONICO: %s\n", directorio.correo);
    }
    fclose(puntero_a_archivo);
}
void ordenar_datos(void)
{
    datos_alumnos directorio, aux;
    int i=0, j=0, k=0,n;
    FILE *puntero_a_archivo;
    n=contar_registro();
    datos_alumnos registros[n];
    puntero_a_archivo=fopen("DATOS.DAT","rb");
    while(fread(&directorio, sizeof(directorio), 1, puntero_a_archivo)==1)
    {
        registros[i]=directorio;
        i++;
    }
    fclose(puntero_a_archivo);

    for (j=0;j<n-1;j++)
    {
      for (k=j+1;k<n;k++)
      {
        if(strcmp(registros[j].nombre_alumno,registros[k].nombre_alumno)>0)
        {
            aux=registros[j];
            registros[j]=registros[k];
            registros[k]=aux;
        }
      }
    }

    for(i=0;i<n;i++)
    {
        printf("\nNOMBRE DEL ALUMNO: %s\n", registros[i].nombre_alumno);
        printf("EDAD: %i\n", registros[i].edad);
        printf("SEXO: %s\n", registros[i].sexo);
        printf("DIRECCION: %s\n", registros[i].direccion);
        printf("TELEFONO: %s\n", registros[i].telefono);
        printf("CORREO ELECTRONICO: %s\n", registros[i].correo);
    }
}
int contar_registro(void)
{
    datos_alumnos directorio;
    int i=0;
    FILE *puntero_a_archivo;
    puntero_a_archivo=fopen("DATOS.DAT","rb");
    while(fread(&directorio, sizeof(directorio), 1, puntero_a_archivo)==1)
    {
        i++;
    }
    fclose(puntero_a_archivo);
    return i;
}
void promedio_edades(void)
{
    datos_alumnos directorio;
    float prom, aux=0, i;
    FILE *puntero_a_archivo;
    i=contar_registro();
    puntero_a_archivo=fopen("DATOS.DAT","rb");
    while(fread(&directorio, sizeof(directorio), 1, puntero_a_archivo)==1)
    {
        aux=(aux+directorio.edad);
    }
    prom=aux/i;
    printf("\nEL PROMEDIO DE LAS EDADES ES: %f\n\n", prom);
    fclose(puntero_a_archivo);
}
