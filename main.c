#include "inc_file.h" //Includes everything needed
#define FILENAME "dbase.bin"

void newDatabase();
void addItemToDatabase();
void deleteItemFromDatabase();
void searchInDatabase();
void editItemInDatabase();
void sortItemsInDatabase();
void outAllDatabase();
void modifyItemInDatabase();

int main(int argc, char *argv[])
{
	int user_choice;
	printf("Welcome to the soccer clubs database! Please choose one of the following:\n");
	while(1){ //Main program loop
		user_choice = showMenu(mainMenu, mainMenuPts);
		switch(user_choice)
		{
			case 1: newDatabase(); break;
			case 2: addItemToDatabase(); break;
			case 3: deleteItemFromDatabase(); break;
			case 4: searchInDatabase(); break;
			case 5: sortItemsInDatabase(); break;
			case 6: outAllDatabase(); break;
			case 7: modifyItemInDatabase(); break;
			case 8: exit(0); break;
			default: printf("Invalid input\n"); break;
			
		}
	}

	return 0;
}

void newDatabase()
{
	create_db(FILENAME);
}

void outAllDatabase()
{
	displayAllTeams(FILENAME);
}

void addItemToDatabase()
{
	addTeam(FILENAME);
}

void deleteItemFromDatabase()
{
	int a;
	printf("Input the ordinary number of the team in the list.\nThe list can be seen using the command number 6.\n");
	scanf("%d", &a);

	delTeam(FILENAME, a);	
}

void searchInDatabase()
{
	int user_choice;
	user_choice = showMenu(searchSubMenu, searchSubMenuPts);

	search(FILENAME, user_choice);


}

void sortItemsInDatabase()
{
	int user_choice;
	user_choice = showMenu(sortSubMenu, sortSubMenuPts);

	sort(FILENAME, user_choice);

}

void modifyItemInDatabase()
{
	int k;
	printf("Input the ordinary number of a team you want to edit ");
	scanf("%d", &k);

	modifyTeam(FILENAME, k);
}
