#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "ring_que.h"

int

main()
{
  RINGQ rq, *p_queue;  
  unsigned int i,data;  
  DataNode mDataNode1, mDataNode2, temp, *ptemp;

  p_queue = &rq;  
  ringq_init(p_queue);  
  memset(mDataNode1.mData, 0, sizeof(mDataNode1.mDataLen));
  memset(mDataNode2.mData, 0, sizeof(mDataNode1.mDataLen));
  memset(temp.mData, 0, sizeof(temp.mDataLen));
  ptemp = &temp;
  
  for (i = 0; i < 5; i++)
  {
    mDataNode1.mData[i] = i;
	mDataNode2.mData[i] = i + 5;
  }
  mDataNode1.mDataLen = 5;
  mDataNode2.mDataLen = 5;
 
  for(i = 0; i < 5; i++){
	   printf("mDataNode1[%u]: %x\n", i, mDataNode1.mData[i]);
	   printf("mDataNode2[%u]: %x\n", i, mDataNode2.mData[i]);
  }
//  for( i=0; i < 2 ; i++)  
 //  {
      i = 0;
	  i = ringq_push(p_queue,  &(mDataNode1.mData), mDataNode1.mDataLen);   
	  printf("tail1:%u\n", i);
	  i = 0;
	  i = ringq_push(p_queue,  &(mDataNode2.mData), mDataNode2.mDataLen);   
	  printf("tail2:%u\n", i);
   //}   
   i = 0;
   i = ringq_poll(p_queue, ptemp);
   printf("head:%u\n", i);
   for(i = 0; i < 5; i++)
		 printf("NO.1 Temp[%u]: %x\n", i, ptemp->mData[i]);
   
#if 1
   i = 0;
   i = ringq_poll(p_queue, ptemp);
   printf("head:%u\n", i);
   for(i = 0; i < 5; i++)
		 printf("NO.2 Temp[%u]: %x\n", i, ptemp->mData[i]);
  
#endif 
   i = ringq_poll(p_queue, ptemp);
   printf("\nEnd\n");
}
