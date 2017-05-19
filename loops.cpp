#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() 
{
    int NumDatos;
    cout << "\n Por favor, digite el numero de alumnos a procesar: ";
    cin >> NumDatos;
    
    if (NumDatos > 0)
    {
        char Carnet[NumDatos][30];
        int Edad[NumDatos], Nota[NumDatos];      
        
        for (int x = 0; x < NumDatos; x++)
        {
            cout << " \n \n Digite el carnet del estudiante " <<x + 1<< ": ";
            fflush(stdin);
            gets(Carnet[x]);
            
            cout << " \n Digite la edad del estudiante "<<x + 1<<": ";
            cin >> Edad[x];
            
            cout << " \n Digite la nota del estudiante "<<x + 1<<": ";
            cin >> Nota[x];
         }
         
        int PromedioTodo = 0, PromedioApro = 0, Contador=0;
        for (int x = 0; x < NumDatos; x++)
        {
            PromedioTodo +=  Nota[x];
            
            if (Nota[x] >= 6)
            {
               PromedioApro +=  Nota[x];
               Contador ++;
            }
        }
        
        PromedioTodo = PromedioTodo / NumDatos;
        PromedioApro = PromedioApro / Contador;
        
        // ordenando notas
             
        for (int y=0; y < NumDatos; y++){
            for (int z=0; z < NumDatos; z++){
                     int a, b; char Carnet_O[30], Carnet_O2[30];
                     
                     if (Nota[y] < Nota[z]){
                                   a = Nota[y]; b = Nota[z];
                                   Nota[z] = a; Nota[y] = b;

                                   a = Edad[y]; b = Edad[z];
                                   Edad[z] = a; Edad[y] = b;
                                   
                                   strcpy(Carnet_O, Carnet[y]);
                                   strcpy(Carnet_O2, Carnet[z]);
                                   
                                   strcpy(Carnet[z], Carnet_O);
                                   strcpy(Carnet[y], Carnet_O2);
                                 }
                }
            }
        
               
        cout<< "\n \n  - El promedio de las notas es: "<<PromedioTodo<<"\n";
        cout<< " - El promedio de los aprobados es: "<<PromedioApro<<"\n \n";
        
        for (int x = 0; x < NumDatos; x++)
        {
            cout<<"\n Alumno "<<x + 1<<": \n \t Carnet: "<<Carnet[x]<<"\n \t Edad: "<<Edad[x]<<"\n \t Nota: "<<Nota[x]<<"\n";
        }
        system("pause");
    } 
    else
    {
        cout << "\n El numero no es valido porque es menor o igual que cero.";
    }
       
}
       
