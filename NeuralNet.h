#ifndef _NEURALNET_H_
#define _NEURALNET_H_


class NeuralNet{
private:
	float **ihWeight, **hoWeight;
	float **ihWeightDelta, **hoWeightDelta;
	float *inputI, *inputH, *inputO;
	float *outputI, *outputH, *outputO;
	float *errorH, *errorO, *preferenceO, *differenceO;
	int amountI, amountH, amountO;
	float errorTolerance, learnRate, impuls;
	void setZero();
	void mem_alloc(int input, int hidden, int output);
	void backprop();
public:
	NeuralNet(int input, int hidden, int output);
	NeuralNet(int input, int hidden, int output, float **inpHidWeight, float **hidOutWeight);
	NeuralNet(char *file);
	~NeuralNet();
	bool saveWeightsToFile(char *file);
	float calculateError();
	float *getOutput();
	float *getOutputDifference();
	void setErrorTolerance(float tolerance);
	void setLearnRate(float rate);
	void setImpuls(float impuls);
	float *run(float *input);
	bool train(float *input, float *outputPointer);
};

#endif
