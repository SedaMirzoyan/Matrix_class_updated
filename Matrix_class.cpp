
#include <iostream>
#include "Matrix_class.h"


Matrix_class::Matrix_class()
{
    std::cout << "Default constructor\n";
    row = 0;
    column = 0;

    p = new int* [row];

    for (int i = 0; i < row; i++)
    {
        p[i] = new int[column];
    }
}

void Matrix_class::setRow(int r)
{
    if (r <= 0)
    {
        
    throw std::invalid_argument("Invalid size");
    }
    row = r;   
}

int Matrix_class::getRow()const
{
    return row;
}

void Matrix_class::setColumn(int c)
{
    if (c <= 0)
    {
        throw std::invalid_argument("Invalid size");
        
    }
    column = c;
}

int Matrix_class::getColumn()const
{
    return column;
}


Matrix_class::Matrix_class(int r, int c){
    row = r;
    column = c;   

    p = new int* [row];

    for (int i = 0; i < row; i++)
    {
        p[i] = new int[column];
    }
}



Matrix_class::Matrix_class(const Matrix_class& ob)
{
    std::cout << "Copy constructor\n";
    this->row = ob.row;
    this->column = ob.column;

    this->p = new int* [row];

    for (int i = 0; i < row; i++)
    {
        this->p[i] = new int[column];
    }

    for (int i = 0; i < ob.row; i++)
    {
        for (int j = 0; j < ob.column; j++)
        {
            this->p[i][j] = ob.p[i][j];
        }
    }
}

Matrix_class& Matrix_class::operator=(const Matrix_class& ob)
{
    std::cout << "Assignment operator\n";

    if (this != &ob)
    {
        this->row = ob.row;
        this->column = ob.column;

        delete []p;
        this->p = new int* [row];

        for (int i = 0; i < row; i++)
        {
            this->p[i] = new int[column];
        }

        for (int i = 0; i < ob.row; i++)
        {
            for (int j = 0; j < ob.column; j++)
            {
                this->p[i][j] = ob.p[i][j];
            }
        }
    }
    return *this;
}


Matrix_class::~Matrix_class()
{
    std::cout << "Destructor\n";

    for (int i = 0; i < row; i++)
    {
        delete[] p[i];
    }
    delete[] p;
}


void Matrix_class::initializeMatrix()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            p[i][j] = rand() % 100 + 1;
        }
    }
}


void Matrix_class::changeRows(int k, int g)
{
    for (int i = 0; i <= column; i++)
    {
        int tmp = p[k][i];
        p[k][i] = p[g][i];
        p[g][i] = tmp;
    }
}


void Matrix_class::changeColumns(int k, int g)
{
    for (int i = 0; i < row; i++)
    {
        int tmp = p[i][k];
        p[i][k] = p[i][g];
        p[i][g] = tmp;
    }
}


void Matrix_class::printMatrix()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            std::cout << "p[" << i << "][" << j << "] = " << p[i][j] << "\n";
        }
    }
}
