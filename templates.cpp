#include <iostream>
#include <math.h>
using namespace std;


template <class T>
class Triangulo {
      private:
              T L1,L2,L3;
      public:
             Triangulo(){};
             Triangulo(T La1, T La2, T La3){
                         L1=La1;
                         L2=La2;
                         L3=La3;
             };
             void Dibujar(){
                  cout << endl;
                  cout << "                 *            " << endl ;     
                  cout << "                * *           " << endl ;
                  cout << "               *   *          " << endl ;
                  cout << "     Lado 1   *     *  Lado 2 " << endl ;
                  cout << "             *       *        " << endl ;
                  cout << "            *         *       " << endl ;
                  cout << "           *************      " << endl ;
                  cout << "               Lado 3         " << endl ;
             };
             
             void Calcular_Area(){
                  T Area;
                  Area = pow((((L1+L2+L3)/2)*(((L1+L2+L3)/2)-L1)*(((L1+L2+L3)/2)-L2)*(((L1+L2+L3)/2)-L3)),0.5);
                  cout << endl << " El area es : " << Area << endl ;
              };
              
             void Calcular_Perimetro(){
                  cout << endl << " El perimetro es : " << (L1+L2+L3) << endl ;
             };

};

int main(){

Triangulo <int> T1(2,3,4);
Triangulo <double> T2(250.23,3.151,4.50);
Triangulo <float> T3(2.005,3.12,4.9);
Triangulo <long> T4(200000,300000,450000);
T1.Dibujar();
T1.Calcular_Perimetro();
T1.Calcular_Area();
T2.Calcular_Perimetro();
T2.Calcular_Area();
T3.Calcular_Perimetro();
T3.Calcular_Area();


system("PAUSE");
return 0;
};
