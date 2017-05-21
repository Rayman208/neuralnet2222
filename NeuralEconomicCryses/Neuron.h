#pragma once

#include <iostream>
#include <map>

using namespace std;

class Neuron
{
private:
	map<Neuron*, float> m_inputConnections;
	float m_output;
public:
	Neuron();
	~Neuron();

	void SetConnection(Neuron * neuron, float weight);
	
	float GetOutput();
	void SetOutput(float output);

	void Activate();
};

