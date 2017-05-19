#include <iostream>
using namespace std;

int main()

{
    int *ptr_array_1, *ptr_array_2, n;
    cout<<"Ingrese el numero de elementos de los arreglos"<<endl;
    cin>>n;
    
    int array_1[n], array_2[n], array_f[n];
    ptr_array_1 = array_1;
    ptr_array_2 = array_2;
    cout << "***** Llenando arreglo 1 *****"<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<"Ingrese el elemento " << i+1 <<": ";
        cin>> array_1[i];
        }
    cout<<endl;
    cout<<"***** Llenando arreglo 2 *****"<<endl;
    for (int i=0; i<n;i++)
    {
        cout<<"Ingrese el elemento "<<i+1<<": ";
        cin>> array_2[i];
        }
    cout <<endl;
    system("PAUSE");
    system("CLS");
    cout<<"***** Imprimiendo la suma del arreglo 1 + arreglo 2 *****"<<endl;
    for (int i=0; i<n;i++)
    {
        array_f[i] = *(ptr_array_1 + i) + *(ptr_array_2 + i);
        cout << "["<<array_f[i]<<"] ";
        }
    cout<<endl;
    system("PAUSE");
    return(0);
}
