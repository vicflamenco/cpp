#include <iostream>
#include <stdlib.h>
using namespace std;
//LA CLASE 'COMBUSTIBLE' ADMINISTRA LOS TRES TIPOS DE COMBUSTIBLES POSIBLES: REGULAR, ESPECIAL, DIESEL
class Combustible{
      private:
              float Galones; //CAPACIDAD DEL TANQUE
              float Precio; //PRECIO POR GALON DE COMBUSTIBLE
      public:
             Combustible(); //CONSTRUCTOR POR OMISION
             Combustible(float,float); //CONSTRUCTOR CON PARAMETROS
             ~Combustible(); //DESTRUCTOR
             void VerificarNivel(); //PROCEDIMIENTO QUE DEVUELVE LOS GALONES RESTANTES EN EL TANQUE
             void VerificarPrecio(); //PROCEDIMIENTO QUE DEVUELVE EL PRECIO POR GALON DEL COMBUSTIBLE
             void SurtirGalones(float); //PROCEDIMIENTO QUE DESPACHA UNA CANTIDAD DE GALONES ESPECIFICA
             void SurtirMonto(float); //PROCEDIMIENTO QUE DESPACHA UNA CANTIDAD DE GALONES, EN BASE A UN MONTO DE DINERO
             void ModificarPrecio(float); //PROCEDIMIENTO UTILIZADO PARA MODIFICAR EL PRECIO POR GALON DE COMBUSTIBLE
};

Combustible::Combustible(float G, float P){
   this->Galones=G;
   this->Precio=P;
};

void Combustible::VerificarNivel(){
     cout<<"\tCombustible restante: "<<(this->Galones)<<" galones.\n\n\t";     
};

void Combustible::VerificarPrecio(){
     cout<<"\tPrecio por Galon: $"<<(this->Precio)<<"\n\n\t";
};

void Combustible::SurtirGalones(float G){
     
     float Total;
     //VERIFICAR QUE LA CANTIDAD DE GALONES RESTANTES EN EL TANQUE SEA SUFICIENTE PARA PODER SURTIR
     if ((this->Galones)<G){
        cout<<"\tNo hay suficiente combustible.\n\tSe surtira la cantidad que sea posible.\n\n";
        G=this->Galones; //SI NO HAY SUFICIENTE COMBUSTIBLE, SE SURTIRA SOLAMENTE LA CANTIDAD DE GALONES QUE HAYA DISPONIBLES
     }
        
     this->Galones=(this->Galones)-G; //RESTAR LA CANTIDAD DE GALONES SURTIDOS, DE LA CANTIDAD DE GALONES DEL TANQUE
     Total=G*(this->Precio); //CALCULAR VENTA TOTAL
     cout<<"\t\tFactura de Ventas\n\n";
     cout<<"\tGalones Surtidos:\t"<<G<<"\n\tPrecio por Galon:\t$"<<(this->Precio)<<"\n\tVenta Total:\t\t$"<<Total<<"\n\n\t";
};

void Combustible::SurtirMonto(float M){
     
     float G,Total;
     G = M/(this->Precio); //CALCULAR NUMERO DE GALONES EN BASE AL MONTO Y AL PRECIO POR GALON
     
     //VERIFICAR SI HAY SUFICIENTES GALONES PARA PODER SURTIR
     //SI NO HAY SUFICIENTE COMBUSTIBLE, SE SURTE LA CANTIDAD DISPONIBLE SOLAMENTE
     if ((this->Galones)<G){
        cout<<"\tNo hay suficiente combustible.\n\tSe surtira la cantidad que sea posible.\n\n";                    
        G=this->Galones;}
     
     this->Galones=(this->Galones)-G; //RESTAR GALONES SURTIDOS, DE LA CANTIDAD DE GALONES DEL TANQUE
     Total=G*(this->Precio); //CALCULAR VENTA TOTAL
     cout<<"\n\t\tFactura de Ventas\n\n";
     cout<<"\tGalones Surtidos:\t"<<G<<"\n\tPrecio por Galon:\t$"<<(this->Precio)<<"\n\tVenta Total:\t\t$"<<Total<<"\n\n\t";
};

void Combustible::ModificarPrecio(float P){
     this->Precio=P;
};

void MenuBombas(); //PROCEDIMIENTO QUE MUESTRA EN PANTALLA EL MENU PARA ELEGIR UNA BOMBA DE LAS DISPONIBLES
void MenuCombustibles(); //PROCEDIMIENTO QUE MUESTRA EN PANTALLA EL MENU PARA ELEGIR UN TIPO DE COMBUSTIBLE: REGULAR, ESPECIAL, DIESEL

