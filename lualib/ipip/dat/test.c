#include <stdio.h>
#include "ipip.h"

int main() {
    init("17monipdb.dat");
    char *ip = "8.8.8.8";
    char result[128];
    find(ip, result);
    printf("%s -> %s\n", ip, result);
    destroy();

    init("17monipdb.dat");
    find("127.0.0.1", result);
    printf("127.0.0.1 -> %s\n", result);
    destroy();
    return 0;
}
