#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "code.h"

// GLOBALS

//FUNCTIONS
// welcome message
void welcome_message()
{
    printf("Welcome!\n");
}

// get group name
void get_name(char* name)
{
    printf("Enter group name :DCspearsv2 ");
    gets(name);
}

void create_folder(char* name)
{
    // Create a directory with read/write/execute permissions for user
    if (mkdir(name, 0777) == 0)
    {
        printf("Folder '%s' created successfully.\n", name);
    }
    else
    {
        perror("Folder creation failed");
    }
}

void create_file(char* folder_name, char* group_name)
{
    char path[256];
    snprintf(path, sizeof(path), "%s/group.txt", folder_name);
    FILE *file = fopen(path, "w");
    if (file == NULL)
    {
        perror("File creation failed");
        return;
    }
    fprintf(file, "Group Name: %s\n", group_name);
    fclose(file);
    printf("File '%s' created with group name.\n", path);
}
