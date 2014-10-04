#include <stdio.h>
#include "config.h"
#include "ipc.h"

int main(int argc, char *argv[])
{
    struct i3h_config conf;

    i3h_config_parse(argc, argv, &conf);

    i3h_test_ipc(conf.pid_file);

    return 0;
}
