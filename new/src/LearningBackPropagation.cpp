#include "headers/LearningBackPropagation.hpp"

LearningBackPropagation::LearningBackPropagation(NeuralNetwork* target, double s) {
    speed = s;
    currentIteration = 0;
    network = target;
}

void LearningBackPropagation::start(unsigned iterationCount, unsigned printLog = 0) {
    for (unsigned i=1; i<=iterationCount; i++, currentIteration++) {
        iteration();
        if (printLog!=0 && i%printLog==0) log();
    }
}

void LearningBackPropagation::iteration() {
    //
}

void LearningBackPropagation::log() {
    cout << "Iteration " << currentIteration << ", (speed: " << speed << ")" << endl;
}
