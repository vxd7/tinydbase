#include "inc_file.h"

/* For the function descriptions see the fteam_DB.h file */
int create_db(const char *fname)
{
	int number, i, n;
	team a;
	FILE *fp;
	if((fp = fopen(fname, "rb+")) == NULL)
	{
		fprintf(stderr, "Cannot create file %s, function create_db\n", fname);
		return 1;	
	}
	printf("You are going to form the database of soccer clubs.\n");
	printf("Input the number of entries in %s file, n = ", fname);
	scanf(" %d", &n);
	getchar(); //remove any newline character that is still in the stream
	for(i = 0; i<n; i++){
		newTeam(&a);
		fwrite(&a, sizeof(team),1, fp);
	}
	printf("Input is completed\n");
	fclose(fp);
	return 0;
}

void newTeam(team *pt)
{
	/* -1 means the user left this entry blank. */
	pt->Points = -1;
	pt->Diff = -1;

	printf("Name of the club = "); fgets(pt->Clubname, 100, stdin);
	chop(pt->Clubname);
	printf("City of the club = "); fgets(pt->City, 100, stdin);
	chop(pt->City);
	printf("Number of points = "); scanf("%d", &(pt->Points));
	printf("Difference in ... = "); scanf("%d", &(pt->Diff));
	getchar(); //remove any newline character that is still in the stream
	printf("The name of the trainer = "); fgets(pt->TrainerName, 100, stdin);
	chop(pt->TrainerName);
}

int addTeam(const char *fname)
{
	team a;
	int filelength;
	FILE *fp;

	if((fp = fopen(fname, "rb+")) == NULL)
	{
		fprintf(stderr, "Cannot open file %s, function addTeam\n", fname);
		return 1;	
	}

	printf("Adding new team, please enter the following:\n");
	getchar(); //remove any newline character that is still in the stream
	newTeam(&a);
	filelength = lof(fp, sizeof(team));

	fseek(fp, 0, SEEK_END); //jump to the end of file
	fwrite(&a, sizeof(team), 1, fp); //And write the entry
	fclose(fp);

	return 0;

}

int delTeam(const char *fname, int k)
{
	int i, n;
	team a;
	FILE *fp;

	if((fp = fopen(fname, "rb+")) == NULL)
	{
		fprintf(stderr, "Cannot open file %s, function delTeam\n", fname);
		return 1;	
	}
	
	n = lof(fp, sizeof(team));
	if(n == 0)
	{
		printf("Cannot delete! File is empty.\n");
		return 2;
	}

	if((k>n) || (k<0))
	{
		fprintf(stderr, "Invalid entry number %d, cannot delete given team\n", k);
		return 3;
	}

	for(i = k;i<n;i++) //shift all the entries left by one
	{
		fseek(fp, (i+1)*sizeof(team), SEEK_SET);
		fread(&a, sizeof(team),1,fp);
		fseek(fp, i*sizeof(team), SEEK_SET);
		fwrite(&a, sizeof(team), 1, fp);
	}
	n = lof(fp, sizeof(team));

	//truncate here
	//Works only on Linux, needs POSIX-compatible unistd.h file!
	ftruncate(fileno(fp), (n - 1)*sizeof(team));
	fclose(fp);
	return 0;
}

int modifyTeam(const char *fname, int k)
{
	int i, n;
	team a;
	team tnew;
	FILE *fp;

	if((fp = fopen(fname, "rb+")) == NULL)
	{
		fprintf(stderr, "Cannot open file %s, function modifyTeam\n", fname);
		return 1;	
	}

	n = lof(fp, sizeof(team));

	if((k>n) || (k<0))
	{
		fprintf(stderr, "Invalid entry number %d, cannot modify given team\n", k);
		return 2;
	}

	fseek(fp, k*sizeof(team), SEEK_SET);
	fread(&a, sizeof(team), 1, fp);

	printf("Old values:\n");
	displayT(&a);
	printf("Input new values. Leave field blank(or -1 for integer values) if you don't want to change it.\n");
	getchar();
	newTeam(&tnew);

	if(strlen(tnew.Clubname) == 0) strcpy(tnew.Clubname, a.Clubname);
	if(strlen(tnew.City) == 0) strcpy(tnew.City, a.City);
	if(strlen(tnew.TrainerName) == 0) strcpy(tnew.TrainerName, a.TrainerName);

	if(tnew.Points == -1) tnew.Points = a.Points;
	if(tnew.Diff == -1) tnew.Diff = a.Diff;
	
	fseek(fp, k*sizeof(team), SEEK_SET);
	fwrite(&tnew, sizeof(team), 1, fp);

	fclose(fp);

	return 0;

}

int readAllTeams(const char *fname, team *pteams)
{
	int i, n;
	FILE *fp;

	if((fp = fopen(fname, "rb")) == NULL)
	{
		fprintf(stderr, "Cannot read file %s, function readAllTeams\n", fname);
		return 1;	
	}

	n = lof(fp, sizeof(team));

	for(i = 0; i < n; i++)
	{
		fseek(fp, i*sizeof(team), SEEK_CUR);
		fread((pteams + i), sizeof(team), 1, fp);
	}
	 
	return 0;
	
}

