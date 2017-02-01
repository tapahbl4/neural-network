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

void loadData(vector<double> &r) {
    ifstream data;
    data.open("../prepare/timeline.txt");
    double t;
    //vector<double> r;
    while (data >> t) {
        //cout << t << " ";
        r.push_back(t);
    }
    //return r;
}

int main(int argc, char** argv) {
    srand(time(0));
    string filename = "conf/test.nn";
    Network* neuralNetwork = new Network();
    neuralNetwork->open(filename);
    vector<double> data;
    loadData(data);
    cout << data.size() << endl;
    for (int i=0; i<=1000; i++) {
        if (i%20==0) cout << "iteration "<< i<<endl;
        vector<double> lr;
        //copy(data.begin()+i, data.begin()+i+4, lr.begin());
        for (int j=0; j<5; j++) lr.push_back(data[i+j]);
        neuralNetwork->learn(10, lr, data[i+5]);
    }
    neuralNetwork->save(filename);

    int a = 0;
    for (int i=1000; i<=1100; i++) {
        if (i%5==0) cout << "\ntest " << (i-1000) <<endl;
        vector<double> lr;
        //copy(data.begin()+i, data.begin()+i+5, lr.begin());
        for (int j=0; j<5; j++)
            lr.push_back(data[i+j]);
        //neuralNetwork->learn(1, lr, data[i+6]);
        vector<double> output = neuralNetwork->process(lr);
        //if (output[0]==data[i+5]) a++;
        cout << (output[0]) << " ";
    }
    cout << "result = " << a << endl;
    //neuralNetwork->save(filename);

    /*vector<double> input = {5.1, 10.2, 234.3},
                   output = neuralNetwork->process(input);
    //neuralNetwork->printAll();
    neuralNetwork->save(filename);*/
    /*for (unsigned i=0; i<output.size(); i++) {
        cout << output[i];
        if (i+1==output.size()) cout << endl;
        else cout << ", ";
    }*/



    return 0;
}
