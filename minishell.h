/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:48:05 by hskowron          #+#    #+#             */
/*   Updated: 2022/03/31 13:52:00 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "libftplus/libftplus.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <termios.h>
# include <sys/ioctl.h>

typedef struct s_cmd
{
	char	**cmd;
	char	*cmd_low;
	int		in_fd;
	int		out_fd;
	char	*in_path;
	char	*out_path;
	int		nmb;
	int		append;
	char	*exe_path;
	char	*here_doc;
	int		here_doc_pipe[2];
}	t_cmd;

typedef struct s_env
{
	char			**var;
	struct s_env	*next;
}	t_env;

typedef struct s_flag
{	
	int	exit_val;
	int	int_flag;
	int	here_doc;
	int	quit;
	int	quit_flag;
}	t_flag;

typedef struct s_data
{
	char	*line;
	int		pipe[2];
	int		tmp_fd;
	char	*prompt;
	char	**builtins;
	char	*cwd;
	int		nmb_cmd;
	int		*ch_pid;
	t_cmd	**cmd_lst;
	t_env	*env;
}	t_data;

extern t_flag	g_flag;

t_data	*data_init(char **envp, t_data *data);
char	*get_prompt(t_data *data);
char	*fuse_prompt(char *prompt, char *dis_dir, char *user);
char	*get_displayed_dir(t_data *data);
void	err_exit(char *msg, int p_err, t_data *data);
void	prompt(t_data *data);
char	**define_builtins(t_data *data);
int		handle_input(char *line, t_data *data);
void	free_all(t_data *data);
void	handle_exe(t_data *data);
int		e_fork(t_data *data);
void	e_pipe(t_data *data);
int		handle_cmd(t_cmd *cmd, t_data *data, int x);
int		handle_other(t_cmd *cmd, t_data *data);
int		check_builtins(t_cmd *cmd, t_data *data);
void	init_cmd(t_cmd *cmd, int x);
int		handle_redirect(t_cmd **cmd_lst, t_data *data);
void	cut_redirect(t_cmd *cmd, int red_index, t_data *data, int pieces);
void	fill_new_cmd(int red_index, char **tmp, char **cmd, int pieces);
int		get_nmb_cmd(char *line);
char	**get_path_variable(t_data *data);
char	*find_exe_path(t_cmd *cmd, t_data *data);
int		handle_out_red(t_cmd **cmd_lst, t_data *data);
int		apply_out_red(t_cmd *cmd, char *red);
int		cmp_out_red(char *part);
int		handle_in_red(t_cmd **cmd_lst, t_data *data);
int		apply_in_red(t_cmd *cmd, char *red);
int		cmp_in_red(char *part);
void	execute_cmd_lst(t_data *data);
void	err_cmd_not_found(char *cmd, t_data *data);
int		cd(t_cmd *cmd, t_data *data);
int		echo(t_cmd *cmd, t_data *data);
void	echo_print(t_cmd *cmd, int i);
void	env_init(char **envp, t_data *data);
char	*get_env(t_data *data, char *to_srch);
t_env	*lstnew(char **str);
int		lstadd_back(t_env **lst, t_env *new);
t_env	*lstlast(t_env *lst);
char	**form_array(t_data *data);
void	split_cmd(char *line, t_data *data, int parts);
int		env(t_cmd *cmd, t_data *data);
int		export(t_cmd *cmd, t_data *data);
int		pwd(t_cmd *cmd, t_data *data);
int		unset(t_cmd *cmd, t_data *data);
void	exit_builtin(t_cmd *cmd, t_data *data);
int		count_quotes(char *line, int c);
void	handle_no_quotes(char *cmd, t_data *data);
void	lst_delete(t_env *lst, int i);
void	free2d(char **str);
int		exit_free(t_data *data, int i);
void	set_next_pipe(t_data *data);
void	handle_builtins(t_cmd *cmd, t_data *data, int bi_id);
void	set_redirections(t_cmd *cmd, t_data *data);
int		find_right_in_red(t_cmd *cmd, t_data *data, int y);
int		find_right_out_red(t_cmd *cmd, t_data *data, int y);
int		check_here_doc(t_cmd *cmd, t_data *data, int y, int len);
void	handle_here_doc(t_cmd *cmd, t_data *data, char *delim, int mode);
char	*append_input(char *line, char *input, t_data *data, int mode);
void	put_here_doc(t_cmd *cmd, t_data *data);
void	set_up_here_doc_pipe(t_cmd *cmd, t_data *data,
			char *input, char *delim);
void	get_out(int exit_val, t_data *data);
int		handle_builtins_parent(t_cmd *cmd, t_data *data, int x);
void	sig_int(int sig);
int		set_qf(char *line, int quote_flag);
int		check_closed_quote(char *line, char quote);
int		fill_full_cmd(char *line, char *dest, int quote_flag);
int		get_full_cmd_len(char *line, int quote_flag);
int		skip_unwanted_whitespace(char *line, int quote_flag);
char	**ft_split_cmd(char *line, int parts, t_data *data);
void	err_no_exe_rights(char *cmd, t_data *data, char **path);
char	**ft_split_args(char *line, t_data *data);
int		fill_full_part(char *line, char *dest, int qf, t_data *data);
int		exchange_var(char *dest, char *var_name, t_data *data);
int		get_part_len(char *line, int qf, t_data *data);
char	*get_var_name(char *line, int quote_flag, t_data *data);
int		get_env_len(char *line, int quote_flag, t_data *data);
int		get_nmb_parts(char *line, int quote_flag);
int		check_exe(t_data *data, char *path, char **path2d);
void	print_decider(t_cmd *cmd, int i);
int		ignore_quote(char chr, int quote_flag);
void	fuse_prompt_extension(char *prompt, char *user, int x, int y);
void	free_input(t_data *data);
void	free_split(char **split);
void	put_in_env(char **split, t_data *data);
char	**check_for_empty_var(char *args);
int		ret_terminated(char *line, char *dest, int y, int x);
void	free_tmp(t_env *tmp);
void	lst_delete_first(t_env **lst);
void	ft_cases(int j, t_data *data);
void	set_tings(void);
int		out_red_cmb(t_cmd *cmd, t_data *data, int y);
void	check_for_minishell(t_data *data);
void	set_redirections_redacted(t_cmd *cmd, t_data *data);
int		fill_exit_val(char *dest);
void	wait_all(int ext, t_data *data);
int		get_nmb_extern(t_data *data);
void	ft_sigfunc_here_doc(int sig);
void	ft_assign_new_var(t_env *tmp, char **split);
void	ft_export_var(t_data *data, char **split);
char	*allocate_input(void);
int		empty_input(char *cmd);
void	set_tingsrev(void);
void	prompt_flags(int i);
void	sig_quit(int sig);
void	free_prompt(t_data *data);
void	assign_wds(t_data *data, char *oldwd);
void	ft_assign_new_wd(t_env *tmp, char *wd);
void	handle_export_no_arg(t_data *data);
void	ft_export_other_var(t_data *data, char *cmd, int i);
void	export_without_equal(t_data *data, char *cmd);
void	malloc_str(char *cmd, char **str);
int		check_input(char **split);
char	*cpy_no_quotes(char *nstr, char *str);
char	*ft_strdup_low(char *str);
int		quote_decider(char *str, int start);
int		is_valid_char(char cha);
int		get_new_len(char *line, char *input, t_data *data, int mode);
char	*append_onto_old(char *line, char *input, t_data *data, int mode);
void	cpy(char *line, char *dest, int *x, int *y);
int		fill_already_existing(char *input, char *ret);
char	*return_term_nl(char *ret, int y);
void	assign_wds_home(t_data *data, char *oldwd);
int		skip_var(char *line);
char	*return_ret_val(void);
int		initial_pipe_check(char *line);
int		err_pipe(void);
int		skip_whitespace_pipe_check(char *line, int quote_flag);
int		initial_pipe_check_help(char *line, int flag);
int		ext_exec_help(t_data *data, int x, int y);
void	exit_print_isnodigit(char *cmd, t_data *data);
void	check_unset_input(char **split);
void	here_doc_settings(void);
char	*ft_handle_quotes(char *delim);
int		set_qf_here_doc(char *delim);
int		check_input_nbr(char *split);
int		check_first(char *cmd);
int		export_routine(char **split, t_data *data, t_cmd *cmd, int i);
void	print_invalid_iden(char *cmd);
char	*ft_handle_quotes_export(char *delim);
int		check_unset_input2(char **split);
int		ft_plus(char *cmd);
int		error_cd(void);
void	error_message_exit(char *cmd);
void	check_input_error(t_cmd *cmd, t_data *data, char **path);
void	input_fail(void);
void	err_command_not_found(char *cmd, t_data *data, char **path);

#endif