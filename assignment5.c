#include <stdio.h>

int main() {
    int A[10][10], B[10][10], C[10][10];
    int i, j, r, c;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter elements of Matrix A:\n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&A[i][j]);

    printf("Enter elements of Matrix B:\n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&B[i][j]);

    // Matrix Addition
    printf("\nMatrix Addition:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            C[i][j]=A[i][j]+B[i][j];
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }

    // Saddle Point
    int min, col, saddle=0;
    for(i=0;i<r;i++){
        min=A[i][0];
        col=0;

        for(j=1;j<c;j++){
            if(A[i][j]<min){
                min=A[i][j];
                col=j;
            }
        }

        int k, flag=1;
        for(k=0;k<r;k++){
            if(A[k][col]>min){
                flag=0;
                break;
            }
        }

        if(flag){
            printf("\nSaddle Point: %d\n",min);
            saddle=1;
        }
    }

    if(!saddle)
        printf("\nNo Saddle Point Found\n");

    // Magic Square Check
    if(r==c){
        int sum=0, magic=1;

        for(j=0;j<c;j++)
            sum+=A[0][j];

        for(i=0;i<r;i++){
            int rowsum=0;
            for(j=0;j<c;j++)
                rowsum+=A[i][j];

            if(rowsum!=sum)
                magic=0;
        }

        if(magic)
            printf("\nMatrix A is a Magic Square\n");
        else
            printf("\nMatrix A is not a Magic Square\n");
    }

    return 0;
}
