#include "headers/Neuron.hpp"

Neuron::Neuron(NeuronType type) {
    this->type = type;
}

double Neuron::summator() {
    double sum = bias;
    for (unsigned i=0; i<input.size(); i++) {
        sum += (*input[i])*weight[i];
    }
    return sum;
}

void Neuron::setInput(double bias, vector<double*> input, vector<double> weight) {
    this->bias = bias;
    this->input = input;
    this->weight = weight;
}

double Neuron::getOutput() {
    return this->output;
}

void Neuron::process() {
    double x = summator();
    this->output = activator(x);
}

double Neuron::activator(double x) {
    double a = 1.0;
    return 1.0 / (1.0 + exp(-x * a));
}
