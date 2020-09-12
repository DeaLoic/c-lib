#include "levenshtein.h"
#include <string.h>
#include <stdio.h>

int levenshteinMatrix(const char *s1, const char *s2)
{
    int firstSize = strlen(s1);
    int secondSize = strlen(s2);
    int answer = 0;
    if (firstSize == 0 && secondSize > 0)
    {
        answer = secondSize;
    }
    else if (secondSize == 0 && firstSize > 0)
    {
        answer = firstSize;
    }
    else
    {
        char matrixTransformation[2][secondSize + 1];
        for (int j = 0; j < secondSize + 1; j++)
        {
            matrixTransformation[0][j] = j;
        }
        for (int i = 1; i < firstSize + 1; i++)
        {
            int diagonalStep;
            matrixTransformation[1][0] = i;
            for (int j = 1; j < secondSize + 1; j++)
            {
                matrixTransformation[1][j] = (matrixTransformation[0][j] < matrixTransformation[1][j - 1] ?
                                              matrixTransformation[0][j] : matrixTransformation[1][j - 1]) + 1;
                diagonalStep = matrixTransformation[0][j - 1];
                diagonalStep += (s1[i - 1] == s2[j - 1] ? 0 : 1);
                if (diagonalStep < matrixTransformation[1][j])
                {
                    matrixTransformation[1][j] = diagonalStep;
                }
            }
            for (int j = 0; j < secondSize + 1; j++)
            {
                matrixTransformation[0][j] = matrixTransformation[1][j];
            }
        }
        answer = matrixTransformation[1][secondSize];
    }

    return answer;
}

int levenshteinRecursiveMatrixless(const char *s1, const char *s2);
int levenshteinRecursiveMatrix(const char *s1, const char *s2);

int levenshteinMatrixExpose(const char *s1, const char *s2)
{
    int firstSize = strlen(s1);
    int secondSize = strlen(s2);
    int answer = 0;
    if (firstSize == 0 && secondSize > 0)
    {
        answer = secondSize;
    }
    else if (secondSize == 0 && firstSize > 0)
    {
        answer = firstSize;
    }
    else
    {
        printf("%7s%7s","", "/0\\");
        for (int i = 0; i < secondSize; i++) {
            printf("%7c", s2[i]);
        }
        printf("\n%7s", "/0\\");
        char matrixTransformation[2][secondSize + 1];
        for (int j = 0; j < secondSize + 1; j++)
        {
            printf("%7d", j);
            matrixTransformation[0][j] = j;
        }
        for (int i = 1; i < firstSize + 1; i++)
        {
            int diagonalStep;
            matrixTransformation[1][0] = i;
            printf("\n%7c", s1[i - 1]);
            printf("%7d", i);
            for (int j = 1; j < secondSize + 1; j++)
            {
                matrixTransformation[1][j] = (matrixTransformation[0][j] < matrixTransformation[1][j - 1] ?
                                              matrixTransformation[0][j] : matrixTransformation[1][j - 1]) + 1;
                diagonalStep = matrixTransformation[0][j - 1];
                diagonalStep += (s1[i - 1] == s2[j - 1] ? 0 : 1);
                if (diagonalStep < matrixTransformation[1][j])
                {
                    matrixTransformation[1][j] = diagonalStep;
                }
                printf("%7d", matrixTransformation[1][j]);
            }
            for (int j = 0; j < secondSize + 1; j++)
            {
                matrixTransformation[0][j] = matrixTransformation[1][j];
            }
        }
        answer = matrixTransformation[1][secondSize];
        printf("\n");
    }

    return answer;
}

int levenshteinRecursiveMatrixExpose(const char *s1, const char *s2);