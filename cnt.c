#include <stdio.h>
#include <limits.h>

void worst_fit(int*, int, int*, int);

int main(){
    int n_block, n_process, b, p;
    printf("Enter the number of blocks: ");
    scanf("%d", &n_block);
    printf("Enter the number of process: ");
    scanf("%d", &n_process);

    int block[n_block];

    printf("\nEnter the size of blocks\n");
    for(b=0; b<n_block; b++){
        printf("Block %d: ", b+1);
        scanf("%d", &block[b]);
    }

    int process[n_process];

    printf("Enter the size of process\n");
    for(p=0; p<n_process; p++){
        printf("Process %d: ", p+1);
        scanf("%d", &process[p]);
    }

    worst_fit(block, n_block, process, n_process);

    return 0;
}

void worst_fit(int *block, int n_block, int *process, int n_process){
    int p, b, allocated[n_block], frag, set;
    for(b=0; b<n_block; b++){
        allocated[b]=0;
    }

    printf("Process_no\t Process_size\t Block_no\t Block_size\t Fragment\n");
    for(p=0; p<n_process; p++){
        frag=0;
        set=-1;
        for(b=0; b<n_block; b++){
            if(allocated[b]==0 && frag<block[b]-process[p]){
                frag=block[b]-process[p];
                set=b;
            }
        }
        allocated[set]=1;

        if(set==-1){
            printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\n", p+1, process[p], 0, 0, 0);
        }
        else{
            printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\n", p+1, process[p], set+1, block[set], block[set]-process[p]);
        }
    }

}
