/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief This file has the C- Implementation to performs statitical analysis 
 *      on an set of data like maximum, minimum, mean, and median. Also It arranges 
 *      the data in decending order.
 *
 *
 * @author Akshith Aluguri
 * @date 03-04-2022
 *
 */


#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
    unsigned int count=SIZE;
  //   maximum,minimum,median,mean=0;

  /* Statistics and Printing Functions Go Here */
  printf("Given Array: \n");
  print_array(test, count);

  printf("Sorted Array in Decending Order: \n");
  sort_array(test,count);
  print_array(test, count);

  printf("Array Statistics:\n");
  print_statistics(test,count);

}

/* Add other Implementation File Code Here */
void print_statistics(unsigned char* Array, unsigned int count){

  unsigned char median = find_median(Array, count);
  unsigned char mean = find_mean(Array, count);
  unsigned char maximum = find_maximum(Array, count);
  unsigned char minimum = find_minimum(Array, count);

  printf("The median is %d \n", median);
  printf("The mean is %d \n", mean);
  printf("The maximum is %d \n", maximum);
  printf("The minimum is %d \n", minimum);
}

void print_array(unsigned char* Array, unsigned int count){

  for(int i = 0 ; i < count ; i++)printf("%d, ", Array[i]);
  printf("\n");
}

unsigned char find_median(unsigned char* Array, unsigned int count){

    if(count & 1) return Array[count /2];
  return (Array[(count - 1) /2] + Array[count /2]) /2;
}

unsigned char find_mean(unsigned char* Array, unsigned int count){

  int sum=0;
  for(int i = 0 ; i < count ; i++) sum+=Array[i];
  if ((sum/((float)count)-sum/count)>0.5)return (sum/count)+1;
  else return sum/count;
}

unsigned char find_maximum(unsigned char* Array, unsigned int count){
  
  unsigned char max=0;
  for(int i=0; i<count; ++i) if(Array[i]>max) max= Array[i];
  return max;
}

unsigned char find_minimum(unsigned char* Array, unsigned int count){
    
  unsigned char min=Array[0];
  for(int i=0; i<count; ++i) if(Array[i]<min) min= Array[i];
  return min;
}

void sort_array(unsigned char* Array, unsigned int count){

    int temp;
    for(int i=0; i<count; ++i){
    for(int j=i+1; j<count; ++j){
      if(Array[i]<Array[j]){
        temp = Array[i];
        Array[i]=Array[j];
        Array[j]=temp;
      }
    }
  }
}

