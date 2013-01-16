#include "helper.h"

float **generateAsciiArray(char* file, int amount, int height, int width){
	float **array;
	array = new float*[amount];
	fstream filestream;
	filestream.open(file, fstream::in);

	for(int i=0; i<amount; i++){
		array[i] = new float[height*width];
		for(int j=0; j<height; j++){
			for(int k=0; k<width; k++){
				filestream >> array[i][j*7+k];
			}
		}
	}
	filestream.close();
	return array;
}



