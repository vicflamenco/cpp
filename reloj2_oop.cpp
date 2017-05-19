// Evaluado Programación II - Período 1
// Reloj que permite: adelantar, retrasar, iniciar, detener, formato de hora
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <windows.h>

using namespace std;

class reloj
{ private:
          int _hh, _mm, _ss;
          int formato;
          bool activo;
  public:
         reloj();
         ~reloj();
         
         void iniciar();
         void tictac();
         void detener();
         
         void adelantar(int, int, int);
         void retrasar(int, int, int);
         
         void cambiarFormato(int);
         
         int hora();
         int minuto();
         int segundo();
};

reloj::reloj()
{
     formato=0; _hh=0; _mm=0; _ss=0; activo=false;
}

reloj::~reloj()
{
}

void reloj::iniciar()
{
       activo = true;
}

void reloj::detener()
{
       activo = false;
}

void reloj::tictac()
{
     if(activo)
     {
         _ss++;
         
         if(_ss>=60)
         {   _ss=0;
             _mm++;
         }
         
         if(_mm>=60)
         {
             _mm=0;
             _hh++;
         }     
         
         if(_hh>=24)
         {
             _hh=0;
         }
     }
}

void reloj::retrasar(int hora, int min, int seg)
{
     
}

void reloj::adelantar(int hora, int min, int seg)
{
     
}

void cambiarFormato(int)
{
         
}

int reloj::hora()
{
    
    return _hh;
}

int reloj::minuto()
{
    return _mm;
}

int reloj::segundo()
{
    return _ss;
}

int main()
{
    int opt=0;
    reloj miReloj;

    while(opt!=6){
    system("cls");
    cout<<"\n*************** Bienvenido ***************";
    cout<<"\n************** Reloj en c++ **************";   
    
    cout<<"\n\nReloj "<<miReloj.hora()<<":"<<miReloj.minuto()<<":"<<miReloj.segundo()<<"\n";
    cout<<"\n\nOpciones del reloj: \n1) Iniciar \n2) Detener \n3) Adelantar \n4) Retrasar \n5) Cambiar formato \n6) Salir \n\nSu opcion: ";

    scanf("%i", &opt);

    switch(opt)
    {
        case 1:
             miReloj.iniciar();
        break;
        
        case 2:
             miReloj.detener();
        break;
    };
    
    miReloj.tictac();
    
    //Sleep(1000);
    };
    
    //system("pause");
}
