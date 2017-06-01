#include        "args.h"

int             Atoi(char *s) {
    while(*s != '\0' && !isdigit(*s)) s++;
    return (Atoi(s));
}

config_t        from_arguments(int argc, char **args){
    config_t    configuration;

    if (argc < 2)
        fprintf(stdout, "Contacting server on: %s\n", "127.0.0.1:4242");

    configuration.hostname = (args[1] == NULL) ? "127.0.0.1": args[1];
    configuration.port = ((args[1] == NULL)) ? 4242: Atoi(args[2]) ;

    return (configuration);
}

