#include "../include/matrix.hpp"
#include <iostream>
#include <random>

using namespace std;

double Matrix::random_numbers_generator() {
    return (double) rand() / RAND_MAX;
//    random_device random_dev;
//    mt19937 gen(random_dev());
//    uniform_real_distribution<> dis(0.0,100000.0);
//    srand((unsigned) time(NULL));
}


void Matrix::print_matrix_to_stdout() {
    for (int row = 0; row < num_rows; row++) {
        for (int col = 0; col < num_cols; col++) {
            cout << this->values.at(row).at(col) << "\t\t";
        }
        cout << endl;
    }
}

Matrix::Matrix(int num_rows, int num_cols) {
    this->num_rows = num_rows;
    this->num_cols = num_cols;

    for (int row = 0; row < num_rows; row++) {
        vector<double> colum_values;
        for (int col = 0; col < num_cols; col++) {
            double random_number = random_numbers_generator();
            colum_values.push_back(random_number);
        }
        this->values.push_back(colum_values);
    }
}
