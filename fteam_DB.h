#pragma once

/* -----Creating functions, manipulation with teams----- */

/* create_db(...) function
 * Creates the initial database, asks user for input, writes to file
 * Uses newTeam(...) function */
int create_db(const char *fname);

/* newTeam(...)
 * Asks user for the data, forms one team */
void newTeam(team *pteam);

/* addTeam(...)
 * Adds specific team to the database, writes to file */
int addTeam(const char *fname);

/* int delTeam(...)
 * Deletes k'th team from the database, as well deleting it from the file */
int delTeam(const char *fname, int k);

/*modifyTeam(...)
 * Modifies the k'th entry in the database. */
int modifyTeam(const char *fname, int k);

/* readAllTeams(...)
 * Reads all the teams from file to the memory.
 * mumble mumble */
int readAllTeams(const char *fname, team *pteams);


/* -----Display functions, for outputting the entries to the user----- */

/* displayAllTeams(...)
 * Displays all the teams in current database file */
int displayAllTeams (const char *fname);

/* dispayTeam(...)
 * Reads k'th team from the file, displays it */
int displayTeam (const char *fname, int k);

/* displayT(...)
 * Displays given team, doesn't interact with file in any way
 * Just displays team in nice table */
void displayT (team *pt);

/* -----Misc functions, searching and displaying menu, etc. */

/* search(...)
 * Searches a database according to a given criteria. 
 * Returns an ordinary number of a found entry.
 *
 * Possible criterias:
 * 1 - Search by the name of the club
 * 2 - Search by the city of the club
 * 3 - Search by the points the club has won
 * 4 - Search by the difference between 
 * 5 - Search by the trainer name
 * 6 - Reserved. Not implemented yet.
 * All values greater than the last in this list are considered invalid. */
int search(const char *fname, int criteria);

/* team *sort(...)
 * Sorts a database according to a given criteria. 
 * Returns a pointer to the structure of teams in memory.
 *
 * Possible criterias:
 * 1 - Sort by the name of the club
 * 2 - Sort by the city of the club
 * 3 - Sort by the points the club has won
 * 4 - Sort by the difference between 
 * 5 - Sort by the trainer name
 * 6 - Reserved. Not implemented yet.
 * All values greater than the last in this list are considered invalid. */
int sort(const char *fname, int criteria);

/* int showMenu()
 * Shows menu of actions for the user, reads action name */
int showMenu();

/* int lof(...)
 * Returns the lenght of current file with in components, according to component_size variable.
 * component_size variable usually stands for sizeof(team) */
int lof(FILE *file, int component_size);

/* chop(...)
 * Removes any trailing newline from a string */
void chop(char *str);
