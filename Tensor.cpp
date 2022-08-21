#include "Tensor.h"

Tensor Tensor::operator*(const Tensor& other) {
    vector<vector<double> > matrix3{this->num_rows()};

    for (size_t i = 0; i < this->num_rows(); i++) {

        for (size_t j = 0; j < other.num_cols(); j++) {
            
            double result = 0;
            for (size_t k = 0; k < other.num_rows(); k++) {
                result += this->array[i][k] * other.array[k][j];
            }
            matrix3[i].push_back(result);
        }
    }

    return Tensor(matrix3);
}

Tensor Tensor::operator+(const vector<double>& vec) {
    Tensor t(this->array);
    // add each vector[i] value to each matrix[j][i] value
    for (size_t j = 0; j < t.array.size(); j++) {
        for (size_t i = 0; i < vec.size(); i++) {
            t.array[j][i] += vec[i];
        }
    }
    return t;
}


Tensor Tensor::transpose() {
    vector<vector<double> > t_matrix{this->num_cols()}; // initializing transpose matrix at size of original matrix's dimension

    // for each row value in matrix, take each value and push them into the new matrix's column
    for (size_t i = 0; i < this->num_rows(); i++) {
        // pushing each original row value into each column space for new matrix
        for (size_t j = 0; j < this->num_cols(); j++) {
            //t_matrix.push_back(emptyvec);
            t_matrix[j].push_back(this->array[i][j]);
        }
    }

    return t_matrix;
}




string Tensor::shape() {
    ostringstream shapeOSS;
    if (this->array.size() != 0) {
        shapeOSS << '(' << this->array.size() << ", " << this->array[0].size() << ')';
    } else {
        shapeOSS << "(0, 0) -- no data inputted in tensor";
    }
    return shapeOSS.str();
}

string Tensor::to_string() {
    ostringstream matrixOSS;

    for (vector<double> row : this->array) {
        matrixOSS << vec_to_string(row) << '\n';
    }

    return matrixOSS.str();
}

template <typename T>
string Tensor::vec_to_string(vector<T>& v) {
    ostringstream vecOSS;

    vecOSS << '[';
    for (size_t i = 0; i < v.size() - 1; i++) {
        vecOSS << v[i] << ", ";
    }
    vecOSS << v[v.size()-1] << ']'; // adding last value in vector without a comma after it to close vector

    return vecOSS.str();
}