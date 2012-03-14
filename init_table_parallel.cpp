#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    const int size = 50;
    double sinTable[size];

    #pragma omp parallel for num_threads( 5 )
    for(int n=0; n<size; ++n) {
        sinTable[n] = std::sin(2 * M_PI *n/size);
        cout << "n = " << n << "\n";
    }

    return 0;
}

