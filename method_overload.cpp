#include <iostream>
using namespace std;

class Vector {

private:
        
public:
       double x,y;
       Vector();
       Vector(double,double);
       ~Vector();
       Vector operator + (Vector V);  
};
Vector :: Vector(){};
Vector :: ~Vector(){};

Vector :: Vector(double compx,double compy){
       this->x=compx;
       this->y=compy;
};
Vector Vector :: operator + (Vector V){
       Vector Res;
       Res.x=(this->x)+V.x;
       Res.y=(this->y)+V.y;
       return Res;
};

int main(){
	double cx1,cy1,cx2,cy2;
	cout<<"x1: ";
	cin>>cx1;
	cout<<"y1: ";
	cin>>cy1;
	cout<<"x2: ";
	cin>>cx2;
	cout<<"y2: ";
	cin>>cy2;
	Vector *V1,*V2,*V3;
	V1 = new Vector(cx1,cy1);
	V2= new Vector(cx2,cy2);
	V3 = new Vector();
	*V3=*V1+*V2;
	cout<<"\n Suma: ("<<V3->x<<","<<V3->y<<")\n\n";
	system("PAUSE");
	return 0;
}
