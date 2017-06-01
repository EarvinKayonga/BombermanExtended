/**
 * \file common/common.c
 * \brief Argument Handling.
 * \version 0.1
 * \date June 2017, 1
 *
 * Argument Handling
 *
 */
#include        "args.h"


/**
 * \fn int getnumber(char *str)
 * \brief libc helper which extracts an Int from a char*
 * \param str a string
 * \return -1 if an error occured.
 */
int	            getnumber(char *str)
{
    int	        multi;
    int	        res;

    res = 0;
    multi = 1;
    while (('-' == (*str)) || ('+' == (*str)))
    {
        if (*str == '-')
            multi = multi * -1;
        str++;
    }
    while ((*str >= '0') && (*str <= '9'))
    {
        res = (res * 10) + ((*str) - 48);
        str++;
    }
    return (res * multi);
}

/**
 * \fn config_t       from_arguments(int argc, char *args[])
 * \brief Reads the programs arguments and creates a configuration struct
 * \param argc number of arguments
 * \param args list of arguments.
 * \return configuration struct.
 */
config_t       from_arguments(int argc, char *args[])
{
    config_t    configuration;

    configuration.hostname = (args[1] == NULL) ? "127.0.0.1": args[1];
    configuration.port = ((argc < 2) ||(args[1] == NULL) || (args[2] == NULL)) ? 4242: getnumber(args[2]);

    if (argc < 2)
        fprintf(stdout, "Server on: %s\n", "127.0.0.1:4242");
    else
        fprintf(stdout, "Server on: %s:%d:\n", configuration.hostname, configuration.port);

    return (configuration);
}

