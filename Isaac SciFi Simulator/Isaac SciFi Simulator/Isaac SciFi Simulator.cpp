// isaacSciFi Simulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <cmath>
#include <iomanip>


using namespace std;

double rand_normal(double mean, double stddev);

int main()
{
    int Gen, simCount = 10;
    double seed, lifeSpan, newLifeSpan, deathAge, deathAgePercent, birthAge, oldBirthAge, birthAgePercent, converge, lifeSpanRatio;

    do {
        cout << "Enter Average Life Span" << endl;
        cin >> lifeSpan;
    } while (lifeSpan <= 0);

    do {
        cout << "Enter Average Age of Child Birth" << endl;
        cin >> birthAge;
    } while (birthAge > lifeSpan);

    do {
        cout << "Enter Average Age of Child Death" << endl;
        cin >> deathAge;
    } while (deathAge < birthAge);

    do {
        cout << "Enter Integer for Number of Cases You Would Like to Run" << endl;
        cin >> simCount;
    } while (simCount < 0);

    birthAgePercent = (birthAge / lifeSpan) * 100 ;
    deathAgePercent = (deathAge / lifeSpan) * 100 ;
    
    seed = time(NULL);
    srand(seed);

    cout << endl << "Seed Value : " << seed << endl;
    
    for (int i = 1; i <= simCount; i++) {
        Gen = 0;
        oldBirthAge = 0;
        newLifeSpan = rand_normal(lifeSpan, 5);

        cout << "Simulation Number " << i << endl;
        cout << "Generation\tBirth Age\tDeath Age\tLife Span\tLife Span Ratio" << endl;
        do {
            Gen++;
            birthAge = ((rand_normal(birthAgePercent, 2) / 100) * newLifeSpan) + oldBirthAge;
            deathAge = ((rand_normal(deathAgePercent, 2) / 100) * newLifeSpan) + oldBirthAge;

            lifeSpanRatio = newLifeSpan / (deathAge - birthAge);

            cout << setprecision(3) << fixed << Gen << "\t\t" << birthAge << "\t\t" << deathAge << "\t\t" << newLifeSpan << "\t\t" << lifeSpanRatio << endl;

            converge = birthAge - oldBirthAge;

            lifeSpanRatio = newLifeSpan / (deathAge - birthAge);
            newLifeSpan = deathAge - birthAge;
            
            oldBirthAge = birthAge;

        } while (converge > 0);
        cout << endl;
    }

    cout << "All times are recorded here in units of Generation 1's years." << endl
        << "Birth Age is the time the individual of that generation had a kid." << endl
        << "Death Age is the time the individual of that generation would experience their kids death." << endl
        << "Life Span is simply how long the member of that generation lived." << endl
        << "Life Span Ratio is a multiplier of how much longer a generation lives compared to its kid's generation" << endl
        << endl;


    system("pause");
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