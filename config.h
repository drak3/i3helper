#ifndef I3HELPER_GUARD_CONFIG_H
#define I3HELPER_GUARD_CONFIG_H

/* FIXME: make this dynamic or sth. */
#define I3H_MAX_PATH_LEN  255

struct i3h_config {
    char pid_file[I3H_MAX_PATH_LEN];
};

/*
 * Parses the i3 config, falling back to default parameters
 */
extern int i3h_config_parse(int argc, char* argv[], struct i3h_config *conf);

#endif
