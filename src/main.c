#define LOG_DEBUG

#include <stdio.h>
#include <string.h>

#include <debug_logging.h>
#include <linked_list.h>

// Program states
#define STATE_START         0x2100
#define STATE_FRONTMATTER   0x2101
#define STATE_LITERATURE    0x2102
#define STATE_CODE          0x2103
#define STATE_OUTPUT        0x2104
#define STATE_END           0x21FF

// Errors
#define FILE_NOT_FOUND 0x1001

// Tokens
#define TOKEN_FRONTMATTER   "---"
#define TOKEN_CODE          ">>>"
#define TOKEN_OUTPUT        "<<<"

int tangle(char* file_name) {
    FILE* f = fopen(file_name, "r");
    if (f == NULL) {
        dbg_msg("File not found");
        return FILE_NOT_FOUND;
    }

    int line_nr = 0;
    int program_state = STATE_START;
    char* line;
    while (fgets(line, 100, f) != NULL) {
        if (program_state == STATE_START) {
            if (line_nr == 0 
                && strncmp(line, TOKEN_FRONTMATTER, 3) == 0) 
            {
                dbg_msg("Entering frontmatter");
                program_state = STATE_FRONTMATTER;
            }
        }
        else if (program_state == STATE_FRONTMATTER) {
            if (strncmp(line, TOKEN_FRONTMATTER, 3) == 0) {
                dbg_msg("Frontmatter done, entering literature");
                program_state = STATE_LITERATURE;
            }
        } 
        else if (program_state == STATE_LITERATURE) {
            if (strncmp(line, TOKEN_CODE, 3) == 0) {
                dbg_msg("Entering code block");
                program_state = STATE_CODE;
            }
        }
        else if (program_state == STATE_CODE) {
            if (strncmp(line, TOKEN_CODE, 3) == 0) {
                dbg_msg("Exiting code block");
                program_state = STATE_LITERATURE;
            }
        }

        line_nr++;
    }
    
    
    dbg_msg("Closing file");
    return fclose(f);
}

int main(int argc, char* argv[]) {

    return tangle(argv[1]);
}

