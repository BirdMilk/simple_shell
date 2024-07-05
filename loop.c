#include "shell.h"

/**
 * shell_loop - main shell loop
 * @shell_info: the parameter & return info struct
 * @args: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int shell_loop(info_t *shell_info, char **args)
{
	ssize_t read_status = 0;
	int builtin_result = 0;

	while (read_status != -1 && builtin_result != -2)
	{
		clear_info(shell_info);
		if (interactive(shell_info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		read_status = get_input(shell_info);
		if (read_status != -1)
		{
			set_info(shell_info, args);
			builtin_result = handle_builtin(shell_info);
			if (builtin_result == -1)
				handle_command(shell_info);
		}
		else if (interactive(shell_info))
			_putchar('\n');
		free_info(shell_info, 0);
	}
	write_history(shell_info);
	free_info(shell_info, 1);
	if (!interactive(shell_info) && shell_info->status)
		exit(shell_info->status);
	if (builtin_result == -2)
	{
		if (shell_info->err_num == -1)
			exit(shell_info->status);
		exit(shell_info->err_num);
	}
	return (builtin_result);
}

/**
 * handle_builtin - handles a builtin command
 * @shell_info: the parameter & return info struct
 *
 * Return: -1 if builtin not found,
 *			0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 */
int handle_builtin(info_t *shell_info)
{
	int i, builtin_exec_result = -1;
	builtin_table builtin_cmds[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{"help", shell_help},
		{"history", shell_history},
		{"setenv", shell_setenv},
		{"unsetenv", shell_unsetenv},
		{"cd", shell_cd},
		{"alias", shell_alias},
		{NULL, NULL}
	};

	for (i = 0; builtin_cmds[i].type; i++)
		if (_strcmp(shell_info->argv[0], builtin_cmds[i].type) == 0)
		{
			shell_info->line_count++;
			builtin_exec_result = builtin_cmds[i].func(shell_info);
			break;
		}
	return (builtin_exec_result);
}

/**
 * handle_command - handles a command in PATH
 * @shell_info: the parameter & return info struct
 *
 * Return: void
 */
void handle_command(info_t *shell_info)
{
	char *full_path = NULL;
	int i, non_delim_count = 0;

	shell_info->path = shell_info->argv[0];
	if (shell_info->linecount_flag == 1)
	{
		shell_info->line_count++;
		shell_info->linecount_flag = 0;
	}
	for (i = 0; shell_info->arg[i]; i++)
		if (!is_delim(shell_info->arg[i], " \t\n"))
			non_delim_count++;
	if (!non_delim_count)
		return;

	full_path = find_path(shell_info, _getenv(shell_info, "PATH="), shell_info->argv[0]);
	if (full_path)
	{
		shell_info->path = full_path;
		execute_fork(shell_info);
	}
	else
	{
		if ((interactive(shell_info) || _getenv(shell_info, "PATH=")
			|| shell_info->argv[0][0] == '/') && is_cmd(shell_info, shell_info->argv[0]))
			execute_fork(shell_info);
		else if (*(shell_info->arg) != '\n')
		{
			shell_info->status = 127;
			print_error(shell_info, "not found\n");
		}
	}
}

/**
 * execute_fork - forks and execs a command
 * @shell_info: the parameter & return info struct
 *
 * Return: void
 */
void execute_fork(info_t *shell_info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* Handle fork error */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(shell_info->path, shell_info->argv, get_environ(shell_info)) == -1)
		{
			free_info(shell_info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* Handle exec error */
	}
	else
	{
		wait(&(shell_info->status));
		if (WIFEXITED(shell_info->status))
		{
			shell_info->status = WEXITSTATUS(shell_info->status);
			if (shell_info->status == 126)
				print_error(shell_info, "Permission denied\n");
		}
	}
}

