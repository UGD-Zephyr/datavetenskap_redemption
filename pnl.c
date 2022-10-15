/* Programmer: Per Stoor
 * Date: 2022-10-15
 * Last changed: 2022-10-15
 * Type of program: Trying some structs and file functions together.
 */

#include <stdio.h> 
#include <stdlib.h> 

#define FILE_PATH "/mnt/c/wsl_programming/c/c_projects/datavetenskap_redemption/pnl_list.txt"

typedef struct {

    char *name;
    size_t age;
    char *occupation;

} person_data;

size_t count_persons_in_list(FILE *function_pointer);

int main(int argc, char *argv[]){ 

    FILE *file_pointer_read;
    size_t persons_in_list;
    //person_data individual;

        file_pointer_read = fopen(FILE_PATH, "r");
            persons_in_list = count_persons_in_list(file_pointer_read);
            printf("There are %zu person(s) in the list.\n", persons_in_list);
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
