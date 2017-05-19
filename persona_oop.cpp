#include <iostream>
#include <iomanip> 
#include <string.h>
using namespace std;

class Persona 
{ 
      protected:
                char nombre[40];
                int edad;
      public:
               Persona( ) { };
               void leerdatos( );
               void imprimirdatos( );
               void ImprimirNombre();
};


void Persona :: leerdatos( )
{ 
     cout << "\t\tNombre: ";
     fflush(stdin);
     gets(nombre);
     cout<<"\n\n"<< nombre;
     cout << "\t\tEdad: ";
     cin >> edad;
};


void Persona :: imprimirdatos( )
{ 
    cout << endl << endl;
    cout << "----- Imprimir los Datos del Empleado -----" << endl;
    cout << "Nombre : " << nombre << endl;
    cout << "Edad : " << edad << " a";
    printf("%c",164); // Para mostrar la letra "ñ"
    cout << "os" << endl;
};

void Persona :: ImprimirNombre(){
     cout << "Nombre: " << nombre;
};



class Empleado : public Persona
{ 
    protected:
            float salarioanual;
            char cargo[60];
    public:
            Empleado( ){ }; 
            void leeremp( );
            void imprimiremp( );
};



void Empleado :: leeremp( )
{ 
    Persona::leerdatos();
    cout << "\t\tCargo: ";
    cin >> cargo;
    cout << "\t\tSueldo: $";
    cin >> salarioanual;
}

void Empleado :: imprimiremp( )
{ 
    Persona :: imprimirdatos( );
    cout << "Cargo del empleado: " << cargo << endl;
    cout << "Sueldo anual empleado: $ " << fixed << showpoint << setprecision(2) << salarioanual << endl;
}

class Estudiante : public Persona
{
      protected:
                char Numcarnet[8];
                char NivelEstudios[50];
      public:
                Estudiante(){}
                void LeerEstudiante();
                void ImprimirEstudiante();
};

void Estudiante :: LeerEstudiante(){

    cout << "\t\tNo. Carnet: ";
    fflush(stdin);
    gets(Numcarnet);
    cout << "\t\tNivel de Estudios: ";
    fflush(stdin);
    gets(NivelEstudios);

};

void Estudiante :: ImprimirEstudiante(){
     Persona::imprimirdatos();
     cout<<"No. Carnet: " << Numcarnet << "\n";
     cout<<"Nivel de Estudios: " << NivelEstudios;
};

class Universitario : public Estudiante
{
      protected:
             char Universidad[50];
             char Carrera[50];
             int nMaterias;
             char Materias[][50];
             float Notas[];
             float CUM;
             float Promedio;
      public:
             Universitario(){};
             void LeerUniversitario();
             void ImprimirUniversitario();
             void ImprimirProm();
};

void Universitario :: LeerUniversitario(){
     Estudiante::LeerEstudiante();
     cout<<"\t\tUniversidad: ";
     fflush(stdin);
     gets(Universidad);
     cout<<"\t\tCarrera: ";
     fflush(stdin);
     gets(Carrera);
     cout<<"\t\tCUM: ";
     cin>>CUM;
     float suma;
     cout<<"\t\tNumero de Materias Inscritas: ";
     cin>>nMaterias;
     
     for (int i=0; i<nMaterias; i++){
         cout<<"\t\t\t Materia "<<i+1<<"\n\t\t\t\tNombre: ";
         fflush(stdin);
         gets(Materias[i]);
         cout<<"\t\t\t\tNota: ";
         cin>>Notas[i];
         cout<<"\n";
         suma+=Notas[i];
     }
     Promedio=suma/nMaterias;
};

void Universitario :: ImprimirUniversitario(){
     Estudiante::ImprimirEstudiante();
     cout<<"Universidad: " << Universidad;
     cout<<"Carrera: " << Carrera;
     cout<<"CUM: " << CUM;
     cout<<"Promedio: " << Promedio;
};

void Universitario:: ImprimirProm(){
     cout<<"Promedio: " << Promedio;

};

class Pasante : public Universitario, public Empleado
{
      protected:
             char NombreProyecto[50];
             int TotalHoras, HorasCom;   
      public:
             Pasante(){};
             void LeerPasante();
             void ImprimirPasante();
};

void Pasante :: LeerPasante(){
     Empleado::leeremp();
     Universitario::LeerUniversitario();
     cout<<"\t\tNombre del Proyecto: ";
     fflush(stdin);
     gets(NombreProyecto);
     cout<<"\t\tTotal de Horas: ";
     cin>>TotalHoras;
     cout<<"\t\tHoras Completadas: ";
     cin>>HorasCom;
};

void Pasante:: ImprimirPasante(){
     Universitario::ImprimirNombre();
     cout<<"\n";
     Universitario::ImprimirProm();
};


int main( )
{ 
    int N;
    Pasante *P;
    
    int opt;
    
    do {
        system("CLS");
        cout<<"\n\t\tMENU DE SELECCION\n\n\t1. Ingresar pasantes \n\t2. Verificar universidad dominante";
        cout<<"\n\t3. Promedio de notas \n\t4. Salir\n\n\tOpcion <1-4>: ";
        cin>>opt;
        cout<<"\n\n";
        switch (opt){
        
        case 1:
             {
                     cout<<"\tNumero de Pasantes: ";
                     cin>>N;
                     cout<<"\n";
                     P = new Pasante[N];
                     for (int i=0; i<N; i++){
                         cout<<"\n\n\tPasante No. " << i+1 << "\n\n";
                         P[i].LeerPasante();
                     }
                     cout<<"\n\n";
                     system("PAUSE");                     
             break;
             }
        
        case 2: 
             {
             
             break;
             }
        case 3:
             {
                   for (int i=0;i<N;i++){
                       cout<<"\tPasante "<<i+1;
                       P[i].ImprimirPasante();
                       cout<<"\n";
                   }
                   cout<<"\n\n";
                   system("PAUSE"); 
             break;      
             }
        case 4:
             {
             cout<<"\tSaliendo del programa.\n\n";
             break;
             }
        default:
                {
                break;
                }
        };
    }while (opt!=4);
   
   
    system("pause>nul");
    return 0;
}
