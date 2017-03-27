#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("error");
        //fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];
    //char *outfile = argv[2];
    
    printf("%p inside infile \n",(void*)infile);
    printf("%p address of inside\n",(void*)&infile);
    printf("%p inside command line array  \n",(void*)argv);
    printf("%p address of command line array\n",(void*)&argv);
    printf("%p inside command line array at index  1\n",(void*)argv[1]);
    printf("%p address command line array at index  1\n",(void*)&argv[1]);
    printf("%p inside command line array at index  0\n",(void*)argv[0]);
    
}