int main(){

Combustible *Diesel,*Regular,*Especial; //CREAR OBJETOS DE TIPO 'COMBUSTIBLE'
Diesel = new Combustible(800,3.25);
Regular = new Combustible(800,3.50);
Especial = new Combustible(600,3.95);

int opt,Bomba,C;
float M,G;

do{
      //MOSTRAR MENU PRINCIPAL EN PANTALLA
   system("CLS");
   cout<<"\n\t\tESTACION DE SERVICIO\n\n";
   cout<<"\t1. Verificar nivel de combustible.\n";
   cout<<"\t2. Verificar precio por galon.\n";
   cout<<"\t3. Surtir pedido en monto de dinero.\n";
   cout<<"\t4. Surtir un pedido en numero de galones.\n";
   cout<<"\t5. Salir.\n\n";
   cout<<"\t\tSu opcion <1-5>: ";
   cin>>opt;

   switch (opt) {
          case 1:
               {
                        cout<<"\n\n";
                        cout<<"--------------------------------------------------------\n";
                        MenuCombustibles(); //MOSTRAR EL MENU DE ELECCION DE TIPO DE COMBUSTIBLE
                        cin>>C;
                        cout<<"\n\n"; 
                        cout<<"--------------------------------------------------------\n";
                        /*   C=1 -> ESPECIAL
                             C=2 -> REGULAR
                             C=3 -> DIESEL    */
                        if (C==1){
                           Especial->VerificarNivel();
                        } else if (C==2){
                           Regular->VerificarNivel();
                        } else if (C==3) {
                           Diesel->VerificarNivel();
                        }
                        cout<<"\n--------------------------------------------------------\n\n\t";
                        system("PAUSE");
                        break;}
          case 2:
               {
                        cout<<"\n\n";
                        cout<<"--------------------------------------------------------\n";
                        MenuCombustibles(); //MOSTRAR EL MENU DE ELECCION DE TIPO DE COMBUSTIBLE
                        cin>>C;
                        cout<<"\n\n";
                        cout<<"--------------------------------------------------------\n";
                        /*   C=1 -> ESPECIAL
                             C=2 -> REGULAR
                             C=3 -> DIESEL    */
                        int Resp;
                        float P;
                        if (C==1){
                           Especial->VerificarPrecio();
                        } else if (C==2){
                           Regular->VerificarPrecio();
                        } else if (C==3) {
                           Diesel->VerificarPrecio();
                        }
                        cout<<"\n--------------------------------------------------------\n";
                        do {cout<<"\n\tDesea modificar el precio por galon?\n\n\t1. Si\n\t2. No\n\n\tSu opcion <1-2>: ";
                        cin>>Resp;
                        }while (Resp<1||Resp>2);
                        
                        switch (Resp){
                               case 1: 
                                       cout<<"\n\n\tNuevo precio: $";
                                       cin>>P;
                                       if (C==1){
                                           Especial->ModificarPrecio(P);
                                        } else if (C==2){
                                           Regular->ModificarPrecio(P);
                                        } else if (C==3) {
                                           Diesel->ModificarPrecio(P);
                                        }
                                       cout<<"\n\n\tPrecio Modificado\n\n"; 
                                       break;
                               case 2:
                                    break;
                               default:
                                       
                                       break;
                      }
               cout<<"--------------------------------------------------------\n\n\t";
               system("PAUSE");
               break;}
          
          case 3:
               {
                        cout<<"\n\n";
                        cout<<"--------------------------------------------------------\n";
                        MenuBombas(); //MOSTRAR EL MENU DE ELECCION DE BOMBA A UTILIZAR
                        cin>>Bomba;
                        cout<<"\n\n";
                        cout<<"--------------------------------------------------------\n";
                        MenuCombustibles(); //MOSTRAR EL MENU DE ELECCION DE TIPO DE COMBUSTIBLE
                        cin>>C;
                        cout<<"\n\n"; 
                        cout<<"--------------------------------------------------------\n";
                        /*   C=1 -> ESPECIAL
                             C=2 -> REGULAR
                             C=3 -> DIESEL    */
                        cout<<"\tMonto de dinero a surtir: $";
                        cin>>M;
                        cout<<"\n";
                        cout<<"--------------------------------------------------------\n";
                        if (C==1){
                           Especial->SurtirMonto(M);
                        } else if (C==2){
                           Regular->SurtirMonto(M);
                        } else if (C==3) {
                           Diesel->SurtirMonto(M);
                        }      
                    cout<<"\n--------------------------------------------------------\n\n\t";
                    system("PAUSE");
                    break;}
          case 4:
               {
                        cout<<"\n\n";
                        cout<<"--------------------------------------------------------\n";
                        MenuBombas(); //MOSTRAR EL MENU DE ELECCION DE BOMBA A UTILIZAR
                        cin>>Bomba;
                        cout<<"\n\n";
                        cout<<"--------------------------------------------------------\n";
                        MenuCombustibles(); //MOSTRAR EL MENU DE ELECCION DE TIPO DE COMBUSTIBLE
                        cin>>C;
                        cout<<"\n\n"; 
                        cout<<"--------------------------------------------------------\n";
                        /*   C=1 -> ESPECIAL
                             C=2 -> REGULAR
                             C=3 -> DIESEL    */
                        cout<<"\tNumero de galones a surtir: ";
                        cin>>G;
                        cout<<"\n";
                        cout<<"--------------------------------------------------------\n";
                        if (C==1){
                           Especial->SurtirGalones(G);
                        } else if (C==2){
                           Regular->SurtirGalones(G);
                        } else if (C==3) {
                           Diesel->SurtirGalones(G);
                        }      
                    cout<<"\n--------------------------------------------------------\n\n\t";
                    system("PAUSE");
                    break;}
                    
               default:
                       {break;}
   };

} while(opt!=5);

cout<<"\n\n";
cout<<"--------------------------------------------------------\n";
cout<<"\t";
system("PAUSE");
return 0;
}

void MenuBombas(){
     cout<<"\t\tBombas disponibles\n\n";
     cout<<"\t1. Bomba 1 \n";
     cout<<"\t2. Bomba 2 \n";
     cout<<"\t3. Bomba 3 \n";
     cout<<"\t4. Bomba 4 \n";
     cout<<"\t5. Bomba 5 \n";
     cout<<"\t6. Bomba 6 \n\n";
     cout<<"\t\tSu bomba <1-6>: ";
};

void MenuCombustibles(){
     cout<<"\t\tTipos de Combustibles\n\n";
     cout<<"\t1. Gasolina Especial \n";
     cout<<"\t2. Gasolina Regular \n";
     cout<<"\t3. Diesel \n\n";
     cout<<"\t\tEleccion <1-3>: ";   
};
