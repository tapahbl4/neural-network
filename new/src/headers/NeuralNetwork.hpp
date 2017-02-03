#ifndef NEURALNETWORK_HPP
#define NEURALNETWORK_HPP

#include <vector>
#include <fstream>
#include <iostream>
#include "Neuron.hpp"

typedef std::vector<Neuron*> ListNeuronP;
typedef std::vector<ListNeuronP> ListLayer;

using namespace std;

class NeuralNetwork {
private:
    ListLayer layers;
    bool isReady;
public:
    NeuralNetwork();
    void loadFromFile(string);
    void saveToFile(string);
    void print();
    ListDoubleP getOutputPointers(unsigned);
    void process();
    void setInput(ListDouble);
    ListDouble getOutput();
    void printOutput();
    ListNeuronP getLayerAt(unsigned);
};

#endif
