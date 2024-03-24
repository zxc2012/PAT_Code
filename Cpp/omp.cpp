#include <stdio.h>
#include <omp.h>
int main()
{
    int nthreads, tid;
    /* Fork team of threads with private var tid */
    #pragma omp parallel for private(tid)
    {

        for(tid=0;tid<20;++tid){
            nthreads = omp_get_thread_num(); /* get thread id */
            printf("Hello World from thread = %d tid =%d\n", nthreads, tid);
        }


    } /* All threads join master and terminate */
}