#include "shell.h"

/**
 * exit_shell - Terminates the shell process
 * @context: Structure containing command arguments. Ensures consistent function signature.
 * Return: Exits with a specified exit status
 *         (0) if context.argv[0] != "exit"
 */
int exit_shell(context_t *context)
{
    int exitStatus;

    if (context->argv[1]) /* If exit parameter is provided */
    {
        exitStatus = str_to_int(context->argv[1]);
        if (exitStatus == -1)
        {
            context->status = 2;
            display_error(context, "Invalid number: ");
            print_to_stderr(context->argv[1]);
            print_char_to_stderr('\n');
            return (1);
        }
        context->err_code = str_to_int(context->argv[1]);
        return (-2);
    }
    context->err_code = -1;
    return (-2);
}

/**
 * change_directory - Changes the working directory of the process
 * @context: Structure containing command arguments. Ensures consistent function signature.
 * Return: Always 0
 */
int change_directory(context_t *context)
{
    char *currentDir, *targetDir, buffer[1024];
    int dirChangeStatus;

    currentDir = getcwd(buffer, sizeof(buffer));
    if (!currentDir)
        print_to_stdout("TODO: >>Error retrieving current directory<<\n");
    if (!context->argv[1])
    {
        targetDir = get_env_var(context, "HOME=");
        if (!targetDir)
            dirChangeStatus = /* TODO: Define appropriate value */
                chdir((targetDir = get_env_var(context, "PWD=")) ? targetDir : "/");
        else
            dirChangeStatus = chdir(targetDir);
    }
    else if (string_compare(context->argv[1], "-") == 0)
    {
        if (!get_env_var(context, "OLDPWD="))
        {
            print_to_stdout(currentDir);
            print_char_to_stdout('\n');
            return (1);
        }
        print_to_stdout(get_env_var(context, "OLDPWD=")), print_char_to_stdout('\n');
        dirChangeStatus = /* TODO: Define appropriate value */
            chdir((targetDir = get_env_var(context, "OLDPWD=")) ? targetDir : "/");
    }
    else
        dirChangeStatus = chdir(context->argv[1]);
    if (dirChangeStatus == -1)
    {
        display_error(context, "Cannot change directory to ");
        print_to_stderr(context->argv[1]), print_char_to_stderr('\n');
    }
    else
    {
        set_env_var(context, "OLDPWD", get_env_var(context, "PWD="));
        set_env_var(context, "PWD", getcwd(buffer, sizeof(buffer)));
    }
    return (0);
}

/**
 * display_help - Displays help information
 * @context: Structure containing command arguments. Ensures consistent function signature.
 * Return: Always 0
 */
int display_help(context_t *context)
{
    char **argumentList;

    argumentList = context->argv;
    print_to_stdout("Help function executed. Not yet implemented \n");
    if (0)
        print_to_stdout(*argumentList); /* Temporary unused workaround */
    return (0);
}

