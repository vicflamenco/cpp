#include <iostream>
#include <string.h>
using namespace std;

class Biblioteca {
      
      public:
             char Codigo[8];
      protected:
             char Identificar[10];
             char Titulo[50];
             char Autor [50];
             int Year; //año
             char Editorial[50];
      public:
             Biblioteca(){};
             virtual void Visualizar(){};
};



class Libro : public Biblioteca {
      protected:
                
      public:
             Libro(char *,char *,char *,char *,int,char *);
             void Visualizar();
};

Libro :: Libro (char Iden[], char Tit[], char Cod[], char Aut[], int Anio, char Edit[]){
      strcpy(Identificar,Iden);
      strcpy(Titulo,Tit);
      strcpy(Codigo,Cod);
      strcpy(Autor, Aut);
      Year=Anio;
      strcpy(Editorial,Edit);
}; 


void Libro :: Visualizar () {
     cout << endl << "Codigo de " << Identificar << ": " << Codigo << endl;
     cout << "Titulo: " <<  Titulo << endl;
     cout << "Autor: " << Autor << endl;
     cout << "Editorial: " << Editorial;
     cout << "Anio: " << Year << endl << endl;
};


class Revista : public Biblioteca {
      protected:
                
      public:
             Revista(char*,char*,char*,char*,int,char*);
             void Visualizar();
};

Revista :: Revista (char Iden[], char Tit[], char Cod[], char Aut[], int Anio, char Edit[]){
      strcpy(Identificar,Iden);
      strcpy(Titulo,Tit);
      strcpy(Codigo,Cod);
      strcpy(Autor, Aut);
      Year=Anio;
      strcpy(Editorial,Edit);
}; 


void Revista :: Visualizar () {
     cout << endl << "Codigo de " << Identificar << ": " << Codigo << endl;
     cout << "Titulo: " <<  Titulo << endl;
     cout << "Autor: " << Autor << endl;
     cout << "Editorial: " << Editorial;
     cout << "Anio: " << Year << endl << endl;
};


class Articulo : public Biblioteca{
      protected:
                
      public:
             Articulo(char*,char*,char*,char*,int,char*);
             void Visualizar();
};

Articulo :: Articulo (char Iden[], char Tit[], char Cod[], char Aut[], int Anio, char Edit[]){
      strcpy(Identificar,Iden);
      strcpy(Titulo,Tit);
      strcpy(Codigo,Cod);
      strcpy(Autor, Aut);
      Year=Anio;
      strcpy(Editorial,Edit);
}; 

void Articulo :: Visualizar () {
     cout << endl << "Codigo de " << Identificar << ": " << Codigo << endl;
     cout << "Titulo: " <<  Titulo << endl;
     cout << "Autor: " << Autor << endl;
     cout << "Editorial: " << Editorial;
     cout << "Anio: " << Year << endl << endl;
};

int Comparar(char Cad1[], char Cad2[]);

int main(){


    Biblioteca * Objetos[100];
        
     int opt,tipo;
     int nObjeto=0;
     char Identificar[10];
     char Titulo[50];
     char Codigo[8];
     char Autor [50];
     int Year; //año
     char Editorial[50];
    
    do {
    
    system("CLS");
    cout << endl << "\t\t MENU PRINCIPAL " << endl << endl;
    cout << "\t1. Crear Objeto " << endl << "\t2. Visualizar Objeto" << endl << "\t3. Salir" << endl << endl;
    cout << "\t\t Su opcion <1-3>: ";
    cin >> opt;
    
    
    switch (opt) {
           
           case 1:
                {
                   do {
                           cout << endl << endl << "\t\t Tipo de objeto: " << endl << endl;
                           cout << "\t1. Libro" << endl << "\t2. Revista" << endl << "\t3. Articulo" << endl << endl;
                           cout << "\t\tTipo <1-3>: ";
                           cin >> tipo;
                   } while (tipo!=1 && tipo!=2 && tipo!=3);
                   
                   cout << endl << endl << "\t\tIngresando datos" << endl << endl << "\tCodigo: ";
                   fflush (stdin);
                   gets(Codigo);
                   cout << endl << "\tTitulo: ";
                   fflush (stdin);
                   gets(Titulo);
                   cout << endl << "\tAutor: ";
                   fflush (stdin);
                   gets(Autor);
                   cout << endl << "\tEditorial: ";
                   fflush(stdin);
                   gets(Editorial);
                   cout << endl << "\tAnio: ";
                   cin>>Year;
              
                   switch (tipo) {
                          case 1:
                               {
                                           strcpy(Identificar,"Libro");
                                           Libro L(Identificar,Titulo,Codigo,Autor,Year,Editorial);
                                           Objetos[nObjeto]= &L;
                                           break;
                               };
                          case 2:
                               {
                                         strcpy(Identificar,"Revista");
                                         Revista R(Identificar,Titulo,Codigo,Autor,Year,Editorial);
                                         Objetos[nObjeto]= &R;
                                         break;
                               };
                          case 3:
                               {
                                         strcpy(Identificar,"Articulo");
                                         Articulo A(Identificar,Titulo,Codigo,Autor,Year,Editorial);
                                         Objetos[nObjeto]= &A;
                                         break;
                               };
                          default:
                               {break;
                               };
                               
                   };
                   nObjeto++;
                   
                   cout << endl << endl << "\tObjeto creado con exito. " << endl << endl <<"\t";
                   system("PAUSE");
                   
                   break;
                };
           case 2:
                {
                
                char Cod[8];
                int IndiceEncontrado;
                int Encontrado = 0;
                cout << endl << endl << "\tCodigo del objeto: ";
                fflush(stdin);
                gets(Cod);
                          cout << "nObjeto = " << nObjeto << endl;
                         for (int i=0; i<=nObjeto; i++){
                             if (Encontrado==0){
                                
                                cout << "BUSCADO: "<< Cod << "     OBJETO ACTUAL: " << Objetos[i]->Codigo << endl;
                                Encontrado = Comparar(Objetos[i]->Codigo,Cod);
                                if (Encontrado==1) {
                                   IndiceEncontrado=i;
                                }                            
                             }
                         };
                         if (Encontrado==1){
                            cout << endl << endl << "\t\tDatos del Objeto:" << endl << endl;
                            Objetos[IndiceEncontrado]->Visualizar();
                         } else if (Encontrado==0) {
                           
                           cout << endl << endl << "\t\tObjeto no encontrado.";
                         };
                         cout << endl << endl << "\t";
                         system("PAUSE");    
                break;      
                };
           case 3:
                {
                cout << endl << endl << "\tSaliendo del programa" << endl << endl << "\t";
                break;
                };
           default:
                   {
                   break;
                   };
    }; 
    } while (opt!=3);

    system("PAUSE");
    return 0;
};



int Comparar(char Cad1[], char Cad2[]){
     
     int Igual=1;
     
     for (int j=0; j<=8; j++) {
         
         if (Cad1[j]!=Cad2[j]) {
            Igual=0;
         }
     };
     
     return Igual;

};
