#include <iostream>
#include <stdio.h>

using namespace std;

struct Hashitem{
    int key;
    int val;
    struct Hashitem *next;
};

struct Hashtable{
    Hashitem **arr;
    int size;
    int current_count;
};

int Hashtable_init(Hashtable *hash,int size){
    int i = 0;

    hash->size = size;
    hash->current_count = 0;
    hash->arr = (Hashitem **)malloc(size*(sizeof(Hashitem *)));
    if(hash->arr == NULL){
        return -1;
    }else{
        for(i = 0;i <size;i++){
            hash->arr[i] = NULL;
        }
        return 0;
    }
}

int HashFunc(int key){
    return key%13;
}

int Hashtable_insert(Hashtable *hash,int key,int val){
    int index;
    index = HashFunc(key);
    Hashitem *p = hash->arr[index];
    Hashitem *tmp = NULL;
    if(p == NULL){
        p = (Hashitem *)malloc(sizeof(Hashitem));
        if(p == NULL){
            return -1;
        }
        p->key = key;
        p->val = val;
        p->next = NULL;
        hash->arr[index] = p;
    }else{
        while(p->next != NULL){
            p = p->next;
        }
        tmp = (Hashitem *)malloc(sizeof(Hashitem));
        if(tmp == NULL){
            return -1;
        }
        tmp->key = key;
        tmp->val = val;
        tmp->next = NULL;   
        p->next = tmp;
    }
    return 0;
}

int Hashtable_find(Hashtable hash,int key){
    int index = 0;
    index = HashFunc(key);
    Hashitem *p = hash.arr[index];
    while(p != NULL && p->key != key){
        p = p->next;
    }
    if(p == NULL){
        return -1;
    }else{
        return p->val;
    }
}

int main(){
    int ret = 0;
    Hashtable hs_t;

    ret = Hashtable_init(&hs_t,13);
    
    ret = Hashtable_insert(&hs_t,19,0);
    ret = Hashtable_insert(&hs_t,14,1);
    ret = Hashtable_insert(&hs_t,23,2);
    ret = Hashtable_insert(&hs_t,84,3);

    ret = Hashtable_find(hs_t,84);
    cout << "ret = " <<ret<<endl;

}