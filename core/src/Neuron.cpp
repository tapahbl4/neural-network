#include "headers/Neuron.hpp"

/* constructor */
Neuron::Neuron() {
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
    double a = 3;
    return (2.0 / (1 + exp(-a*x))) - 1;
    // if (x>0) return 1;
    // else if (x<0) return -1;
    // else return 0;
}

double Neuron::derivative(double x) {
    double a = 2.5;
    return (2 * a * exp(a*x)) / ((exp(a*x) + 1) * (exp(a*x) + 1));
}

double Neuron::getSummatorValue() {
    return summator_value;
}

/* other */
void Neuron::process() {
    double sum = summator();
    output = activator(sum);
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
