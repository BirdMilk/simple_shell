#include "shell.h"

/**
 * is_executable - checks if a file is an executable command
 * @info: the info struct
 * @filepath: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_executable(info_t *info, char *filepath)
{
    struct stat st;

    (void)info;
    if (!filepath || stat(filepath, &st))
        return (0);

    if (st.st_mode & S_IFREG)
    {
        return (1);
    }
    return (0);
}

/**
 * duplicate_chars - duplicates characters from a string
 * @pathstr: the PATH string
 * @start: starting index
 * @end: stopping index
 *
 * Return: pointer to new buffer with duplicated characters
 */
char *duplicate_chars(char *pathstr, int start, int end)
{
    static char buffer[1024];
    int i = 0, j = 0;

    for (j = 0, i = start; i < end; i++)
        if (pathstr[i] != ':')
            buffer[j++] = pathstr[i];
    buffer[j] = 0;
    return (buffer);
}

/**
 * locate_command_in_path - finds the command in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the command to find
 *
 * Return: full path of the command if found or NULL
 */
char *locate_command_in_path(info_t *info, char *pathstr, char *cmd)
{
    int i = 0, curr_pos = 0;
    char *fullpath;

    if (!pathstr)
        return (NULL);
    if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
    {
        if (is_executable(info, cmd))
            return (cmd);
    }
    while (1)
    {
        if (!pathstr[i] || pathstr[i] == ':')
        {
            fullpath = duplicate_chars(pathstr, curr_pos, i);
            if (!*fullpath)
                _strcat(fullpath, cmd);
            else
            {
                _strcat(fullpath, "/");
                _strcat(fullpath, cmd);
            }
            if (is_executable(info, fullpath))
                return (fullpath);
            if (!pathstr[i])
                break;
            curr_pos = i;
        }
        i++;
    }
    return (NULL);
}

