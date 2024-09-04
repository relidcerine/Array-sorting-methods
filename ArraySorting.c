#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>
#include <stdbool.h>

//-------------------------------------Insertion Sort-----------------------------------------------
void Tri_par_insertion (long T[10000] , long i, long j, long n, long x){
    for(i=1; i<n;i++){
            x = T[i];
            j = i;
            while( (j > 0) && (T[j - 1] > x)){
                     T[j] = T[j - 1];
                     j = j - 1;
            }
            T[j] = x;
	}
}
//-------------------------------------Bubble Sort----------------------------------------------------
void Tri_a_bulle(long  tableau[], long  taille){
    int k,i;
    bool end;

    do{
        end = false;
        for(i = 0; i < taille - 1; i++){
        	if(tableau[i] > tableau[i+1]){
                k = tableau[i];
                tableau[i] = tableau[i+1];
                tableau[i+1] = k;
                end = true;
            }
		}
    }while(end);
}

//-------------------------------------Merge Sort----------------------------------------------------
void Fusion( long T[],  long Debut,  long Milieu, long Fin){
        long n1 = Milieu - Debut + 1;
        long n2 = Fin - Milieu;

        long G[n1], D[n2];
        long i ;
        for (i= 0; i < n1; i++)
            G[i] = T[Debut + i];
        int j;
        for (j = 0; j < n2; j++)
            D[j] = T[Milieu + 1 + j];


        long k;
        i = 0;
        j = 0;
        k = Debut;

        while ((i < n1) && ( j< n2)){
            if (G[i] <= D[j])
            {
                T[k] = G[i];
                i++;
            }
            else
            {
                T[k] = D[j];
                j++;
            }
            k++;
        }

        while (i < n1){
            T[k] = G[i];
            i++;
            k++;
        }

        while (j < n2){
            T[k] = D[j];
            j++;
            k++;
        }
    }

   void Tri_fusion(long T[],  long Debut, long Fin,long count){
        if (Debut < Fin){
            count++;

            int m = (Debut + Fin) / 2;

            Tri_fusion(T, Debut, m,count);
            Tri_fusion(T, m + 1, Fin,count);

            Fusion(T, Debut, m, Fin);
        }

    }
//-------------------------------------Quick Sort----------------------------------------------------
void swap( long* a,  long* b ) {
    long  t = *a;
    *a = *b;
    *b = t;
}
int quicksort_partition( long  array[], long  low, long  high ) {

    long  pivot = array[ high ];

    long  i = low - 1;  long  j;

    for ( j = low; j <= high - 1; j += 1 ) {

        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);

    return (i + 1);

}


void quicksort_pivot( long  array[], long  low, long  high ) {
    // Create stack
    long  stack[high - low + 1];

    long  top = -1;

    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0){

        high = stack[top--];
        low = stack[top--];

        long  p = quicksort_partition(array, low, high);

        if (p - 1 > low){
            stack[++top] = low;
            stack[++top] = p - 1;
        }

        if (p + 1 < high){
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }
}
//-------------------------------------Heap Sort----------------------------------------------------
void permuter(long *a, long *b){
    long tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void heapify(long arr[], long N, long i){
    long largest = i;
    long left = 2 * i + 1;
    long right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest]){
	       largest = left;
	}
   
    if (right < N && arr[right] > arr[largest]){
	      largest = right;
	}

    if (largest != i){
        permuter(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}

void TriTas(long *T, long n){
    long i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(T, n, i);

    for (i = n - 1; i >= 0; i--){
        permuter(&T[0], &T[i]);

        heapify(T, i, 0);
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------------------

int main(){
	long  i,j,x;
    long  n=10,K;
    int cnt=0,t;
    long   T [n];


    clock_t t1, t2;
    double delta;

    for(i=1; i<=n; i++) {
       T[i] =rand();
	}

   
    t1=clock();

    printf("The Table before sorting : \n");
    for(i=0 ; i<n ; i++){
       printf("%d ,",T[i]);
    }
    printf("\n");

   printf("The Table after sorting : \n");
   for(i=0 ; i<n ; i++){
      printf("%d ,",T[i]);
   }
   t2=clock();
   delta= (double)(t2-t1)/CLOCKS_PER_SEC;
   printf("\nExecution time = %f\n",delta);

    return 0;
}
