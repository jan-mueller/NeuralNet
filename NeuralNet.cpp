#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string>
#include <fstream>
#include "NeuralNet.h"

using namespace std;

ANN_ERROR::file_exception::file_exception(const char* q){p = q;}

//Private Methoden

NeuralNet::NeuralNet(int input, int hidden, int output){
	mem_alloc(input, hidden, output);
	srand(time(NULL));
	//Füllen der Gewichtungsmatrix mit Werten zwischen -0,3 und 0,3
	for (int i = 0; i <= amountI; i++)
		for (int j = 0; j < amountH; j++)
			ihWeight[i][j] = (float) rand() / RAND_MAX * 0.6 - 0.3;
	for (int i = 0; i <= amountH; i++)
		for (int j = 0; j < amountO; j++)
			hoWeight[i][j] = (float) rand() / RAND_MAX * 0.6 - 0.3;
}
NeuralNet::NeuralNet(int input, int hidden, int output, float **inpHidWeight, float **hidOutWeight){
	mem_alloc(input, hidden, output);
	srand(time(NULL));
	//Füllen der Gewichtungsmatrix mit Werten zwischen -0,3 und 0,3
	for (int i = 0; i <= amountI; i++)
		for (int j = 0; j < amountH; j++)
			ihWeight[i][j] = (float) rand() / RAND_MAX * 0.6 - 0.3;
	for (int i = 0; i <= amountH; i++)
		for (int j = 0; j < amountO; j++)
			hoWeight[i][j] = (float) rand() / RAND_MAX * 0.6 - 0.3;
	//Befüllen der Gewichtungsmatrix mit Übergabe Werten
	for (int i = 0; i <= amountI; i++)
		for (int j = 0; j < amountH; j++)
			ihWeight[i][j] = inpHidWeight[i][j];
	for (int i = 0; i <= amountH; i++)
		for (int j = 0; j < amountO; j++)
			hoWeight[i][j] = hidOutWeight[i][j];
}
NeuralNet::NeuralNet(char *file){
	int input, hidden, output;
	ifstream in(file);
	if (!in) {
		throw ANN_ERROR::file_exception("Error opening file");
		return;
	}
	//Exception Ausgabe wenn Datei einlesen fehlschlägt
	in.exceptions(ios_base::failbit | ios_base::badbit | ios_base::eofbit);
	try {
		in >> input;
		in >> hidden;
		in >> output;
	} catch (ios_base::failure &) {
		throw ANN_ERROR::file_exception(
				"Error reading weight matrix dimensions");
		return;
	}
	mem_alloc(input, hidden, output);

	for (int i = 0; i <= input; i++)
		for (int j = 0; j < hidden; j++) {
			try {
				in >> ihWeight[i][j];
			} catch (ios_base::failure &) {
				throw ANN_ERROR::file_exception(
						"Error reading input-hidden weight matrix");
				return;
			}
		}
	for (int i = 0; i <= input; i++)
		for (int j = 0; j < output; j++) {
			try {
				in >> hoWeight[i][j];
			} catch (ios_base::failure &) {
				throw ANN_ERROR::file_exception(
						"Error reading hidden-output weight matrix");
				return;
			}
		}
	in.close();
}
NeuralNet::~NeuralNet(){
	delete[] preferenceO;
	delete[] inputI;
	delete[] inputH;
	delete[] inputO;
	delete[] outputI;
	delete[] outputH;
	delete[] outputO;
	delete[] errorH;
	delete[] errorO;
	delete[] differenceO;

	for(int i=0; i<=amountI; i++)
		delete ihWeight[i];
	for(int i=0; i<=amountH; i++)
		delete[] hoWeight[i];
	for(int i=0; i<=amountI; i++)
		delete[] ihWeightDelta[i];
	for(int i=0; i<=amountH; i++)
		delete hoWeightDelta[i];
	delete[] ihWeight; delete[] hoWeight;
	delete[] ihWeightDelta; delete[] hoWeightDelta;
}
bool NeuralNet::saveWeightsToFile(char *file){
	ofstream out(file);
	if(!out){
		throw ANN_ERROR::file_exception("Error opening file");
		return false;
	}
	//throw exception on output failing
	out.exceptions(ios_base::failbit|ios_base::badbit|ios_base::eofbit);
	try{
		out<<amountI<<endl;
		out<<amountH<<endl;
		out<<amountO<<endl;
	}
	catch(ios_base::failure &){
		throw ANN_ERROR::file_exception("Error writing weight matrix dimensions");
		return false;
	}
	for(int i=0; i<=amountI; i++)
		for(int j=0; j<amountH; j++){
			try{
				out<<ihWeight[i][j]<<endl;
			}
			catch(ios_base::failure &){
				throw ANN_ERROR::file_exception("Error writing input-hidden weight matrix");
				return false;
			}
		}
	for(int i=0; i<=amountH; i++)
		for(int j=0; j<amountO; j++){
			try{
				out<<hoWeight[i][j]<<endl;
			}
			catch(ios_base::failure &){
				throw ANN_ERROR::file_exception("Error writing hidden-output weight matrix");
				return false;
			}
		}
	 out.close();
	 return true;
}
float NeuralNet::calculateError() {
	float quad=0;
	for(int i=0; i<amountO; i++)
		quad+=differenceO[i]*differenceO[i];
	return quad;
}
float *NeuralNet::getOutput() {
	return outputO;
}
float *NeuralNet::getOutputDifference() {
	return differenceO;
}
void NeuralNet::setErrorTolerance(float tolerance) {
	errorTolerance=tolerance;
}
void NeuralNet::setLearnRate(float rate) {
	learnRate=rate;
}
void NeuralNet::setImpuls(float impuls) {
	this->impuls=impuls;
}
float *NeuralNet::run(float *input) {

}
bool NeuralNet::train(float *input, float *outputPointer) {

}

