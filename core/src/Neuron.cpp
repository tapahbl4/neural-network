#include "headers/Neuron.hpp"

Neuron::Neuron(NeuronType type) {
    this->type = type;
    error = 0.0;
}

double Neuron::summator() {
    double s = bias;
    for (unsigned i=0; i<input.size(); i++) {
        s += (*input[i])*weight[i];
    }
    return s;
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
    this->sum = summator();
    this->output = activator(this->sum);
}

double Neuron::activator(double x) {
    //double a = 1.0;
    cout << 1.0 / (1.0 + exp(-x)) << "e ";
    return 1.0 / (1.0 + exp(-x));
}

double Neuron::derivative(double x) {
    //double a = 1.0;
    cout << activator(x)*(1.0 - activator(x)) << "d ";
    return activator(x)*(1.0 - activator(x));
}

// обучение для скрытых
void Neuron::learn(double speed) {
    error = error*derivative(sum);
    delta = error*speed;
    for (unsigned i=0; i<prevLayer->size(); i++) {
        (*prevLayer)[i]->error += error;
        weight[i] += delta*(*input[i]);
        bias += delta;
    }
}

// обучение для выходных
void Neuron::learn(double speed, double t) {
    error = (t-output)*derivative(sum);
    delta = speed*error;
    for (unsigned i=0; i<prevLayer->size(); i++) {
        (*prevLayer)[i]->error += error;
        weight[i] += delta*(*input[i]);
        bias += delta;
    }
}
