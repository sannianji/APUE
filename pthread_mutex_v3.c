//simple v2
#include <stdlib.h>
#include <pthread.h>

#define NHASH 29
#define HASH(id) (((unsined long) id)%NHASH)


struct foo *fh[NHASH];
pthread_mutex_t hashlock=PTHREAD_MUTEX_INITIALIZER;

struct foo
{
	int f_count;
	pthread_mutex_lock f_lock;
	int f_id;
	struct foo *f_next;
	//other
};


struct foo* foo_alloc(int id)
{
	struct foo *fp;
	int idx;
	
	if((fp=malloc(sizeof(struct foo)))!=NULL)
	{
		fp->f_count=1;
		fp->id=id;
		if(pthread_mutex_init(fp->f_lock)!=0)
		{
			free(fp);
			return NULL;
		}
		idx=HASH(id);
		pthread_mutex_lock(&hashlock);
		fp->next=fh[idx];
		fh[idx]=fp;
		pthread_mutex_lock(&fp->f_lock);
		pthread_mutex_unlock(&hashlock);
		//initialization others

		pthread_mutex_unlock(&fp->f_lock);
	}
	return (fp);
}


void foo_hold(struct foo *fp)
{
	pthread_mutex_lock(&hashlock);
	fp->f_count++;
	pthread_mutex_unlock(&hashlock);
}

struct foo * foo_find(int id)
{
	struct foo *fp;
	pthread_mutex_lock(&hashlock);
	for(fp=fh[HASH(id)];fp!=NULL;fp=fp->f_next)
	{
		if(id==fp->f_id)
		{
			fp->f_count++;
			break;
		}
	}
	pthread_mutex_unlock(&hashlock);
	return (fp);
}

void foo_rele(struct foo *fp)
{
	struct foo *tfp;
	int idx;
	pthread_mutex_lock(&hashlock);
	if(--fp->f_count==0)
	{
		idx=HASH(fp->f_id);
		tfp=fh[idx];
		if(tfp==fp)
		{
			fh[idx]=fp->f_next;
		}
		else
		{
			while(tfp->next!=fp)
				tfp=tfp->f_next;
			tfp->f_next=fp->f_next;
		}
		pthread_mutex_unlock(&hashlock);
		pthread_mutex_destroy(&fp->f_lock);
		free(fp);
	}
	else
		pthread_mutex_unlock(&fp->f_lock);
}
