//PROGRAMA QUE POR MEDIO DE CLASES, FUNCIONES Y PROCEDIMIENTOS, CREA OBJETOS DE TIPO RECTANGULO,
//CALCULA PERIMETRO, AREA, DIAGONALES, MUESTRA DATOS

#include <iostream>
#include <math.h>
using namespace std; 

class Rectangulo{
      private:
              float Base, Altura;
              
      public:
              Rectangulo();
              Rectangulo(float,float);
              void ModificarValores(float,float);
              void Area();      
              void Perimetro();
              void Diagonales();
              void MostrarDatos();  
};

Rectangulo::Rectangulo(){
}
                         
Rectangulo::Rectangulo(float B, float A){
                       Base=B;
                       Altura=A;
}

void Rectangulo::ModificarValores(float B, float A){
     Base=B;
     Altura=A;
}

void Rectangulo::Area(){
         cout<<"\nEl area es: "<<Base*Altura<<".\n";     
         system("PAUSE");     
}

void Rectangulo::Perimetro(){
                        cout<<"\nEl perimetro es: "<<(2*Base)+(2*Altura)<<".\n";
                        system("PAUSE");
}

void Rectangulo::Diagonales(){
                         cout<<"\nLas diagonales del rectangulo son: "<<pow(Base*Base+Altura*Altura,0.5)<<".\n";
                         system("PAUSE");
}

void Rectangulo::MostrarDatos(){
                           cout<<"\n\tDatos del triangulo\n\n";
                           cout<<"Base: "<<Base<<".\nAltura: "<<Altura<<".\n\n";
system("PAUSE");
}
Rectangulo Rect(0,0);
int main(){
    
    int opc;
    float B=0;
    float A=0;
    Rectangulo Rect(B,A);
    do {
       system("CLS");
       cout<<"\n\tMENU\n\n";
       cout<<"1. Crear rectangulo nuevo.\n2. Modificar valores.\n3. Calcular area.\n4. Calcular perimetro.\n";
       cout<<"5. Calcular diagonales.\n6. Mostrar valores.\n7. Salir.\n\n Su opcion: ";
       cin>>opc;
       switch (opc) {
                case 1: {
                     cout<<"\nCreando un rectangulo nuevo. \nBase: ";
                     cin>>B;
                     cout<<"Altura: ";
                     cin>>A;
                     Rect.ModificarValores(B,A);
                break;}
                case 2:
                     cout<<"\nModificando valores del rectangulo.\nBase: ";
                     cin>>B;
                     cout<<"Altura: ";
                     cin>>A;
                     Rect.ModificarValores(B,A);
                break;
                case 3:
                     Rect.Area();
                break;
                case 4:
                     Rect.Perimetro();
                break;
                case 5:
                     Rect.Diagonales();
                break;
                case 6:
                     Rect.MostrarDatos();
                break;
                default:
                break;}
    }while (opc!=7);
    
cout<<"\n\nSaliendo del programa.\n\n";
system("PAUSE");
return 0;   
}
