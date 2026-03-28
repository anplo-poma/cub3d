/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuewang <xuewang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:19:38 by xueyan_wang       #+#    #+#             */
/*   Updated: 2026/03/28 20:59:49 by xuewang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_rgb(char *str)
{
	char	**parts;
	int		rgb[3];
	int		i;

	parts = ft_split(str, ',');
	if (!parts)
		ft_error("invalid color");
	i = 0;
	while (parts[i])
		i++;
	if (i != 3)
		ft_error("invalid color: need 3 values for R,G and B");
	i = 0;
	while (i < 3)
	{
		if (!is_all_digits(parts[i]))
			ft_error("invalid color: not a number");
		rgb[i] = ft_atoi(parts[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			ft_error("invalid color: out of range 0-255");
		i++;
	}
	ft_free_matrix(parts); //later
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}


void	read_six_surface_to_struct(t_mapdata *mapdata, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		mapdata->no_texture = ft_strdup(trim_newline(skip_spaces(line + 3)));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		mapdata->so_texture = ft_strdup(trim_newline(skip_spaces(line + 3)));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		mapdata->we_texture = ft_strdup(trim_newline(skip_spaces(line + 3)));
	else if (ft_strncmp(line, "EA ", 3) == 0)//load path into struct, load 
		mapdata->ea_texture = ft_strdup(trim_newline(skip_spaces(line + 3)));
	else if (ft_strncmp(line, "F ", 2) == 0)
		mapdata->floor_color = parse_rgb(trim_newline(skip_spaces(line + 2)));
	else if (ft_strncmp(line, "C ", 2) == 0)
		mapdata->ceiling_color = parse_rgb(trim_newline(
				skip_spaces(line + 2)));
	else
		ft_error("unknown identifier");
}

void	read_cub_file(const char *filename, t_mapdata *mapdata)
{
	int		fd;
	char	*line;
	int		map_start;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("cannot open file");
	map_start = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (handle_empty_line(line, map_start))
		{
			free(line);
			continue;
		}
		if (!map_start && is_map_line(line))
			map_start = 1;
		if (map_start)
			read_map_to_str(mapdata, line);
		else
			read_six_surface_to_struct(mapdata, line);
		free(line);
	}
	close(fd);
}

int	check_map_extension(const char *filename)
{
	//int	len;
	const char	*ext;

	if (!filename)
		return (0);
	ext = ft_strrchr(filename, '.');
	if (!ext || ft_strncmp(ext, ".cub", 5))
		return (0);
	if (ext == filename || *(ext -1) == '/')
		return (0);
	return (1);
}

void	parse_cub(const char *filename, t_mapdata *mapdata)
{
	if (!check_map_extension(filename))
		ft_error("invalid file extension");
	read_cub_file(filename, mapdata);
	build_matrix(mapdata);
	pad_matrix_rows(mapdata);
	validate_map(mapdata);
}

//no free version 
/*just read map info into long str*/
/*
void	read_cub_file(const char *filename, t_mapdata *mapdata)
{
	int		fd;
	char	*line;
	int		map_start;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("cannot open file");
	map_start = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (handle_empty_line(line, map_start))
			continue;
		if (!map_start && is_map_line(line))
			map_start = 1;
		if (map_start)
			read_map_to_str(mapdata, line);
		else
			read_six_surface_to_struct(mapdata,line);
		free(line);
	}
	close(fd);
}
*/

//  test map
/*
void	debug_matrix(t_mapdata *mapdata)
{
	int	i;

	i = 0;
	write(1, "=== matrix ===\n", 15);
	while (mapdata->matrix[i])
	{
		write(1, mapdata->matrix[i], ft_strlen(mapdata->matrix[i]));
		write(1, "\n", 1);
		i++;
	}
	write(1, "=== end ===\n", 12);
}
*/
/*
void	texture_load_checking()
{
	void	*img
	//不自己检测 用mlx工具函数 只要load不了 就错
	//这个环节放在load texture的部分 因为纯parsing的部分mlx还没create
	img = mlx_xpm_file_to_image(mlx, path, &w, &h);
	if (!img)
		ft_error("fail to load texture")
}
*/

//
/*
颜色部分checking 环节
parse_rgb("220,100,0")
(220 << 16) | (100 << 8) | 0  →  int floor_color = 0x00DC6400
while （x=0 到x = width -1）  → DDA → render_column（put pixel在这个里） (天花板+墙+地板写入内存)
put_pixel(&img, x, y, xxx)//画天花板和地板是直接写 画墙要有一个映射扭曲的步骤
写完整个后 mlx_put_image_to_window(...)

*/