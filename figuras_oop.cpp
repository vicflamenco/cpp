#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class triangulo
{
 private:
         float lado1, lado2, lado3, base, altura;
         int tipoTriangulo; // 0=equilatero, 1=isósceles, 2=escaleno
 public:
        triangulo();
        triangulo(float, float, float, int); //Todos los atributos para ser inicializados
        
        ~triangulo(); //Destructor
        
        float calcularAreaBaseAltura(); //Primer metodo
        float calcularAreaPorSemiPerimetro(); //Segundo metodo
        float calcularPerimetro();
        void ModificarDatos();
        void ImprimirDatos();
        int tipoT();
        
};

triangulo::triangulo()
{
      lado1=0;
      lado2=0;
      lado3=0;
      base=0;
      altura=0;
}

triangulo::triangulo(float a, float b, float c, int tipo)
{
      lado1=a;
      lado2=b;
      lado3=c;
      
      if (tipo<=1)
      {
       base = lado1/2;
       altura = sqrt((pow(lado2,2)) - (pow(base,2)));
      }
}

triangulo::~triangulo()
{
}

int triangulo::tipoT()
{
    return tipoTriangulo;
}

float triangulo::calcularAreaBaseAltura()
{
      cout<<lado1;
      return (base*altura)/2;
}

float triangulo::calcularAreaPorSemiPerimetro()
{
      float p=0;
      p = (lado1+lado2+lado3)/2; // Este es el semiperimetro
      return sqrt(p*(p-lado1)*(p-lado2)*(p-lado3));
}

float triangulo::calcularPerimetro()
{
      return (lado1+lado2+lado3);
}

void triangulo::ModificarDatos()
{
     float _bas, _lad, _lad1, _lad2, _lad3;
     switch(tipoTriangulo)
     {
      case 0:
           cout<<"\n \nModificando datos: \nSu triangulo es equilatero. \n\tEl valor de sus lados es: "; cin>>_lad;
           lado1=_lad;
           lado2=_lad;
           lado3=_lad;
      break;
      
      case 1:
           cout<<"\n \nModificando datos: \nSu triangulo es isosceles. \n\tEl valor de su base es: "; cin>>_bas;
           cout<<"\n\tEl valor de su otros dos lados es: "; cin>>_lad;
           lado1=_bas;
           lado2=_lad;
           lado3=_lad;
      break;
      
      case 2:
           cout<<"\n \nModificando datos: \nSu triangulo es escaleno. \n\tEl valor de lado 1 es: "; cin>>_lad1;
           cout<<"\n\tEl valor de lado 2 es: "; cin>>_lad2;
           cout<<"\n\tEl valor de lado 3 es: "; cin>>_lad3;
           lado1=_lad1;
           lado2=_lad2;
           lado3=_lad3;
      break;
      
     }
     
     if (tipoTriangulo<=1)
      {
       base = lado1/2;
       altura = sqrt((pow(lado2,2)) - (pow(base,2)));
      }  
}

void triangulo::ImprimirDatos()
{
     cout<<"El lado 1 es: "<<lado1<<"\nEl lado 2 es: "<<lado2<<"\nEl lado 3 es: "<<lado3;
     if (tipoTriangulo<=1)
     cout<<"\nLa base es: "<<base<<"\nLa altura es: "<<altura;
}

int main()
{
    triangulo miTriangulo;
    char opt[1];
    do
    { 
      cout<<"\n\n*************** Operaciones con triangulos en C++ ***************\n";
      cout<<"                                /\\ \n";
      cout<<"                               /  \\ \n";
      cout<<"                              /    \\ \n";
      cout<<"                             /      \\ \n";
      cout<<"                            /        \\ \n";
      cout<<"                            ---------- \n";
      cout<<" a) Crear triangulo.\n b) Modificar triangulo. \n c) Calcular area de dos maneras. \n d) Calcular perimetro.\n e) Salir. \n \nSu opcion: ";
      cin>>opt;
      
      switch(opt[0])
      {
       case 'a':
            {
            int t=0;
            
            cout<<"\n \nSeleccione el tipo de triangulo: \n 1) Equilatero.\n 2) Isosceles \n 3) Escaleno \n \nSu opcion: ";     
            cin>>t;
            float _lado1, _lado2, _lado3;
            
            switch(t)
            {
             case 1:
                  {
                  cout<<"\n\n Digite el valor de cada lado: "; cin>>_lado1;
                  triangulo miTriangulo(_lado1, _lado1, _lado1, t-1);
                  break;
                  }
             case 2:
                  {
                  cout<<"\n\n Digite el valor de la base: "; cin>>_lado1;
                  cout<<"\n\n Digite el valor de los otros dos lados: "; cin>>_lado2;
                  triangulo miTriangulo(_lado1, _lado2, _lado2, t-1);
                  break;
                  }
             
             case 3:
                  
                  cout<<"\n\n Digite valor del lado 1: "; cin>>_lado1;
                  cout<<"\n\n Digite valor del lado 2: "; cin>>_lado2;
                  cout<<"\n\n Digite valor del lado 3: "; cin>>_lado3;
                  
                  triangulo miTriangulo(_lado1, _lado2, _lado3, t-1);
             break;    
            }
            break;
            }
       case 'b':
            miTriangulo.ModificarDatos();
       break;
       
       case 'c':
           if(miTriangulo.tipoT() <= 1)
           {
            cout<<"\n \nEl area (base*altura) es: "<<miTriangulo.calcularAreaBaseAltura();
            cout<<"\nEl area (por semiperimetro) es: "<<miTriangulo.calcularAreaPorSemiPerimetro();
           }
      }
      
      cout<<endl; 
      system("pause");
    }while(opt[0]!='e');
}
