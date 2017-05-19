//PROGRAMA QUE SUMA DOS MATRICES DE DOS FILAS Y TRES COLUMNAS

#include <cstdlib>
#include <iostream>
using namespace std;

int A[2][3];
int B[2][3];

main()
{
    int x,y;
    //LLENAR MATRIZ "A"
    cout<<"\nIngrese los valores  de la matriz A:\n\n";
    for (x=0;x<=1;x++) {
        cout<<"\tFila "<<x+1<<":\n";
        for (y=0;y<=2;y++) {
            cout<<"\t\tColumna "<<y+1<<": ";
            cin>>A[x][y];
            }
        }
    //LLENAR MATRIZ "B"
    cout<<"\nIngrese los valores  de la matriz B:\n\n";
    for (x=0;x<=1;x++) {
        cout<<"\tFila "<<x+1<<":\n";
        for (y=0;y<=2;y++) {
            cout<<"\t\tColumna "<<y+1<<": ";
            cin>>B[x][y];
            }
        }
    system("cls");    
    //MOSTRAR MATRICES INGRESADAS
    int m,n;
    cout<<"\n\n\nMatriz A:\n";
    for (m=0;m<=1;m++) {
        cout<<"\n";
        for (n=0;n<=2;n++) {
            cout<<A[m][n]<<"\t";
            }
        }
       cout<<"\n\n\nMatriz B:\n";
        for (m=0;m<=1;m++) {
            cout<<"\n";
            for (n=0;n<=2;n++) {
                cout<<B[m][n]<<"\t";
                }
            } 
    
    cout<<"\nA + B = \n\n";
    
    for (x=0;x<=1;x++) {
        for(y=0;y<=2;y++) {
                          
             cout<<A[x][y]+B[x][y]<<"\t";              
                          }
             cout<<"\n";
        
        }
    
    system("PAUSE");
    return (0);
}
