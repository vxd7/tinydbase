#include "inc_file.h"

int sortByClubname(FILE *fp ,int n, int *st_arr)
{
	int i, j, k;
	int tmp;
	team a, b;

	for(i = 0; i < n; i++) st_arr[i] = i;

	for(i = 0; i < n - 1; i++)
	{
		for(j = 0; j < n-i-1; j++)
		{
			fseek(fp, st_arr[j]*sizeof(team), SEEK_SET);
			fread(&a, sizeof(team), 1, fp);
			fseek(fp, st_arr[j + 1]*sizeof(team), SEEK_SET);
			fread(&b, sizeof(team), 1, fp);

			if(strcmp(a.Clubname, b.Clubname) > 0)
			{
				tmp = st_arr[j];
				st_arr[j] = st_arr[j + 1];
				st_arr[j + 1] = tmp;
			}
		}
	}

	return 1;
}

int sortByCity(FILE *fp, int n, int *st_arr)
{
	int i, j, k;
	int tmp;
	team a, b;

	for(i = 0; i < n; i++) st_arr[i] = i;

	for(i = 0; i < n - 1; i++)
	{
		for(j = 0; j < n-i-1; j++)
		{
			fseek(fp, st_arr[j]*sizeof(team), SEEK_SET);
			fread(&a, sizeof(team), 1, fp);
			fseek(fp, st_arr[j + 1]*sizeof(team), SEEK_SET);
			fread(&b, sizeof(team), 1, fp);

			if(strcmp(a.City, b.City) > 0)
			{
				tmp = st_arr[j];
				st_arr[j] = st_arr[j + 1];
				st_arr[j + 1] = tmp;
			}
		}
	}

	return 1;
	
}

int sortByPoints(FILE *fp, int n, int *st_arr)
{
	int i, j, k;
	int tmp;
	team a, b;

	for(i = 0; i < n; i++) st_arr[i] = i;

	for(i = 0; i < n - 1; i++)
	{
		for(j = 0; j < n-i-1; j++)
		{
			fseek(fp, st_arr[j]*sizeof(team), SEEK_SET);
			fread(&a, sizeof(team), 1, fp);
			fseek(fp, st_arr[j + 1]*sizeof(team), SEEK_SET);
			fread(&b, sizeof(team), 1, fp);

			if(a.Points > b.Points)
			{
				tmp = st_arr[j];
				st_arr[j] = st_arr[j + 1];
				st_arr[j + 1] = tmp;
			}
		}
	}

	return 1;
	
	
}
int sortByDiff(FILE *fp, int n, int *st_arr)
{
	int i, j, k;
	int tmp;
	team a, b;

	for(i = 0; i < n; i++) st_arr[i] = i;

	for(i = 0; i < n - 1; i++)
	{
		for(j = 0; j < n-i-1; j++)
		{
			fseek(fp, st_arr[j]*sizeof(team), SEEK_SET);
			fread(&a, sizeof(team), 1, fp);
			fseek(fp, st_arr[j + 1]*sizeof(team), SEEK_SET);
			fread(&b, sizeof(team), 1, fp);

			if(a.Diff> b.Diff)
			{
				tmp = st_arr[j];
				st_arr[j] = st_arr[j + 1];
				st_arr[j + 1] = tmp;
			}
		}
	}

	return 1;
	
	
}
int sortByTrainername(FILE *fp, int n, int *st_arr)
{
	int i, j, k;
	int tmp;
	team a, b;

	for(i = 0; i < n; i++) st_arr[i] = i;

	for(i = 0; i < n - 1; i++)
	{
		for(j = 0; j < n-i-1; j++)
		{
			fseek(fp, st_arr[j]*sizeof(team), SEEK_SET);
			fread(&a, sizeof(team), 1, fp);
			fseek(fp, st_arr[j + 1]*sizeof(team), SEEK_SET);
			fread(&b, sizeof(team), 1, fp);

			if(strcmp(a.TrainerName, b.TrainerName) > 0)
			{
				tmp = st_arr[j];
				st_arr[j] = st_arr[j + 1];
				st_arr[j + 1] = tmp;
			}
		}
	}

	return 1;
	
	
}
