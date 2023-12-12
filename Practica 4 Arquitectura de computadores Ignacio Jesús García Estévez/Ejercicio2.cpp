#include <iostream>
#include <mpi.h>
#include <vector>
using namespace std;
int main(int argc, char** argv) {
int rango;
int minum;
int recv_data[4]; //buffer recepción
int matriz[4][4]={{1 ,2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12},{13, 14, 15, 16}};//matriz inicial
int mis_nums[4];// fila de la matriz inicial
MPI_Init(&argc, &argv); //inicialización entorno MPI
MPI_Comm_rank(MPI_COMM_WORLD, &rango); //rango del proceso
for (int i=0;i<4;i++){//segun el proceso que sea le voy guardando cada fila de mi matriz
if(rango==i){
for(int j=0;j<4;j++){
mis_nums[j]=matriz[i][j];
}
}
}
MPI_Alltoall(&mis_nums, 1, MPI_INT, &recv_data, 1,
MPI_INT, MPI_COMM_WORLD);//envio y recibo datos diferentes de mi arrat a todos los procesos

for (int i=0;i<4;i++){//imprimo mis datos recibidos 
cout<< recv_data[i]<< " ";
}
cout << endl;

MPI_Finalize(); //fin entorno MPI
return 0;
}
