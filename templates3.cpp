#include<iostream>
#include<math.h>
using namespace std;

template<class T>
class triangulo
{
      private:
              T l1, l2, l3, s, area, v, p;
      public:
             void calcular_semiperimetro(T a, T b, T c);
             void calcular_area();
             void calcular_perimetro();
             void dibujar_triangulo();
             void mostrar_datos();
             void dibujar();
};

template<class T>
void triangulo<T>::calcular_semiperimetro(T a, T b, T c)
{
     l1=a;
     l2=b;
     l3=c;
     s=(l1+l2+l3)/2;
}

template<class T>
void triangulo<T>::calcular_area()
{
     v=s*(s-l1)*(s-l2)*(s-l3);
     if(v>0){
     area=sqrt(v);}
     else{
     cout<<"verifique los datos que ha ingresado"<<endl;
     system("pause");
     system("cls");}
}

template<class T>
void triangulo<T>::calcular_perimetro()
{
     p=s*2;
}

template<class T>
void triangulo<T>::mostrar_datos()
{
     cout<<"El area del triangulo es: "<<area<<""<<endl;
     cout<<"El semi perimetro es: "<<s<<""<<endl;
     cout<<"El perimetro del triangulo es: "<<p<<""<<endl;
}


template<class T>
void triangulo<T>::dibujar()
{
cout << endl;
cout << "                 *            " << endl ;     
cout << "                * *           " << endl ;
cout << "               *   *          " << endl ;
cout << "     Lado 1   *     *  Lado 2 " << endl ;
cout << "             *       *        " << endl ;
cout << "            *         *       " << endl ;
cout << "           *************      " << endl ;
cout << "               Lado 3         " << endl ;

}



main()
{
    triangulo <int> obj1;
    triangulo <float> obj2;
    triangulo <double> obj3;
    triangulo <long> obj4;
    
    obj2.calcular_semiperimetro(3, 4, 5);
    obj2.calcular_area();
    obj2.calcular_perimetro();
    obj2.mostrar_datos();
    obj2.dibujar();
    
    system("pause");
    return 0;
}
