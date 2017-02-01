#include "headers/Neuron.hpp"

/* constructor */
Neuron::Neuron(ListDoubleP i, ListDouble w, double b) {
    input = i;
    weight = w;
    bias = b;
    summator_value = output = 0;
}

/* input */
ListDoubleP Neuron::getInput() {
    return input;
}

double* Neuron::getInputAt(unsigned p) {
    return input[p];
}

void Neuron::setInput(ListDoubleP list) {
    input = list;
}

void Neuron::setInputAt(unsigned p, double* v) {
    input[p] = v;
}

/* bias */
double Neuron::getBias() {
    return bias;
}

void Neuron::setBias(double b) {
    bias = b;
}

/* weight */
ListDouble Neuron::getWeight() {
    return weight;
}

double Neuron::getWeightAt(unsigned p) {
    return weight[p];
}

void Neuron::setWeight(ListDouble list) {
    weight = list;
}

void Neuron::setWeightAt(unsigned p, double v) {
    weight[p] = v;
}

/* output */
double* Neuron::getOutputPointer() {
    return &output;
}

double Neuron::getOutputValue() {
    return output;
}

/* body */
double Neuron::summator() {
    double result = bias;
    for (unsigned i=0; i<input.size(); i++) {
        result += (*input[i]) * weight[i];
    }
    summator_value = result;
    return result;
}

double Neuron::activator(double x) {
    return exp(-x);
}

double Neuron::derivative(double x) {
    return exp(-x);
}

double Neuron::getSummatorValue() {
    return summator_value;
}

/* other */
void Neuron::process() {
    //
}
