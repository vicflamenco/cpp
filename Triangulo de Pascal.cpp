#include <iostream>
#include <conio.h>

using namespace std;

int dibujartriangulo(int h);
int h,n,i,j;
int trian[100][100]={0};

int main()
{
    system("cls");
    
    do {
        cout<<"Ingrese el grado del triangulo [1-100] = \n";
        cin>>h;
        }
    while (h<1 || h>100);
    
    system("cls");
    cout<<"El triangulo de Pascal definido es: \n";
    
    dibujartriangulo(h);
    system("pause");
    }
    
    int dibujartriangulo(int h)
    {
        n=(2*h)-1;
        trian[0][h-1]=1;
        for (i=1;i<=h;i++)
        { for (j=h+1-i;j<=i-h+n;j++)
        { trian[i][j]=trian[i-1][j-1]+trian[i-1][j+1];
        }
        }
    for (i=1; i<=h;i++){
        for (j=1;j<=n;j++)
        { if (trian[i][j] != 0)
        { if (h<10)
        { if (trian[i][j] >9)
             cout<<trian[i][j];
        else
             cout<<" "<<trian[i][j];
             }
        else
            if (trian[i][j]>9)
            cout<<trian[i][j];
            else
            cout<<" "<<trian[i][j];
            }
            else
            {cout<<" ";
            }
            }
            cout<<endl;
            }
            }
    
    
    
    
    
    
    
    
    
    
    
    
    
