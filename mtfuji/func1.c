#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
  char *loc;   // location name
  double alt;  // altitude (km)
  double temp; // temperature (centigrade)
} Sample;

static size_t sample_count = 0;
static Sample *samples;

static int comp_alt(const void *x0, const void *x1)
{
  const Sample* s0 = x0;
  const Sample* s1 = x1;

  if (s0->alt == s1->alt)
    return 0;
  else
    return s0->alt > s1->alt ? 1 : -1;
}

void load_samples(const char filename[]) {

  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "couldn't open '%s'\n", filename);
    exit(1);
  }

  char buffer[100];
  while((fgets(buffer, 100, fp)) != NULL) sample_count++;

  fseek(fp, 0L, SEEK_SET);

  samples = (Sample*)calloc(sample_count, sizeof(Sample));
  for (int i=0; i<sample_count; i++) {
    fgets(buffer, 100, fp);
    char *loc = (char*)malloc(100);
    sscanf(buffer, "%[^,],%lf,%lf", loc, &samples[i].alt, &samples[i].temp);
    samples[i].loc = loc;
  }

  qsort(samples, sample_count, sizeof(Sample), comp_alt);

  fclose(fp);

}

void show_samples() {

  printf("%8s, %9s, %s\n", "Alt.[km]", "Temp.[°C]", "Location");
  printf("\nsamples:\n");
  for (int i=0; i<sample_count; i++) {
    printf("%8.6lf, %9.6lf, %s\n", samples[i].alt, samples[i].temp, samples[i].loc);
  }

}

int f_dimension()
{
  return 2;
}

double f_value(const double x[])
{
  double error = 0;
  for (int i=0; i<sample_count; i++) {
    error += pow(samples[i].temp - (x[0] * samples[i].alt + x[1]), 2);
  }
  return error;
}

void f_gradient(const double x[], double g[])
{
  g[0] = 0;
  g[1] = 0;

  for (int i=0; i<sample_count; i++) {
    g[0] += (samples[i].temp - (x[0] * samples[i].alt + x[1])) * samples[i].alt;
  }
  g[0] *= -2;

  for (int i=0; i<sample_count; i++) {
    g[1] += (samples[i].temp - (x[0] * samples[i].alt + x[1]));
  }
  g[1] *= -2;

}

