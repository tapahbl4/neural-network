#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>
#include <cmath>
#include <iostream>

//#include "Layer.hpp"

using namespace std;

enum NeuronType {Input, Hidden, Output};

class Neuron {
private:
    double bias;
    NeuronType type;
public:
    double output;
    double sum;
    vector<double*> input;
    vector<double> weight;

    vector<Neuron*>* prevLayer;
    double error; // (t-y)*f'(sum)
    double delta; // speed*error*input
    double delta_bias; // speed*error


    Neuron(NeuronType type);
    void setInput(double bias, vector<double*> input, vector<double> weight);
    double getOutput();
    double summator();
    double activator(double);
    double derivative(double);
    void process();
    void calcError();
    void learn(double);
    void learn(double,double);
};

#endif
