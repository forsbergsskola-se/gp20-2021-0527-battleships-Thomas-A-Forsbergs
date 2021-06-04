/*
 * Copied from Joel Ring.
 */

#include <iostream>
#include <chrono>
#include <vector>
using namespace std::chrono;
using namespace std;

int fibRecursive(int n)
{
    if (n <= 1)
        return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int fibSmallSpace(int n)
{
    int a = 0, b = 1, c, i;
    if (n == 0)
        return a;
    for (i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int fibStorage(int n)
{
    // Declare an array to store
    // Fibonacci numbers.
    // 1 extra to handle
    // case, n = 0
    std::vector<int> fibVector(n + 2);
    int i;

    // 0th and 1st number of the
    // series are 0 and 1
    fibVector[0] = 0;
    fibVector[1] = 1;

    for (i = 2; i <= n; i++)
    {
        //Add the previous 2 numbers
        // in the series and store it
        fibVector[i] = fibVector[i - 1] + fibVector[i - 2];
    }
    return fibVector[n];
}


int main()
{
    int n;
    cout << "enter #fibonacci: ";
    cin >> n;
    auto start = high_resolution_clock::now();
    auto fibNumber = fibRecursive(n);

    auto stop = high_resolution_clock::now();
    milliseconds duration = duration_cast<milliseconds>(stop - start);
    cout << "Found " << fibNumber << " in " << duration.count() << " milliseconds, using recursion." << endl;

    fibNumber = 0;

    start = high_resolution_clock::now();
    fibNumber = fibStorage(n);
    stop = high_resolution_clock::now();
    nanoseconds durationns = duration_cast<nanoseconds>(stop - start);
    cout << "Found " << fibNumber << " in " << durationns.count() << " nanoseconds, using an array to store all old numbers." << endl;

    fibNumber = 0;

    start = high_resolution_clock::now();
    fibNumber = fibSmallSpace(n);
    stop = high_resolution_clock::now();
    durationns = duration_cast<nanoseconds>(stop - start);
    cout << "Found " << fibNumber << " in " << durationns.count() << " nanoseconds, storing the two last numbers in variables." << endl;

    getchar();
    return 0;
}