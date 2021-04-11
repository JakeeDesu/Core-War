/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 12:28:30 by ouzamhar          #+#    #+#             */
/*   Updated: 2021/01/27 12:00:46 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*g_type[11] = {"COMMAND_NAME",
	"COMMAND_COMMENT",
	"LABEL",
	"INSTRUCTION",
	"SEPARATOR",
	"STRING",
	"REGISTER",
	"DIRECT",
	"INDIRECT",
	"DIRECT_LABEL",
	"INDIRECT_LABEL"};

t_op	g_tab[16] = {{1, "live", 1, {T_DIR, 0, 0}, 0, DIR_SIZE},
	{2, "ld", 2, {T_DIR | T_IND, T_REG, 0}, 252, DIR_SIZE},
	{3, "st", 2, {T_REG, T_IND | T_REG, 0}, 252, DIR_SIZE},
	{4, "add", 3, {T_REG, T_REG, T_REG}, 252, DIR_SIZE},
	{5, "sub", 3, {T_REG, T_REG, T_REG}, 252, DIR_SIZE},
	{6, "and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		252, DIR_SIZE},
	{7, "or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		252, DIR_SIZE},
	{8, "xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		252, DIR_SIZE},
	{9, "zjmp", 1, {T_DIR, 0, 0}, 0, IND_SIZE},
	{10, "ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 252,
		IND_SIZE},
	{11, "sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 252,
		IND_SIZE},
	{12, "fork", 1, {T_DIR, 0, 0}, 0, IND_SIZE},
	{13, "lld", 2, {T_DIR | T_IND, T_REG, 0}, 252, IND_SIZE},
	{14, "lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		252, IND_SIZE},
	{15, "lfork", 1, {T_DIR, 0, 0}, 0, IND_SIZE},
	{16, "aff", 1, {T_REG, 0, 0}, 252, DIR_SIZE}};
