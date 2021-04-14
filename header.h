#ifndef HEADER_A_H_INCLUDED
#define HEADER_A_H_INCLUDED
using namespace std;

//A R R A Y S


int show(int arr[],int cap);
int in_arr(int arr[],int n,int cap, int x);
bool search(int arr[], int n, int cap, int x);  // s e a r c h
void del(int arr[], int n, int &cap, int x);    //d e l e t e
int max_index(int arr[], int n, int cap);
int sec_max(int arr[], int n);                  //second largest element's index
int z_right(int arr[], int n);                  //zeros to the right in an array (complex solution could be linear)
int rev_arr(int a[], int n);                    //reverse an array
int rotate_arr(int a[], int n);                 //clockwise rotation



// R E C U R S I O N

int fact(int n);
int fibo(int n);
int sum_dig(int n);
int printn(int n);
bool comp(int a, int b);
int maxcuts(int n, int a, int b, int c);
void tail_print(int n, int k = 1);                                  //tail recursion from 1 to n print
int tail_fact(int n, int val =1);                                   //tail recursion of factorial
bool isPal(string str, int s, int e);                                  //palindrome checking
void printsub(string str, string curr="", int index = 0);           //print the subsets of a string
int toh(int n, char a='A', char b = 'B', char c = 'C', int nos=0);  //tower of hanoi
//question from theory
bool find(int arr[], int n, int s);     //to check a num present in an array
void permu(string str, int s = 0, int e=0);  //permutations (selfmade 50%)
//do joesphus too!



// S O R T I N G
void bubble_sort(int arr[], int n);   //bubble sort
void selection_sort(int arr[], int n); // selection sort
void isort(int arr[], int n); // insertion sort















#endif // HEADER_A_H_INCLUDED
