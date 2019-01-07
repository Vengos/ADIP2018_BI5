#include <stdio.h>
#include <stdlib.h>


typedef struct{
	int matrikelnummer;
	char* vorname;
	char* nachname;
}student;


void printf_student(student* student){
	printf("Vorname: %s, Nachname: %s, Matrikelnummer: %i\n", student->vorname, student->nachname, student->matrikelnummer);
}

void init_students20(student* student){
	for (int i= 0; i<20; i++)
	{
		student[i].matrikelnummer=0;
		student[i].vorname=NULL;
		student[i].nachname=NULL;

	}
}

void printf_student20(student* student){
	for(int i=0; i<20; i++)
	{
		printf("%i. Vorname: %s, Nachname: %s, Matrikelnummer: %i\n", i+1, student[i].vorname, student[i].nachname, student[i].matrikelnummer);
	}
}

void clear_students20(student* student){
	for (int i= 0; i<20; i++)
	{
		student[i].matrikelnummer=0;
		student[i].vorname=NULL;
		student[i].nachname=NULL;
	}
	free(student);
}



void get_name20(student* student, int matrikelnummer){
	for(int i= 0; i<20; i++)
	{
		if(student[i].matrikelnummer==matrikelnummer){
			printf("Name: %s %s\n", student[i].vorname, student[i].nachname);
			break;
		}
	}
}


void add_student20(student* student, char* vorname, char* nachname, int matrikelnummer){
	for(int i= 0; i<20; i++)
	{
		if(student[i].matrikelnummer== 0){
			student[i].matrikelnummer= matrikelnummer;
			student[i].vorname= vorname;
			student[i].nachname= nachname;
			break;
		}
		if(i==19){
			printf("Liste voll\n");
		}
	}
}

void remove_student(student* student, int matrikelnummer){
	for(int i= 0; i<20; i++)
	{
		if(student[i].matrikelnummer== matrikelnummer){
			student[i].matrikelnummer=0;
			student[i].vorname=NULL;
			student[i].nachname=NULL;
			break;
		}
	}
}






int main(){
    student* st;

	st= malloc(sizeof(student));

	st[0].matrikelnummer = 1234567;
	st[0].vorname = "Max";
	st[0].nachname = "Mustermann";

	printf_student(&st[0]);

	student studentlist[20];
	init_students20(studentlist);

	clear_students20(studentlist);
	add_student20(studentlist, "prof", "Anlauf", 42);
	get_name20(studentlist, 42);
	add_student20(studentlist, "Prof" ,"Klein" , 30);
	remove_student(studentlist, 42);
	printf_student20(studentlist);
	clear_students20(studentlist);
	printf_student20(studentlist);

	return 0;
}
