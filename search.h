#pragma once
/* Header file for all the search functions in a database. The code goes to the search.c file */

int searchByClubname(const char *fname, const char *teamname);
int *searchAllByClubname(const char *fname, const char *teamname);
int searchByCity(const char *fname, const char *cname);
int searchByPoints(const char *fname, int pts);
int searchByDiff(const char *fname, int diff);
int searchByTrainerName(const char *fname, const char *tname);
