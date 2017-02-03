#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "headers/Neuron.hpp"
#include "headers/NeuralNetwork.hpp"
#include "headers/LearningBackPropagation.hpp"

using namespace std;

int main(int argc, char** argv) {
    ListDouble sampleInput(5, 1);
    NeuralNetwork* network = new NeuralNetwork();
    network->loadFromFile("../core/conf/test.nn");
    network->setInput(sampleInput);
    network->process();
    network->printOutput();
    network->saveToFile("../core/conf/test.nn");
    LearningBackPropagation* learning = new LearningBackPropagation(network, 0.5);
    learning->start(10, 2);
    delete network;
    return 0;
}
