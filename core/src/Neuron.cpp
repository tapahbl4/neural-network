#include "headers/Neuron.hpp"

/* constructor */
Neuron::Neuron() {
    // input = NULL;
    bias = 0;
    summator_value = output = 0;
}

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
    if (p>=input.size()) input.push_back(v);
    else input[p] = v;
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

void Neuron::setWeightAdd(double v) {
    weight.push_back(v);
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
    return 1.0 / (1.0 + exp(-x));
}

double Neuron::derivative(double x) {
    return activator(x)*(1.0 - activator(x));
}

double Neuron::getSummatorValue() {
    return summator_value;
}

/* other */
void Neuron::process() {
    double sum = summator();
    output = activator(sum);
    // cout << sum << endl;
}

unsigned Neuron::getLength() {
    return weight.size();
}

void Neuron::correctBias(double c) {
    bias += c;
}

void Neuron::correctWeightAt(unsigned n, double c) {
    weight[n] += c;
}
