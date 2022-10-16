/* Programmer: Per Stoor
 * Date: 2022-10-15
 * Last changed: 2022-10-15
 * Type of program: Trying some structs and file functions together.
 */

#include <stdio.h> 
#include <stdlib.h> 

#define STRING_LENGTH 50
#define FILE_PATH "/mnt/c/wsl_programming/c/c_projects/datavetenskap_redemption/pnl_list.txt"

typedef struct {

    char name[STRING_LENGTH];
    int age;
    char occupation[STRING_LENGTH];

} person_data;

size_t count_persons_in_list(FILE *function_pointer);

int main(int argc, char *argv[]){ 

    char string_buffer[STRING_LENGTH];
    char character_buffer;
    FILE *file_pointer_read;
    int loop_counter1;
    size_t persons_in_list;
    //person_data individual;
    person_data *person_data_struct_pointer;

        file_pointer_read = fopen(FILE_PATH, "r");

            persons_in_list = count_persons_in_list(file_pointer_read);
            printf("There are %zu person(s) in the list.\n", persons_in_list);

            person_data_struct_pointer = (person_data *) malloc(persons_in_list * sizeof(person_data));
                if(person_data_struct_pointer == NULL){
                    perror("Error allocationg memory for the struct.\n");
                    exit(EXIT_FAILURE);
                }

            printf("Search for [N]ame, [A]ge or [O]ccupation: ");
            fgets(string_buffer, STRING_LENGTH, stdin);
            sscanf(string_buffer, "%c", &character_buffer);

                for(loop_counter1 = 0; loop_counter1 < persons_in_list; loop_counter1++){
                    fscanf(file_pointer_read, "%s\n", person_data_struct_pointer[loop_counter1].name);
                    fscanf(file_pointer_read, "%d\n", &person_data_struct_pointer[loop_counter1].age);
                    fscanf(file_pointer_read, "%s\n", person_data_struct_pointer[loop_counter1].occupation);


                }

                for(loop_counter1 = 0; loop_counter1 < persons_in_list; loop_counter1++){
                    printf("%s", (person_data_struct_pointer + loop_counter1)->name);
                    printf("%d", (person_data_struct_pointer + loop_counter1)->age);
                    printf("%s", (person_data_struct_pointer + loop_counter1)->occupation);
                }

                /*
                if(character_buffer == 78|| character_buffer == 110){
                }
                else if(character_buffer == 65|| character_buffer == 97){
                }
                else if(character_buffer == 79|| character_buffer == 111){
                }
                */

            free(person_data_struct_pointer);

        fclose(file_pointer_read);

return 0;
} 

size_t count_persons_in_list(FILE *function_pointer){

    char file_character;
    size_t function_amount_of_lines;
    size_t function_amount_of_persons;

        function_amount_of_lines = 0;
        function_amount_of_persons = 0;

        while((file_character = fgetc(function_pointer)) != EOF){
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
