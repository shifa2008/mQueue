#include "mQueue.h"
void CallRet(void *This)
{
   printf("\r\nThis:%d\r\n",(int)This);
}
int main(void)
{
   void  *ret=0;
   mQueueObj_t Queue[1];
   mQueueStroageSpace_t QueueSpace[4];
   CreateQueueObj(Queue,&QueueSpace[0],(void *)1);
   Queue->LstQueue(Queue,CallRet);
   
   Queue->EnterQueue(Queue,&QueueSpace[1],(void *)2);
   Queue->EnterQueue(Queue,&QueueSpace[2],(void *)3);
   Queue->EnterQueue(Queue,&QueueSpace[3],(void *)4);

   Queue->LstQueue(Queue,CallRet);
   char OutFlag[1];
   printf("\r\n");
   ret=Queue->OutQueue(Queue,OutFlag);
   printf("OutFlag1:%d Val:%d\r\n",OutFlag[0],*(int*)&ret);
   Queue->LstQueue(Queue,CallRet);
   printf("\r\n");
  
   ret=Queue->OutQueue(Queue,OutFlag);
   printf("OutFlag2:%d Val:%d\r\n",OutFlag[0],*(int*)&ret);
   Queue->LstQueue(Queue,CallRet);
   printf("\r\n");  
   
   ret=Queue->OutQueue(Queue,OutFlag);
   printf("OutFlag2:%d Val:%d\r\n",OutFlag[0],*(int*)&ret);
   Queue->LstQueue(Queue,CallRet);
   printf("\r\n"); 
  
   ret=Queue->OutQueue(Queue,OutFlag);
   printf("OutFlag2:%d Val:%d\r\n",OutFlag[0],*(int*)&ret);
   Queue->LstQueue(Queue,CallRet);
   printf("\r\n"); 
   ret=Queue->OutQueue(Queue,OutFlag);
   printf("OutFlag2:%d Val:%d\r\n",OutFlag[0],*(int*)&ret);
   Queue->LstQueue(Queue,CallRet);
   printf("\r\n");  
}
