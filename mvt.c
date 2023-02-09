#include<stdio.h>

void mvt(int total_mem, int num_of_process, int process_mem[]){

    printf("Process\t Memory Required\tAllocated\n");
    int count=0, total_extern_freg, i, total_process_mem=0;

    for(i=0;i<num_of_process;i++){
        if(process_mem[i] <= (total_mem - total_process_mem) && total_process_mem <= total_mem){
            total_process_mem+=process_mem[i];
            printf("%d \t\t %d\t\t Yes\n",i+1,process_mem[i]);
        }
        else{

            printf("Memory full!!\n");
            break;
        }
    }
    total_extern_freg= total_mem - total_process_mem;
    printf("Total External Fregment: %d\n",total_extern_freg);
}

int main() {
    int i,total_mem, num_of_process;
    printf("Enter the total memory available (in Byte)- ");
    scanf("%d",&total_mem);
    printf("Enter the number of process: ");
    scanf("%d",&num_of_process);

    int process_mem[num_of_process];

    for(i=0;i<num_of_process;i++){
        printf("Enter the memory required for process %d (in Bytes): ",i+1);
        scanf("%d",&process_mem[i]);
    }
    mvt(total_mem, num_of_process,process_mem);

    return 0;
}
