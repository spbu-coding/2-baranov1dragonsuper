#include<stdio.h>
#include<string.h>
#include <stdlib.h>
void sort(long long *arr, int n);

long long * check_word(char *args){
	int f = 1, t = 1; //f - "from", t - "to"
	char *f_word[] = {"-", "-", "f", "r", "o", "m", "="}, *t_word[] = {"-", "-", "t", "o", "="};
	for (int i = 0; i < 7; ++i){
		if(args[i] != *f_word[i]){f = 0;}
		if(i < 5 && args[i] != *t_word[i]){t = 0;}
	}
	int sign = 1, start;
	long long res = 0;
	static long long null[2] = {-1,-1}; //array for case of wrong parameter like "--lololo"
	if(f){ start = 7; }
	if(t){ start = 5; }
	if(t+f == 0){ return (null); }
	if(args[start] == '-'){start++; sign = -1;}
	for(long unsigned int i = start; i < strlen(args); ++i){
		res*= 10;
		if(args[i] < 48 || args[i] > 57){break;}
		res += args[i]-48;
	}
	res*=sign;
	long long *res2 = malloc (sizeof (int) * 2);
	res2[0] = f; res2[1] = res;
	return (res2);
}

int main(int argc, char *argv[]){
	long long from = 0, to= 0, *t, arr[101]; //t - temporary variable for parsing arguments
	int tob = 0, fromb = 0, res = 0; // tob, fromb - count of args "from" and "b", res - result
	for (int i = 0; i < 101; i++) arr[i] = 0;
	if(argc < 2){return(-1);}
	for (int i = 1; i < argc; ++i){
		t = check_word(argv[i]);
		if(t[0] == -1) {}
		else if (t[0] == 1) {from = t[1]; fromb++;}
		else {to = t[1]; tob++;}
	}
	if(fromb > 1 || tob > 1){return (-3);}
	if(argc - fromb - tob > 2){return (-4);}
	if(argc > 3){return(-2);}
	int size = 0;
	char c = ' ';
	while (c == ' ') scanf("%lli%c", &arr[size++], &c);
	long long copy[101];
	for (int j = 0; j < size; ++j){
		if(tob && (to <= arr[j])) fprintf(stderr, "%lli ", arr[j]);
		if(fromb && (from >= arr[j])) fprintf(stdout, "%lli ", arr[j]);
		copy[j] = arr[j];
	}
	sort(arr,size);
	for (int j = 0; j < size; ++j){
		if(arr[j] != copy[j]) {res++;}
	}
	return(res);
}
