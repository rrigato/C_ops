#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main (int argc, char * argv [])
{
    FILE * fp =NULL;
    //open for writing
    fp = fopen("output.txt", "w");
    if (!fp)
        exit (1);
    fclose(fp);
    return 0;
}
