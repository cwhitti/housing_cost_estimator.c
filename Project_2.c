// header files
#include "Console_IO_Utility.h"

// global constants
const double ABSOLUTE_BASE = 0.0000001;
const double BOOSTING_VALUE = 5.55;
const double DRYWALL_PRICE = 3.00;
const double PLYWOOD_PRICE = 3.125;    // per square foot
const double ROOFING_PRICE = 3.535525;  // per square foot
const double SIDE_WALL_RATIO = 0.67;
const double SQUARE_ROOT_PRECISION = 0.000001;
const double TWO_BY_FOUR_PRICE = 7.50;  // per board

const int HOUSE_HEIGHT = 10;
const int NUM_2x4_PER_FOOT = 6;
const int TRIMMING_VALUE = 10;
const int TWO_ENDLINES = 2;

// constants for table
const int DESCRIPTION_WIDTH = 16;
const int TABLE_WIDTH = 39;
const int UNIT_WIDTH = 9;
const int VALUE_WIDTH = 10;

const char THICK_LINE = '=';
const char THIN_LINE = '-';

// prototypes
double findAbsolute( int value );
double findSquareRoot( double value );
void printDividedLine( char thickness );
void printHeavyDividedLine();
void printLightDividedLine();
void printTopLine();

// main program
int main()
   {
    // TODO: Write program as specified

      //initialize variables
      double desired_area, actual_area;
      double house_width, house_depth;
      double four_wall_total;
      double width_area, depth_area;
      double plywood_cost, roofing_cost, two_by_four_cost, drywall_cost;
      double total_estimate;

      //program initialization component
      printString("Housing Cost Estimator");
      printEndline();
      printString("====================");
      printEndlines(TWO_ENDLINES);

      //get input
      desired_area =
      promptForInteger("Enter the desired floor square footage: ");
      printEndline();

      //Data Processing

        //House Width
          //must be calculated from the desired house square feet input
          house_width = findSquareRoot(desired_area / SIDE_WALL_RATIO );

          //Boost House Width
          house_width += BOOSTING_VALUE;

          //Floor house_width to TRIMMING_VALUE place
          house_width = ((int)(house_width)/TRIMMING_VALUE)*TRIMMING_VALUE;

        //House Depth
          // must be calculated as approximately 2/3 (0.67)
          // of the front/back length
          house_depth = house_width * SIDE_WALL_RATIO;

          //Boost House Depth
          house_depth += BOOSTING_VALUE;

          //Floor house_width to TRIMMING_VALUE place
          house_depth = ((int)(house_depth)/TRIMMING_VALUE)*TRIMMING_VALUE;

        //Actual Area
          //Shown before House Width and House Depth
          actual_area = house_width * house_depth;

        //Roofing cost
          // calculated by multiplying the actual floor area against the
          // roofing price constant
          roofing_cost = actual_area * ROOFING_PRICE;

        //Plywood cost
          // calculated by finding and summing the areas of the front, back,
          // and both sides of the house, and calculating the cost, using the
          // plywood price constant

          //Calculate area for front/back walls
          width_area = house_width * HOUSE_HEIGHT ;

          //Calculate area for front/back
          depth_area = house_depth * HOUSE_HEIGHT ;

          //Calculate total area of house walls
          four_wall_total = (2 * width_area) + (2 * depth_area);

          //CALCULATE THE COST
          plywood_cost =  PLYWOOD_PRICE * (four_wall_total + actual_area);

        // 2 x 4 Cost
          // calculated by multiplying the number of 2x4 per foot
          // (a given constant) against the front length and the side length
          // of the house.

          //Find the footage of the house
          two_by_four_cost = house_width + house_depth;

          //Find the total number of 2 x 4's
          two_by_four_cost *= NUM_2x4_PER_FOOT;

          //Find the total cost
          two_by_four_cost *= TWO_BY_FOUR_PRICE;

        //Drywall cost
          // calculated by finding the area of the front, side,
          // and back walls by the drywall price constant
          drywall_cost = four_wall_total * DRYWALL_PRICE;

        //Total Estimate
          // found by adding up the roofing, plywood, 2x4, and drywall costs
          total_estimate = roofing_cost + plywood_cost + two_by_four_cost +
                          drywall_cost;

    //Program display component

      //Print top of Chart
        printTopLine();
        printEndline();

      //This block prints the NAMED DESCRIPTORS section
        printCharacter( PIPE );
        printCharacter( SPACE );

        //Print the "Description", LEFT JUSTIFIED
          //function:printStringJustified
        printStringJustified( "  Description", DESCRIPTION_WIDTH - 1, "LEFT");

        printCharacter( PIPE );

        //Print the "Value", RIGHT JUSTIFIED
          //function: printStringJustified
        printStringJustified( "Value ", VALUE_WIDTH - 1, "RIGHT");

        printCharacter( SPACE );
        printCharacter( PIPE );
        printCharacter( SPACE );

        //Print the "Unit", LEFT JUSTIFIED
          //function: printStringJustified
        printStringJustified( " Unit", UNIT_WIDTH - 1, "LEFT");

        printCharacter( PIPE );
        printEndline();

        //Print thick devided line
          //printHeavyDividedLine
        printHeavyDividedLine();
        printEndline();

      //This block prints the DESIERED AREA section

        printCharacter( PIPE );
        printCharacter( SPACE );

        //print "Desired Area", LEFT justified
          //function: printStringJustified
        printStringJustified( "Desired Area", DESCRIPTION_WIDTH - 1, "LEFT");

        printCharacter( PIPE );

        //print desired_area, RIGHT justfied
          //Function:
          //printIntegerJustified;
        printIntegerJustified( desired_area, VALUE_WIDTH - 1, "RIGHT" );

        printCharacter( SPACE );
        printCharacter( PIPE );
        printCharacter( SPACE );

        //Print sq feet, LEFT JUSTIFIED
          //Function:
          //printStringJustified;
        printStringJustified( "sq ft", UNIT_WIDTH - 1, "LEFT" );

        printCharacter( PIPE );
        printEndline();

        //Print light devided line
          //function: printLightDividedLine
        printLightDividedLine();
        printEndline();

      //This block prints the ACTUAL AREA section

        printCharacter( PIPE );
        printCharacter( SPACE );

        //print "Actual area", LEFT justified
          //function: printStringJustified
        printStringJustified( "Actual Area", DESCRIPTION_WIDTH - 1, "LEFT");

        printCharacter( PIPE );

        //print actual_area, RIGHT justfied
          //Function: printIntegerJustified
        printIntegerJustified( actual_area, VALUE_WIDTH - 1, "RIGHT" );

        printCharacter( SPACE );
        printCharacter( PIPE );
        printCharacter( SPACE );

        //Print sq feet, LEFT JUSTIFIED
          //Function: printStringJustified
        printStringJustified( "sq ft", UNIT_WIDTH - 1, "LEFT" );

        printCharacter( PIPE );
        printEndline();

        //Print light devided line
          //function: printLightDividedLine
        printLightDividedLine();
        printEndline();

      //This block prints the HOUSE WIDTH section

        printCharacter( PIPE );
        printCharacter( SPACE );

        //print "House Width", LEFT justified
          //function: printStringJustified
        printStringJustified( "House Width", DESCRIPTION_WIDTH - 1, "LEFT");

        printCharacter( PIPE );

        //print house_width, RIGHT justfied
          //Function:
          //printIntegerJustified
        printIntegerJustified( house_width, VALUE_WIDTH - 1, "RIGHT" );

        printCharacter( SPACE );
        printCharacter( PIPE );
        printCharacter( SPACE );

        //Print feet, LEFT JUSTIFIED
          //Function:
          //printStringJustified
        printStringJustified( "feet", UNIT_WIDTH - 1, "LEFT" );

        printCharacter( PIPE );
        printEndline();

        //Print light devided line
          //function: printLightDividedLine
        printLightDividedLine();
        printEndline();

      //This block prints the HOUSE DEPTH section

        printCharacter( PIPE );
        printCharacter( SPACE );

        //print "House Depth", LEFT justified
          //function: printStringJustified
        printStringJustified( "House Depth", DESCRIPTION_WIDTH - 1, "LEFT");

        printCharacter( PIPE );

        //print house_depth, RIGHT justfied
          //Function:
          //printIntegerJustified
        printIntegerJustified( house_depth, VALUE_WIDTH - 1, "RIGHT" );

        printCharacter( SPACE );
        printCharacter( PIPE );
        printCharacter( SPACE );

        //Print sq feet, LEFT JUSTIFIED
          //Function:
          //printStringJustified
        printStringJustified( "feet", UNIT_WIDTH - 1, "LEFT" );

        printCharacter( PIPE );
        printEndline();

        //Print light devided line
          //function: printLightDividedLine
        printLightDividedLine();
        printEndline();

      //This block prints the ROOFING COST section

        printCharacter( PIPE );
        printCharacter( SPACE );

        //print "Roofing Cost", LEFT justified
          //function: printStringJustified
        printStringJustified( "Roofing Cost", DESCRIPTION_WIDTH - 1, "LEFT");

        printCharacter( PIPE );

        //print roofing_cost, RIGHT justfied
          //Function: printDoubleJustified
        printDoubleJustified(roofing_cost, PRECISION, VALUE_WIDTH - 1,
           "RIGHT" );

        printCharacter( SPACE );
        printCharacter( PIPE );
        printCharacter( SPACE );

        //Print dollars, LEFT JUSTIFIED
          //Function: printStringJustified
        printStringJustified( "dollars", UNIT_WIDTH - 1, "LEFT" );

        printCharacter( PIPE );
        printEndline();

        //Print light devided line
          //function: printHeavyDividedLine
        printLightDividedLine();
        printEndline();

      //This block prints the PLYWOOD COST section

        printCharacter( PIPE );
        printCharacter( SPACE );

        //print "Plywood cost", LEFT justified
          //function: printStringJustified
        printStringJustified( "Plywood cost", DESCRIPTION_WIDTH - 1, "LEFT");

        printCharacter( PIPE );

        //print plywood cost, RIGHT justfied
          //Function: printDoubleJustified
        printDoubleJustified( plywood_cost, PRECISION, VALUE_WIDTH - 1,
           "RIGHT" );

        printCharacter( SPACE );
        printCharacter( PIPE );
        printCharacter( SPACE );

        //Print dollars, LEFT JUSTIFIED
          //Function: printStringJustified
        printStringJustified( "dollars", UNIT_WIDTH - 1, "LEFT" );

        printCharacter( PIPE );
        printEndline();

        //Print light devided line
          //function: printLightDividedLine
        printLightDividedLine();
        printEndline();

      //This block prints the 2X4 COST section

        printCharacter( PIPE );
        printCharacter( SPACE );

        //print "2 x 4 Cost", LEFT justified
          //function: printStringJustified
        printStringJustified( "2 x 4 Cost", DESCRIPTION_WIDTH - 1, "LEFT");

        printCharacter( PIPE );

        //print two x four cost, RIGHT justfied
          //Function: printDoubleJustified
        printDoubleJustified(two_by_four_cost, PRECISION, VALUE_WIDTH - 1,
          "RIGHT");

        printCharacter( SPACE );
        printCharacter( PIPE );
        printCharacter( SPACE );

        //Print dollars, LEFT JUSTIFIED
          //Function: printStringJustified
        printStringJustified( "dollars", UNIT_WIDTH - 1, "LEFT" );

        printCharacter( PIPE );
        printEndline();

        //Print light devided line
          //function: printLightDividedLine
        printLightDividedLine();
        printEndline();

      //This block prints the DRYWALL COST section

        printCharacter( PIPE );
        printCharacter( SPACE );

        //print "Drywall Cost", LEFT justified
          //function: printStringJustified
        printStringJustified( "Drywall Cost", DESCRIPTION_WIDTH - 1, "LEFT");

        printCharacter( PIPE );

        //print drywall cost, RIGHT justfied
          //Function: printDoubleJustified
        printDoubleJustified( drywall_cost, PRECISION, VALUE_WIDTH - 1,
          "RIGHT" );

        printCharacter( SPACE );
        printCharacter( PIPE );
        printCharacter( SPACE );

        //Print dollars, LEFT JUSTIFIED
          //Function: printStringJustified
        printStringJustified( "dollars", UNIT_WIDTH - 1, "LEFT" );

        printCharacter( PIPE );
        printEndline();

        //Print light devided line
          //function: printLightDividedLine
        printLightDividedLine();
        printEndline();

      //This block prints the TOTAL ESTIMATE section

        printCharacter( PIPE );
        printCharacter( SPACE );

        //print "Total Estimate", LEFT justified
          //function: printStringJustified
        printStringJustified( "Total Estimate", DESCRIPTION_WIDTH - 1, "LEFT");

        printCharacter( PIPE );

        //print total estimate cost, RIGHT justfied
          //Function: printDoubleJustified
        printDoubleJustified( total_estimate, PRECISION, VALUE_WIDTH - 1,
          "RIGHT" );

        printCharacter( SPACE );
        printCharacter( PIPE );
        printCharacter( SPACE );

        //Print dollars, LEFT JUSTIFIED
          //Function: printStringJustified
        printStringJustified( "dollars", UNIT_WIDTH - 1, "LEFT" );

        printCharacter( PIPE );
        printEndline();

        //Print light devided line
          //function: printLightDividedLine
        printLightDividedLine();
        printEndline();

    //Program end display
        printEndline();
        printString("End Program");
        printEndline();

    //return program success
        return 0;
   }


