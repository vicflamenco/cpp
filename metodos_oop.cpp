#include <iostream>
#include <conio.h>
using namespace std;

class Paralelepipedo 
{
      private:
              //atributos del paralelepipedo
              float alto;
              float ancho;
              float largo;
              double volumen;
      public:
             //constructor con parametros
             Paralelepipedo(float,float,float);
             //funcion que calcula el volumen del paralelepipedo
             double calcular_volumen();
      
};
Paralelepipedo::Paralelepipedo(float x, float y, float z)
{
//asignar los valores de los parametros a las variables
     this->alto=x;
     this->ancho=y;
     this->largo=z;                                                                
}
double Paralelepipedo::calcular_volumen()
{
       this->volumen=this->alto*this->ancho*this->largo; //calcular el volumen  V=b*a*h
       return this->volumen;      
}
int main()
{
    Paralelepipedo objeto1 = Paralelepipedo(10,5,10); //instanciar un objeto de la clase Paralelepipedo
    cout<<"volumen de objeto 1: "<<objeto1.calcular_volumen(); 
    getch();
}
