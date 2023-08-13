#define __DEBUG__

#include <stdio.h>
#include <string.h>

#include <debug_logging.h>
#include <linked_list.h>

//Program states
#define START       0x2100
#define FRONTMATTER 0x2101
#define LITERATURE  0x2102
#define CODE        0x2103
#define END         0x21FF

// Errors
#define FILE_NOT_FOUND 0x1001

int tangle(char* file_name) {
    FILE* f = fopen(file_name, "r");
    if (f == NULL) {
        DBG_MSG("File not found");
        return FILE_NOT_FOUND;
    }

    int line_nr = 0;
    int program_state = START;
    char* line;
    while (fgets(line, 100, f) != NULL) {
        if (program_state == START) {
            if (line_nr == 0 
                && strncmp(line, "---", 3) == 0) 
            {
                DBG_MSG("Entering frontmatter");
                program_state = FRONTMATTER;
            }
        }
        else if (program_state == FRONTMATTER) {
            if (strncmp(line, "---", 3) == 0) {
                DBG_MSG("Frontmatter done, entering literature");
                program_state = LITERATURE;
            }
        } 
        else if (program_state == LITERATURE) {
            if (strncmp(line, "+++", 3) == 0) {
                DBG_MSG("Entering code block");
                program_state = CODE;
            }
        }
        else if (program_state == CODE) {
            if (strncmp(line, "+++", 3) == 0) {
                DBG_MSG("Exiting code block");
                program_state = LITERATURE;
            }
        }

        line_nr++;
    }
    
    
    DBG_MSG("Closing file");
    return fclose(f);
}

int main(int argc, char* argv[]) {
    return tangle(argv[1]);
}

