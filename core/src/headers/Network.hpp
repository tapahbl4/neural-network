#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <fstream>
#include <iostream>
#include <vector>
#include "Layer.hpp"
#include "Neuron.hpp"

class Network {
private:
    //ifstream scheme;
    double speed;
    vector<Layer*> layers;
public:
    Network();
    void open(string);
    void setWeight(string);
    vector<double> process(vector<double>);
    void printAll();
    void save(string);
    void learn(vector<double>);
    double getError();

};

#endif
