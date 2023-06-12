#include <iostream>
#include "Matrix_class.h"


int main()
{
	int size; 
	Matrix_class ob;

	std::cout << "Enter the size of a matrix\n";
	std::cin >> size;

	Matrix_class ob1;

	try {
		ob1.getRow();
		ob1.setRow(size);
	}
	catch (const std::invalid_argument ia)
	{
		std::cerr << ia.what() << std::endl;
	}

	try {
		ob1.getColumn();
		ob1.setColumn(size);
	}
	catch (const std::invalid_argument ia)
	{
		std::cerr << ia.what() << std::endl;
	}

	std::cout << "Before Swap\n";
	ob1.initializeMatrix();
	ob1.printMatrix();
	std::cout << "Swapping colums\n";
	ob1.changeColumns(0, 2);
	ob1.printMatrix();
	std::cout << "Swapping rows\n";
	ob1.changeRows(0, 2);
	ob1.printMatrix();

	Matrix_class ob_cp(ob1);
	ob_cp.printMatrix();

	ob = ob_cp;

	return 0;
}