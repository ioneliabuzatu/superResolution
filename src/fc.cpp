#include "../include/fc.hpp"

void FC::set_input(vector<double> input) {
    this->input = input;
    for (int layer_; layer_ < input.size(); layer_++) {
        this->layers.at(0)->set_value(layer_, input.at(layer_));
    }

}


FC::FC(vector<int> architecture) {
    for (int layer_ = 0; architecture.size(); layer_++) {
        Layer *new_layer = new Layer(architecture.at(layer_));
        this->layers.push_back(new_layer);
    }

    for (int layer_ = 0; architecture.size() - 1; layer_++) {
        Matrix *new_matrix = new Matrix(architecture.at(layer_), architecture.at(layer_ + 1));
        this->weighted_matrices.push_back(new_matrix);
    }


}