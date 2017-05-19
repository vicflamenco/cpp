// Evaluado Programación II - Período 1
// Reloj que permite: adelantar, retrasar, iniciar, detener, formato de hora
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <windows.h>

using namespace std;

class reloj //CLASE RELOJ
{ private:
          int _hh, _mm, _ss;
          int formato;
          bool activo; //VARIABLE BOOLEANA QUE DETERMINA SI EL RELOJ ESTA ACTIVO O NO
  public:
         reloj();//CONSTRUCTOR POR OMISION
         ~reloj();//DESTRUCTOR
         
         //PROCEDIMIENTOS
         void iniciar(); //INICIAR RELOJ
         void tictac(); //ESPERAR UN SEGUNDO
         void detener(); //DETENER EL RELOJ
         
         void adelantar(int, int, int); //ADELANTAR EL RELOJ
         void retrasar(int, int, int); //RETRASAR EL RELOJ
         
         void cambiarFormato(int); //CAMBIO DE FORMATO ENTRE 12 Y 24 HORAS
         void imprimirReloj(); //MUESTRA EL RELOJ EN PANTALLA
         
         //VARIABLES ENTERAS PARA EL MANEJO DEL TIEMPO
         int hora();
         int minuto();
         int segundo();
};

reloj::reloj() //CONSTRUCTOR POR OMISION
{
     formato=0; _hh=12; _mm=0; _ss=0; activo=false;
}

reloj::~reloj() //DESTRUCTOR
{
}

void reloj::iniciar() //ACTIVAR EL RELOJ
{
       activo = true;
}

void reloj::detener() //DESACTIVAR EL RELOJ
{
       activo = false;
}

void reloj::tictac() //ESPERAR UN SEGUNDO
{
     if(activo)
     {
         _ss++;
         //SUMAR UN MINUTO CADA 60 SEGUNDOS
         if(_ss>=60)
         {   _ss=0;
             _mm++;
         }
         //SUMAR UNA HORA CADA 60 MINUTOS
         if(_mm>=60)
         {
             _mm=0;
             _hh++;
         }     
         //REGRESAR EL VALOR DE LAS HORAS A CERO CUANDO SE LLEGA A 24 HORAS
         if(_hh>=24)
         {
             _hh=0;
         }
     }
}

void reloj::retrasar(int hora, int min, int seg) //
{
     bool exito=false;
     
     if(hora<=_hh)       
        {_hh += -hora; exito = true;}
         
     if(min<=_mm)       
        {_mm += -min; exito = true;}
         
     if(seg<=_ss)       
        {_ss += -seg; exito = true;}
         
     if (exito==true)
     {cout<<"\n\nEl reloj fue retrasado\n";}
     else
     {cout<<"\n\nEl reloj no fue retrasado porque los datos que ingreso no son validos\n";}
     
     //imprimirReloj();
     system("pause");
}

void reloj::adelantar(int hora, int min, int seg)
{       
     _hh += hora;   
     _mm += min;
     _ss += seg;
     
     cout<<"\n\nEl reloj fue adelantado\n";
     //imprimirReloj();
     system("pause");
}

void reloj::cambiarFormato(int num)
{
     formato = num;
     
     cout<<"\n\nEl formato fue cambiado.\n";
     system("pause");
}

void reloj::imprimirReloj()
{
     if(formato==1)
     {
      cout<<_hh<<":"<<_mm<<":"<<_ss<<"\n";
     }
     else if(formato==0)
     {
         if(_hh==0)
         {
            cout<<_hh+12<<":"<<_mm<<":"<<_ss<<" A.M.\n"; 
         }
         else if(_hh==12)
         {
            cout<<_hh<<":"<<_mm<<":"<<_ss<<" P.M.\n"; 
         }
         else if (_hh>12)
         {
              cout<<_hh-12<<":"<<_mm<<":"<<_ss<<" P.M.\n";
         }
         else
         {
             cout<<_hh<<":"<<_mm<<":"<<_ss<<" A.M\n";
         }
     }
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
    char op[1];
    reloj miReloj;
    
    miReloj.iniciar(); //INICIAR EL RELOJ
    do{
    system("cls"); //LIMPIAR LA PANTALLA
    
    cout<<"\n*************** Bienvenido ***************";
    cout<<"\n************** Reloj en c++ **************";   

    cout<<"\n\nLa hora es: ";
    miReloj.imprimirReloj();//MOSTRAR EL RELOJ EN PANTALLA
    
    cout<<"\n\nOpciones del reloj: \n1) Iniciar \n2) Detener \n3) Adelantar \n4) Retrasar \n5) Cambiar formato \n6) Refrescar reloj \n7) Salir \n\nSu opcion: ";
    //cout<<""<<""<<""<<""<<""<<""<<"";
    cin>>opt;
    
    Sleep(1000);
    //gets(op);  
    
    //scanf("%i", &opt);
    
    //ELEGIR OPCION DEPENDIENDO DEL MENU
    switch(opt)
    {
        case 1:
             miReloj.iniciar();
        break;
        
        case 2:
             miReloj.detener();
        break;
        
        case 3:
             {//PARA ADELANTAR EL RELOJ
             int _h=0,_m=0,_s=0;
             
             cout<<"\n\n Horas a adelantar: "; cin>>_h;
             cout<<"\n Minutos a adelantar: "; cin>>_m;
             cout<<"\n Segundos a adelantar: "; cin>>_s;
             
             miReloj.adelantar(_h,_m,_s);
             break;
             }
        case 4: //PARA ATRASAR EL RELOJ
             {
             int _h=0,_m=0,_s=0;
             
             cout<<"\n\n Horas a retrasar: "; cin>>_h;
             cout<<"\n Minutos a retrasar: "; cin>>_m;
             cout<<"\n Segundos a retrasar: "; cin>>_s;
             
             miReloj.retrasar(_h,_m,_s);
             break;
             }
        
        case 5:
             {//PARA CAMABIAR EL FORMATO A LA HORA
             int _f=0;
             cout<<"\n\nSeleccione un formato de hora \n1) Formato 24 horas \n2) Formato AM/PM \n\nSu opcion: ";
             cin>>_f;
             
             miReloj.cambiarFormato(_f);
             break;
             }
    };
    
    miReloj.tictac();
    
    
    }while(opt!=7);
    
    //system("pause");
}
