#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "headers/Neuron.hpp"
#include "headers/NeuralNetwork.hpp"
#include "headers/LearningBackPropagation.hpp"

using namespace std;

ListDouble loadData(string filename) {
    ifstream file(filename);
    ListDouble result;
    double t;
    while (file >> t) {
        result.push_back(t);
    }
    return result;
}

int main(int argc, char** argv) {
    ListDouble data = loadData("../prepare/timeline.txt"), l, t;
    unsigned c = 4000, a = 500;
    for (unsigned i=0; i<a; i++) {
        l.push_back(data[c+i]-1);
        t.push_back(data[c+i+a]-1);
    }
    NeuralNetwork* network = new NeuralNetwork();
    network->loadFromFile("conf/test.nn");
    LearningBackPropagation* learning = new LearningBackPropagation(network, 0.5, l);
    learning->start(500, 100);
    double error = learning->test(t);
    network->saveToFile("conf/test.nn");
    // for (unsigned i=5000; i<5010; i++) {
    //     ListDouble u;
    //     for (unsigned j=0; j<5; j++) u.push_back(data[i]);
    //     network->setInput(u);
    //     network->process();
    //     cout << "compare: " << data[i+5]-1 << " and ";
    //     network->printOutput();
    // }
    delete network;
    cout << "Error: " << error*100 << " percents" << endl;
    return 0;
}
