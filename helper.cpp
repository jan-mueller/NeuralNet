#include "helper.h"
ANN_ERROR::file_exception::file_exception(const char* q){p = q;}

float **generateAsciiArray(char* file, int amount, int height, int width){
	float **array;
	array = new float*[amount];
	fstream filestream;
	filestream.open(file, fstream::in);

	for(int i=0; i<amount; i++){
		array[i] = new float[height*width];
		for(int j=0; j<height; j++){
			for(int k=0; k<width; k++){
				try {
					filestream >> array[i][j*7+k];
				} catch (ios_base::failure &) {
					throw ANN_ERROR::file_exception("Error reading array from file");
				}
			}
		}
	}
	filestream.close();
	return array;
}
