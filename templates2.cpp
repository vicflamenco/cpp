#include<iostream>
using namespace std;

template<class T>
void potencia(T);

int main()
{
    int x1=4;
    float y1=8.23;
    double z1=6.233455465;
    
    potencia(x1);
    potencia(y1);
    potencia(z1);
    
    system("pause");
    return 0;
}

template<class T>
void potencia(T x)
{
     cout<<"El cuadrado de "<<x<<" es: "<<x*x<<""<<endl;
}
