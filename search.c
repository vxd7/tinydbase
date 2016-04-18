#include "inc_file.h"

int searchByClubname(const char *fname, const char *teamname)
{
	int i, n;
	team a;
	FILE *fp;

	if((fp = fopen(fname, "rb")) == NULL)
	{
		fprintf(stderr, "Cannot read file %s, function searchByClubname\n", fname);
		return -1;	
	}

	fseek(fp, 0, SEEK_SET);

	n = lof(fp, sizeof(team));

	for(i = 0; i < n; i++)
	{
		fseek(fp, i*sizeof(team), SEEK_SET);
		fread(&a, sizeof(team), 1, fp);
		fseek(fp, i*sizeof(team), SEEK_SET);
		if(strcmp(a.Clubname, teamname) == 0)
		{
			fclose(fp);
			return i;	
		}
	}

	return -1; //if we didn't find anything -- here is the error
}

int searchByCity(const char *fname, const char *cname)
{
	int i, n;
	team a;
	FILE *fp;

	if((fp = fopen(fname, "rb")) == NULL)
	{
		fprintf(stderr, "Cannot read file %s, function searchByCity\n", fname);
		return -1;	
	}

	fseek(fp, 0, SEEK_SET);

	n = lof(fp, sizeof(team));

	for(i = 0; i < n; i++)
	{
		fseek(fp, i*sizeof(team), SEEK_SET);
		fread(&a, sizeof(team), 1, fp);
		fseek(fp, i*sizeof(team), SEEK_SET);
		if(strcmp(a.City, cname) == 0)
		{
			fclose(fp);
			return i;	
		}
	}

	return -1; //if we didn't find anything -- here is the error
}
int searchByPoints(const char *fname, int pts)
{
	int i, n;
	team a;
	FILE *fp;

	if((fp = fopen(fname, "rb")) == NULL)
	{
		fprintf(stderr, "Cannot read file %s, function searchByPoints\n", fname);
		return -1;	
	}

	fseek(fp, 0, SEEK_SET);

	n = lof(fp, sizeof(team));

	for(i = 0; i < n; i++)
	{
		fseek(fp, i*sizeof(team), SEEK_SET);
		fread(&a, sizeof(team), 1, fp);
		fseek(fp, i*sizeof(team), SEEK_SET);
		if(a.Points == pts)
		{
			fclose(fp);
			return i;	
		}
	}

	return -1; //if we didn't find anything -- here is the error
}
int searchByDiff(const char *fname, int diff)
{
	int i, n;
	team a;
	FILE *fp;

	if((fp = fopen(fname, "rb")) == NULL)
	{
		fprintf(stderr, "Cannot read file %s, function searchByDiff\n", fname);
		return -1;	
	}

	fseek(fp, 0, SEEK_SET);

	n = lof(fp, sizeof(team));

	for(i = 0; i < n; i++)
	{
		fseek(fp, i*sizeof(team), SEEK_SET);
		fread(&a, sizeof(team), 1, fp);
		fseek(fp, i*sizeof(team), SEEK_SET);
		if(a.Diff == diff)
		{
			fclose(fp);
			return i;	
		}
	}

	return -1; //if we didn't find anything -- here is the error
}
int searchByTrainerName(const char *fname, const char *tname)
{
	int i, n;
	team a;
	FILE *fp;

	if((fp = fopen(fname, "rb")) == NULL)
	{
		fprintf(stderr, "Cannot read file %s, function searchByTrainerName\n", fname);
		return -1;	
	}

	fseek(fp, 0, SEEK_SET);

	n = lof(fp, sizeof(team));

	for(i = 0; i < n; i++)
	{
		fseek(fp, i*sizeof(team), SEEK_SET);
		fread(&a, sizeof(team), 1, fp);
		fseek(fp, i*sizeof(team), SEEK_SET);
		if(strcmp(a.TrainerName, tname) == 0)
		{
			fclose(fp);
			return i;	
		}
	}

	return -1; //if we didn't find anything -- here is the error
}

/*int *searchAllByClubname(const char *fname, const char *teamname)
{
	int i, n, count = 0;
	int *res = NULL;
	team a;
	FILE *fp;

	if((fp = fopen(fname, "rb")) == NULL)
	{
		fprintf(stderr, "Cannot read file %s, function searchAllByClubname\n", fname);
		return NULL;	
	}

	fseek(fp, 0, SEEK_CUR);

	n = lof(fp, sizeof(team));

	res = (int *)realloc(res, count * sizeof(int)); //allocate memory for out growing array of found objects
	for(i = 0; i < n; i++)
	{
		fseek(fp, i*sizeof(team), SEEK_CUR);
		fread(&a, sizeof(team), 1, fp);
		if(strcmp(a.Clubname, teamname) == 0)
		{
			count++;
			res = (int *)realloc(res, count * sizeof(int)); 
			*(res + count -1) = i; //found items goes here
		}
	}

	fclose(fp);

	if(count != 0) return res;
	else return NULL; //didn't find anything -- no such item
}*/