//Public Methoden

void NeuralNet::setZero(){
	for(int i=0; i<amountI; i++){
		inputI[i]=0.0;
		outputI[i]=0.0;
	}
	for(int i=0; i<amountH; i++){
		inputH[i]=0.0;
		outputH[i]=0.0;
		errorH[i]=0.0;
	}
	for(int i=0; i<amountO; i++){
		inputO[i]=0.0;
		outputO[i]=0.0;
		errorTolerance[i]=0.0;
	}
}
void NeuralNet::mem_alloc(int input, int hidden, int output){
	//Dimensionen des Netzes speichern
	amountI = input;
	amountH = hidden;
	amountO = output;
	//erstellen der Gewichtungsmatrix
	ihWeight = new float*[amountI + 1];
	for (int i = 0; i <= amountI; i++)
		ihWeight[i] = new float[amountH];
	hoWeight = new float*[amountH + 1];
	for (int i = 0; i <= amountH; i++)
		hoWeight[i] = new float[amountO];
	//erstellen der Matrix für die Gewichtungsunterschiede
	ihWeightDelta = new float*[amountI + 1];
	for (int i = 0; i <= amountI; i++)
		ihWeightDelta[i] = new float[amountH];
	hoWeightDelta = new float*[amountH + 1];
	for (int i = 0; i <= amountH; i++)
		hoWeightDelta[i] = new float[amountO];
	//Speicher allozieren für die restlichen Arrays
	preferenceO = new float[amountO];
	inputI = new float[amountI];
	inputH = new float[amountH];
	inputO = new float[amountO];
	outputI = new float[amountI + 1];
	outputH = new float[amountH + 1];
	outputO = new float[amountO];
	errorH = new float[amountH + 1];
	errorO = new float[amountO];
	differenceO = new float[amountO];
	//differenceO bereitmachen für calculateError()
	for (int i = 0; i < amountO; i++)
		differenceO[i] = 0.0;
	//Gewichtungsunterschiedmatrix auf Startwert setzen
	for (int i = 0; i <= amountI; i++)
		for (int j = 0; j < amountH; j++)
			ihWeightDelta[i][j] = 0.0;
	for (int i = 0; i <= amountH; i++)
		for (int j = 0; j < amountO; j++)
			hoWeightDelta[i][j] = 0.0;
	//Default Lern Rate setzen
	learnRate = 2.0;
	//Default Fehler Toleranz setzen
	errorTolerance = 0.1;
	//Default Impuls Rate setzen
	impuls = 0.4;
}
void NeuralNet::backprop(){
	//Berechnung der Fehlertoleranzen im Output Layer
	for(int i=0; i<amountO; i++)
		errorTolerance[i]=differenceO[i]*outputO[i]*(1-outputO[i]);
	//Berechnung der Fehlertoleranzen im Hidden Layer
	for(int i=0; i<=amountH; i++){
		for(int j=0; j<amountO; j++)
				errorH[i]+=errorO[j]*hoWeight[i][j];
		errorH[i]*=outputH[i]*(1-outputH[i]);
	}
	//backpropagation nach der Implementierung von "Robert Callan [2003]"
	//update der Hidden-Output Schicht Gewichtungsmatrix
	for(int i=0; i<=amountH; i++)
		for(int j=0; j<amountO; j++){
			hoWeightDelta[i][j] = learnRate*errorTolerance[j]*outputH[i] + hoWeightDelta[i][j]*impuls;
			hoWeight[i][j] = hoWeight[i][j]+hoWeightDelta[i][j];
		}
	//update der Input-Hidden Schicht Gewichtungsmatrix
	for(int i=0; i<=amountI; i++)
		for(int j=0; j<amountH; j++){
			ihWeightDelta[i][j] = learnRate*errorH[j]*outputI[i] + ihWeightDelta[i][j]*impuls;
			ihWeight[i][j] = ihWeight[i][j]+ihWeightDelta[i][j];
		}
}
