//Kevin Ernesto Gomez Hernandez
//Victor Manuel Flamenco Quijada

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class celular
{
  private:
          char miNumero[9];
          string ultimoMensaje;
          
  public: 
          celular();
          celular(char numero[]);
          ~celular(){};
          
          char *llamar();
          bool contestar(char numero[]);
          string verMensaje();
          string enviarMensaje();
          bool recibirMensaje(char numero[], string mensaje);
          char *verNumero();    
};

celular::celular()
{
 miNumero[0]='\0';
 ultimoMensaje="";
}

celular::celular(char numero[])
{
 for(int i=0; i<8; i++)
         miNumero[i]=numero[i];
 miNumero[8]='\0';
 ultimoMensaje="";
}

char *celular::llamar()
{
 static char numero[9];
 cout<<"\n Digite el numero al que desea llamar: ";
 cin>>numero;
 numero[8]='\0';
 return numero;
}

bool celular::contestar(char numero[])
{
 int equivocado=0;
 for (int i=0; i<8; i++)
     {    if(numero[i]!=miNumero[i])
             equivocado=1;
     }
     if(!equivocado)
        return true;
     else
        return false;
}

char *celular::verNumero()
{
 return miNumero;     
}

bool celular::recibirMensaje(char numero[], string mensaje)
{
 int equivocado=0;
 for(int i=0;i<8;i++)
 { 
  if(numero[i]!=miNumero[i])
  equivocado=1;
 }
 if(!equivocado)
 {
  ultimoMensaje = mensaje;
  return true;
 }
 else
  return false; 
}

string celular::enviarMensaje()
{
 string  mensaje; 
  cout << "Ingrese el mensaje que desea enviar: ";
  cin >> mensaje;
  return mensaje;
}

string celular::verMensaje()
{
 return ultimoMensaje;
}

int main()
{
    int op;
    char numero[8];
    fflush(stdin);
    fflush(stdin);
    celular cell1("75757575"); 
    celular cell2("57575757");
 
    cout<<"  El numero del celular 1 es: "<<cell1.verNumero()<<"\n";
    cout<<"  El numero del celular 2 es: "<<cell2.verNumero()<<"\n";
   
    do
    { 
        
        cout<<"\n \n Menu de celular 1 \n";
        cout<<"\t 1. Llamar \n";
        cout<<"\t 2. Enviar mensaje \n";
        cout<<"\t 3. Leer ultimo mensaje \n";
        cout<<"\t 4. Apagar celular \n";
        
        cout<<"\n Menu de celular 2 \n";
        cout<<"\t 5. Llamar \n";
        cout<<"\t 6. Enviar mensaje \n";
        cout<<"\t 7. Leer ultimo mensaje \n";
        cout<<"\t 8. Apagar celular \n \n Su opcion: ";
        fflush(stdin);
        cin>>op;
         
        switch(op)
        { 
          case 1:
               if(cell2.contestar(cell1.llamar()))
               {cout<<"\n Su llamada fue realizada satisfactoriamente. \n";
               system("pause");
               }
               else
               {cout<<"\n El numero que usted marco es incorrecto. \n";
               system("pause");
               }
          break;
          
          case 2:
                char numero[9];
                cout << "\n Ingrese el numero del celular al que desea enviar el mensaje: ";
                cin >> numero;
                if(cell2.recibirMensaje(numero, cell1.enviarMensaje()))
                {
                cout<<"\n El mensaje fue enviado satisfactoriamente.";
                cout<<"\n El contenido del mensaje enviado es: " + cell2.verMensaje()<<"\n";
                system("pause");
                }
                else
                {cout<<"\n El mensaje no pudo ser enviado. \n";
                system("pause");
                }
          break;
          
          case 3:
                cout<<"\n El ultimo mensaje recibido fue: " + cell1.verMensaje()<<"\n";
                system("pause");
          break;
                          
          case 4:
                system("cls");
                cout<<"\n Su celular se esta apagando....";
                cout<<endl;
                
                cout<<endl;
                system("pause");
                return 0;
          break;

          case 5:
               if(cell1.contestar(cell2.llamar()))
               {cout<<"\n Su llamada fue realizada satisfactoriamente. \n";
               system("pause");
               }
               else
               {cout<<"\n El numero que usted marco es incorrecto. \n";
               system("pause");
               }
          break;
          
          case 6:
                char numero1[9];
                cout << "\n Ingrese el numero del celular al que desea enviar el mensaje: ";
                cin >> numero;
                if(cell1.recibirMensaje(numero, cell2.enviarMensaje()))
                {
                cout<<"\n El mensaje fue enviado satisfactoriamente.";
                cout<<"\n El contenido del mensaje enviado es: " + cell1.verMensaje()<<"\n";
                system("pause");
                }
                else
                {cout<<"\n El mensaje no pudo ser enviado. \n";
                system("pause");
                }
          break;
          
          case 7:
                cout<<"\n El ultimo mensaje recibido fue: " + cell2.verMensaje()<<"\n";
                system("pause");
          break;
                          
          case 8:
                system("cls");
                cout<<"\n Su celular se esta apagando....";
                cout<<endl;
                
                cout<<endl;
                system("pause");
                return 0;
          break;
          
          default:
                cout<<"\n La opcion no es valida \n\n\n"; 
        };                                           
     } while(op!=4 or op!=8);
}

 
