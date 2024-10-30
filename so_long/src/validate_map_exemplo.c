#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define WALL '1'
#define PLAYER 'P'
#define EXIT 'E'
#define COLLECTIBLE 'C'
#define EMPTY '0'

// Estrutura de dados para armazenar o mapa
typedef struct {
    char **map;
    int rows;
    int cols;
} t_map;

// Verifica se o mapa é retangular
int is_rectangular(t_map *map) {
    int i = 0;
    while (i < map->rows) {
        if (strlen(map->map[i]) != map->cols)
            return 0;
        i++;
    }
    return 1;
}

// Verifica se as bordas do mapa são paredes
int has_walls(t_map *map) {
    int i = 0;
    
    // Verifica as bordas superior e inferior
    while (i < map->cols) {
        if (map->map[0][i] != WALL || map->map[map->rows - 1][i] != WALL)
            return 0;
        i++;
    }
    
    i = 0;
    // Verifica as bordas esquerda e direita
    while (i < map->rows) {
        if (map->map[i][0] != WALL || map->map[i][map->cols - 1] != WALL)
            return 0;
        i++;
    }
    
    return 1;
}

// Conta a quantidade de jogadores, saídas e colecionáveis
int has_required_elements(t_map *map, int *player_count, int *exit_count, int *collectible_count) {
    *player_count = 0;
    *exit_count = 0;
    *collectible_count = 0;
    
    int i = 0;
    while (i < map->rows) {
        int j = 0;
        while (j < map->cols) {
            if (map->map[i][j] == PLAYER)
                (*player_count)++;
            else if (map->map[i][j] == EXIT)
                (*exit_count)++;
            else if (map->map[i][j] == COLLECTIBLE)
                (*collectible_count)++;
            j++;
        }
        i++;
    }
    
    return (*player_count == 1 && *exit_count == 1 && *collectible_count >= 1);
}

// Função para validar o mapa
int validate_map(t_map *map) {
    int player_count, exit_count, collectible_count;

    if(!map)
	return (0);
    if (!is_rectangular(map)) {
        printf("Erro: O mapa não é retangular.\n");
        return 0;
    }
    
    if (!has_walls(map)) {
        printf("Erro: As bordas do mapa não estão rodeadas de paredes.\n");
        return 0;
    }
    
    if (!has_required_elements(map, &player_count, &exit_count, &collectible_count)) {
        printf("Erro: O mapa deve conter 1 jogador, pelo menos 1 saída e pelo menos 1 colecionável.\n");
        return 0;
    }
    
    printf("Mapa válido.\n");
    return 1;
}

// Exemplo de criação de mapa e validação
int main() {
    // Exemplo de mapa (deve ser carregado de um arquivo)
    char *map_data[] = {
    "1111111111111111111111111",
    "1P00000000000000000000001",
    "1111111000111110000111111",
    "1C00001000000100001000001",
    "1000111110001111100011111",
    "100010000C000001000C00001",
    "1111101111111111111101111",
    "1C00001000000100001000001",
    "1000001111111111111100001",
    "1111111000000000000111111",
    "1C000010001111110000C0001",
    "1111100100100000100011111",
    "1E000010000000000010000C1",
    "1111111111111111111111111",
    };
    	if (sizeof(map_data) / sizeof(map_data[0]) == 0) {
        printf("Erro: O mapa não possui dados.\n");
        return 0;
    }
    t_map map;
    map.map = map_data;
    map.rows = 14;
    map.cols = strlen(map_data[0]);


    // Valida o mapa
    if (validate_map(&map)) {
        printf("Mapa passou na validação!\n");
    } else {
        printf("Mapa não é válido.\n");
    }

    return 0;
}
