#include "Tensor.h"

Tensor Tensor::operator*(const Tensor& other) {
    vector<vector<double> > matrix3{other.array.size()};

    for (size_t i = 0; i < other.array.size(); i++) {

        for (size_t j = 0; j < other.array[0].size(); j++) {
            
            double result = 0;
            for (size_t k = 0; k < other.array.size(); k++) {
                result += array[i][k] * other.array[k][j];
            }
            matrix3[i].push_back(result);
        }
    }

    Tensor product = { array = matrix3 };
    return product;
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