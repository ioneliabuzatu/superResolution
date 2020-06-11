#include <iostream>
#include <vector>
#include "../include/neuron.hpp"
#include "../include/matrix.hpp"
#include "../include/fc.hpp"

using namespace std;

int main(int argc, char **argv) {
    cout << "\n_____ Neuron Unit Example ______" << endl;
    Neuron *neuron_ = new Neuron(0.8);
    cout << "Neuron value: " << neuron_->get_value() << endl;
    cout << "Neuron activated: " << neuron_->get_activated_value() << endl;
    cout << "Neuron derivative: " << neuron_->get_derivative_activated_value() << "\n" << endl;
    Layer *layer_ = new Layer(10);

    Matrix *matrix = new Matrix(4, 3);
    matrix->print_matrix_to_stdout();
    cout << "\n_____ Transpose matrix ______" << endl;
    Matrix *matrix_traspose = matrix->transpose_matrix();
    matrix_traspose->print_matrix_to_stdout();


    cout << "\n_____ Building model _____" << endl;
    vector<int> architecture;
    architecture.push_back(3);
    architecture.push_back(2);
    architecture.push_back(3);

    vector<double> dummy_input;
    dummy_input.push_back(1);
    dummy_input.push_back(0);
    dummy_input.push_back(1);

    FC *model = new FC(architecture);
    model->set_input(dummy_input);
    model->print_model_to_stdout();
    model->feed_forward_move();

    cout << "\n----- Model after first forward pass -------" << endl;
    model->print_model_to_stdout();


    return 0;
}