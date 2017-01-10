#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "headers/Neuron.hpp"
#include "headers/Layer.hpp"
#include "headers/Network.hpp"

#define rangerand(A,B) rand() % B + A
#define randone() ((double) rand() / (RAND_MAX))

using namespace std;

int main(int argc, char** argv) {
    srand(time(0));
    string filename = "conf/test.nn";
    Network* neuralNetwork = new Network();
    neuralNetwork->open(filename);
    vector<double> input = {5.1, 10.2, 234.3},
                   output = neuralNetwork->process(input);
    //neuralNetwork->printAll();
    neuralNetwork->save(filename);
    for (unsigned i=0; i<output.size(); i++) {
        cout << output[i];
        if (i+1==output.size()) cout << endl;
        else cout << ", ";
    }
    return 0;
}
