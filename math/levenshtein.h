#ifndef LEVENSHTEIN_H
#define LEVENSHTEIN_H

int levenshteinMatrix(const char *s1, const char *s2);
int levenshteinRecursiveMatrixless(char *s1, char *s2);
int levenshteinRecursiveMatrix(const char *s1, const char *s2);

int levenshteinMatrixExpose(const char *s1, const char *s2);
int levenshteinRecursiveMatrixExpose(const char *s1, const char *s2);

#endif