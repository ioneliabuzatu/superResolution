#ifndef _MODEL_HPP_
#define _MODEL_HPP_

#include "../include/fc.hpp"
#include <vector>

void FC::set_errors() {
    if (this->target.size() == 0) {
        cerr << "No targets" << endl;
        assert(false);
    }
    if (this->target.size() != this->layers.at(this->layers.size() - 1)->get_neurons().size()) {
        cerr << "Target size is not has the last layer size" << endl;
        assert(false);
    }

    this->total_error = 0.0;
    int output_layer_index = this->layers.size() - 1;
    vector<Neuron *> output_neurons = this->layers.at(output_layer_index)->get_neurons();
    for (int neuron_unit = 0; neuron_unit < target.size(); neuron_unit++) {
        double cost_function_error = (output_neurons.at(neuron_unit)->get_activated_value() - target.at(neuron_unit));
        this->total_error += cost_function_error;
        errors.push_back(cost_function_error);
    }
    errors_history.push_back(this->total_error);
}


void FC::feed_forward_move() {
    for (int layer_ = 0; layer_ < this->layers.size() - 1; layer_++) {
        Matrix *matrix_a = this->get_matrix(layer_);
        if (layer_ != 0) {
            matrix_a = this->get_activated_matrix(layer_);
        }
        Matrix *matrix_b = this->get_weighted_matrices(layer_);
        Matrix *matrix_c = (new utils::Matrix_multiplication(matrix_a, matrix_b))->execute();

        for (int matrix_c_index = 0; matrix_c_index < matrix_c->get_num_cols(); matrix_c_index++) {
            this->set_neuron_value(layer_ + 1, matrix_c_index, matrix_c->get_value(0, matrix_c_index));
        }
    }

}

void FC::set_input(vector<double> input) {
    this->input = input;
    for (int layer_ = 0; layer_ < input.size(); layer_++) {
        this->layers.at(0)->set_value(layer_, input.at(layer_));
    }

}


FC::FC(vector<int> architecture) {
    this->architecture = architecture;
    this->architecture_size = architecture.size();
    for (int layer_ = 0; layer_ < architecture_size; layer_++) {
        Layer *new_layer = new Layer(architecture.at(layer_));
        this->layers.push_back(new_layer);
    }
    for (int layer_ = 0; layer_ < (architecture.size() - 1); layer_++) {
        Matrix *new_matrix = new Matrix(architecture.at(layer_), architecture.at(layer_ + 1));
        this->weighted_matrices.push_back(new_matrix);
    }


}

void FC::print_model_to_stdout() {
    cout << "TOT LAYERS: " << layers.size() << endl;
    for (int layer_ = 0; layer_ < this->layers.size(); layer_++) {
        cout << "LAYER: " << layer_ << endl;
        if (layer_ == 0) {
            Matrix *matrix_ = this->layers.at(layer_)->flatten_matrix_values();
            matrix_->print_matrix_to_stdout();
        } else {
            Matrix *matrix_ = this->layers.at(layer_)->flatten_matrix_activated_values();
            matrix_->print_matrix_to_stdout();
        }
        if (layer_ < this->layers.size() - 1) {
            cout << "\n--- Weight matrix ---" << endl;
            this->get_weighted_matrices(layer_)->print_matrix_to_stdout();
            cout << endl;
        }
    }
}


#endif