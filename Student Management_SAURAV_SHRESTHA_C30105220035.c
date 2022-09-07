#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

void student();
void admin();
typedef struct{

	int rollNumber;
	char name[50];
	char branch[50];
	int dob; //day of birth
	int semister;

}STUDENT_INFO_t;

int max_record=10;

//Global array of record
STUDENT_INFO_t students[10];

void display_menu(void);
int read_menu_code(void);
void decode_menu_code(int8_t menu_code);
void display_all_record(STUDENT_INFO_t *record,int8_t max_record);
int check_roll_number(int roll_number,STUDENT_INFO_t *record,int8_t max_record);
int add_new_record(STUDENT_INFO_t *record,int8_t max_record);
int delete_record(STUDENT_INFO_t *record,int8_t max_record);

int main(){
	system("clear");
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t|____________________|\n\t\t\t\t\t|                    |\n\t\t\t\t\t|\tWelcome      |\n\t\t\t\t\t|____________________|\n\t\t\t\t\t|\t\t     |\n\n\n");
    getchar();
   system("clear");
   system("clear");
   
        printf("\n\t+-------------------------------------------------------+");
        printf("\n\t|                                                       |");
        printf("\n\t|                                                       |");
        printf("\n\t|          Students Record Management system            |");
        printf("\n\t|                                                       |");
        printf("\n\t|                                                       |");
        printf("\n\t|                                                       |");
        printf("\n\t|                                                       |");
        printf("\n\t+-------------------------------------------------------+");
       int select;
        printf("\n\n\n\n\t\t[+] Select->");
        printf("\n\t\t[1] Login as admin");
        printf("\n\t\t[2] Visit as student");
        printf("\n\n\t\t[*] input number which you want: ");
        scanf(" %d",&select);

        switch (select)
        {
        case 1:
         system("clear");
            admin();
            break;
        case 2:
         system("clear");
            student();
            break;
       default:
            printf("Enter valid choice.");
            break;

            return 0;
}
            return 0;



	return 0;
}
void student()
{
 
   char user_name[20];
   char pass_word[20];

            printf("\n\t\tUsername: ");
            scanf("%s",&user_name);

            FILE *user_user;
            user_user=fopen("student/username.txt","r");
            char user_name_str[20];
            fgets(user_name_str,20,user_user);
            fclose(user_user);

            if(strcmp(user_name,user_name_str)==0){
                printf("\t\tPassword: ");
                scanf("%s",&pass_word);

                FILE *user_pass;
                user_pass=fopen("student/password.txt","r");
                char user_pass_str[20];
                fgets(user_pass_str,20,user_pass);    /*Make "user_pass" to a string "user_pass_str"*/
                fclose(user_pass);
               system("clear");

                if(strcmp(pass_word,user_pass_str)==0){
                    int8_t app_continue=1;
	int8_t menu_code;

	while(app_continue){
          getchar();
system("clear");

		printf("\n\t\t\tDisplay all record -->1\n");
	printf("\t\t\tExit application   -->0\n");
	printf("\t\t\tPlease enter your option here :\t");
         //display the menu code

		menu_code=read_menu_code();

		if(menu_code){

system("clear");
			decode_menu_code(menu_code);

		}
		else{
			printf("Exiting application\n");
			app_continue=0;
		}
	}


                }
            }
}
void admin()
{
 
   char user_name[20];
   char pass_word[20];

            printf("\n\t\tUsername: ");
            scanf("%s",&user_name);

            FILE *user_user;
            user_user=fopen("admin/username.txt","r");
            char user_name_str[20];
            fgets(user_name_str,20,user_user);
            fclose(user_user);

            if(strcmp(user_name,user_name_str)==0){

                printf("\t\tPassword: ");
                scanf("%s",&pass_word);

                FILE *user_pass;
                user_pass=fopen("admin/password.txt","r");
                char user_pass_str[20];
                fgets(user_pass_str,20,user_pass);    /*Make "user_pass" to a string "user_pass_str"*/
                fclose(user_pass);
                printf("\n\n");
                system("clear");

                if(strcmp(pass_word,user_pass_str)==0){
            
                 int8_t app_continue=1;
	int8_t menu_code;

	while(app_continue){
        getchar();
  system("clear");
		display_menu();  //display the menu code

		menu_code=read_menu_code();

		if(menu_code){
               system("clear");

			decode_menu_code(menu_code);

		}
		else{
			printf("Exiting application\n");
			app_continue=0;
		}
	}

                }
            }
}

