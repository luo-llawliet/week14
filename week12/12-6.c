#include "my.h"
int main()
{
   pid_t p1,p2,p3;
   int s1,s2,s3;

   p1=fork();
  
   
   if(p1<0)
     {
         perror("fork failed.\n");
         //fprintf(STDOUT,"error %d",str(errno));
         return -1;
     }
   else if (p1==0)
    {
        printf("[child %d]\t[parent %d]\n",getpid(),getppid());
        exit(9);
    }
   else{

           p2=fork();
           if(p2<0)
            {
                    perror("fork failed.\n");
                    //fprintf(STDOUT,"error %d",str(errno));
                    return -1;
            }
           else if (p2==0)
                {
                   printf("[child %d]\t[parent %d]\n",getpid(),getppid());
                   exit(19);
                 }
            else{
                    p3=fork();
                    if(p3<0)
                      {
                         perror("fork failed.\n");
                         //fprintf(STDOUT,"error %d",str(errno));
                          return -1;
                       }
                     else if (p3==0)
                      {
                       printf("[child %d]\t[parent %d]\n",getpid(),getppid());
                        exit(99);
                        }
                     else
                     {
                         p1=wait(&s1);
                         p2=wait(&s2);
                         p3=wait(&s3);
                         printf("%d exit code %d\n%d exit code %d\n%d exit code %d\n",p1,WEXITSTATUS(s1),p2,WEXITSTATUS(s2),p3,WEXITSTATUS(s3));
                         return 0;
                      }


                }
}

       }
