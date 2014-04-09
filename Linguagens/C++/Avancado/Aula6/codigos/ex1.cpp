#include <iostream>

using namespace std;

#define PI 3.14159265


class ElementoGeometrico{

	protected:
		int x, y, r;


	public:
		ElementoGeometrico(int x, int y){
			this->x = x;
			this->y = y;
		}

		ElementoGeometrico(int r){
			this->r = r;
		}


		float virtual perimetro() const = 0;
		float virtual area() const = 0;
		
};


class Circulo: public ElementoGeometrico{

	public:
		Circulo(int r)
			: ElementoGeometrico(r){
		}

		float perimetro() const{
			return 2*PI*this->r;
		}

		float area() const{
			return PI*(this->r * this->r);
		}

};


class Retangulo: public ElementoGeometrico{

	public:
		Retangulo(int x, int y)
			: ElementoGeometrico(x,  y){
		}

		float perimetro() const{
			return 4*this->x;
		}

		float area() const{
			return this->x*this->y;
		}

};



int main(int argc, char const *argv[]){
	
	Circulo *c1 = new Circulo(10);
	Retangulo *r1 = new Retangulo(4, 3);

	cout << "CIRCULO:" << endl;
	cout << "Perimetro: " << c1->perimetro() << endl;
	cout << "Area: " << c1->area() << endl;

	cout << endl;

	cout << "RETANGULO:" << endl;
	cout << "Perimetro: " << r1->perimetro() << endl;
	cout << "Area: " << r1->area() << endl;

	//delete c1;
	//delete r1;

	return 0;
}