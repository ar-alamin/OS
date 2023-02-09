#include <stdio.h>

void mfnt(int total_memory, int block_size, int process, int *process_mem){

    int block_num = total_memory/block_size;
    int total_external_frag = total_memory % block_size;
    int p, b, total_internal_frag=0;

    printf("\n\nNo. of Blocks available in memory: %d\n ",block_num);

    printf("PROCESS\t MEMORY REQUIRED\t ALLOCATED\t INTERNAL FARAGMENTATION\n");

    for(p=0, b=0, total_internal_frag=0; p<process && b<block_num; p++){
        if(process_mem[p] <= block_size){
            printf("%d\t %d\t\t Yes\t\t %d\n", p+1, process_mem[p], block_size-process_mem[p]);
            b++;
            total_internal_frag += block_size-process_mem[p];
        }
        else{
            printf("%d\t %d\t\t No\t\t --\n", p, process_mem[p]);
        }
    }

    if(b >= block_num){
        printf("Memory is full Remaining process cannot be accommodated\n ");
    }
    printf("Total internal fragmentation %d\n", total_internal_frag);
    printf("Total External fragmentation %d\n", total_external_frag);
}


int main(){
    int total_memory, block_size, process, i;

    printf("Enter the total memory available (in Bytes) -- ");
    scanf("%d",&total_memory);

    printf("Enter the block size (in Bytes) -- ");
    scanf("%d",&block_size);

    printf("Enter the number of process -- ");
    scanf("%d",&process);

    int process_mem[process];

    for(i=0; i<process; i++){
        printf("Enter the memory required for process %d (in Bytes) ", i+1);
        scanf("%d",&process_mem[i]);
    }

    mfnt(total_memory,block_size,process,process_mem);

    return 0;
}
