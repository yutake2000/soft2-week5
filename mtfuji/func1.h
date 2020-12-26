#ifndef OPTIMIZE_FUNC_H
#define OPTIMIZE_FUNC_H

// csvファイルから標高と気温の標本データを読み取る。
// f_value以外で使うことはないのでstaticグローバル変数に収納しておく。
void load_samples(const char filename[]);
// 標本データを標高順に出力する。
void show_samples();

int f_dimension();
double f_value(const double x[]);
void f_gradient(const double x[], double g[]);

#endif
