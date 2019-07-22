#include "mQueue.h"

static void EnterQueue(mQueueObj_t *This,mQueueStroageSpace_t *StroageSpace,void *data)
{
   StroageSpace->data=data;
   StroageSpace->next=NULL;
   This->EnterNode->next=StroageSpace;
   This->EnterNode=This->EnterNode->next;
   This->End=1;
}
static void *OutQueue(mQueueObj_t *This,char *OutFlag)
{
   void *PopValue=0;
   OutFlag[0]=1;
   PopValue=This->OutNode->data;
   if(This->End==0){OutFlag[0]=0;return PopValue;}
   if(This->OutNode==This->EnterNode)
	   This->End=0;
   else
	   This->OutNode=This->OutNode->next;
   return PopValue;
}
static long LstQueue(mQueueObj_t *This,void (*CallRet)(void *This))
{
   long ret=0;
   mQueueStroageSpace_t *LstQueue=This->OutNode;
   if(This->End==0){return -1;}
   while(LstQueue!=NULL)
   {
      CallRet(LstQueue->data);
      LstQueue=LstQueue->next;
      ret++;
   }
   return ret;
}
static long IsQueueNull(mQueueObj_t *This)
{
   return (This->OutNode==This->EnterNode);
}
mQueueObj_t *CreateQueueObj(mQueueObj_t *This,mQueueStroageSpace_t *StroageSpace,void *data)
{
   StroageSpace->data=data;
   StroageSpace->next=NULL;
   This->EnterNode=StroageSpace;
   This->OutNode=StroageSpace;
   This->End=1;
   This->EnterQueue=EnterQueue;
   This->OutQueue=OutQueue;
   This->LstQueue=LstQueue;
   This->IsQueueNull=IsQueueNull;

   return This;
}
#if 0
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
   LstQueue(Queue,CallRet);
   
   EnterQueue(Queue,&QueueSpace[1],(void *)2);
   EnterQueue(Queue,&QueueSpace[2],(void *)3);
   EnterQueue(Queue,&QueueSpace[3],(void *)4);

   LstQueue(Queue,CallRet);
   char OutFlag[1];
   printf("\r\n");
   ret=OutQueue(Queue,OutFlag);
   printf("OutFlag1:%d Val:%d\r\n",OutFlag[0],*(int*)&ret);
   LstQueue(Queue,CallRet);
   printf("\r\n");
  
   ret=OutQueue(Queue,OutFlag);
   printf("OutFlag2:%d Val:%d\r\n",OutFlag[0],*(int*)&ret);
   LstQueue(Queue,CallRet);
   printf("\r\n");  
   
   ret=OutQueue(Queue,OutFlag);
   printf("OutFlag2:%d Val:%d\r\n",OutFlag[0],*(int*)&ret);
   LstQueue(Queue,CallRet);
   printf("\r\n"); 
  
   ret=OutQueue(Queue,OutFlag);
   printf("OutFlag2:%d Val:%d\r\n",OutFlag[0],*(int*)&ret);
   LstQueue(Queue,CallRet);
   printf("\r\n"); 
   ret=OutQueue(Queue,OutFlag);
   printf("OutFlag2:%d Val:%d\r\n",OutFlag[0],*(int*)&ret);
   LstQueue(Queue,CallRet);
   printf("\r\n");  
}
#endif

