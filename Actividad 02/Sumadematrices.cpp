#include <iostream>

using namespace std;

void sumarM(int *pmt1,int *pmt2, int rows, int columns);
void agregarM(int *pmt,int rows, int columns);
void mostrarSuma(int *pmt1,int rows,int columns);
int nRows, nColumns;
int main (){
    cout<<"ingrese en numero de filas: "<<endl;
    cin>>nRows;
    cout<<"Ingrese el numero de columnas: "<<endl;
    cin>>nColumns;
    int mat1[nRows][nColumns];
    int mat2[nRows][nColumns];
    cout<<"\nIngrese los datos de la primera matriz: "<<endl;
    agregarM(*mat1,nRows,nColumns);
    cout<<"\nIngrese los datos de la segunda matriz: "<<endl;
    agregarM(*mat2,nRows,nColumns);
    sumarM(*mat1,*mat2,nRows,nColumns);
    mostrarSuma(*mat1,nRows,nColumns);
    return 0;
}
void agregarM(int *pmt,int rows, int columns){
	for(int i=0;i<rows;i++){
		for(int j=0;j<columns;j++){
			cout<<"Digite un numero["<<i<<"]["<<j<<"]: ";
			cin>>*(pmt+i*columns+j);
		}
	}
}
void sumarM(int *pmt1,int *pmt2,int rows, int columns){
    for(int i=0;i<rows;i++){
		for(int j=0;j<columns;j++){
			*(pmt1+i*columns+j) += *(pmt2+i*columns+j);  
		}
	}
}
void mostrarSuma(int *pmt1,int rows,int columns){
	cout<<"\nLa suma de ambas matrices es: "<<endl;
	for(int i=0;i<rows;i++){
		for(int j=0;j<columns;j++){
			cout<<*(pmt1+i*columns+j)<<" ";
		}
		cout<<endl;
	}
}