# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>

pthread_mutex_t x;
int a;

void    *f()
{
    pthread_mutex_lock(&x);
    int i = 0;

    while (i++ < 10000)
        a++;
    pthread_mutex_unlock(&x);
}

int main()
{
    pthread_t *b;
    b = malloc(sizeof(pthread_t)* 4);
    int i = 0;

    pthread_mutex_init(&x, NULL);
    while(i++ < 4)
        pthread_create(&b[i], NULL, &f, NULL);
    i = 0;
    while(i++ < 4)
        pthread_join(b[i], NULL);
    printf("%d", a);
}
