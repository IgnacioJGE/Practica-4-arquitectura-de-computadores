#include <iostream>
#include <mpi.h>
#include <vector>
using namespace std;
int main(int argc, char** argv) {
int rango;
int minum;
int recv_data[4]; //buffer recepción
MPI_Init(&argc, &argv); //inicialización entorno MPI
MPI_Comm_rank(MPI_COMM_WORLD, &rango); //rango del proceso
for (int i=0;i<4;i++){
if(rango==i){
minum= rango +rand()%101;//genero un numero aleatorio del 1 al 100 y se lo sumo al rango de cada proceso para que solo el proceso sepa su numero
}
}

MPI_Allgather(&minum, 1, MPI_INT, &recv_data, 1,
MPI_INT, MPI_COMM_WORLD); //recopilacion y distribución de datos
cout<< "Soy el proceso "<<rango<<" y estos son los numeros que he recibido: ";
for (int i=0;i<4;i++){
cout << recv_data[i]<< " ";//muestro los datos por pantalla

}

cout << endl;
MPI_Finalize(); //fin entorno MPI
return 0;
}
