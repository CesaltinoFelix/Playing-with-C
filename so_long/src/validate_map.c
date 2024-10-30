#include "so_long.h"

int has_walls(t_data *data) {
    int i = 0;

    for (i = 0; i < data->width; i++) {
        if (data->map[0][i] != WALL || data->map[data->height - 1][i] != WALL) {
            return 0;
        }
    }

    for (i = 0; i < data->height; i++) {
        if (data->map[i][0] != WALL || data->map[i][data->width - 1] != WALL) {
            return 0;
        }
    }

    return 1;
}

int has_required_elements(t_data *data, int *player_count, int *exit_count, int *collectible_count) {
    *player_count = 0;
    *exit_count = 0;
    *collectible_count = 0;

    for (int i = 0; i < data->height; i++) {
        for (int j = 0; j < data->width; j++) {
            if (data->map[i][j] == PLAYER)
                (*player_count)++;
            else if (data->map[i][j] == EXIT)
                (*exit_count)++;
            else if (data->map[i][j] == COLLECTIBLE)
                (*collectible_count)++;
        }
    }

    return (*player_count == 1 && *exit_count == 1 && *collectible_count >= 1);
}

int validate_map(t_data *data) {
    int player_count, exit_count, collectible_count;

    if (!data || !data->map) {
        return 0;
    }
    
    if (!has_walls(data)) {
        printf("Erro: As bordas do mapa não estão rodeadas de paredes.\n");
        return 0;
    }
    
    if (!has_required_elements(data, &player_count, &exit_count, &collectible_count)) {
        printf("Erro: O mapa deve conter 1 jogador, pelo menos 1 saída e pelo menos 1 colecionável.\n");
        return 0;
    }
    
    return 1;
}

int validate_extension(char *extension) {
    if (strncmp(extension, ".ber", 4) != 0) {
        return 0;
    }
    return 1;
}

int validate_lines(int fd, t_data *data) {
    char bit;
    int width = 0;

    while (read(fd, &bit, 1) != 0) {
        if (bit == '\n') {
            if (width != data->width) {
                printf("Error\nFormato do Mapa: ");
                printf("%d -> %d\n", width, data->width);
                exit(1);
            }
            width = 0;
        } else {
            width++;
        }
    }

    close(fd);
    return 0;
}
