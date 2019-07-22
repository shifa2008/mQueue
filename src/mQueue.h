#ifndef MQUEUE_H
#define MQUEUE_H
#include <stdio.h>
typedef struct node{
   void *data;
   struct node* next;
}mQueueStroageSpace_t;
typedef struct mQueueObj_n {
  mQueueStroageSpace_t *EnterNode;
  mQueueStroageSpace_t *OutNode;
  char End;
void (*EnterQueue)(struct mQueueObj_n *This,mQueueStroageSpace_t *StroageSpace,void *data);
void *(*OutQueue)(struct mQueueObj_n *This,char *OutFlag);
long (*LstQueue)(struct mQueueObj_n *This,void (*CallRet)(void *This));
long (*IsQueueNull)(struct mQueueObj_n *This);
}mQueueObj_t;
mQueueObj_t *CreateQueueObj(mQueueObj_t *This,mQueueStroageSpace_t *StroageSpace,void *data);
#endif


