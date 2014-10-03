#include "config.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int i3h_config_parse(int argc, char* argv[], struct i3h_config* conf) 
{    
    if(argc != 2) {
	printf("Usage: %s <i3-socket-file>", argv[0]);
    }

    if(strlen(argv[1]) >= I3H_MAX_PATH_LEN) {
	printf("socket file name too long\n");
	exit(1);
    }
    
    strncpy(conf->pid_file, argv[1], I3H_MAX_PATH_LEN);
    

    return 1;
}
