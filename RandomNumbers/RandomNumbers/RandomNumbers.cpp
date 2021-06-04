/*
 * Copied from Joel Ring.
 */

#include <iostream>
using namespace std;

constexpr auto GREEN = "\033[32m";

int main()
{
    cout << GREEN;
    int randomNumberDistribution[20]{};
    float deltaFromIdealValues[20]{};
    srand(time(nullptr));
    cout << "How many random numbers? ";
    int iterations = 0;
    cin >> iterations;

    for (int i = 0; i < iterations; i++) {

        auto randomInt = rand() % 20 + 1;
        randomNumberDistribution[randomInt - 1]++;
    }
    
    cout <<endl<< "Generated " << iterations << " random numbers."<<endl << endl;

    const float expectedPercentage = 5;
    cout << "Expected percentage: " << expectedPercentage <<"%"<<endl;
    float maxDelta = 0, minDelta = 100, sumDelta = 0;;
    cout << "Deltas (absolute values): " << endl;
    for (int i = 0;i < sizeof(randomNumberDistribution) / sizeof(int);i++) {
        deltaFromIdealValues[i] = abs((100 * randomNumberDistribution[i] / static_cast<float>(iterations)) - expectedPercentage);
        cout << deltaFromIdealValues[i] << " ";
        maxDelta = deltaFromIdealValues[i] > maxDelta ? deltaFromIdealValues[i] : maxDelta;
        minDelta = deltaFromIdealValues[i] < minDelta ? deltaFromIdealValues[i] : minDelta;
        sumDelta += deltaFromIdealValues[i];
    }
    cout <<endl<< "Max delta: " << maxDelta << endl;
    cout << "Min delta: " << minDelta << endl;
    cout << "Sum of all deltas: " << sumDelta << endl;
    cout << "Average delta: " << sumDelta/20.0f << endl << endl;

    for (int i = 0;i < sizeof(randomNumberDistribution)/sizeof(int);i++) {
        cout << "Number " << i+1<<": "<< randomNumberDistribution[i]<< " times ("<< 100*randomNumberDistribution[i]/ static_cast<float>(iterations) <<"%)"<< endl;
    }
}

/*
Create a large number of random numbers between 1 and 20!
Count how often every number appears
Compare this to the ideal distribution
(i.e. display probability of every number or something like that)
maybe, show the average, absolute discrepancy off the expected value
Number 2: 189 times (4.975%)
Number 3: 191 times (5.025%)
...
Maximum Offset: Number 4 (0.004%)
Minimum Offset: Number 7 (0.0%)
Average Offset: 0.002%
*/