void display_menu(void){  

	printf("\t\t\tDisplay all record -->1\n");
	printf("\t\t\tAdd new record     -->2\n");
	printf("\t\t\tDelete a record    -->3\n");
	printf("\t\t\tExit application   -->0\n");
	printf("\t\t\tPlease enter your option here :\t");
       
 

}

int read_menu_code(void){

	int input;
	scanf("%d",&input);

	return input;
}

void decode_menu_code(int8_t menu_code){

	int8_t ret;

	switch(menu_code)
	{
	case 1: printf("Displaying all students records\n");
	display_all_record(students, max_record);
	break;
	case 2:printf("Add a new record\n");
    add_new_record(students, max_record);
  printf("Record added succesfully\n");
	break;
	case 3:printf("Delete a record\n");
	delete_record(students, max_record);
	printf("Record deleted successfully\n") ; 
	break;
	default:
		printf("invalid input\n");
	}
}

void display_all_record(STUDENT_INFO_t *record,int8_t max_record){

	int record_found=0;

	for(int i=0;i<max_record;i++){

		if(record[i].rollNumber)
		{
			record_found=1;
			//display the record
			printf("***********\n");
			printf("\t\t\trollnumber : %u\n",record[i].rollNumber);
			printf("\t\t\tname       : %s\n",record[i].name);
			printf("\t\t\tbranch     : %s\n",record[i].branch);
			printf("\t\t\tdob        : %u\n",record[i].dob);
			printf("\t\t\tsemister   : %u\n",record[i].semister);
			printf("\t\t\t***********\n");
		}

	}
	if(! record_found)
	        printf("No records found.......\n");
            getchar();

}

int check_roll_number(int roll_number,STUDENT_INFO_t *record,int8_t max_record){

	int is_exist=0;

	for(int i=0;i<max_record;++i){
		if(record[i].rollNumber==roll_number)
		{
			is_exist=1;
			break;
		}
	}

	return is_exist;
}


int add_new_record(STUDENT_INFO_t *record,int8_t max_record){

	int i;
	int roll_number;
	int is_exist=0;
	int add_status=0;

	for(i=0;i<max_record;++i){

		if(!record[i].rollNumber)
		{
			//add the record
			printf("\t\tEnter the rollNumber:\t");
			scanf("%d",&roll_number);
			is_exist=check_roll_number(roll_number, students, max_record);
			if(!is_exist)
			{
               	add_status = 1; //adding new record
                record[i].rollNumber = roll_number;
                printf("\t\tEnter the studentSemister   : ");
                scanf("%d",&record[i].semister);
                printf("\t\tEnter the studentDOB year        : ");
                scanf("%d",&record[i].dob);
                getchar();
                printf("\t\tEnter the StudentBranch     : ");
                scanf("%s",record[i].branch);
                getchar();
                printf("\t\tEnter the studentName       : ");
                scanf("%s",record[i].name);
			}
			else
			{
				printf("roll_number already exist\n");
			}

			break;

		}
	}

	if(i==max_record)
		printf("No SPACE available\n");

	return add_status;

}

int delete_record(STUDENT_INFO_t *record,int8_t max_record){

	int roll_number;
	int8_t delete_flag=0;

	printf("Enter the roll_number of the student:");
	scanf("%d",&roll_number);

	for(int i=0;i<max_record;++i){
		if(roll_number==record[i].rollNumber)
			delete_flag=1;
		memset(&record[i],0,sizeof(STUDENT_INFO_t));
		break;
	}

	return delete_flag;
}
