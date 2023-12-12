#include <iostream>
#include <mpi.h>
#include <vector>
#include <math.h>
using namespace std;
int main(int argc, char** argv) {
int rango;
int size;
int minum;
int minum_final;

vector<int> mis_nums;// fila de la matriz inicial
MPI_Init(&argc, &argv); //inicialización entorno MPI
MPI_Comm_rank(MPI_COMM_WORLD, &rango); //rango del proceso
MPI_Comm_size(MPI_COMM_WORLD, &size);//numero de procesos
int numero = atoi(argv[1]);//guardo el numero que recibo por argumento
int recv_data[size];//recv_data tiene que ser un array de tamaño= al size
while (numero > 0) {
mis_nums.insert(mis_nums.begin(), numero % 10);
numero /= 10;
}//inserto el numero en un vector para poder recorrerlo y operar con cada bit
for (int i=0; i<size;i++){
if(rango==i){
minum= (mis_nums[size-i-1])*pow(2,rango);//multiplico la posicion del vector que le corresponde por 2^rango
}
}
MPI_Allgather(&minum, 1, MPI_INT, &recv_data, 1,
MPI_INT, MPI_COMM_WORLD); //comparto los resultados entre todos
minum=0;
for (int i=0;i<size;i++){//realizo la suma para terminar la conversiona decimal
minum= minum+recv_data[i];

}

cout <<minum<< endl;

MPI_Finalize(); //fin entorno MPI
return 0;
}
