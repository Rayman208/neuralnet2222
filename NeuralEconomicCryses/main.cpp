#include "Neuron.h"
#include <vector>

#include <ctime>

void SetInputs(vector<float> test, vector<Neuron> &inputs)
{
	for (int i = 0; i < inputs.size(); i++)
	{
		inputs[i].SetOutput(test[i]);
	}
}

void main()
{
	const float speed = 0.1f;
	srand(time(NULL));

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

	vector<Neuron> inputs(4);
	vector<Neuron> hidden(3);
	Neuron output;

	for (int h = 0; h < hidden.size(); h++)
	{
		for (int i = 0; i < inputs.size(); i++)
		{
			hidden[h].SetConnection(&inputs[i], (rand() % 100) / 100.0);
		}

		output.SetConnection(&hidden[h], (rand() % 100) / 100.0);
	}

	for (int generation = 0; generation < 50000; generation++)
	{
		int indexTest = rand() % tests.size();

		SetInputs(tests[indexTest], inputs);
		for (int h = 0; h < hidden.size(); h++)
		{
			hidden[h].Activate();
		}
		output.Activate();

		//back propagation
		float errorOutputLayer = output.GetOutput() - answers[indexTest];
		float deltaOutputLayer = errorOutputLayer * output.GetOutput()*(1 - output.GetOutput());

		for (int h = 0; h < hidden.size(); h++)
		{
			float currentWeight = output.GetWeight(&hidden[h]);
			
			currentWeight = currentWeight - hidden[h].GetOutput()*deltaOutputLayer*speed;

			output.SetWeight(&hidden[h], currentWeight);
		}
		
		for (int h = 0; h < hidden.size(); h++)
		{
			float currentWeight = output.GetWeight(&hidden[h]);
			float currentError = currentWeight*deltaOutputLayer;

			float currentDelta = currentError * hidden[h].GetOutput() * (1- hidden[h].GetOutput());

			for (int i = 0; i < inputs.size(); i++)
			{
				float currentW = hidden[h].GetWeight(&inputs[i]);
				currentW = currentW - inputs[i].GetOutput()*currentDelta*speed;
				hidden[h].SetWeight(&inputs[i], currentW);
			}
		}
	/*	cout << "indexTest: " << indexTest << endl;
		cout << "actual: " << output.GetOutput() << endl;
		cout << "expected: " << answers[indexTest] << endl << endl;*/
	}

	SetInputs(tests[0], inputs);
	for (int h = 0; h < hidden.size(); h++)
	{
		hidden[h].Activate();
	}
	output.Activate();

	cout << "actual: " << output.GetOutput() << endl;
	cout << "expected: " << answers[1] << endl << endl; 

	cin.get();
}