#ifndef TEST_MATRIX_H
#define TEST_MATRIX_H

#include <iostream>

using namespace std;

template<class T>
class Matrix {
private:
    T **ptr = NULL;
    int rows = 0, cols = 0;

public:
    Matrix() = default;

    Matrix(int x, int y) {
        rows = x;
        cols = y;
        ptr = new T *[rows];
        for (int i = 0; i < rows; i++)
            ptr[i] = new T[cols];
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++)
            delete[] ptr[i];
        delete ptr;
        ptr = NULL;
    }

    int getRow() {
        return rows;
    }

    int getCols() {
        return cols;
    }

    friend ostream &operator<<(ostream &o, const Matrix<T> &obj) {
        for (int i = 0; i < obj.rows; i++) {
            for (int j = 0; j < obj.cols; j++)
                o << obj.ptr[i][j] << " ";
            o << endl;
        }
        return o;
    }

    friend istream &operator>>(istream &is, Matrix<T> &obj) {
        cin >> obj.rows >> obj.cols;
        obj.ptr = new T *[obj.rows];
        for (int i = 0; i < obj.rows; i++)
            obj.ptr[i] = new T[obj.cols];
        for (int i = 0; i < obj.rows; i++)
            for (int j = 0; j < obj.cols; j++)
                is >> obj.ptr[i][j];
        return is;
    }

    Matrix<T> operator+(Matrix<T> &obj) {
        Matrix<T> obj2(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                obj2.ptr[i][j] = ptr[i][j] + obj.ptr[i][j];
        return obj2;
    }

    Matrix<T> operator-(Matrix<T> &obj) {
        Matrix<T> obj2(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                obj2.ptr[i][j] = ptr[i][j] - obj.ptr[i][j];
        return obj2;
    }

    Matrix<T> operator*(Matrix<T> &obj) {
        Matrix<T> obj2(rows, obj.cols);

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < obj.cols; j++)
                obj2.ptr[i][j] = 0;

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < obj.cols; j++)
                for (int n = 0; n < cols; n++)
                    obj2.ptr[i][j] += ptr[i][n] * obj.ptr[n][j];
        return obj2;
    }

    Matrix<T> TransposeMatrix() {
        Matrix<T> obj(cols, rows);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                obj.ptr[j][i] = ptr[i][j];
        return obj;
    }
};

template<class T>
class MatrixCalculator {
public:
    MatrixCalculator() = default;

    ~MatrixCalculator() = default;

    void matrixMenu() {
        bool state = true;
        int num;
        Matrix<T> matrixOb, matrixOb2;
        while (state) {
            cout << "Welcome to the simple Matrix Calculator\n\n";
            cout << "----------------------\n\n";
            cout << "Choose a desired option from below:\n\n\n";
            cout << "1- Perform Matrix Addition\n\n";
            cout << "2- Perform Matrix Subtraction\n\n";
            cout << "3- Perform Matrix Multiplication\n\n";
            cout << "4- Matrix Transpose\n\n";
            cout << "5- Close app\n\n";
            cin >> num;
            switch (num) {
                case 1:
                    cout << "Specify the dimensions of the first matrix\nthen input it's data\n";
                    cin >> matrixOb;
                    cout << "Now, specify the dimensions of the second matrix\nthen input it's data\n";
                    cin >> matrixOb2;
                    if (matrixOb.getRow() == matrixOb2.getRow() && matrixOb.getCols() == matrixOb2.getCols())
                        cout << "Sum = \n" << matrixOb + matrixOb2 << endl;
                    else
                        cout << "Sorry, the two matrices are NOT equal\n";
                    break;
                case 2:
                    cout << "Specify the dimensions of the first matrix\nthen input it's data\n";
                    cin >> matrixOb;
                    cout << "Now, specify the dimensions of the second matrix\nthen input it's data\n";
                    cin >> matrixOb2;
                    if (matrixOb.getRow() == matrixOb2.getRow() && matrixOb.getCols() == matrixOb2.getCols())
                        cout << "Difference = \n" << matrixOb - matrixOb2 << endl;
                    else
                        cout << "Sorry, the two matrices are NOT equal\n";
                    break;
                case 3:
                    cout << "Specify the dimensions of the first matrix\nthen input it's data\n";
                    cin >> matrixOb;
                    cout << "Now, specify the dimensions of the second matrix\nthen input it's data\n";
                    cin >> matrixOb2;
                    if (matrixOb.getCols() == matrixOb2.getRow())
                        cout << "Product = \n" << matrixOb * matrixOb2 << endl;
                    else
                        cout << "Sorry, the two matrices should be in form of N x M and M x P\n";
                    break;
                case 4:
                    cout << "Specify the dimensions of the first matrix\nthen input it's data\n";
                    cin >> matrixOb;
                    cout << "Transpose = \n" << matrixOb.TransposeMatrix() << endl;
                    break;
                case 5:
                    state = false;
                    break;
                default:
                    cout << "Please, enter a valid number from the above choices\n";
            }
        }
    }
};

#endif //TEST_MATRIX_H
