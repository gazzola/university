#include <iostream>
#include <iomanip>

using namespace std;


class Ponto{
	public:
		float x, y;

		Ponto(float x, float y);
		void mostrar();
		Ponto operator + (Ponto &p);
		Ponto operator - (Ponto &p);
		bool operator == (Ponto &p);
		bool operator != (Ponto &p);
};


Ponto::Ponto(float x, float y){
	this->x = x;
	this->y = y;
}

void Ponto::mostrar(){
	cout << this->x << " | " << this->y << endl;
}

Ponto Ponto::operator + (Ponto &p){
	return Ponto((this->x + p.x), (this->y + p.y));
}

Ponto operator + (Ponto &p, float a) {
	return Ponto(p.x + a, p.y + a);
}


Ponto Ponto::operator - (Ponto &p){
	return Ponto((this->x - p.x), (this->y - p.y));
}

Ponto operator - (Ponto &p, float a) {
	return Ponto(p.x - a, p.y - a);
}


bool Ponto::operator == (Ponto &p){
	return (this->x == p.x && this->y == p.y);
}

bool Ponto::operator != (Ponto &p){
	return (this->x != p.x || this->y != p.y);
}



int main(){
	
	Ponto *p1 = new Ponto(2, 5);
	Ponto *p2 = new Ponto(4, 7);

	Ponto p3 = *p1 + *p2;
	Ponto p4 = *p1 - *p2;

	Ponto p5 = *p1 + 2;
	Ponto p6 = *p1 - 3;


	cout << "P1: " << setw(10);
	p1->mostrar();
	cout << "P2: " << setw(10);
	p2->mostrar();

	cout << "P3: P1+P2: " << setw(3);
	p3.mostrar();
	cout << "P4: P1-P2: " << setw(3);
	p4.mostrar();

	cout << "P5: P1+2: " << setw(4);
	p5.mostrar();
	cout << "P6: P1-3: " << setw(4);
	p6.mostrar();



	cout << "P1 == P2: " << setw(7);
	cout << ((*p1 == *p2) ? "true" : "false") << endl;

	cout << "P2 != P5: " << setw(7);
	cout << ((*p2 != p5) ? "true" : "false") << endl;



	delete p1;
	delete p2;


	return 0;
}