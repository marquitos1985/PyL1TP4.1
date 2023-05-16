#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#define CANT_CABECERA 5
#define LARGO_ STRING 12
#define DISTRITOS 5
#define VALIDOS_DATOS 5
#define CANT_CANDIDATOS 4

void imprimirTabla(int filas, int columnas, char cabecera[filas][columnas], int colDistr, int distritos[colDistr], int fil, int col, int votosCandidatos[fil][col]);
int totalVotosCandidato(int validos, int arreglo[]);
float porcentajeVotos(int total, int votos);
int mayorDelArreglo(int validos, int arreglo[]);
void ordenarArreglo(int validos, int arreglo[], char arregloChar[]);


int main() {

    printf("\nNumero random %d", rand()%100);
<<<<<<< HEAD
    printf("\nTP 4.1 EJERCICIO 16\n");
    printf("\nPor Marcos Carrizo");
=======
    printf("\nMARCOS CARRIZO")
>>>>>>> rama1
    int largoString = 12;
    char arregloLetras[CANT_CANDIDATOS] = {'A', 'B', 'C', 'D'};
    char cabecera[5][12] = {"Distrito", "Candidato A", "Candidato B", "Candidato C", "Candidato D"};
    int distritos[DISTRITOS] = {1, 2, 3, 4, 5};
    int votosCandidatos[CANT_CANDIDATOS][VALIDOS_DATOS] = {{194,180,221,432,820}, {48,20,90,51,61}, {206,320,14,821,110}, {45,16,20,14,18}};
    int votosTotalesCandidatos[CANT_CANDIDATOS];
    float porcentajeVotosTotalesCandidatos[CANT_CANDIDATOS];
    int totalVotos = 0;
    int flag = 0;
    int i = 0;


    imprimirTabla(CANT_CABECERA, largoString, cabecera, DISTRITOS, distritos, CANT_CANDIDATOS, VALIDOS_DATOS, votosCandidatos);

    for(int i = 0; i < CANT_CANDIDATOS; i++) {
        votosTotalesCandidatos[i] = totalVotosCandidato(VALIDOS_DATOS, votosCandidatos[i]);
        totalVotos = totalVotos + votosTotalesCandidatos[i];
    }

    for(int i = 0; i < CANT_CANDIDATOS; i++) {
        porcentajeVotosTotalesCandidatos[i] = (float)votosTotalesCandidatos[i]*100/totalVotos;
    }


    printf("\n====== CANDIDATO A ======");
    printf("\nTotal votos: %d.", votosTotalesCandidatos[0]);
    printf("\nPorcentaje de votos: %.2f", porcentajeVotosTotalesCandidatos[0]);
    printf("\n");

    printf("\n====== CANDIDATO B ======");
    printf("\nTotal votos: %d.", votosTotalesCandidatos[1]);
    printf("\nPorcentaje de votos: %.2f", porcentajeVotosTotalesCandidatos[1]);
    printf("\n");


    printf("\n====== CANDIDATO C ======");
    printf("\nTotal votos: %d.", votosTotalesCandidatos[2]);
    printf("\nPorcentaje de votos: %.2f", porcentajeVotosTotalesCandidatos[2]);
    printf("\n");


    printf("\n====== CANDIDATO D ======");
    printf("\nTotal votos: %d.", votosTotalesCandidatos[3]);
    printf("\nPorcentaje de votos: %.2f", porcentajeVotosTotalesCandidatos[3]);
    printf("\n");

    printf("\nEl candidato mas votado es el CANDIDATO %c.", arregloLetras[mayorDelArreglo(CANT_CANDIDATOS, votosTotalesCandidatos)]);


        if(porcentajeVotosTotalesCandidatos[mayorDelArreglo(CANT_CANDIDATOS, votosTotalesCandidatos)] > 50){
            printf("\nEL GANADOR ES EL CANDIDATO %c.", arregloLetras[mayorDelArreglo(CANT_CANDIDATOS, votosTotalesCandidatos)]);
        }else{
            ordenarArreglo(CANT_CANDIDATOS, votosTotalesCandidatos, arregloLetras);
            printf("\nCANDIDATO %c y CANDIDATO %c pasan a 2da ronda.", arregloLetras[3], arregloLetras[2]);
        }



    return 0;
}

//a. Imprimir la tabla anterior con cabeceras incluidas.
void imprimirTabla(int filas, int columnas, char cabecera[filas][columnas], int colDistr, int distritos[colDistr], int fil, int col, int votosCandidatos[fil][col]) {


    for(int i = 0; i < filas; i++) {
        printf("%12s |", cabecera[i]);
    }

    printf("\n");

    for(int i  = 0; i < colDistr; i++) {
        printf("%12d |", distritos[i]);
        for(int j = 0; j < fil; j++) {
            printf("%12d |", votosCandidatos[j][i]);
        }
        printf("\n");
    }
}

//b. Calcular e imprimir el número total de votos recibidos por cada candidato y el porcentaje
//total de votos emitidos. Así mismo, visualizar el candidato más votado.
int totalVotosCandidato(int validos, int arreglo[]) {
    int suma = 0;
    for(int i = 0; i < validos; i++) {
        suma = suma + arreglo[i];
    }
    return suma;
}
float porcentajeVotos(int total, int votos) {
    return ((float)votos*100/total);
}
int mayorDelArreglo(int validos, int arreglo[]) {

    int mayor = arreglo[0];
    int posMayor = 0;
    int i = 1;

    while(i < validos) {
        if(arreglo[i] > mayor) {
            mayor = arreglo[i];
            posMayor = i;
        }
        i++;
    }
    return posMayor;
}
void ordenarArreglo(int validos, int arreglo[], char arregloChar[]){
    int i;
    int aux;
    char auxChar;
    while(validos > 0){
        i = mayorDelArreglo(validos, arreglo);
        aux = arreglo[i];
        auxChar = arregloChar[i];

        arreglo[i] = arreglo[validos-1];
        arregloChar[i] = arregloChar[validos-1];

        arreglo[validos-1] = aux;
        arregloChar[validos-1] = auxChar;

        validos = validos -1;
    }

}
