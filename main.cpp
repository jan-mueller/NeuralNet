#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include "NeuralNet.h"
#include "pattern.h"

using namespace std;

int main(int argc, char** argv){

	int iL=63, hL=6, oL=9;
	float *output;
	char *percO=new char[20];
	int recog[10];
	NeuralNet knn(iL,hL,oL);
	int n;

	cout << "Training over how much epoches?: "; cin >> n;
	cout << "\nLearning phase:\n---------------\n";
	for(int i=0; i<n*10; i++){
		knn.train(trainI[i%10],trainO[i%10]);
		cout << "\r" << setprecision(4) << i*10.0/n << "%   ";
	}
	cout << "\n\n";

	cout << "Testing phase:\n--------------\n";
	cout << "=> Highest percentage is most probable (except 0)...\n\n";
	cout << "  ";
	for(int j=1; j<=oL; j++)
		cout << setw(8) << setprecision(1) << j;
	for(int i=0; i<10; i++){                     //test outputs
		output=knn.run(testI[i]);
		recog[i]=-1;
		for(int j=0; j<oL&&recog[i]!=0; j++)
				if(output[j]>0.25) recog[i]=0;
		if(recog[i]==0)
				for(int j=1; j<oL; j++)
								if(output[j]>output[recog[i]]) recog[i]=j;
		cout << "\n" << i << ": ";
		for(int j=0; j<oL; j++){
				/*if(output[j]<0.1) output[j]=0;
				else if(output[j]>0.9) output[j]=1;*/
				sprintf(percO,"%6.2f%% ",output[j]*100);
				cout << percO;
		}
	}
	cout << "\n\n";
	for(int i=0; i<10; i++){                     //test outputs
		cout << "=> The falsified " << i << " has been recognized as " << recog[i]+1 << ".\n";
	}
	cout << "\n\n";

	system("PAUSE");
	return 0;


}




