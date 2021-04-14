#ifndef HEADER_A_H_INCLUDED
#define HEADER_A_H_INCLUDED


//A R R A Y S


int show(int arr[],int cap);
int in_arr(int arr[],int n,int cap, int x);
bool search(int arr[], int n, int cap, int x);                    // s e a r c h
void del(int arr[], int n, int &cap, int x);       //d e l e t e
int max_index(int arr[], int n, int cap);
int sec_max(int arr[], int n);           //second largest element's index
int z_right(int arr[], int n);                //zeros to the right in an array (complex solution could be linear)
int rev_arr(int a[], int n);       //reverse an array
int rotate_arr(int a[], int n);             //clockwise rotation



// R E C U R S I O N

int fact(int n);
int fibo(int n);
int sum_dig(int n);
int printn(int n);
bool comp(int a, int b);
int maxcuts(int n, int a, int b, int c);
śś



#endif // HEADER_A_H_INCLUDED
