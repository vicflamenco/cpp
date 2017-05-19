#include <iostream>
#include <iomanip>
using namespace std;

#define CAL 5
//     CLASE ALUMNO 
class Alumno{
      private:
              char Nombre[50];
              float Calificaciones[CAL];
              int NumMaterias;
              
      public:
             Alumno(){};
             ~Alumno(){};
             void Ingresar();
             void Mostrar_Nombre();
             void Reporte();          
};

//    DEFINICION DE LOS METODOS DE LA CLASE ALUMNO

void Alumno::Ingresar()
{
     fflush(stdin);
     cout<<"\nIngrese el nombre del estudiante: ";
     gets(Nombre);
     
     int i;
     for (i=0; i<CAL; i++){
         cout<<"\nCalificacion No. "<<i+1<<": ";
         cin>>Calificaciones[i+1];
     }
}

void Alumno::Mostrar_Nombre()
{
     cout<<Nombre;
}

void Alumno::Reporte()
{
    int i;
    cout<<"-------------------------------";
    
    for (i=0; i<CAL; i++)
    {
        cout<<setw(15)<<"Nota "<<i+1<<": "<<Calificaciones[i+1]<<setw(5)<<endl;
    } 
}


//  PROCEDIMIENTO MAIN

int main()
{
    
    int num_est = 0;
    int numero_objeto = 0;
    int opcion;
    char nom[50];
    int i=0;
    int n=0;
    int dim;
    Alumno *p;
    
    cout<<"\nNumero de alumnos de la clase: ";
    cin>>dim;
    cout<<"\n";
    p=new Alumno[dim];
    
    if (p==0){
       cout<<"\nNo hay suficiente memoria.\n";
       return 0; 
    };
    
    // CREAR EL MENU EN PANTALLA
    
    do
    {
             cout<<"\n\t\tMENU \n";
             cout<<"1. Ingresar datos. \n";
             cout<<"2. Ver lista de inscritos. \n";
             cout<<"3. Reporte\n";
             cout<<"4. Salir\n";
             cout<<"----------------------------\n";
             fflush(stdin);
             cout<<"\nSu opcion (1-4): ";
             cin>>opcion;
             
             switch (opcion){
                    case 1:
                         (p+numero_objeto) -> Ingresar();
                         numero_objeto++;
                         system("CLS");
                         break;
                    case 2:
                         cout<<"\n";
                         cout<<"\tLISTADO DE ESTUDIANTES INSCRITOS\n\n";
                         
                         for(i=0;i<numero_objeto;i++)
                         {
                         cout<<"Estudiante "<<i+1<<": ";
                         (p+i) -> Mostrar_Nombre();
                         cout<<"\n";                                                     
                         }
                         cout<<"\n";
                         system("PAUSE");
                         system("CLS");
                         break;
                    case 3:
                         cout<<"Ingrese el numero de lista del estudiante: ";
                         cin>>n;
                         if (n>0){
                                  cout<<"ALUMNO: ";
                                  (p+n-1)->Mostrar_Nombre();
                                  cout<<"\n\n";
                                  cout<<"NOTAS\n";
                                  (p+n-1)->Reporte();
                                  cout<<"\n\n";
                         } else {
                                cout<<"Digite un codigo de alumno valido\n\n";}
                         system("PAUSE");
                         system("CLS");
                         break;
                    case 4:
                         break;
                    default:
                         cout<<"\nIngrese una opcion valida del menu.\n";
                         system("PAUSE");
                         system("CLS");      
             }
 
    } while (opcion!=4);
    delete[] p;

}



