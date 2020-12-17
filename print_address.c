// 関数を含めて、いろいろなアドレスを見てみる
#include <stdio.h>
#include <stdlib.h>

int global = 0;

int add_one(int x){

	static int count = 0;
	
	// 関数内のstatic変数	
	printf("count_in_add_one: %p\n", &count);
	// add_one関数の引数x
	printf("x_in_add_one: %p\n",&x);
	return x + 1;
}

int main(){
	int x = 10;
	int *a = (int*) malloc(sizeof(int));
	
	// main関数のアドレス
	printf("function_main: %p\n", &main);
	
	// main内の変数x
	printf("x_in_main: %p\n", &x);
	// グローバル変数global
	printf("global: %p\n", &global);
	// malloc されたa
	printf("allocated_a: %p\n", a);
	// ポインタそのもののアドレス
	printf("pointer_a_in_main: %p\n", &a);
	
	add_one(x);
	
	// add_one関数のアドレス
	printf("function_add_one: %p\n", &add_one);
	
	return 0;
}
