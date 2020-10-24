#include<iostream>
using namespace std;
#include"meme.h"
#include<ctime>
#define k_max 10000
#define STAGE 300
#define EVO_RATIO 0.05

int main(){


    srand(time(NULL));
    meme *t[k_max];
    int is_live[k_max];
    int point;


    int count = 0;

    for (int i = 0; i < k_max;i++){
        t[i] = new meme(23,1);
        t[i]->mark = t[i]->sum();
    }

    for (int i = 0; i < 50;i++){
      //  cout << t[rand() % k_max]->sum()<<endl;
      count += t[rand() % k_max]->mark;
    }
    cout << count;

    for (int l = 0; l < STAGE;l++){
        for (int i = 0; i < k_max;i++){
            t[i]->mark = t[i]->sum();
            is_live[i] = -1;
        }
        cout << 1;
        point = 0;
        meme_rank(t, k_max);
        for (int i = 0; i < k_max;i++){
            if (t[i]->rank> k_max*EVO_RATIO)
                t[i]->live = 0;
            if(t[i]->live==1)
                is_live[point++] = i;
        }
        cout << 2;
        for (int i = 0; i < k_max;i++){
            if(!t[i]->live){
                search_live_rand(t[i],t,k_max,is_live,point);
            }
        }
        cout << 3;
    }
    cout << endl<<endl;
    count = 0;
    for (int i = 0; i < 50;i++){
        count += t[rand() % k_max]->mark;
    }
    cout << count;
    return 0;
}