#include <stdio.h>
#include <stdlib.h>
#include "optimize.h"
#include "func1.h"

int main(const int argc, const char **argv)
{
  // 引数の個数が1の時だけ、alpha に第1引数を採用し、それ以外は0.01
  const double alpha = (argc >= 2) ? atof(argv[1]) : 0.01;
  const char *data_filename = (argc >= 3) ? argv[2] : "data.csv";

  load_samples(data_filename);

  const int dim = f_dimension();

  double *x = malloc(dim * sizeof(double));
  for (int i = 0; i < dim; i++) {
    x[i] = 0;
  }

  printf("alpha = %f\n", alpha);

  const int iter = optimize(alpha, dim, x, f_gradient);

  printf("number of iterations = %d\n\n", iter);

  double alt_Fuji = 3.776;
  show_samples();
  printf("\nestimation:\n");
  printf("%8.6lf, %9.6lf, Mt.Fuji\n", alt_Fuji, x[0] * alt_Fuji + x[1]);

  free(x);

  return 0;
}

