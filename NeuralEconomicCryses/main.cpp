#include "Neuron.h"
#include <vector>

void main()
{
	vector<vector<float>> tests;//война, нефть, кредит, трудоспособность
	vector<float> answers;

	tests.push_back(vector<float>() = { 1,0,0,1 });
	answers.push_back(1);

	tests.push_back(vector<float>() = { 1,0,1,0 });
	answers.push_back(1);

	tests.push_back(vector<float>() = { 0,0,1,0 });
	answers.push_back(0);

	tests.push_back(vector<float>() = { 0,0,0,1 });
	answers.push_back(0);

	tests.push_back(vector<float>() = { 1,1,0,0 });
	answers.push_back(1);

	tests.push_back(vector<float>() = { 0,1,1,0 });
	answers.push_back(1);



	Neuron inputs[4];
	Neuron hidden[3];
	Neuron output;

	inputs[0].SetOutput(1);

	hidden[0].SetConnection(&inputs[0], 0.4);
}