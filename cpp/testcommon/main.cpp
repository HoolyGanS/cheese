
#include "../common/stopWatch.h"
#include <cstdlib>

using namespace std;

int main()
{
    char* numbers[10000];
    for (int i = 0; i < 10000; i++)
    {
        numbers[i] = new char[6];
        int num = i;
        for (int j = 0; j < 5; j++)
        {
            numbers[i][j] = num % 10;
            num /= 10;
        }

        numbers[i][5] = 0;
    }


    volatile int result;
    StopWatch sw;
    sw.run([&](){ for (int i = 0; i < 10000; ++i) result = atoi(numbers[i]); });
    sw.printResults();

    sw.run([&](){ for (int i = 0; i < 10000; ++i) result = (numbers[i][0] - '0') * 10000 +
                                                           (numbers[i][1] - '0') * 1000 +
                                                           (numbers[i][2] - '0') * 100 +
                                                           (numbers[i][3] - '0') * 10 +
                                                           (numbers[i][4] - '0'); });
    sw.printResults();
    for (int i = 0; i < 10000; i++) delete[] numbers[i];
    return 0;
}
