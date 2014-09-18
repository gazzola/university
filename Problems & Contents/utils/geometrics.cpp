```cpp
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*
condicao de existencia de um trinagulo:
|b-c| < a < b+c
|a-c| < b < a+c
|a-b| < c < a+b 
*/

bool formaUmTriangulo(int a, int b, int c){
	return (abs(b-c) < a && a < b+c) && (abs(a-c) < b && b < a+c) && (abs(a-b) < c && c < a+b);
}

double triangleArea(double base, double height){
	return (base*height)/2;
}

double circleArea(double radius){
	return PI*(radius*radius);
}

double trapeziumArea(double base1, double base2, double height){
	return (height*(base1+base2))/2;
}

double squareArea(double height){
	return height*height;
}

double rectangleArea(double width, double height){
	return width*height;
}



void sortThreeValues(int *v){
	if(v[0] < v[1])
		swap(v[0], v[1]);

	if(v[1] < v[2])
		swap(v[1], v[2]);

	if(v[0] < v[1])
		swap(v[0], v[1]);
}

string formaDoTrinangulo(int a, int b, int c){
	if(a >= b+c)
		return "NAO FORMA TRIANGULO";
	else if(a*a == b*b + c*c)
		return "TRIANGULO RETANGULO";
	else if(a*a > b*b + c*c)
		return "TRIANGULO OBTUSANGULO";
	else if(a*a < b*b + c*c)
		return "TRIANGULO ACUTANGULO";

	if(a == b && b == c)
		return "TRIANGULO EQUILATERO";
	else if(a == b || a == c || b == c)
		return "TRIANGULO ISOSCELES";
}

int distanciaEntreDoisPontos(int x1, int y1, int x2, int y2){
	int x = x2-x1;
	int y = y2-y1;
	return sqrt((x*x) + (y*y));
}


bool ehTripla(int x, int y, int z){
	
	if(x*x == y*y + z*z)
		return true;
	
	if(y*y == x*x + z*z)
		return true;
	
	if(z*z == x*x + y*y)
		return true;

	return false;
}

bool ehPrimitiva(int x, int y, int z){
	int s = mdc(x, y);
	s = mdc(s, z);
	return (s == 1);
}
```