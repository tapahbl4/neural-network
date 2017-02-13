#ifndef NEURALNETWORK_HPP
#define NEURALNETWORK_HPP

#include <vector>
#include <fstream>
#include <iostream>
#include "Neuron.hpp"

#define rangerand(A,B) rand() % B + A
#define randone() ((double) rand() / (RAND_MAX))

typedef std::vector<Neuron*> ListNeuronP;
typedef std::vector<ListNeuronP> ListLayer;

using namespace std;

class NeuralNetwork {
private:
    ListLayer layers;
    bool isReady;
public:
    NeuralNetwork();
    void loadFromFile(string, bool);
    void saveToFile(string);
    void print();
    ListDoubleP getOutputPointers(unsigned);
    void process();
    void setInput(ListDouble);
    ListDouble getOutput();
    void printOutput(string);
    ListNeuronP getLayerAt(unsigned);
    unsigned getLayersCount();
    ListDouble getDerivativesLayer(unsigned);
};

#endif