int displayAllTeams (const char *fname)
{
	int i, n;
	team a;
	FILE *fp;

	if((fp = fopen(fname, "rb")) == NULL)
	{
		fprintf(stderr, "Cannot read file %s, function displayAllTeams\n", fname);
		return 1;	
	}

	n = lof(fp, sizeof(team));

	for(i = 0; i < n; i++)
	{
		printf("Team #%d'th\n", i);
		fseek(fp, i*sizeof(team), SEEK_SET);
		fread(&a, sizeof(team), 1, fp);
		displayT(&a); 
	}
	printf("\n");

	fclose(fp);
}

int displayTeam (const char *fname, int k)
{
	int n;
	team a;
	FILE *fp;

	if((fp = fopen(fname, "rb")) == NULL)
	{
		fprintf(stderr, "Cannot read file %s, function displayTeam\n", fname);
		return 1;	
	}

	n = lof(fp, sizeof(team));

	if((k>n) || (k<0))
	{
		fprintf(stderr, "Invalid entry number %d, cannot display given team\n", k);
		return 2;
	}

	fseek(fp, k*sizeof(team), SEEK_SET); //jump to a k'th team
	fread(&a, sizeof(team), 1, fp);
	displayT(&a);
	fclose(fp);
	
}

void displayT (team *pt)
{
	printf("Clubname = %s\n", pt->Clubname);
	printf("City  = %s\n", pt->City);
	printf("Trainer name = %s\n", pt->TrainerName);
	printf("Points = %d\n", pt->Points);
	printf("Difference = %d\n", pt->Diff);
	printf("---------------------------------\n");
}

int search(const char *fname, int criteria)
{
	int i, n, ans;
	int num; //for the integer fields in a database
	char str[STRLEN]; //for the string type of fields in a database
	team tmp;
	int *res = NULL;
	FILE *fp;


	switch(criteria)
	{
		case 1: 
			printf("Name of the team = "); 
			getchar();
			fgets(str, STRLEN, stdin);
			chop(str);

			ans = searchByClubname(fname, str);
		   	break;
			
		case 2: 
			printf("City = "); 
			getchar();
			fgets(str, STRLEN, stdin);
			chop(str);

			ans = searchByCity(fname, str); 
			break;
		case 3: 
			printf("Number of the points = "); 
			scanf("%d", &num);
			
			ans = searchByPoints(fname, num); break;
		case 4: 
			printf("Difference = "); 
			scanf("%d", &num);
			
			ans = searchByDiff(fname, num); break;
			break;
		case 5: 
			printf("Name of the trainer = "); 
			getchar();
			fgets(str, STRLEN, stdin);
			chop(str);

			ans = searchByTrainerName(fname, str); 
			break;
		case 6: return; break;
		default: return -2; break;
	}
	
	if(ans == -1) return -3;

	printf("Found teams:\n");
	displayTeam(fname, ans);

	
}

int sort(const char *fname, int criteria)
{
	int i, n;
	//team *allteams;
	team tmp;
	int *res; //Resulting array of ordinary entry numbers
	FILE *fp;

	if((fp = fopen(fname, "rb")) == NULL)
	{
		fprintf(stderr, "Cannot read file %s, function sort\n", fname);
		return 1;	
	}
	/*
	printf("Reading teams, this may take a while...\n");
	if(readAllTeams(fname, allteams) != 0) //read all the teams from the file
	{
		printf("Failed reading the teams! Exiting now.");
		return 1;
	}
	printf("Done!\n");*/

	n = lof(fp, sizeof(team));
	res = (int *)malloc(n*sizeof(int));


	switch(criteria)
	{
		case 1: sortByClubname(fp, n, res); break;
		case 2: sortByCity(fp, n, res); break;
		case 3: sortByPoints(fp, n,res); break;
		case 4: sortByDiff(fp, n, res); break;
		case 5: sortByTrainername(fp, n, res); break;
		case 6: return; break;
		default: return 2; break;
	}
	
	printf("The result of sorting:\n");
	for(i = 0; i < n; i++)
	{
		fseek(fp, (*(res + i))*sizeof(team), SEEK_SET);
		fread(&tmp, sizeof(team), 1, fp);
		displayT(&tmp);

	}

	free(res);
	fclose(fp);
}

int lof(FILE *file, int component_size)
{
	int size, pos;
	pos = ftell(file); //save our old position in file 

	fseek(file, 0, SEEK_END);
	size = ftell(file)/component_size;
	fseek(file, pos, SEEK_SET); //restore our old position

	return size;

}

int showMenu(const char *menu, int n)
{
	int a;
	printf("%s\n", menu); //Print menu items, one by one

	scanf("%d", &a);
	while((a<1) || (a>n))
	{
		printf("Invalid input, please try again\n");
		getchar();
		scanf(" %d", &a); //The space at the start -- to discard all whitespace
	}

	return a;
							
}

void chop(char *str)
{
	char *ptr = strchr(str, '\n');
	*ptr = '\0';
}
