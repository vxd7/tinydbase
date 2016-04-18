#pragma once
/* Header fole for the sorting algorithms and methods described in the sort.c file */
/* All string sorts are lexicographical, all int sorts are normal int sorts */

/* Sorts by the name of the club */
int sortByClubname(FILE *fp, int n, int *st_arr);

/*Sorts by the city of the club */
int sortByCity(FILE *fp, int n, int *st_arr);

int sortByPoints(FILE *fp, int n, int *st_arr);
int sortByDiff(FILE *fp, int n, int *st_arr);
int sortByTrainername(FILE *fp, int n, int *st_arr);
