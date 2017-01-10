#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>
#include <cmath>

using namespace std;

enum NeuronType {Input, Hidden, Output};

class Neuron {
private:
    double bias;

    NeuronType type;
public:
    double output;

    vector<double*> input;

    vector<double> weight;

    Neuron(NeuronType type);
    void setInput(double bias, vector<double*> input, vector<double> weight);
    double getOutput();
    double summator();
    double activator(double);
    void process();
};

#endif
