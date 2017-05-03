#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstring>

#include "headers/Neuron.hpp"
#include "headers/NeuralNetwork.hpp"
#include "headers/LearningBackPropagation.hpp"

using namespace std;


/**
 * Load data from text file
 * @param  filename File name with path
 * @return          String vector of data
 */
ListDouble loadData(string filename) {
    ifstream file(filename);
    ListDouble result;
    double t;
    while (file >> t) {
        result.push_back(t);
    }
    return result;
}

/**
 * Main function
 * @param  argc Arguments count
 * @param  argv Arguments array
 * @return      Exit code
 */
int main(int argc, char** argv) {
    bool learn = false, test = false, process = false;
    double speed = 0;
    unsigned iteration = 0, printlog = 0;
    string inputfile="", outputfile="stdout", datafile="";
    for (int i=1; i<argc; i++) {
        if (strcmp(argv[i], "--version")==0 || strcmp(argv[i], "-v")==0) {
            cout << "v0.0.2\nDmitry Marchenko" << endl;
            return EXIT_SUCCESS;
        }
        if (strcmp(argv[i], "--help")==0 || strcmp(argv[i], "-h")==0) {
            cout << "Neural network\nUsage:\nTODO" << endl;
            return EXIT_SUCCESS;
        }
        if (strcmp(argv[i], "--learn")==0 || strcmp(argv[i], "-l")==0) {
            learn = true;
        }
        if (strcmp(argv[i], "--speed")==0 || strcmp(argv[i], "-s")==0) {
            if (learn) {
                speed = stod(argv[i+1]);
                i++;
                continue;
            }
        }
        if (strcmp(argv[i], "--test")==0 || strcmp(argv[i], "-t")==0) {
            test = true;
        }
        if (strcmp(argv[i], "--process")==0 || strcmp(argv[i], "-p")==0) {
            process = true;
        }
        if (strcmp(argv[i], "--input")==0 || strcmp(argv[i], "-i")==0) {
            inputfile = argv[i+1];
            i++;
            continue;
        }
        if (strcmp(argv[i], "--output")==0 || strcmp(argv[i], "-o")==0) {
            outputfile = argv[i+1];
            i++;
            continue;
        }
        if (strcmp(argv[i], "--data")==0 || strcmp(argv[i], "-d")==0) {
            datafile = argv[i+1];
            i++;
            continue;
        }
        if (strcmp(argv[i], "--iteration")==0) {
            iteration = stoi(argv[i+1]);
            i++;
            continue;
        }
        if (strcmp(argv[i], "--log")==0) {
            printlog = stoi(argv[i+1]);
            i++;
            continue;
        }
    }
    // Running with CLI params
    NeuralNetwork* network = new NeuralNetwork();
    network->loadFromFile(inputfile, false);
    if (learn) {
        ListDouble data = loadData(datafile);
        LearningBackPropagation* learning = new LearningBackPropagation(network);
        learning->start(data, speed, iteration!=0 ? iteration : data.size(), printlog);
        network->saveToFile(outputfile);
    }
    if (test) {
        ListDouble data = loadData(datafile);
        LearningBackPropagation* learning = new LearningBackPropagation(network);
        double error = learning->test(data);
        if (outputfile=="stdout") {
            cout << error << endl;
        } else {
            ofstream file(outputfile);
            file << error << endl;
            file.close();
        }
    }
    if (process) {
        ListDouble data = loadData(datafile);
        network->setInput(data);
        network->process();
        network->printOutput(outputfile);
    }
    delete network;
    return 0;
}
