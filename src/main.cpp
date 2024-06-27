#include <cstring>
#include <stdio.h>
#include "LucidDB.h"

int main (int argc, char *argv[]) 
{

    LucidDB data("example.txt");

    LucidEntry e = data.search(0);

    printf("%s\n", e.accountName.c_str());

    return 0;
}
