#include "headers/LearningBackPropagation.hpp"

LearningBackPropagation::LearningBackPropagation(NeuralNetwork* target) {
    currentIteration = 0;
    network = target;
}

void LearningBackPropagation::start(ListDouble data, double s, unsigned _iterationCount, unsigned printLog = 0) {
    learnData = data;
    speed = s;
    if (learnData.size()<_iterationCount) {
        cout << "data vector length less than iteration count" << endl;
        cout << learnData.size() << endl;
        return;
    } else {
        iterationCount = _iterationCount;
    }
    unsigned inputLayerLength = network->getLayerAt(0).size(),
             outputLayerLength = network->getLayerAt(network->getLayersCount()-1).size();
    currentIteration = 0;
    summaryError = 0;
    for (unsigned i=0; i<iterationCount; i++) {
        currentIteration++;
        ListDouble input, teacher;
        for (unsigned j=0; j<inputLayerLength; j++) input.push_back(learnData[i+j]);
        for (unsigned j=0; j<outputLayerLength; j++) teacher.push_back(learnData[i+j+inputLayerLength]);
        iteration(input, teacher);
        if (printLog!=0 && currentIteration%printLog==0) log();
    }
}

void LearningBackPropagation::iteration(ListDouble input, ListDouble teacher) {
    network->setInput(input);
    network->process();
    ListDouble output = network->getOutput();
    double err_sum_prev = 0, err_sum = 0;
    for (unsigned i=network->getLayersCount()-1; i>0; i--) {
        ListDouble derivatives = network->getDerivativesLayer(i);
        err_sum = 0;
        for (unsigned j=0; j<network->getLayerAt(i).size(); j++) {
            double err;
            if (i+1==network->getLayersCount()) {
                err = (teacher[j] - output[j])*derivatives[j];
            }
            else {
                err = err_sum_prev * derivatives[j];
            }
            double delta = getSpeed()*err;
            for (unsigned k=0; k<network->getLayerAt(i)[j]->getLength(); k++) {
                err_sum += *(network->getLayerAt(i)[j]->getInputAt(k)) * err;
                network->getLayerAt(i)[j]->correctWeightAt(k, *(network->getLayerAt(i)[j]->getInputAt(k)) * delta);
            }
            network->getLayerAt(i)[j]->correctBias(delta);
        }
        err_sum_prev = err_sum;
    }
}

double LearningBackPropagation::test(ListDouble testData) {
    unsigned inputLayerLength = network->getLayerAt(0).size(),
             outputLayerLength = network->getLayerAt(network->getLayersCount()-1).size();
    double global_sum = 0, testCount = testData.size()-inputLayerLength-outputLayerLength;
    for (unsigned i=0; i<testCount; i++) {
        ListDouble input, test;
        for (unsigned j=0; j<inputLayerLength; j++) input.push_back(testData[i+j]);
        for (unsigned j=0; j<outputLayerLength; j++) test.push_back(testData[i+j+inputLayerLength]);
        network->setInput(input);
        network->process();
        ListDouble output = network->getOutput();
        double sum = 0;
        for (unsigned j=0; j<output.size(); j++) {
            sum += (output[j]-test[j])*(output[j]-test[j]);
        }
        sum /= output.size();
        global_sum += sum;
    }
    global_sum /= testCount-1;
    return sqrt(global_sum)*100;
}

void LearningBackPropagation::log() {
    cout << "Iteration " << currentIteration << ", (speed: " << speed << ")" << endl;
}