// supporting functions

double findAbsolute( int value )
   {
    // test for value less than negative precision
    if( value < -ABSOLUTE_BASE )
       {
        // return negated value
        return -value;
       }

    // otherwise, assume positive value, return unchanged
    return value;
   }

double findSquareRoot( double value )
   {
    // initialize function/variables
    double testSquare, mid, high = value, low = 0;

    // set initial mid value
    mid = ( high + low ) / 2.0;

    // set initial test square value
    testSquare = mid * mid;

    // loop while difference between test square and value
    //   is greater than desired precision
       // function: findAbsolute
    while( findAbsolute( testSquare - value ) > SQUARE_ROOT_PRECISION )
       {
        // test for calculated value too high
        if( testSquare > value )
           {
            // change low to the mid value
            high = mid;
           }

        // otherwise, assume value was too low
        else
           {
            low = mid;
           }

        // calculate new mid
        mid = ( high + low ) / 2.0;

        // calculate new test square
        testSquare = mid * mid;
       }

    // return estimated square root
    return mid;
   }

void printDividedLine( char thickness )
   {
    // print first pipe
       // function: printCharacter
    printCharacter( PIPE );

    // print description line
       // function: printCharacters
    printCharacters( DESCRIPTION_WIDTH, thickness );

    // print divider pipe
       // function: printCharacter
    printCharacter( PIPE );

    // print description line
       // function: printCharacters
    printCharacters( VALUE_WIDTH, thickness );

    // print divider pipe
       // function: printCharacter
    printCharacter( PIPE );

    // print description line
       // function: printCharacters
    printCharacters( UNIT_WIDTH, thickness );

    // print last pipe
       // function: printCharacter
    printCharacter( PIPE );
   }

void printHeavyDividedLine()
   {
    // call print divided line with light character
       // function: printDividedLine
    printDividedLine( THICK_LINE );
   }

void printLightDividedLine()
   {
    // call print divided line with light character
       // function: printDividedLine
    printDividedLine( THIN_LINE );
   }

void printTopLine()
   {
    // print top line
       // function: printCharacters
    printCharacters( TABLE_WIDTH, THIN_LINE );
   }
