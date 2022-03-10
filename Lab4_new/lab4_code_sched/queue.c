
#include <stdlib.h>
#include "queue.h"
#include <pthread.h>

/* Remember to initilize the queue before using it */
void initialize_queue(struct pqueue_t * q) {
	q->head = q->tail = NULL;
	pthread_mutex_init(&q->lock, NULL);
}

/* Return non-zero if the queue is empty */
int empty(struct pqueue_t * q) {
	return (q->head == NULL);
}

/* Get PCB of a process from the queue (q).
 * Return NULL if the queue is empty */
struct pcb_t * de_queue(struct pqueue_t * q) {
	struct pcb_t * proc = NULL;
	// TODO: return q->head->data and remember to update the queue's head
	// and tail if necessary. Remember to use 'lock' to avoid race
	// condition
	
	// YOUR CODE HERE
	if(q->head != NULL)
	{
		if(q->head == q->tail)
		{
			proc = q->head->data;
			pthread_mutex_lock(&q->lock);
			//proc = q->head->data;
			q->head = NULL;
			q->tail = NULL;
			pthread_mutex_unlock(&q->lock);
		}
		else
		{	
			proc = q->head->data;
			pthread_mutex_lock(&q->lock);
			//proc = q->head->data;
			q->head = q->head->next;
			pthread_mutex_unlock(&q->lock);
		}

	}
	return proc;
}

/* Put PCB of a process to the queue. */
void en_queue(struct pqueue_t * q, struct pcb_t * proc) {
	// TODO: Update q->tail.
	// Remember to use 'lock' to avoid race condition
	
	// YOUR CODE HERE
	//
	struct qitem_t * pnew
	       	= (struct qitem_t *)malloc(sizeof(struct qitem_t));
	pnew->data = proc;
	pnew->next = NULL;
	if(q->head == NULL)
	{
		pthread_mutex_lock(&q->lock);
		q->head = pnew;
		q->tail = pnew;
		pthread_mutex_unlock(&q->lock);
	}
	else
	{
		pthread_mutex_lock(&q->lock);
		q->tail->next = pnew;
		q->tail = pnew;
		pthread_mutex_unlock(&q->lock);
	}
	

}


