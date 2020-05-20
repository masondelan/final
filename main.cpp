#include "header.h"

int main(){

	int userInput;

	MatrixOps<int> matrixOne(3,3,"size.txt");
	MatrixOps<int> matrixTwo(3,3,"size.txt");
	MatrixOps<int> matrixThree(3,3, "size.txt");

	MatrixOps<double> matrix1(3,3,"double.txt");
	MatrixOps<double> matrix2(3,3,"double.txt");
	MatrixOps<double> matrix3(3,3, "double.txt");


	cout << "Matrix Calculator: Select One Of The Following Numbers" << endl;
	cout << "(1) Determinant" << endl;
	cout << "(2) Addition" << endl;
	cout << "(3) Subtraction" << endl;
	cout << "(4) Multiplication" << endl;
	cout << "(5) Exit" << endl;

	cin >> userInput;


	while(userInput != 5)
	{


		switch(userInput)
		{
			case 1: 
				matrixThree.calculateDeterminant();
				matrix3.calculateDeterminant();
				break;	

			case 2:
				matrixThree = matrixOne + matrixTwo;
				matrix3 = matrix1 + matrix2;
				break;
			
			case 3:
				matrixThree = matrixOne - matrixTwo;
				matrix3 = matrix1 - matrix2;
				break;

			case 4:
				matrixThree = matrixOne * matrixTwo;
				matrix3 = matrix1 * matrix2;
				break;

			default:
				cout << "Invalid Selection";
				break;
		}	
	
		cout << "Result for int Type:" << endl;
		cout << matrixThree << endl;

		cout << "Result for double Type:" << endl;
		cout << matrix3;

		cout << "Matrix Calculator: Select One Of The Following Numbers" << endl;
		cout << "(1) Determinant" << endl;
		cout << "(2) Addition" << endl;
		cout << "(3) Subtraction" << endl;
		cout << "(4) Multiplication" << endl;
		cout << "(5) Exit" << endl;

		cin >> userInput;

	}

	return 0;
}
