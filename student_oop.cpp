//Porcentajes 30%, 35%, 35%
//60% Teoria, 40% Laboratorio

#include <iostream>
#include <cstring>

using namespace std;

class alumno
{ private:
          string nombre, carnet, asignaturas[5];
          float notasTeo[5][3], notasLab[5][3];
  public:
         alumno();
         ~alumno(){};
         
         string cod_carnet();
         
         void ingresarAlumno();
         void ingresarNotas();
         void mostrarDatos();            
};

alumno::alumno()
{
 nombre = ""; carnet = ""; 
 for(int x=0; x<=4; x++)
 {
  asignaturas[x] = "";      
  notasTeo[x][0] = 0;
  notasLab[x][0] = 0; 
  
  notasTeo[x][1] = 0;
  notasLab[x][1] = 0; 
  
  notasTeo[x][2] = 0;
  notasLab[x][2] = 0; 
 }
}

string alumno::cod_carnet()
{
 return carnet;       
}

void alumno::ingresarAlumno()
{
 cout<<"\n\tIngrese el nombre del estudiante: ";
 fflush(stdin);
 cin>>nombre;
 
 cout<<"\n\tIngrese el carnet del estudiante: ";
 fflush(stdin);
 cin>>carnet;
 
 for(int x=0; x<=4; x++)
 {
  cout<<"\n\tIngrese el nombre de la asignatura "<<x+1<<": ";
  fflush(stdin);
  cin>>asignaturas[x];       
 }

 cout<<"\n\nEl estudiante fue registrados satisfactoriamente."<<endl;
 system("pause");
}

void alumno::ingresarNotas()
{
 cout<<"\n\nIngresando notas...";

 for(int x=0; x<=4; x++)
 {
  cout<<"\n\nAsignatura: "<<asignaturas[x];
  cout<<"\n\tNota teorica periodo 1 (60%):"; cin>>notasTeo[x][0];
  cout<<"\n\tNota laboratorio periodo 1 (40%):"; cin>>notasLab[x][0];
  
  cout<<"\n\tNota teorica periodo 2 (60%):"; cin>>notasTeo[x][1];
  cout<<"\n\tNota laboratorio periodo 2 (40%):"; cin>>notasLab[x][1];
  
  cout<<"\n\tNota teorica periodo 3 (60%):"; cin>>notasTeo[x][2];
  cout<<"\n\tNota laboratorio periodo 3 (40%):"; cin>>notasLab[x][2];
 }
 
 cout<<"\n\nLas notas fueron registradas satisfactoriamente."<<endl;
 system("pause");
}

void alumno::mostrarDatos()
{
 cout<<"\nEstudiante "<<nombre<<": "; 
 for(int x=0; x<5; x++)
 {                     
  cout<<"\n\nAsignatura "<<asignaturas[x]<<": ";
  cout<<"\n\tNota teorica periodo 1 (60%):"; notasTeo[x][0];
  cout<<"\n\tNota laboratorio periodo 1 (40%):"; notasLab[x][0];
  cout<<"\n\tPromedio periodo 1: "<<((notasTeo[x][0])*0.6 + (notasLab[x][0])*0.4);
  
  cout<<"\n\n\tNota teorica periodo 2 (60%):"; notasTeo[x][1];
  cout<<"\n\tNota laboratorio periodo 2 (40%):"; notasLab[x][1];
  cout<<"\n\tPromedio periodo 2: "<<((notasTeo[x][1])*0.6 + (notasLab[x][1])*0.4);
  
  cout<<"\n\n\tNota teorica periodo 3 (60%):"; notasTeo[x][2];
  cout<<"\n\tNota laboratorio periodo 3 (40%):"; notasLab[x][2];
  cout<<"\n\tPromedio periodo 3: "<<((notasTeo[x][2])*0.6 + (notasLab[x][2])*0.4);
  
  cout<<"\n\n\tPromedio final: "<<((notasTeo[x][2])*0.6 + (notasLab[x][2])*0.4)*0.35 + ((notasTeo[x][1])*0.6 + (notasLab[x][1])*0.4)*0.35 + ((notasTeo[x][0])*0.6 + (notasLab[x][0])*0.4)*0.3;
  
 }
 cout<<endl;
 system("pause");
}

int main()
{
 int nDatos=0, pos=0;

 cout<<"\n***************Sistema de control de notas***************";   
 cout<<"\n\nIngrese el numero de alumnos que manejara el sistema: "; cin>>nDatos;
 
 alumno *misAlumnos;
 
 misAlumnos = new alumno[nDatos];

 int opt; bool encontrado=false;
 string cad="";
 do
  {
     encontrado = false;
     
     cout<<"\n\nMenu del sistema: ";
     cout<<"\n1) Ingresar datos de nuevo alumno";
     cout<<"\n2) Ingresar notas de un alumno";
     cout<<"\n3) Mostrar datos reporte de notas de un alumno";
     cout<<"\n4) Salir \n \nSu opcion: ";
     fflush(stdin);
     cin>>opt;
     
     
     switch(opt)
     {
      case 1: 
           if (pos >= nDatos)
              {
               cout<<"\n\nHa llegado al maximo de usuarios."<<endl; system("pause");
              }
           else
           {
            (misAlumnos+pos)->ingresarAlumno();
            pos++;
           }
      break;
      
      case 2:
           cout<<"\n\nIngrese el carnet del estudiante: "; fflush(stdin); cin>>cad;
           
           for (int p=0;p<nDatos;p++)
           {
               if (cad.compare((misAlumnos+p)->cod_carnet())==0)
               {
                encontrado = true;
                (misAlumnos+p)->ingresarNotas();
               }
           }
           
           if (encontrado==false)
              {
              cout<<"\n\nEl alumno no fue encontrado"<<endl; 
              system("pause");
              }
      break;

      case 3:
           cout<<"\n\nIngrese el carnet del estudiante: "; fflush(stdin); cin>>cad;
           
           for (int p=0;p<nDatos;p++)
           {
               if (cad.compare((misAlumnos+p)->cod_carnet())==0)
               {
                encontrado = true;
                (misAlumnos+p)->mostrarDatos();
               }
           }
           
           if (encontrado==false)
              {
              cout<<"\n\nEl alumno no fue encontrado"<<endl; 
              system("pause");
              }
      break;
                       
     }
     
  }while (opt!=4);

}
