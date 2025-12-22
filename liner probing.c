#include <stdio.h>
#include <stdlib.h>
int tsize, hash[10], count=0;
int cal_Hash(int key)
{
    return key % tsize;
}
int vcal_ReHash(int key)
{
    return (key+1) % tsize;
}
void insert(int key)
{
    int index;
    if(count!=tsize)
    {
        index=cal_Hash(key);
        while(hash[index]!=-1)
        {
            index=vcal_ReHash(index);
        }
        hash[index]=key;
        count++;
    }
    else
    {
        printf("\nTable is full");
    }
}
int search (int key)
{
    int i, index, loc=-1;
    index=cal_Hash(key);
    for(i=0; i<tsize; i++)
    {
        loc=(index+i)%tsize;
        if(hash[loc]==key)
        {
            return loc;
        }
    }
    return -1;
}
void delete(int key)
{
    int loc;
    if(count==0)
    {
        printf("\nHash table empty,can't delete");
    }
    else
    {
        loc=search(key);
        if(loc!=-1)
        {
            hash[loc]=-1;
            count--;
            printf("\nKey deleted");
        }
        else
        {
            printf("\nKey not found");
        }
    }
}
void display()
{
    int i;
    printf("\nThe Elements in the hash table are:\n");
    for(i=0;i<tsize;i++)
    {
        printf("Elements at position %d%d\n", i,hash[i]);
    }
}
int main()
{
    int key, i, ch, loc;
    printf("\nEnter the size of hash table:");
    scanf("%d", &tsize);
    for(i=0;i<tsize;i++)
    {
        hash[i]=-1;
    }
    while(1)
    {
        printf("\n1.Insert\n2.Search\n3.Delete\n4.Display\nExit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter key insert:");
                scanf("%d", &key);
                insert(key);
                break;
        case 2:
            printf("\nEnter key to search:");
            scanf("%d", &key);
            loc=search(key);
            if(loc!=-1)
                printf("\nKey found at index %d", loc);
            else
                printf("\nKey not found");
            break;
        case 3:
            printf("\nEnter key to delete");
            scanf("%d", &key);
            delete(key);
            break;
        case 4:
            display();
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
