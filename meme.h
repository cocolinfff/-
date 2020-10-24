#include<cstdlib>
#define VARIA_NUM_SPEED 0.000001
#define VARIA_ME_SPEED 0.001
#define VARIA_RANGE 1


class meme{
    public:
        int *me;
        int meme_num;
        int live;
        int mark;
        int rank;
        meme(int i,int rand=1){
            me = new int[i];
            meme_num = i;
            this->me_rand();
            live = 1;
            }
        ~meme(){
            delete[] me;
        }

        void me_rand(){
            for (int i = 0; i <meme_num ;i++){
                me[i] = rand() % 100;
            }
        }
        int sum(){
            int sum = 0;
            for (int i = 0; i <meme_num ;i++){
                sum += me[i];
            }
            return sum;
        }
    private:
        
};


        void merge(meme *a,meme *b,meme *new_m){
            //std::cout << 1;
            new_m->meme_num=((rand() % 2)?a->meme_num:b->meme_num);
            for (int i = 0; i < new_m->meme_num;i++){
                if(i>a->meme_num-1) {
                    new_m->me[i] = b->me[i];
                    continue;
                }
                else if(i>b->meme_num-1) {
                    new_m->me[i] = a->me[i];
                    continue;
                }
                else new_m->me[i] = ((rand() % 2)? a->me[i] : b->me[i]);
            }
        }

        meme varia(meme &new_m){
            ;
        }

        void search_live_rand(meme *former_meme,meme **p,int max,int* is_live,int point){
            int k = rand() % point;
            int j = rand() % point;
            //std::cout << 1;
        //    std::cout <<endl<< k<<' '<<p[k]->live;
       /*     while(p[k]->live==0){
                k = rand() % max;
                
            }
        //     std::cout <<endl<< k<<' '<<p[k]->live;
           
            //std::cout << 1;
            while(p[j]->live==0||j==k){
                j = rand() % max;

            }
        //     std::cout <<endl<< j<<' '<<p[j]->live;
            //std::cout << 1;
            */
            merge(p[is_live[k]], p[is_live[j]], former_meme);
            former_meme->live = 1;
        }


        void quick_sort(meme **p, int start, int end) {
            if(start>=end)
                return;
            int key = p[(start + end) / 2]->mark;
            int i = 0, j = end;
            while(i<j){
                while(p[i]->mark>key&&i<j)
                    i++;
                if(p[i]->mark<=key&&i<j)
                    p[j]->rank=p[i]->rank;
                while(p[j]->mark<key&&i<j)
                    j--;
                if(p[i]->mark>=key&&i<j)
                    p[i]->rank=p[j]->rank;
            }
            p[i]->rank = i;
            quick_sort(p, start, i - 1);
            quick_sort(p, i+1, end);
        }



        void normal_sort(meme **p,int max){
            for (int i = 0; i < max;i++){
                for (int j = i + 1; j < max;j++){
                    if(p[i]->mark<p[j]->mark){
                        int temp=p[i]->rank;
                        p[i]->rank = p[j]->rank;
                        p[j]->rank = temp;
                    }
                }
            }

        }
        void meme_rank(meme **p,int max){
            for (int i = 0; i < max; i++){
                p[i]->rank = i;
            }
        //    for (int i = max/2; i < max;i++)
         //   quick_sort(p,0,max);
            normal_sort(p,max);
        }

       