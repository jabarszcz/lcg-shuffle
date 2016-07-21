#include <QDebug>
#include <QVector>
#include <cmath>
#include <cassert>
#include <algorithm>

// Source: https://en.wikipedia.org/wiki/Linear_congruential_generator
int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    int seed = rand();
    qDebug() << seed;

    int pwr = 8;

    for (int i = 0; i < pwr; i++) {
        int m = std::pow(2, i);

        if (m < 4)
            continue;
        QVector<int> result(m);

        int x0 = seed % m;
        result[0] = x0;
        int a = m - 3;
        int c = 3;

        for (int j = 1; j < m; j++) {
            result[j] = (result[j - 1] * a + c) % m;
        }
        qDebug() << i << m << result;

        // verify
        qSort(result);
        qDebug() << result;
        for (int j = 0; j < m; j++) {
            assert(result[j] == j);
        }

    }


    return 0;
}

