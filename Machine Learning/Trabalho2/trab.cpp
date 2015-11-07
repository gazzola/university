#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <ctime>
#include <cmath>
#include <vector>
#include <cstdlib>

using namespace std;



const int K = 20;
const int D = 1000;
const int ITERS = 10;
const double INF = 999999999;

int W = D;
int H = D;
int M = 255;

struct pixel{
	int r, g, b, k;
}image[D][D], centroids[K];



void initialize_centroids(int max, int min){
	int diff = max - min;
	for(int i=0; i<K; ++i){
		centroids[i].r = (int) (rand() % diff) + min; 
		centroids[i].g = (int) (rand() % diff) + min;
		centroids[i].b = (int) (rand() % diff) + min;
	}
}



void initialize_centroids(){
	int h, w;
	for(int i=0; i<K; ++i){
		h = (int) (rand() % H);
		w = (int) (rand() % W);
		centroids[i].r = image[h][w].r; 
		centroids[i].g = image[h][w].g;
		centroids[i].b = image[h][w].b;
	}
}


void find_closest_centroids(){

	double r, g, b, y, y_star;

	for(int i=0; i<H; ++i){
		for(int j=0; j<W; ++j){

			y_star = INF;

			for(int k=0; k<K; ++k){
				
				r = pow(image[i][j].r - centroids[k].r, 2);
				g = pow(image[i][j].g - centroids[k].g, 2);
				b = pow(image[i][j].b - centroids[k].b, 2);
				y = sqrt(r+g+b);

				if(y < y_star){
					y_star = y;
					image[i][j].k = k;
				}
			}

		}
	}
}


void compute_centroids(){


	double r, g, b;
	int q;

	for(int i=0; i<K; ++i){
			
		r = g = b = q = 0;

		for(int l=0; l<H; ++l){
			for(int j=0; j<W; ++j){
				if(image[j][l].k == i){
					r += image[j][l].r;
					g += image[j][l].g;
					b += image[j][l].b;
					q++;
				}
			}
		}

		centroids[i].r = r / q;
		centroids[i].g = g / q;
		centroids[i].b = b / q;
	}

}

void train(){

	for(int i=0; i<ITERS; ++i){
		printf("Iter: %2d of %d\n", i+1, ITERS);
		find_closest_centroids();
		compute_centroids();
	}

	printf("\n");
}


void update_colors(){

	int k;
	for(int i=0; i<H; ++i){
		for(int j=0; j<W; ++j){
			k = image[i][j].k;
			image[i][j].r = centroids[k].r;
			image[i][j].g = centroids[k].g;
			image[i][j].b = centroids[k].b;
		}
	}

}



int main(){

	srand(time(NULL));

	ifstream iFile("imgs/bird.ppm");
	ofstream oFile("imgs/saida.ppm");

	iFile.ignore(INT_MAX, '\n');
	iFile >> H >> W >> M;


	for(int i=0; i<H; ++i){
		for(int j=0; j<W; ++j){
			iFile >> image[i][j].r;
			iFile >> image[i][j].g;
			iFile >> image[i][j].b;
		}
	}

	initialize_centroids();
	train();
	update_colors();

	oFile << "P3\n" << "# my file\n" << H << " " << W << "\n" << M << "\n";
	for(int i=0; i<H; ++i){
		for(int j=0; j<W; ++j){
			oFile << image[i][j].r << " ";
			oFile << image[i][j].g << " ";
			oFile << image[i][j].b << " ";
		}
		oFile << "\n";
	}

	iFile.close();
	oFile.close();

	return 0;
}