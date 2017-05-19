#include <iostream>
#include <math.h>
using namespace std;
class Triangulo
{
      private:
              float Base, Altura, Lado1, Lado2, Lado3;
      public:
             Triangulo();
             Triangulo(float,float,float,float,float);
             ~Triangulo();
             
             float CalcularArea(); //FUNCION PARA CALCULAR EL AREA (METODO 1)
             float CalcularArea2(); //FUNCION PARA CALCULAR EL AREA (METODO 2)
             float CalcularPerimetro();
             void ImprimeAtributos();
             void ActualizaAtributos(float,float,float,float,float);
             };

//DECLARACION DEL METODO CONSTRUCTOR POR OMISION            
Triangulo::Triangulo()
{
}
//DECLARACION DEL METODO CONSTRUCTOR CON PARAMETROS
Triangulo::Triangulo(float B, float A, float L1, float L2, float L3)
{                          
    Altura=A;
    Base=B;
    Lado1=L1;
    Lado2=L2;
    Lado3=L3;
}
//DECLARACION DEL METODO DESTRUCTOR POR OMISION
Triangulo::~Triangulo()
{
             cout<<"\nSe esta destruyendo el objeto.\n\n";                    
}

//METODO QUE CALCULA EL AREA DE UN TRIANGULO
float Triangulo::CalcularArea()
{
      return (Base*Altura/2);      
}

float Triangulo::CalcularArea2(){
      float s,a;
      //CALCULAMOS EL SEMIPERIMETRO 'S'
      s=(Lado1+Lado2+Lado3)/2;
      //APLICAMOS FORMULA DE HERON:  AREA = SQRT( s*(s-a)*(s-b)*(s-c) )
      a =  pow (  (s*(s-Lado1)*(s-Lado2)*(s-Lado3))    , 0.5 );
      return a;
      
      
}

//METODO QUE DESPLIEGA LOS VALORES DE LOS ATRIBUTOS
void Triangulo::ImprimeAtributos()
{
     cout<<"\n\nLos atributos actuales del triangulo son:\nLado 1: "<<Lado1<<"\nLado 2: "<<Lado2<<"\nLado 3: "<<Lado3<<"\n\n";
     
     }
     
