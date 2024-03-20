#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>

int file_read(char* name){
    
    uint32_t ret_val;
    int size;
    FILE* fp = fopen(name,"rb");
    
    if(fp==NULL){
        printf("error occured while file reading");
        exit(1);
    }
    
    fseek(fp,0,SEEK_END);
    size = ftell(fp);
    fseek(fp,0,SEEK_SET);
    
    if(size!=4){
        printf("error in file size. file size must be 4 bytes.");
        exit(1);
    }
    
    fread(&ret_val,1,4,fp);
    fclose(fp);
    
    return(ntohl(ret_val));

}

int main(int argc, char* argv[]) {

    uint32_t val1;
    uint32_t val2;
    uint32_t add;
    
    val1 = file_read(argv[1]);
    val2 = file_read(argv[2]);

    add = val1+ val2;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", val1, val1, val2, val2, add, add);

}
