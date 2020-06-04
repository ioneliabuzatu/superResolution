#include <iostream>
#include "../include/neuron.hpp"
#include "../include/layer.hpp"
#include "../include/matrix.hpp"


using namespace std;

int main(int argc, char **argv) {
//    srand((unsigned) time(NULL));
//    NeuronUnit *neuron_ = new NeuronUnit(999.9);
//    cout << "Neuron value: " << neuron_->get_value() << endl;
//    cout << "Neuron activated: " << neuron_->get_activated_value() << endl;
//    cout << "Neuron derivative: " << neuron_->get_derivative_activated_value() << endl;
//    Layer *layer_ = new Layer(10);
    Matrix *matrix = new Matrix(4,4);
    matrix->print_matrix_to_stdout();
    srand((unsigned) time(NULL));
    cout << (double) rand() / RAND_MAX << endl;

    return 0;
}