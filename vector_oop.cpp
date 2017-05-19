#include <iostream>
using namespace std;
class Vector
{ private:
float CoordX; // Coordenada en eje x del vector
float CoordY; // Coordenada en eje y del vector
public:
Vector (float Val1 = 0, float Val2 =0); //constructor predeterminado
~Vector(){ }; //destructor
void ImprimeVector (); //Muestra el vector
// Funciones para sobrecarga de operadores
Vector operator + (Vector Vec); //Sobrecarga del operador "+" para realizar la
//suma de vectores
Vector operator - (Vector Vec); //Sobrecarga del operador "-" para realizar la
//resta de vectores
};
/* Método constructor con parámetros predeterminados; a los cuales, si no se les
especifican otros valores, se les asignará 0 */

Vector :: Vector(float Val1, float Val2)
{ CoordX = Val1;
CoordY = Val2;
}
// Método que imprime los valores de los atributos del vector
void Vector :: ImprimeVector( )
{ cout << "La componente en X del vector es: " << CoordX << endl;
cout << "La componente en Y del vector es: " << CoordY << endl;
}
/* Método en el cual se sobrecarga el operador "+"; por lo tanto se podrá utilizar para la
suma aritmética, como para suma de
vectores. Lo anterior da como resultado un objeto de tipo Vector */
Vector Vector :: operator + (Vector Vec)
{ return Vector(CoordX + Vec.CoordX, CoordY + Vec.CoordY);
}
/* Método en el cual se sobrecarga el operador "-"; por lo tanto se podrá utilizar para la
resta aritmética, como para resta de
vectores. Lo anterior da como resultado un objeto de tipo Vector */
Vector Vector :: operator - (Vector Vec)
{ return Vector(CoordX - Vec.CoordX, CoordY - Vec.CoordY);
}
int main()
{
system("cls");
Vector Vec1(3,1), Vec2(1,2), Vec3; //Creamos los objetos de tipo Vector
// Se invoca al operador "+" sobrecargado, es decir, se realiza la suma de vectores
Vec3 = Vec1 + Vec2;
// Mostramos el vector resultante
cout << endl << endl << "Los datos del vector resultante de la suma de vectores son: "
<< endl;
Vec3.ImprimeVector();
// Se invoca al operador "-" sobrecargado, es decir, se realiza la resta de vectores
Vec3 = Vec1 - Vec2;
// Mostramos el vector resultante
cout << endl << endl << "Los datos del vector resultante de la resta de vectores son: "
<< endl;
Vec3.ImprimeVector();
system("pause>nul");
return 0;
}
