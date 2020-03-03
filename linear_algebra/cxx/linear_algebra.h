
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <assert.h>

//#define BOUNDS_CHECK

struct vector
{
  double* data;
  int n;

  vector(int n);
  ~vector();

  double operator()(int i) const
  {
#ifdef BOUNDS_CHECK
    assert(i >= 0 && i < n);
#endif
    return data[i];
  }

  double& operator()(int i)
  {
#ifdef BOUNDS_CHECK
    assert(i >= 0 && i < n);
#endif
    return data[i];
  }

  void print() const;
};

struct matrix
{
  double* data;
  int m, n;

  matrix(int m, int n);
  ~matrix();

  double operator()(int i, int j) const
  {
#ifdef BOUNDS_CHECK
    assert(i >= 0 && i < m);
    assert(j >= 0 && j < n);
#endif
    return data[i * n + j];
  }

  double& operator()(int i, int j)
  {
#ifdef BOUNDS_CHECK
    assert(i >= 0 && i < m);
    assert(j >= 0 && j < n);
#endif
    return data[i * n + j];
  }

  void print() const;
};

double vector_dot(const vector& x, const vector& y);
void vector_add(const vector& x, const vector& y, vector& z);
void matrix_vector_mul(const matrix& A, const vector& x, vector& y);

// ----------------------------------------------------------------------

#include <stdio.h>

#define HERE                                                                   \
  fprintf(stderr, "HERE at %s:%d (%s)\n", __FILE__, __LINE__, __FUNCTION__)

#endif
