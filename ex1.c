//
// Created by sin_een on 8/7/17.
//

#include "ex1.h"
#include <stdio.h>
#include <math.h>
const double ALFA = 0.012299; // Moon mass / earth mass
const double BETA = (0.012299 - 1);// we always use it the the function in -B form so I multiplied it here by -1 an dI will use it as +B in the functions when needed
//todo check how to generalize alfa and beta

double timelabs;// T/n = dt
double numberOfTimesToCheck; //n
double prints;// m

double distance(long double locationX, long double locationY, double parameter);
double acceleration(long double locationX, long double locationY, long double velocity, int flag );
void newLocation(long double *location, long double *velocity);
void newVelocity(long double *velocity, long double acceleration);
void forwardEuler(long double *locationX, long double *locationY,long double *velocityX, long double *velocityY, double timeSteps);

double distance(long double locationX, long double locationY, double parameter)
/**
 * @param locationX of the spaceship in the X axis
 * @param locationY of the spaceship in the Y axis
 * @param parameter ALFA OR BETA
 * @return
 */
{
//todo check if  double and all in place
    return (sqrt(pow(pow(locationX+parameter,2)+ pow(locationY,2),3)));
}

double acceleration(long double locationX, long double locationY, long double velocity, int isXAxis )
/**
 *
 * @param locationX of the spaceship in the X axis
 * @param locationY of the spaceship in the Y axis
 * @param velocity  the speed in X / Y axis depends which acceleration we want
 * @param isXAxis is 1 when we are culculationg for X axis and 0 if Y axis ( instead of having two functions)
 * @return
 */
{
    double distance1 = distance(locationX,locationY, ALFA);
    double distance2 = distance(locationX,locationY, BETA);
    if (isXAxis){
        return ( locationX + (2*velocity)+ (BETA *((locationX + ALFA )/distance1)) - (ALFA *((locationX+BETA)/distance2)));
    }
    else{
        return ( locationY + (2*velocity)+ (BETA *((locationY)/distance1)) - (ALFA *((locationY)/distance2)));

    }
}
//todo maybe make a global var for the dt ( timePAssed / time labs) instead of arguments to the functions entertain the possibility
void newLocation(long double *location, long double *velocity)
/**
 *
 * @param the location  of the spaceship on of the X/ Y axis
 * @param velocity the speed of the spaceship in x/Y axis Respectfully to the location
 * @return changes the location of the spaceship to the new location after specific time have passed
 */
{
    //return double new location  or maybe return 0 void and location = (location + ( velocity*timePassed)); return (location + ( velocity*timePassed));
    *location = (*location + ( velocity*timelabs));
    return 0;
}
void newVelocity(long double *velocity, long double acceleration)
/**
 *
 * @param velocity the speed of the spaceship in x/Y axis
 * @param acceleration the acceleration of the spaceship after specifi time passes
 * @return changes the speed to the new speed of the spaceship after specific time have passed
 */
{
    *velocity=(*velocity + (acceleration*timelabs));
    return 0;
}
void forwardEuler(long double *locationX, long double *locationY,long double *velocityX, long double *velocityY, double timeSteps)
/**
 *
 * @param locationX of the spaceship in the X axis
 * @param locationY of the spaceship in the Y axis
 * @param velocityX the speed in X  axis
 * @param velocityY  the speed in Y  axis
 * @param timeSteps how many times we need to check  T/n
 * @return
 */
{
    double accelerationX;
    double accelerationY;
    assert (timeSteps >0);
    if (timeSteps == 0 )
    {
        return 0;
    }
    else
    {
        // get the new location since its all in pointers teh orginal var changes value
        newLocation(*locationX,*velocityX);
        newLocation(*locationY,*velocityY);
        //calculate acceleration
        accelerationX= acceleration(locationX,locationY,velocityX,1);
        accelerationY= acceleration(locationX,locationY,velocityY,0);
        // calculate new velocity
        newVelocity(*velocityX,accelerationX);
        newVelocity(*velocityY,accelerationY);
        if (numberOfTimesToCheck%prints==0){
            writesInOutputfile(*locationX,*locationY);
        }
        forwardEuler(*locationX,*locationY,*velocityX,*velocityY,timeSteps-1);
    }

}

void writesInOutputfile(long double locationX, long double locationY)
{

}

int main(int argc, char **argv)
{
    File* inputFile = (argv[1],"r");
    File* outputFile = (argv[2],"w");
    if (inputFile==NULL)
    {
        fprintf(stderr, "Error no input file");
        printf("Error no input file"); //todo how to send to stderr???
        exit(-1);
    }




    return 0;
}