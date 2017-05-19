#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <stdio.h>

using namespace std;

class Persona
{
	protected:
		float altura;
		string nombre;
	public:
		Persona(){
		};
		
		Persona(string nomb, float alt)
		{
			nombre = nomb;
			altura = alt;
		};
		
		~Persona(){
		};
		
		Persona operator + (Persona p2)
		{
			string sum; float alt=0;
			
			sum = nombre + " " + p2.nombre;
			
			if(altura > p2.altura)
			{
				alt = altura;
			}
			else if(altura < p2.altura)
			{
				alt = p2.altura;
			}
			else
			{
				alt = altura;
			}
				
			return Persona(sum,alt);
		}
		
		void ImprimirDatos()
		{
			cout<<"\nEl nombre es: "<<nombre<<endl;
			cout<<"\nLa altura es: "<<altura<<endl;
		}
};

int main()
{
	Persona p1, p2, res;
	
	string nomb1, nomb2;
	float alt1, alt2;
	
	cout<<"\nDigite el nombre de la persona 1: ";
	cin>>nomb1;
	cout<<"Digite la altura de la persona 1: ";
	cin>>alt1;
	
	cout<<"\n\nDigite el nombre de la persona 2: ";
	cin>>nomb2;
	cout<<"\nDigite la altura de la persona 2: ";
	cin>>alt2;
	
	p1 = Persona(nomb1,alt1);
	p2 = Persona(nomb2,alt2);
	
	cout<<"\n\nLos datos de la nueva persona son: \n";
	
	(p1 + p2).ImprimirDatos();
	system("pause");
}
