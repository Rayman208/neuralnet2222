#include "Neuron.h"



Neuron::Neuron()
{
}


Neuron::~Neuron()
{
}

void Neuron::SetConnection(Neuron * neuron, float weight)
{
	m_inputConnections[neuron]=weight;
}

float Neuron::GetOutput()
{
	return m_output;
}

void Neuron::SetOutput(float output)
{
	m_output = output;
}

void Neuron::Activate()
{
	float net = 0;
	for (auto & pair : m_inputConnections)
	{
		net += pair.first->GetOutput()*pair.second;
	}

	m_output = 1.0 / (1.0 + exp(-net));
}

float Neuron::GetWeight(Neuron * neuron)
{
	return m_inputConnections[neuron];
}

void Neuron::SetWeight(Neuron * neuron, float weight)
{
	m_inputConnections[neuron] = weight;
}
