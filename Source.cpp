/*
Andrew Seewald
CIS 150
Program 3
Due: 10/28/2014
Converts a point and slope or 2 points inputed by the user to point-slope form
*/

#include <iostream>
using namespace std;

int getproblem(int& problem_num) //Prompts user to choose a method and returns the selection to the main function
{
	cout << "Select the form that you would like to convert to slope-intercept form:\n1) Two-point form (you know two points on the line)\n2) Point-slope form (you know the line's slope and one point)\n=> ";
	cin >> problem_num;
	return problem_num;
}

float get2Pt(float&x1, float&x2, float&y1, float&y2) //Asks user for 2 points and returns them to the main function
{
	cout << "Enter the x-y coordinates of the first point seperated by a space=> ";
	cin >> x1 >> y1;
	cout << "Enter the x-y coordinates of the second point seperated by a space=> ";
	cin >> x2 >> y2;
	return x1, x2, y1, y2;
}

void display2Pt(float x1, float x2, float y1, float y2) //Displays the 2 point form
{
	cout << "\n\tTwo-Point form\n";
	cout << "\t    " << y2;
	if (y1 < 0) // If number is negative it will add instead of subtracting by a negative
	{
		cout << " - ";
		y1 = y1*-1;
	}
	else cout << " + ";
	cout << y1 << endl;
	cout << "\tm = --------\n";
	cout << "\t    " << x2;
	if (x1 < 0) // If number is negative it will add instead of subtracting by a negative
	{
		cout << " - ";
		x1 = x1*-1;
	}
	else cout << " + ";
	cout << x1 << endl;
}

float slopeIntcptFrom2Pt(float x1, float x2, float y1, float y2, float&m, float&b) //determines what slope (m) and y-intercept (b) are and returns their values to the main function
{
	m = (y2 - y1) / (x2 - x1);
	
	b = y1 - (m*x1);

	return m, b;
}

void displaySlopeIntcpt(float m, float b) //Displays Slope intercept form
{
	cout << "\nSlope intercept form:\n";
	cout << "\tY = ";
	if (m == 1); // Does not print slopes of 1 to the screen
	else if (m == -1) cout << "-"; // Slope of -1 will print just a negative sign to screen
	else cout << m; //if slope is not -1 or 1 it is printed to the screen
	cout << "x ";
	if (b != 0) // prevents - 0 to be printed to the screen
	{
		if (b < 0)
		{
			cout << "- ";
			b = b*-1;
		}
		else cout << "+ ";
		cout << b;
	}
	cout << endl << endl;
}

float getPtSlope(float&x1, float&y1, float&m) //asks user for slope and a point and returns them to main function
{
	cout << "Enter the slope=> ";
	cin >> m;
	cout << "Enter the x-y coordinate separated by a space=> ";
	cin >> x1 >> y1;

	return x1, y1, m;
}

void displayPtSlope(float x1, float y1, float m) // displays point slope formula
{
	cout << "\nPoint-slope form:\n";
	cout << "\t Y ";
	if (y1 != 0) // prevents subtracting a negative number
	{
		cout << "- " << y1;
	}
	cout << " = ";
	if (m == 1); //slope of 1 is not printed on the screen
	else if (m == -1) cout << "-"; // slope of -1 is printed as a negative sign
	else cout << m; //all other slopes are printed
	cout << "(x";
	if (x1 !=0) // prevents subtraction of 0 and subtractiong of negative numbers
	{
		if (x1 < 0)
			{
				cout << " - ";
				x1 = x1*-1;
			}
		else cout << " + ";
		cout << x1;
	}
	cout << ")" << endl;
}

float intcptFromPtSlope(float x1, float y1, float m, float&b) //finds y-intercept from a point and slope and returns it to the main function
{
	b = y1 - (m*x1);
	return b;
}

void main()
{
	int problem_num;	//declaration of variables and functions to be used
	float x1, x2, y1, y2, m, b;
	char yesno;
	int getproblem(int&problem_num);
	float get2Pt(float&x1, float&x2, float&y1, float&y2);
	void display2Pt(float x1, float x2, float y1, float y2);
	float slopeIntcptFrom2Pt(float x1, float x2, float y1, float y2, float&m, float&b);
	void displaySlopeIntcpt(float m, float b);
	float getPtSlope(float&x1, float&y1, float&m);
	void displayPtSlope(float x1, float y1, float m);
	float intcptFromPtSlope(float x1, float y1, float m, float&b);

	do
	{
		getproblem(problem_num);	//ask user what information they know

		if (problem_num == 1)	//path to follow for 2 points
		{
			get2Pt(x1, x2, y1, y2);
			display2Pt(x1, x2, y1, y2);
			slopeIntcptFrom2Pt(x1, x2, y1, y2, m, b);
			displaySlopeIntcpt(m, b);
		}

		if (problem_num == 2)	//path to follow for slope and one point
		{
			getPtSlope(x1, y1, m);
			displayPtSlope(x1, y1, m);
			intcptFromPtSlope(x1, y1, m, b);
			displaySlopeIntcpt(m, b);
		}

		cout << "Do another conversion? (Y or N)=> ";	//allow user to do again or end the loop
		cin >> yesno;
	} while (yesno == 'Y' || yesno == 'y');

}