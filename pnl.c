/* Programmer: Per Stoor
 * Date: 2022-10-15
 * Last changed: 2022-10-19
 * Type of program: Trying some structs and file functions together.
 *
 * NOTES:
 * Working on making the search function, if people in the list have
 * the same age I need to think about how to display all of them...
 *
 * UPDATE:
 * if people share data they will be displayed together. Now I am trying to loop
 * the search list...having some issues currently
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#define STRING_LENGTH 100
#define FILE_PATH "/mnt/c/wsl_programming/c/c_projects/datavetenskap_redemption/pnl_list.txt"

typedef struct {

    char name[STRING_LENGTH];
    int age;
    char occupation[STRING_LENGTH];

} person_data;

void save_person_data_list(FILE *function_file_pointer_save, person_data *function_pointer_save , int function_persons_in_list_save);
void print_person_data_list(person_data *function_pointer_print , int function_persons_in_list_print);
void search_data_list(person_data *function_pointer_search, int function_persons_in_list_search);
int count_persons_in_list(FILE *function_file_pointer);

int main(int argc, char *argv[]){ 

    int persons_in_list;
    FILE *file_pointer_read;
    person_data *person_data_struct_pointer;

        file_pointer_read = fopen(FILE_PATH, "r");

            persons_in_list = count_persons_in_list(file_pointer_read);
            printf("There are %d person(s) in the list.\n", persons_in_list);
            printf("-------------------------------------------\n");
            rewind(file_pointer_read);

            person_data_struct_pointer = (person_data *) malloc(persons_in_list * sizeof(person_data));
                if(person_data_struct_pointer == NULL){
                    perror("Error allocationg memory for the struct.\n");
                    exit(EXIT_FAILURE);
                }

            save_person_data_list(file_pointer_read, person_data_struct_pointer, persons_in_list);
            print_person_data_list(person_data_struct_pointer, persons_in_list);
            printf("-------------------------------------------\n");
            search_data_list(person_data_struct_pointer, persons_in_list);

            free(person_data_struct_pointer);

        fclose(file_pointer_read);

return 0;
} 

void save_person_data_list(FILE *function_file_pointer_save, person_data *function_pointer_save , int function_persons_in_list_save){

    int function_loop_counter1;
    char function_string_buffer[STRING_LENGTH];

        for(function_loop_counter1 = 0; function_loop_counter1 < function_persons_in_list_save; function_loop_counter1++){
             fgets((function_pointer_save + function_loop_counter1)->name, STRING_LENGTH, function_file_pointer_save);
             fgets(function_string_buffer, STRING_LENGTH, function_file_pointer_save);
             sscanf(function_string_buffer, "%d", &(function_pointer_save + function_loop_counter1)->age);
             fgets((function_pointer_save + function_loop_counter1)->occupation, STRING_LENGTH, function_file_pointer_save);
         }
}

void print_person_data_list(person_data *function_pointer_print , int function_persons_in_list_print){

    int function_loop_counter1;

        for(function_loop_counter1 = 0; function_loop_counter1 < function_persons_in_list_print; function_loop_counter1++){
              printf("Name:         %s", (function_pointer_print + function_loop_counter1)->name);
              printf("Age:          %d\n", (function_pointer_print + function_loop_counter1)->age);
              printf("Occupation:   %s", (function_pointer_print + function_loop_counter1)->occupation);
                  if(function_loop_counter1 < (function_persons_in_list_print - 1)){
                          printf("\n");
                  }
        }
}

void search_data_list(person_data *function_pointer_search, int function_persons_in_list_search){

    int function_loop_counter1;
    int function_age_buffer;
    int string_compare_value;
    int item_exist_in_list_flag;
    char function_character_buffer;
    char function_string_buffer[STRING_LENGTH];

        item_exist_in_list_flag = 0;

        while(function_character_buffer != 81 || function_character_buffer != 113){

        printf("Search for [N]ame, [A]ge, [O]ccupation or [Q]uit: ");
            fgets(function_string_buffer, STRING_LENGTH, stdin);
            sscanf(function_string_buffer, "%c", &function_character_buffer);

                if(function_character_buffer == 78|| function_character_buffer == 110){
                    printf("Enter name: ");
                    fgets(function_string_buffer, STRING_LENGTH, stdin);
                    printf("-------------------------------------------\n");

                        for(function_loop_counter1 = 0;
                            function_loop_counter1 < function_persons_in_list_search;
                            function_loop_counter1++){

                                string_compare_value = strcmp(function_string_buffer, (function_pointer_search + function_loop_counter1)->name);
                                    if(string_compare_value == 0){
                                        printf("Name:       %s",(function_pointer_search + function_loop_counter1)->name);
                                        printf("Age:        %d\n",(function_pointer_search + function_loop_counter1)->age);
                                        printf("Occupation: %s\n",(function_pointer_search + function_loop_counter1)->occupation);
                                        item_exist_in_list_flag = 1;
                                    }
                        }
                            if(item_exist_in_list_flag == 0){
                                printf("Search has no match...\n");
                            }
                }
                else if(function_character_buffer == 65|| function_character_buffer == 97){
                    printf("Enter age: ");
                    fgets(function_string_buffer, STRING_LENGTH, stdin);
                    sscanf(function_string_buffer, "%d", &function_age_buffer);

                        for(function_loop_counter1 = 0;
                            function_loop_counter1 < function_persons_in_list_search;
                            function_loop_counter1++){

                                    if((function_age_buffer) == ((function_pointer_search + function_loop_counter1)->age)){
                                        printf("Name:       %s",(function_pointer_search + function_loop_counter1)->name);
                                        printf("Age:        %d\n",(function_pointer_search + function_loop_counter1)->age);
                                        printf("Occupation: %s\n",(function_pointer_search + function_loop_counter1)->occupation);
                                        item_exist_in_list_flag = 1;
                                    }
                        }
                            if(item_exist_in_list_flag == 0){
                                printf("Search has no match...\n");

                            }
                }
                else if(function_character_buffer == 79|| function_character_buffer == 111){
                    printf("Enter occupation: ");
                    fgets(function_string_buffer, STRING_LENGTH, stdin);
                    printf("-------------------------------------------\n");

                        for(function_loop_counter1 = 0;
                            function_loop_counter1 < function_persons_in_list_search;
                            function_loop_counter1++){

                                string_compare_value = strcmp(function_string_buffer, (function_pointer_search + function_loop_counter1)->occupation);
                                    if(string_compare_value == 0){
                                        printf("Name:       %s",(function_pointer_search + function_loop_counter1)->name);
                                        printf("Age:        %d\n",(function_pointer_search + function_loop_counter1)->age);
                                        printf("Occupation: %s\n",(function_pointer_search + function_loop_counter1)->occupation);
                                        item_exist_in_list_flag = 1;
                                    }
                        }
                            if(item_exist_in_list_flag == 0){
                                printf("Search has no match...\n");
                            }

                }
        }
}

int count_persons_in_list(FILE *function_file_pointer){

    char file_character;
    int function_amount_of_lines;
    int function_amount_of_persons;

        function_amount_of_lines = 0;
        function_amount_of_persons = 0;

        while((file_character = fgetc(function_file_pointer)) != EOF){
            if(file_character == '\n'){
                function_amount_of_lines++;
            }
        }

        /*
         * Dividing by 3 because there are 3 data types in the struct.
         * */
        function_amount_of_persons = (function_amount_of_lines / 3);

return function_amount_of_persons;
}