//METODO QUE MODIFICA LOS VALORES DE LA BASE Y DE LA ALTURA DEL TRIANGULO
void Triangulo::ActualizaAtributos(float A, float B, float L1, float L2, float L3)
{
     Base=B;
     Altura=A;
     Lado1=L1;
     Lado2=L2;
     Lado3=L3;
}
//PROCEDIMIENTO QUE CALCULA EL PERIMETRO DEL TRIANGULO
float Triangulo::CalcularPerimetro(){
         return (Lado1+Lado2+Lado3);                    
}
//CREAMOS UN TRIANGULO QUE SEA PUBLICO, CON VALORES NULOS (INICIALIZAR UN TRIANGULO POR DEFECTO)
Triangulo Trian(0,0,0,0,0);
int main()
{
    int opt,tipo;
    float B,A,L1,L2,L3; //BASE, ALTURA, Y LOS TRES LADOS DEL TRIANGULO
    do
    { //CREAMOS EL MENU INTERACTIVO EN PANTALLA
    system("CLS");
    cout<<"\n\tMENU\n\n";
    cout<<"1. Crear triangulo.\n2. Modificar valores.\n3. Calcular el area.\n4. Calcular perimetro.\n5. Salir del programa.\n\n";
    cout<<"Seleccion <1-5>: ";
    cin>>opt;
    
    //VERIFICAMOS LA OPCION ELEGIDA POR EL USUARIO
    switch (opt){
           case 1:
                //CREAR UN TRIANGULO NUEVO
                system("CLS");
                do {
                    cout<<"\nSeleccione el tipo de triangulo: <1-3>\n\n1. Equilatero.\n2. Isoceles.\n3. Escaleno.\n\n";
                    cin>>tipo;
                              if (tipo==1){ //TRIANGULO EQUILATERO
                                 cout<<"\n\nTriangulo equilatero.\nValor de los lados: ";
                                 cin>>L1;
                                 L2=L1;
                                 L3=L1;
                                 Trian.ActualizaAtributos(0,0,L1,L2,L3);
                              } else if (tipo==2){ //TRIANGULO ISOCELES
                                 cout<<"\n\nTriangulo Isoceles.\nValor de dos lados iguales: ";
                                 cin>>L1;
                                 cout<<"\n\nValor del lado desigual: ";
                                 cin>>L2;
                                 L3=L1;
                                 Trian.ActualizaAtributos(0,0,L1,L2,L3);       
                              } else if (tipo==3) {//TRIANGULO ESCALENO
                                 cout<<"\n\nTriangulo Escaleno.\nValor del lado 1: ";
                                 cin>>L1;
                                 cout<<"\nValor del lado 2: ";
                                 cin>>L2;
                                 cout<<"\nValor del lado 3: ";
                                 cin>>L3;
                                 Trian.ActualizaAtributos(0,0,L1,L2,L3);    
                              }
                    } while (tipo<1 || tipo>3);
                break;
           case 2:
                //MODIFICAR VALORES DEL TRIANGULO
                Trian.ImprimeAtributos();
                cout<<"Ingrese los nuevos atributos del triangulo:\nLado 1: ";
                cin>>L1;
                cout<<"Lado 2: ";
                cin>>L2;
                cout<<"Lado 3: ";
                cin>>L3;
                Trian.ActualizaAtributos(0,0,L1,L2,L3);
                break;
           case 3:
                //CALCULAR EL AREA DEL TRIANGULO
                
                int metodo;
                //PREGUNTAMOS AL USUARIO QUE METODO DESEA UTILIZAR
                do
                {
                cout<<"\n\nSeleccione el metodo para calcular el area: <1-2>\n";
                cout<<"1. Ley de cosenos e identidad trigonometrica Seno.\n2. Formula de Heron.\n";
                cin>>metodo;
                }while (metodo!=1&&metodo!=2);
                
                switch (metodo){
                       
                case 1:
                     
                             //PRIMER METODO PARA ENCONTRAR EL AREA:
                                  //ENCONTRANDO LA ALTURA, MEDIANTE LEY DE COSENOS E IDENTIDAD TRIGONOMETRICA SENO.
                    
                    
                            //Se tomara como Base del triangulo el Lado 3.
                            
                            B = L3;
                            //Para encontrar la altura, se necesita encontrar el angulo que se forma entre el lado 2 y el lado 3.
                            //Para ello, se utiliza la ley de cosenos.
                            //c^2 = a^2 + b^2 - 2ab*cos(C), despejamos el angulo 'C'.
                            
                            float ang;
                            ang=acos(((L2*L2)+(L3*L3)-(L1*L1))/(2*L2*L3));
                            //Ahora que sabemos el angulo, utilizando la funcion trigonometrica seno, hallamos la altura 'h'
                            A = L2*sin(ang);
                            Trian.ActualizaAtributos(A,B,L1,L2,L3);
                            cout<<"\nEl area del triangulo es: "<<Trian.CalcularArea()<<"\n\n";
                            system("PAUSE");
                            break;
                     
                case 2:
                                  //SEGUNDO METODO PARA ENCONTRAR EL AREA:
                                            //FORMULA DE HERON
                                  //PRIMERO ENCONTRAMOS EL SEMIPERIMETRO
                                  
                                  float s;
                                  s=(L1+L2+L3)/2;
                                  
                            cout<<"\nEl area del triangulo es: "<<Trian.CalcularArea2()<<"\n\n";
                            system("PAUSE");
                            break;

                     break;
                default:
                        break;       
                }
                
                
                break;
           case 4:
                //CALCULAR EL PERIMETRO DEL TRIANGULO
                cout<<"\nEl perimetro del triangulo: "<<Trian.CalcularPerimetro()<<"\n\n";
                system("PAUSE");               
                break;
           case 5:
                cout<<"\n\nSaliendo del programa...\n";
                break;
           default:
                break;      
    }

    }   while(opt!=5);
    
    system("PAUSE");
    return 0;
}
