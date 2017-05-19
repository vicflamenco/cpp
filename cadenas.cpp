#include <iostream>
#include <string.h> // Para las funciones de manejo de cadenas: strcpy, strlen y strcat
using namespace std;
class Cadena
{ private:
int longitud; // longitud de la cadena
char *ptrCadena; // Puntero a la cadena de caracteres
public:
Cadena (char [ ]= ""); //constructor predeterminado
Cadena (Cadena &); //constructor por copia
~Cadena(); //destructor
int long_cadena (); //devuelve longitud de la cadena
// Funciones para sobrecarga de operadores
Cadena & operator + (Cadena &); //concatenación
/* Sobrecarga de los operadores de manejo de flujos de entrada ">>" y de flujos de
salida "<<" */
friend ostream & operator << (ostream &, Cadena &);
friend istream & operator >> (istream &, Cadena &);
};
Cadena :: Cadena (char * cadena) //Constructor por defecto
{
longitud = strlen(cadena);
ptrCadena = new char[longitud + 1]; // Creación dinámica
if(ptrCadena == NULL) // Se verifica si hay memoria disponible
{ cout<<"No hay memoria";
exit(0);
}
strcpy(ptrCadena, cadena); // Se copia el contenido de cadena en el objeto creado
}
Cadena :: Cadena (Cadena & copia) //Constructor copia
{
longitud = strlen(copia.ptrCadena);
ptrCadena = new char[longitud + 1];
if(ptrCadena == NULL) // Se verifica si hay memoria disponible
{ cout<<"No hay memoria";
exit(0);
}
strcpy(ptrCadena, copia.ptrCadena); /* Se copia el contenido de copia en el objeto
creado*/
}

Cadena :: ~Cadena()
{ delete [ ] ptrCadena;
}
// Sobrecarga del operador "+" para que permita concatenar cadenas
Cadena & Cadena :: operator + (Cadena & s)
{
char *temps = ptrCadena;
longitud += s.longitud;
ptrCadena = new char[longitud+1];
if(ptrCadena == NULL) // Se verifica si hay memoria disponible
{ cout<<"No hay memoria";
exit(0);
}
strcpy(ptrCadena, temps); // Se copia el contenido de temps en el objeto creado
strcat(ptrCadena, s.ptrCadena); /* Se realiza la concatenación del contenido de s
con el objeto creado*/
delete [ ] temps; // Se libera memoria reservada con new
return *this;
}
int Cadena :: long_cadena ()
{
return longitud;
}
// Sobrecarga del operador de entrada ">>"
ostream & operator<< (ostream & salida, Cadena & s)
{ salida<< s.ptrCadena;
return salida;
}
// Sobrecarga del operador de salida "<<"
istream & operator>> (istream & entrada, Cadena & s)
{ entrada>> s.ptrCadena;
return entrada;
}
int main()
{ char cad1[20], cad2[20];
system("cls");
cout << "Introducir primer cadena: ";
gets(cad1);
cout << "Introducir segunda cadena: ";
gets(cad2);
Cadena s1(cad1), s2(cad2), s3; //Creamos los objetos de tipo cadena

//probando operador sobrecargado de concatenación
cout << endl << endl << "Resultado de concatenar Cadenas s1 y s2: " << endl;
s3 = s1 + s2;
cout << "s3: " << s3;
//prueba el constructor de copiado
Cadena *s4= new Cadena(s2);
cout << endl << endl << "Constructor copia para *s4: " << *s4;
//prueba del operador de asignación =
cout << endl << endl << "Asignando s3 a *s4, *s4: ";
*s4 = s3;
cout << *s4 << endl << endl << "Longitud de s4: " << s4 -> long_cadena() << "caracteres.";
system("pause>nul");
return 0;
}
