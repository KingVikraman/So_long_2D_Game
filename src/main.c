#include "../includes/so_long.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(2, "Usage: ./so_long map.ber\n",  26);
        return (1);
    }

    (void)argv;

    return (0);
}