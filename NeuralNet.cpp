#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string>
#include <fstream>
#include "NeuralNet.h"

using namespace std;

ANN_ERROR::file_exception::file_exception(const char* q){ p=q; }

//Private Methoden

NeuralNet::NeuralNet(int input, int hidden, int output){
	mem_alloc(input,hidden,output);
	srand(time(NULL));
	//Füllen der Gewichtungsmatrix mit Werten zwischen -0,3 und 0,3
	for(int i=0; i<=amountI; i++)
		for(int j=0; j<amountH; j++)
			ihWeight[i][j]=(float)rand()/RAND_MAX*0.6-0.3;
	for(int i=0; i<=amountH; i++)
		for(int j=0; j<amountO; j++)
			hoWeight[i][j]=(float)rand()/RAND_MAX*0.6-0.3;
}
NeuralNet::NeuralNet(int input, int hidden, int output, float **inpHidWeight, float **hidOutWeight){
	NeuralNet(input, hidden, output);
	//Befüllen der Gewichtungsmatrix mit Übergabe Werten
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
	//Exception Ausgabe wenn Datei einlesen fehlschlägt
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

//Public Methoden

void NeuralNet::setZero(){

}
void NeuralNet::mem_alloc(int input, int hidden, int output){
	//Dimensionen des Netzes speichern
	amountI=input; amountH=hidden; amountO=output;
	//erstellen der Gewichtungsmatrix
	ihWeight=new float*[amountI+1];
	for(int i=0; i<=amountI; i++)
		ihWeight[i]=new float[amountH];
	hoWeight=new float*[amountH+1];
	for(int i=0; i<=amountH; i++)
		hoWeight[i]=new float[amountO];
	//erstellen der Matrix für die Gewichtungsunterschiede
	ihWeightDelta=new float*[amountI+1];
	for(int i=0; i<=amountI; i++)
		ihWeightDelta[i]=new float[amountH];
	hoWeightDelta=new float*[amountH+1];
	for(int i=0; i<=amountH; i++)
		hoWeightDelta[i]=new float[amountO];
	//Speicher allozieren für die restlichen Arrays
	preferenceO=new float[amountO];
	inputI=new float[amountI];
	inputH=new float[amountH];
	inputO=new float[amountO];
	outputI=new float[amountI+1];
	outputH=new float[amountH+1];
	outputO=new float[amountO];
	errorH=new float[amountH+1];
	errorO=new float[amountO];
	differenceO=new float[amountO];
	//differenceO bereitmachen für die getE()
	for(int i=0; i<amountO; i++)
		differenceO[i]=0.0;
	//Gewichtungsunterschiedmatrix auf Startwert setzen
	for(int i=0; i<=amountI; i++)
		for(int j=0; j<amountH; j++)
				ihWeightDelta[i][j]=0.0;
	for(int i=0; i<=amountH; i++)
		for(int j=0; j<amountO; j++)
				hoWeightDelta[i][j]=0.0;
	//Default Lern Rate setzen
	learnRate=2.0;
	//Default Fehler Toleranz setzen
	errorTolerance=0.1;
	//Default Impuls Rate setzen
	impuls=0.4;
}
void NeuralNet::backprop(){

}
