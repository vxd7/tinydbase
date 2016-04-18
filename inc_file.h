#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <sys/io.h>
#include <string.h>
#include <unistd.h> //ftruncate

/* The right order here is very important!!! */
#include "struct_header.h"
#include "sort.h"
#include "fteam_DB.h"
#include "search.h"

/* Variables for menus. Definitions goes here, values are in the menus.c file */
extern const int mainMenuPts;
extern const char *mainMenu;

extern const int searchSubMenuPts;
extern const char *searchSubMenu;

extern const int sortSubMenuPts;
extern const char *sortSubMenu;
