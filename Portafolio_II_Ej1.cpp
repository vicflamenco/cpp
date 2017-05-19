#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string.h>

using namespace std;

class Persona
{
	protected:
		string nombres, apellidos, direccion, DUI;
	public:
		Persona()
		{
		};
		
		Persona(string nomb, string apell, string dir, string dui)
		{
			nombres = nomb;
			apellidos = apell;
			direccion = dir;
			DUI = dui;
		};
		
		~Persona()
		{
		};
		
		string rNombres()
		{return nombres;
		};
		
		string rApellidos()
		{return apellidos;
		};
		
		string rDireccion()
		{return direccion;
		};
		
		string rDUI()
		{return DUI;
		};
		
};

class Empleado: public Persona
{
	protected:
		float SalarioFijo, PorcentajeFijo, VentasRealizadas;
		float PrecioHoraN, PrecioHorasE;
		int HorasTrabajadas;
		
		int TipoEmp; // 0 es Fijo Mensual, 1 es Comisionista, 2 es empleado por Horas
	public:
		
		Empleado()
		{
		};
		
		Empleado(int Tipo, string nomb, string ap, string dir, string dui):Persona(nomb, ap, dir, dui)
		{
			TipoEmp = Tipo;
		};
		
		~Empleado()
		{
		};
		
		void Registrar(int Tipo, string nomb, string ap, string dir, string dui)
		{
			TipoEmp = Tipo;
			Persona::nombres = nomb;
			Persona::apellidos = ap;
			Persona::direccion = dir;
			Persona::DUI = dui;
		}
		
		void imprimirDatos()
		{
			cout<<"\nNombre: "<<Persona::rNombres()<<" "<<Persona::rApellidos();
			cout<<"\nDireccion: "<<Persona::rDireccion();
			cout<<"\nDUI: "<<Persona::rDUI();
		}
		
		void fijarDatosCom(float porc, float vent)
		{
			PorcentajeFijo = porc;
			VentasRealizadas = vent;
		}
		
		void fijarPorHoras(int hTrab, float precioHN, float precioHE)
		{
			HorasTrabajadas = hTrab;
			PrecioHoraN = precioHN;
			PrecioHorasE = precioHE;
		}
		
		void imprimirSalario()
		{
			cout<<"\nNombre: "<<Persona::rNombres()<<" "<<Persona::rApellidos();
			switch (TipoEmp)
			{
				case 1:
					cout<<"\nSalario: $"<<SalarioFijo;
				break;
				
				case 2:
					cout<<"\nSalario: $"<<PorcentajeFijo*VentasRealizadas;
				break;
				
				case 3:
					if (HorasTrabajadas >=40)
					{
						cout<<"\nSalario: $"<<(40*PrecioHoraN)+(HorasTrabajadas-40)*PrecioHorasE;
					}
					else
					{
						cout<<"\nSalario: $"<<(HorasTrabajadas)*PrecioHoraN;
					}
				break;
			}
		}
		
		
		int rTipo()
		{	return TipoEmp;
		};
		
		void cSalarioF(float c)
		{	SalarioFijo = c;
		};
};


int main()
{
	int n=0, opt=0, pos=0;
	
	cout<<"\n\nBienvenido al sistema de nomina de empleados";
	cout<<"\n\nIngrese el numero de empleados que desea administrar: "; cin>>n;
	
	Empleado *ptEmp;
	ptEmp = new Empleado[n];
	
	do
	{
		system("cls");
		
		cout<<"\nMenu del sistema de nomina de emplados: ";
		cout<<"\n\n1) Dar de alta a un empleado.";
		cout<<"\n2) Fijar emolumentos, horas o ventas realizadas de un empleado.";
		cout<<"\n3) Imprimir nomina de empleados.";
		cout<<"\n4) Salir del sistema.";
		
		cout<<"\n\nSeleccione su opcion: "; 
		cin>>opt;
		cout<<"\n";
		
		switch(opt)
		{
			case 1:
			{
				string nombres, apellidos, dir, dui;
				int tip=0;
				
				if (pos == n)
				{
					cout<<"\nSe alcanzó el limite máximo de empleados.";
					system("pause");
				}
				else
				{
					cout<<"\nDigite el nombre del empleado: "; cin>>nombres;
					cout<<"\nDigite el apellido del empleado: "; cin>>apellidos;
					cout<<"\nDigite la direccion del empleado: "; cin>>dir;
					cout<<"\nDigite el DUI del empleado: "; cin>>dui;
										
					cout<<"\n\nSeleccione el tipo de empleado: "; 
					cout<<"\n1) De salario fijo mensual.";
					cout<<"\n2) Comisionista.";
					cout<<"\n3) Empleado por horas.";
					
					cout<<"\n\nEl empleado sera de tipo: ";
					cin>>tip;
					
					(ptEmp + pos)->Registrar(tip, nombres, apellidos, dir, dui);
					pos++;
				}
			}
			break;
			
			case 2:
			{
				for(int x=0;x<pos; x++)
				{
					cout<<"# "<<x+1<<"----------------------------------------";
					(ptEmp + x)->imprimirDatos();
					cout<<"\n\n";
				}
				
				int sel=0;
				
				cout<<"\n\nSeleccione un empleado: ";
				cin>>sel;
				
				switch((ptEmp + (sel-1))->rTipo())
				{
					case 1:
					{
						float sal=0;
						cout<<"\nIngrese el salario fijo mensual: "; 
						cin>>sal;
						
						(ptEmp +(sel-1))->cSalarioF(sal);
					}
					break;
					
					case 2:
					{
						float porc=0, vent=0;
						cout<<"\nIngrese el porcentaje fijo por ventas: "; 
						cin>>porc;
						cout<<"\nIngrese las ventas del empleado: "; 
						cin>>vent;
						
						(ptEmp +(sel-1))->fijarDatosCom(porc, vent);
					}
					break;
					
					case 3:
						float PrecHN=0, PrecHE=0;
						int hT=0;
						
						cout<<"\nIngrese el precio de las primeras 40 horas: "; 
						cin>>PrecHN;
						cout<<"\nIngrese el precio de las horas extra: "; 
						cin>>PrecHE;
						cout<<"\nIngrese las horas trabajadas por el empleado: "; 
						cin>>hT;
						
						(ptEmp +(sel-1))->fijarPorHoras(hT, PrecHN, PrecHE);
					break;
					
				}
				system("pause");
			}
			break;
			
			case 3:
				for(int x=0;x<pos; x++)
				{
					cout<<"# "<<x+1<<"----------------------------------------";
					(ptEmp + x)->imprimirSalario();
					cout<<"\n\n";
				}
				
				system("pause");
			break;
			
			default:
			
			break;	
		}
		
	}while (opt!=4);
	
	system("pause");
}

