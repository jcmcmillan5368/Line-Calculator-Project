//---------------------------------------------------------
// File : line_calculator_project.cpp
// Class: COP 2006, Fall 2022
// Devel: J, McMillan
// Desc : Program that calculates the slope, y-intercept,
//        formula, distance, and angle of a line
//        using two points.
//---------------------------------------------------------
#include <iostream> // console input/output
#include <cmath> // math function access

//Constants
const int FIRST_ACTION = 0;
const int SECOND_ACTION = 1;

//Point Structures
struct Point {
    float xValue;
    float yValue;
};
struct Line {
    Point pointOne;
    Point pointTwo;
};

// Function Declaration (prototypes)
//-------------------------------------------------------
Point inputInfo(int actionNumber);
float slopeFunction (Line theLine);
float y_InterceptFunction(Line theLine);
double distanceFunction(Line theLine);
double angleFunction(Line theLine);
void outputInfo(double slopeValue, double y_interceptValue, double distance, double angleValue);

// Function Definitions
//---------------------------------------------------------

int main() {

    // Explaining the program to the user
    std::cout << "This program will give you information about a line, such";
    std::cout << "\nas the line's slope, y-intercept, formula, and angle!";
    std::cout << "\nIt will also give you the distance between the two points inputted.";
    std::cout << std::endl; // for spacing
    std::cout << "\nTo get started, You will need to input four values representing";
    std::cout << "\ncoordinates for two points. Make sure your first x value is less";
    std::cout << "\nthan your second x value for an accurate angle!";
    char tryAgain; // control variable for main loop
    do {
        std::cout << std::endl; // for spacing
        std::cout << std::endl; // for spacing

        // retrieve values for points using inputInfo function
        Point pointOne = inputInfo(FIRST_ACTION);
        Point pointTwo = inputInfo(SECOND_ACTION);
        // Putting both point values into the Line structure
        Line theLine{pointOne, pointTwo};

        //calculate slope using slope formula
        float slope = slopeFunction(theLine);
        //calculate y-intercept and line formula using point-slope form (y = mx + y_1 - m*x_1)
        float y_intercept = y_InterceptFunction(theLine);
        //calculate distance between the two points using the Quadratic Equation
        double distance = distanceFunction(theLine);
        //calculate angle of line using angle function
        double angle = angleFunction(theLine);
        //output the info given from the previous function calls
        outputInfo(slope, y_intercept, distance, angle);

        // see if user wants to try again
        std::cout << "\nWould you like to calculate another line? (Y/N): ";
        std::cin >> tryAgain;
    } while (tryAgain == 'Y' || tryAgain == 'y');

    return 0;
}


/**
 * Prompting the user to enter coordinates for two points on a line
 * @param actionNumber - tells the function whether to preform action one or action two
 * @return
 */
Point inputInfo(int actionNumber){
    Point thePoint{};
    // get 4 float values to be inputted into pointOne and pointTwo
    if (!actionNumber) {
        std::cout << "First, input the x and y coordinates for point 1 separated by spaces: ";
        std::cout << std::endl; // for spacing
    } else{
        std::cout << "Next, input the x and y coordinates for point 2 separated by spaces: ";
        std::cout << std::endl; // for spacing
    }
    std::cin >> thePoint.xValue >> thePoint.yValue;

    return thePoint;
}

/**
 * creating a slope function outside of main()
 * @param theLine - Contains coordinates for point one and coordinates for point two
 * @return
 */
float slopeFunction (Line theLine){
    float slopeValue;
    slopeValue = (theLine.pointTwo.yValue - theLine.pointOne.yValue) / (theLine.pointTwo.xValue -
                                                                        theLine.pointOne.xValue);

    return slopeValue;
}

/**
 * creating a y-intercept function outside of main()
 * @param theLine - Contains coordinates for point one and coordinates for point two
 * @return
 */
float y_InterceptFunction(Line theLine) {
    float slopeValue;
    float y_interceptValue;
    slopeValue = (theLine.pointTwo.yValue - theLine.pointOne.yValue) / (theLine.pointTwo.xValue -
                                                                        theLine.pointOne.xValue);
    y_interceptValue = theLine.pointOne.yValue - slopeValue * theLine.pointOne.xValue;

    return y_interceptValue;
}

/**
 * creating a distance function outside of main()
 * @param theLine - Contains coordinates for point one and coordinates for point two
 * @return
 */
double distanceFunction(Line theLine){
    double distanceValue;
    distanceValue = sqrt(pow(theLine.pointTwo.xValue - theLine.pointOne.xValue,2) +
                         pow(theLine.pointTwo.yValue  - theLine.pointOne.yValue, 2));

    return distanceValue;
}

/**
 * creating a function to calculate angle of the line
 * @param theLine - Contains coordinates for point one and coordinates for point two
 * @return
 */
double angleFunction(Line theLine){
    double angleValue;
    angleValue = atan2f(theLine.pointTwo.yValue - theLine.pointOne.yValue,
                        theLine.pointTwo.xValue - theLine.pointOne.xValue) * 180 / M_PI;

    return angleValue;
}

/**
 * creating a function to output the data
 * @param slopeValue - value obtained from the slope function
 * @param y_interceptValue value obtained from the y-intercept function
 * @param distance value obtained from the distance function
 * @param angleValue value obtained from the angle function
 */
void outputInfo(double slopeValue, double y_interceptValue, double distance, double angleValue){
    std::cout << "The slope is " << slopeValue << "." << std::endl;
    std::cout << "The y-intercept is (0," << y_interceptValue << ")" << "." << std::endl;
    std::cout << "The line formula for these points is: y = " << slopeValue << "x + " << y_interceptValue << std::endl;
    std::cout << "The distance between the two points = " << distance << "." << std::endl;
    std::cout << "The angle of this line = " << angleValue << " degrees." << std::endl;
}