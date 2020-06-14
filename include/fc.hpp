#ifndef __FC__HPP_
#define __FC__HPP_

#include <iostream>
#include <vector>
#include "matrix.hpp"
#include "layer.hpp"
#include "utils/matrix_multiplication.hpp"

using namespace std;

class FC {
public:
    FC(vector<int> architecture);

    void set_input(vector<double> input);
    void set_target(vector<double> target_) {this->target=target_;};

    void feed_forward_move();

    void print_model_to_stdout();

    void set_errors();

    Matrix *get_matrix(int index_) { return this->layers.at(index_)->flatten_matrix_values(); };

    Matrix *get_activated_matrix(int index_) { return this->layers.at(index_)->flatten_matrix_activated_values(); };

    Matrix *get_derived_matrix(int index_) { return this->layers.at(index_)->flatten_matrix_derivative_values(); };

    Matrix *get_weighted_matrices(int layer_index) { return this->weighted_matrices.at(layer_index); };

    void set_neuron_value(int layer_index, int neuron_index, double value) {
        this->layers.at(layer_index)->set_value(neuron_index, value);
    };

    double get_total_error() { return this->total_error; };

    vector<double> get_errors() { return this->errors; };

private:

    vector<int> architecture;
    int architecture_size;
    vector<Layer *> layers;
    vector<Matrix *> weighted_matrices;
    vector<double> input;
    vector<double> target;
    double total_error;
    vector<double> errors;
    vector<double> errors_history;

};


#endif