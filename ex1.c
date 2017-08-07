//
// Created by sin_een on 8/7/17.
//

#include "ex1.h"
#include <stdio.h>
#include <math.h>
const double ALFA = 0.012299; // Moon mass / earth mass
const double BETA = (0.012299 - 1);// we always use it the the function in -B form so I multiplied it here by -1 an dI will use it as +B in the functions when needed
//todo check how to generalize alfa and beta

double distance(long locationX, long locationY, double parameter);
double acceleration(long locationX, long locationY, long velocity, int flag );


double distance(long locationX, long locationY, double parameter)
/**
 * @param locationX
 * @param locationY
 * @param parameter ALFA OR BETA
 * @return
 */
{
//todo check if long and double and all in place
    return (sqrt(pow(pow(locationX+parameter,2)+ pow(locationY,2),3)));
}

double acceleration(long locationX, long locationY, long velocity, int isXAxis )
/**
 *
 * @param locationX
 * @param locationY
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