#include "headers/Learning.hpp"
//
// Learning::Learning(NeuralNetwork* target, double s) {
//     speed = s;
//     iteration = 0;
//     network = target;
// }
//
// void Learning::algorithmBackPropagation(ListDoubleP learning_data, double teacher, unsigned iteration_count) {
//     for (unsigned i=1; i<=iteration_count; i++) {
//         iteration++;
//         //
//     }
// }
// void Learning::testBackPropagation() {
//     //
// }

double Learning::getSpeed() {
    return speed;
}

void Learning::setSpeed(double s) {
    speed = s;
}
