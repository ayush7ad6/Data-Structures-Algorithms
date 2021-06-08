#ifndef HEADER_A_H_INCLUDED
#define HEADER_A_H_INCLUDED

#include <iostream>


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
void mergesort(int arr[], int l, int r); // merge sort function
void merge(int arr[], int l, int m, int r);  //merge function
void partition(int arr[], int l, int p, int r);   //naive partition
int lomuto(int arr[], int l, int r);           //lumoto partition
int hoares(int arr[], int l, int r);           //hoare's partition
void quicksort(int arr[], int l, int r);        //lomuto partition
void ncsort(int arr[], int n, int k);            //counting sort naive
void csort(int arr[], int n, int k);            //counting sort general
void rsort(int arr[], int n);                   //radix sort
void rcsort(int arr[], int n, int exp);         //counting routine



// S T R I N G
bool anagram(string s1, string s2);   //to check if two strings are permutations of each other
int leftindex(string s);              //index for the leftmost repeating character
int nonrepeat(string s);        //index for the leftmost non repeating character
int lexirank(string s);         //rank
bool anagrampresent(string txt, string pat);    //substring continuous present
bool aresame(int c, int cc);            //compare two
bool rotation(string s1, string s2);        //check it two strings are rotations






// S E A R C H I N G
int binarysearch(int arr[], int n, int num);
int recbsearch(int arr[], int low, int high, int num);  //recursive binary search


// H A S H I N G in hashing.h

// L I N K E D  L I S T S  in linkedl.h























#endif // HEADER_A_H_INCLUDED
