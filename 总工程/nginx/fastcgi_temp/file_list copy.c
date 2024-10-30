#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "fcgi_stdio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

#define FILE_DIRECTORY "/usr/local/nginx/html/photo/"

void send_json_file_list()
{
    struct dirent *entry;
    struct stat file_stat;
    char file_path[1024];
    DIR *dp = opendir(FILE_DIRECTORY);

    if(dp == NULL){
        FCGI_printf("{\"error\":\"Unable to open directory\"}\n");
        return ;
    }

    FCGI_printf("[");
    int first = 1;
    while((entry = readdir(dp)) != NULL){
        if(entry->d_type == DT_REG){
            snprintf(file_path, sizeof(file_path), "%s/%s", FILE_DIRECTORY, entry->d_name);
            if(stat(file_path, &file_stat) == 0){
                if(!first){
                    FCGI_printf(",");
                }
                FCGI_printf("{\"name\": \"%s\", \"url\": \"/%s\", \"size\": %ld, \"lastModified\":%ld}",
                            entry->d_name, entry->d_name, file_stat.st_size, file_stat.st_mtime);
                first = 0;
            }
        }
    }
    FCGI_printf("]");
    closedir(dp);
}

int main(int argc, char *argv[])
{
    while(FCGI_Accept() >= 0){
        printf("Content-type:application/json\r\n\r\n");

        send_json_file_list();
    }

    return 0;
}