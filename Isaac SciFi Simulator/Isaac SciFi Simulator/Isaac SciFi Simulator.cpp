// isaacSciFi Simulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <cmath>


using namespace std;

double rand_normal(double mean, double stddev);

int main()
{
    double seed, lifeSpan, deathAge, birthAge, converge, tolerance;

    do {
        cout << "Enter Average Life Span" << endl;
        cin >> lifeSpan;
    } while (lifeSpan <= 0);

    do {
        cout << "Enter Average Age of Child Birth" << endl;
        cin >> birthAge;
    } while (birthAge < lifeSpan);

    do {
        cout << "Enter Average Age of Child Death" << endl;
        cin >> deathAge;
    } while (deathAge > birthAge);

    do {
        cout << "Enter Convergence Tolerance" << endl;
        cin >> tolerance;
    } while (tolerance <= 0 );
     
    do {
       

        converge = last
    } while (converge > tolerance)
            
    seed = time(NULL);
    srand(seed);


}

double rand_normal(double mean, double stddev)
{//Box muller method
    static double n2 = 0.0;
    static int n2_cached = 0;
    if (!n2_cached)
    {
        double x, y, r;
        do
        {
            x = 2.0 * rand() / RAND_MAX - 1;
            y = 2.0 * rand() / RAND_MAX - 1;

            r = x * x + y * y;
        } while (r == 0.0 || r > 1.0);
        {
            double d = sqrt(-2.0 * log(r) / r);
            double n1 = x * d;
            n2 = y * d;
            double result = n1 * stddev + mean;
            n2_cached = 1;
            return result;
        }
    }
    else
    {
        n2_cached = 0;
        return n2 * stddev + mean;
    }
}