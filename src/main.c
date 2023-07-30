#include <stdio.h>
#include <string.h>

#define __DEBUG__

#define FILE_NOT_FOUND 100

#define NONE 0
#define PROCESSING 1
#define DONE 2

#ifdef __DEBUG__
#define DBG_MSG(string) printf("DEBUG: %s\n", string);
#define DBG_VAL(val, format) printf("DEBUG: %s = "format"\n", #val, val);
#else
#define DBG_MSG(string) __no_op__
#define DBG_VAL(val, type) __no_op__
#endif

int tangle(char* file_name) {
    FILE* f = fopen(file_name, "r");
    if (f == NULL) {
        DBG_MSG("File not found");
        return FILE_NOT_FOUND;
    }

    int line_nr = 0;
    int front_matter_state = NONE;
    char* line;
    while (fgets(line, 100, f) != NULL) {
        if (line_nr == 0 
            && front_matter_state == NONE 
            && strcmp(line, "+++") == 0) 
        {
            front_matter_state = PROCESSING;
        } else if (front_matter_state == PROCESSING) {
        } else if (front_matter_state == DONE) {
        }

        line_nr++;
    }
    
    
    DBG_MSG("Closing file");
    return fclose(f);
}

int main(int argc, char* argv[]) {
    return tangle(argv[1]);
}

