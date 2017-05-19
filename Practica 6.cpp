//Porcentajes 30%, 35%, 35%
//60% Teoria, 40% Laboratorio

#include <iostream>
#include <cstring>

using namespace std;
//CLASE ALUMNO
class alumno
{ private:
          //ATRIBUTOS DE LA CLASE
          string nombre, carnet, asignaturas[5];
          float notasTeo[5][3], notasLab[5][3];
  public:
         alumno(); //CONSTRUCTOR POR DEFECTO
         ~alumno(){}; //DESTRUCTOR
         
         string cod_carnet(); // CODIGO DE CARNET
         
         //METODOS DE LA CLASE
         void ingresarAlumno();
         void ingresarNotas();
         void mostrarDatos();            
};

alumno::alumno()
{
 this->nombre = ""; this->carnet = ""; 
 for(int x=0; x<=4; x++)
 {
 //ASIGNAR A CERO TODAS LAS NOTAS
  this->asignaturas[x] = "";      
  this->notasTeo[x][0] = 0;
  this->notasLab[x][0] = 0; 
  
  this->notasTeo[x][1] = 0;
  this->notasLab[x][1] = 0; 
  
  this->notasTeo[x][2] = 0;
  this->notasLab[x][2] = 0; 
 }
}

string alumno::cod_carnet()
{
 return this->carnet;       
}

void alumno::ingresarAlumno()
{
 cout<<"\n\tIngrese el nombre del estudiante: ";
 fflush(stdin);
 cin>>this->nombre;
 
 cout<<"\n\tIngrese el carnet del estudiante: ";
 fflush(stdin);
 cin>>this->carnet;
 
 for(int x=0; x<=4; x++)
 {
  cout<<"\n\tIngrese el nombre de la asignatura "<<x+1<<": ";
  fflush(stdin);
  cin>>this->asignaturas[x];       
 }

 cout<<"\n\nEl estudiante fue registrados satisfactoriamente."<<endl;
 system("pause");
}

void alumno::ingresarNotas()
{
 cout<<"\n\nIngresando notas...";

 for(int x=0; x<=4; x++) //RECORRER CADA MATERIA INSCRITA
 {
              //SOLICITAR NOTAS DEL PRIMER PERIODO
  cout<<"\n\nAsignatura: "<<this->asignaturas[x];
  cout<<"\n\tNota teorica periodo 1 (60%):"; cin>>this->notasTeo[x][0];
  cout<<"\n\tNota laboratorio periodo 1 (40%):"; cin>>this->notasLab[x][0];
                  //SOLICITAR NOTAS DEL SEGUNDO PERIODO
  cout<<"\n\tNota teorica periodo 2 (60%):"; cin>>this->notasTeo[x][1];
  cout<<"\n\tNota laboratorio periodo 2 (40%):"; cin>>this->notasLab[x][1];
                  //SOLICITAR NOTAS DEL TERCER PERIODO
  cout<<"\n\tNota teorica periodo 3 (60%):"; cin>>this->notasTeo[x][2];
  cout<<"\n\tNota laboratorio periodo 3 (40%):"; cin>>this->notasLab[x][2];
 }
 
 cout<<"\n\nLas notas fueron registradas satisfactoriamente."<<endl;
 system("pause");
}

void alumno::mostrarDatos()
{
 cout<<"\nEstudiante "<<this->nombre<<": "; 
 for(int x=0; x<5; x++)
 {                     
  cout<<"\n\nAsignatura "<<this->asignaturas[x]<<": ";
  //MOSTRAR NOTAS PRIMER PERIODO 
  cout<<"\n\tNota teorica periodo 1 (60%):"; this->notasTeo[x][0];
  cout<<"\n\tNota laboratorio periodo 1 (40%):"; this->notasLab[x][0];
  cout<<"\n\tPromedio periodo 1: "<<((this->notasTeo[x][0])*0.6 + (this->notasLab[x][0])*0.4);
  //MOSTRAR NOTAS SEGUNDO PERIODO
  cout<<"\n\n\tNota teorica periodo 2 (60%):"; this->notasTeo[x][1];
  cout<<"\n\tNota laboratorio periodo 2 (40%):"; this->notasLab[x][1];
  cout<<"\n\tPromedio periodo 2: "<<((this->notasTeo[x][1])*0.6 + (this->notasLab[x][1])*0.4);
  //MOSTRAR NOTAS TERCER PERIODO 
  cout<<"\n\n\tNota teorica periodo 3 (60%):"; this->notasTeo[x][2];
  cout<<"\n\tNota laboratorio periodo 3 (40%):"; this->notasLab[x][2];
  cout<<"\n\tPromedio periodo 3: "<<((this->notasTeo[x][2])*0.6 + (this->notasLab[x][2])*0.4);
  //CALCULAR Y MOSTRAR NOTA PROMEDIO
  cout<<"\n\n\tPromedio final: "<<((this->notasTeo[x][2])*0.6 + (this->notasLab[x][2])*0.4)*0.35 + ((this->notasTeo[x][1])*0.6 + (this->notasLab[x][1])*0.4)*0.35 + ((this->notasTeo[x][0])*0.6 + (this->notasLab[x][0])*0.4)*0.3;
  if ((((this->notasTeo[x][2])*0.6 + (this->notasLab[x][2])*0.4)*0.35 + ((this->notasTeo[x][1])*0.6 + (this->notasLab[x][1])*0.4)*0.35 + ((this->notasTeo[x][0])*0.6 + (this->notasLab[x][0])*0.4)*0.3)>= 6)
  { cout<<"\n\t****Aprobada****";
  }
  else
  { cout<<"\n\t****Reprobada****";
  }
 }
 cout<<endl;
 system("pause");
}

int main()
{
 int nDatos=0, pos=0;

 cout<<"\n***************Sistema de control de notas***************";   
 cout<<"\n\nIngrese el numero de alumnos que manejara el sistema: "; cin>>nDatos;
 //PUNTERO A OBJETO ALUMNO
 alumno *misAlumnos;
 //INSTANCIACION
 misAlumnos = new alumno[nDatos];

 int opt; bool encontrado=false;
 string cad="";
 do
  {
     encontrado = false;
     //MOSTRAR MENU EN PANTALLA AL USUARIO
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
           //VERIFICAR SI YA SE INGRESARON TODOS LOS ALUMNOS
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
           //BUSCAR UN ESTUDIANTE
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
