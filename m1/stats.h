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
 * @file stats.h 
 * @brief This File is the Header file for stats.c
 *
 * @author Akshith Aluguri
 * @date 03-04-2022
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/******************************************************************************
 * Function: print_statistics
 * Description: @brief
 *     This function takes a set of numbers and prints all the Statistics of 
 *     the array including minimum, maximum, mean, and median.
 * Parameters: @param
 *     unsigned char* : Pointer to the data set
 *     unsigned int: Number of items in data set
 * Return: @return
 *     Returns 0.
 *****************************************************************************/
void print_statistics(unsigned char*, unsigned int);



/******************************************************************************
 * Function: print_array
 * Description: @brief
 *     This function takes a set of numbers(Array) and prints all the elements in it.
 * Parameters: @param
 *     unsigned char* : Pointer to the data set
 *     unsigned int: Number of items in data set
 * Return: @return
 *     Returns 0.
 *****************************************************************************/
void print_array(unsigned char*, unsigned int);



/******************************************************************************
 * Function: find_median
 * Description: @brief
 *     This function takes a set of numbers and finds the number which is in the 
 * middle of the set after the sort(this is called as the median of set).
 * Parameters: @param
 *     unsigned char* : Pointer to the data set
 *     unsigned int: Number of items in data set
 * Return: @return
 *     Returns the Median of the provided set as unsigned char type.
 *****************************************************************************/
unsigned char find_median(unsigned char*,unsigned int);



/******************************************************************************
 * Function: find_mean
 * Description: @brief
 *     This function takes a set of numbers and finds the average of
 *     of the complete set.
 * Parameters: @param
 *     unsigned char* : Pointer to the data set
 *     unsigned int: Number of items in data set
 * Return: @return
 *     Returns the Average or Mean of the provided set as unsigned char type.
 *****************************************************************************/

unsigned char find_mean(unsigned char*, unsigned int);



/******************************************************************************
 * Function: find_maximum
 * Description: @brief
 *     This function takes a set of numbers and finds the largest number of
 *     of the set.
 * Parameters: @param
 *     unsigned char* : Pointer to the data set
 *     unsigned int: Number of items in data set
 * Return: @return
 *     Returns the largest of the provided set as unsigned char type.
 *****************************************************************************/
unsigned char find_maximum(unsigned char*, unsigned int);



/******************************************************************************
 * Function: find_minimum
 * Description: @brief
 *     This function takes a set of numbers and finds the smallest number of
 *     of the set.
 * Parameters: @param
 *     unsigned char* : Pointer to the data set
 *     unsigned int: Number of items in data set
 * Return: @return
 *     Returns the smallest of the provided set as unsigned char type.
 *****************************************************************************/
unsigned char find_minimum(unsigned char* ,unsigned int);



/******************************************************************************
 * Function: sort_array
 * Description: @brief
 *     This function takes a set of numbers and sorts them in decending order.
 * Parameters: @param
 *     unsigned char* : Pointer to the data set
 *     unsigned int: Number of items in data set
 * Return: @return
 *     Returns 0.
 *****************************************************************************/
void sort_array(unsigned char*, unsigned int);



