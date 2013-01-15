#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string>
#include <fstream>
#include "NeuralNet.h"

using namespace std;

ANN_ERROR::file_exception::file_exception(const char* q){ p=q; }

//Public Methods

void NeuralNet::setZero(){

}
void NeuralNet::mem_alloc(int input, int hidden, int output){

}
void NeuralNet::backprop(){

}

//Private Methods

NeuralNet::NeuralNet(int input, int hidden, int output){
	mem_alloc(input,hidden,output);
	srand(time(NULL));
	//fill with rand values (low end...high end)
	for(int i=0; i<=amountI; i++)
		for(int j=0; j<amountH; j++)
			ihWeight[i][j]=(float)rand()/RAND_MAX*0.6-0.3;
	for(int i=0; i<=amountH; i++)
		for(int j=0; j<amountO; j++)
			hoWeight[i][j]=(float)rand()/RAND_MAX*0.6-0.3;
}
NeuralNet::NeuralNet(int input, int hidden, int output, float **inpHidWeight, float **hidOutWeight){
	NeuralNet(input, hidden, output);
	//create weight matrices with user-defined values
	for(int i=0; i<=amountI; i++)
		for(int j=0; j<amountH; j++)
			ihWeight[i][j]=inpHidWeight[i][j];
	for(int i=0; i<=amountH; i++)
		for(int j=0; j<amountO; j++)
			hoWeight[i][j]=hidOutWeight[i][j];
}
NeuralNet::NeuralNet(char *file){
	int input, hidden, output;
	ifstream in(file);
	if(!in){
		throw ANN_ERROR::file_exception("Error opening file");
		return;
	}
	//throw exception on input failing
	in.exceptions(ios_base::failbit|ios_base::badbit|ios_base::eofbit);
	try{
		in>>input;
		in>>hidden;
		in>>output;
	}
	catch(ios_base::failure &){
		throw ANN_ERROR::file_exception("Error reading weight matrix dimensions");
		return;
	}
	mem_alloc(input, hidden,output);

	for(int i=0; i<=input; i++)
		for(int j=0; j<hidden; j++){
			try{
				in>>ihWeight[i][j];
			}
			catch(ios_base::failure &){
				throw ANN_ERROR::file_exception("Error reading input-hidden weight matrix");
				return;
			}
		}
	for(int i=0; i<=input; i++)
		for(int j=0; j<output; j++){
			try{
				in>>hoWeight[i][j];
			}
			catch(ios_base::failure &){
				throw ANN_ERROR::file_exception("Error reading hidden-output weight matrix");
				return;
			}
		}
	 in.close();
}
NeuralNet::~NeuralNet(){

}
bool NeuralNet::saveWeightsToFile(char *file){

}
float NeuralNet::calculateError(){

}
float *NeuralNet::getOutput(){

}
float *NeuralNet::getOutputDifference(){

}
void NeuralNet::setErrorTolerance(float tolerance){

}
void NeuralNet::setLearnRate(float rate){

}
void NeuralNet::setImpuls(float impuls){

}
float *NeuralNet::run(float *input){

}
bool NeuralNet::train(float *input, float *outputPointer){

}
