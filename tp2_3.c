#include<stdio.h>
#include<stdlib.h>
#include<time.h>


struct compu {
int velocidad;//entre 1 y 3 GHz
int anio;//entre 2015 y 2023
int cantidad;//entre 1 y 8
char *tipo_cpu; //valores del arreglo tipos
};
typedef struct compu Compu;
void MostrarPCS(Compu PCS[]);
void MostrarPcMasVieja(Compu PCS[]);
void MostrarPcMayorVelocidad(Compu PCS[]);

int main()
{
    srand(time(NULL));
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    int i;
    int arreglo_tipos;
    // arreglo de estructuras para 5 pcs
    Compu PCS[5];

    for(i = 0; i<5 ; i ++)
    {
        //numero = rand () % (N-M+1) + M; Este está entre M y N
        PCS[i].velocidad = rand()% 3  + 1;
        //(2023 - 2015 + 1) = 9
        PCS[i].anio = rand ()% 9 + 2015;
        // (8 - 1 + 1) = 8
        PCS[i].cantidad = rand() % 8 + 1;
        
        arreglo_tipos = rand () % 6 + 0;
        PCS[i].tipo_cpu = tipos[arreglo_tipos];

    }

    MostrarPCS(PCS);
    MostrarPcMasVieja(PCS);
    MostrarPcMayorVelocidad(PCS);

    return 0;

}

void MostrarPCS(Compu mostrar[])
{   int j = 0;
    printf("-----Caracteristicas de las PCs:------ \n");
    for (j = 0; j < 5; j ++)
    {
        printf("///////PC %d://////// \n", j + 1);
        printf("Velocidad : %d\n", mostrar[j].velocidad);
        printf("Anio: %d\n", mostrar[j].anio);
        printf("Cantidad : %d\n", mostrar[j].cantidad);
        printf("Tipo de procesador: %s\n", mostrar[j].tipo_cpu);
    }
}


void MostrarPcMasVieja(Compu mostrar[])
{
  int mayor = 9999;
  int i, j;
  for (i = 0 ; i < 5 ; i ++)
  {
    if(mostrar[i].anio < mayor)
    {
      mayor = mostrar[i].anio;
    }
  }

  for ( j = 0; j < 5 ; j ++)
  {
    if (mostrar[j].anio == mayor)
    {
        printf("///////PC mas vieja %d://////// \n", j + 1);
        printf("Velocidad : %d\n", mostrar[j].velocidad);
        printf("((Anio: %d))\n", mostrar[j].anio);
        printf("Cantidad : %d\n", mostrar[j].cantidad);
        printf("Tipo de procesador: %s\n", mostrar[j].tipo_cpu);
    }
  }
}

void MostrarPcMayorVelocidad(Compu mostrar[])
{   int i , j;
    int mayor=0;
    for ( i=0; i <5 ; i++)
    {
        if(mostrar[i].velocidad > mayor ){
            mayor = mostrar[i].velocidad;
        }

        for( j =0; j <5; j ++)
        {
            if(mostrar[j].velocidad == mayor)
            {
                printf("///////PC de Mayor Velocidad %d://////// \n", j + 1);
                printf("((Velocidad : %d))\n", mostrar[j].velocidad);
                printf("Anio: %d\n", mostrar[j].anio);
                printf("Cantidad : %d\n", mostrar[j].cantidad);
                printf("Tipo de procesador: %s\n", mostrar[j].tipo_cpu);
            }
        }
    }

}








/*#define N 5
#define M 7

int main()
{
int i,j;

srand(time(NULL));
int mt[N][M];
int *punt_m = &mt[0][0];

for(i = 0;i<N; i++)
{
    for(j = 0;j<M; j++)
    {
    *(punt_m + i * M + j)= 1 + rand()% 100;
    printf("%d ", *(punt_m + i * M + j));
    }
    printf("\n");
}


}
*/
