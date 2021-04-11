/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:58:56 by ouzamhar          #+#    #+#             */
/*   Updated: 2021/01/27 10:16:28 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define T_REG					1
# define T_DIR					2
# define T_IND					4

# define REG_SIZE				1
# define IND_SIZE				2
# define DIR_SIZE				4

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define COMMENT_CHAR			'#'
# define ALT_COMMENT_CHAR		';'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define PROG_NAME_LENGTH		128
# define COMMENT_LENGTH			2048
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef	struct s_data			t_data;
typedef struct s_header			t_header;
typedef struct s_line			t_line;
typedef struct s_token			t_token;
typedef	struct s_label			t_label;
typedef	struct s_op				t_op;
typedef struct s_last			t_last;

struct							s_header
{
	unsigned int				magic;
	unsigned int				prog_size;
	char						prog_name[PROG_NAME_LENGTH + 1];
	char						comment[COMMENT_LENGTH + 1];
};

struct							s_last
{
	t_token						*tok;
	t_line						*line;
	t_label						*label;
};

struct							s_data
{
	int							nl;
	int							nt;
	char						*file;
	t_token						*name;
	t_token						*comment;
	t_header					header;
	t_line						*lst;
	t_token						*tlst;
	t_label						*lab;
	t_last						last;
};

struct							s_line
{
	int							nl;
	int							nt;
	int							e;
	int							p;
	char						op;
	unsigned int				size;
	unsigned char				type;
	t_token						*lst;
	t_token						*instr;
	t_token						*arg[3];
	t_line						*next;
};

struct							s_token
{
	int							nl;
	int							nt;
	int							t;
	int							h;
	char						*cnt;
	int							size;
	int							val;
	t_token						*next;
};

struct							s_label
{
	char						*name;
	t_line						*line;
	t_label						*next;
};

struct							s_op
{
	char						op;
	char						*name;
	int							p;
	int							arg[3];
	char						b;
	unsigned int				size;
};

extern	char					*g_type[11];
extern	t_op					g_tab[16];

void							str_cpy(char *src, char *dst, int n);
int								cmp_str(const char *str1, const char *str2);
int								label_chars(char c, char *chars);
void							get_cnt(t_data *data, int fd);
void							parse_file(t_data *data, int fd);
void							read_token(t_data *data, int fd, char c);
void							lexical_error(t_data *d, int f, int l, int t);
void							if_cmd(t_data *data, int fd);
void							is_dir(t_data *data, int fd);
void							is_label(t_data *data, int fd);
void							is_num(t_data *data, int fd);
void							is_reg(t_data *data, int fd);
void							is_string(t_data *data, int fd);
void							is_what(t_data *data, int fd, char c);
void							read_token(t_data *data, int fd, char c);
void							tok_num(int i);
void							print_nbr(int i);
void							print_str(char *str);
void							print_char(char c);
void							free_data(t_data *data);
void							check_syntax(t_data *data);
void							syntax_error(t_data *data, t_token *tok);
void							syntax_endline(t_data *data, t_line *line);
void							null_lst(t_data *data);
void							get_size(t_data *data);
void							invalid_length(t_data *data, int l);
void							invalid_label(t_data *d, t_token *t, char *n);
void							invalid_instr(t_data *data, t_token *tok);
void							inv_para(t_data *d, t_line *l, int i, int t);
void							get_value(t_data *data);
void							to_byecode(t_data *data);
void							free_data(t_data *data);
void							creat_label(t_data *d, t_line *l, t_token *t);
#endif
