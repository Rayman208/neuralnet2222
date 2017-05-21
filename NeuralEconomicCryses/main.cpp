#include "Neuron.h"


void main()
{
	Neuron inputs[4];
	Neuron hidden[3];
	Neuron output;

	inputs[0].SetOutput(1);
	hidden[0].SetConnection(&inputs[0], 0.4);
}