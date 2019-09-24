#include<map>
using namespace std;

int main(int argc, char const *argv[]) {
    int number;
    map <int,int> prime {{2,0},{3,0},{5,0},{7,0},{11,0},{13,0},{17,0},{19,0},{23,0},{29,0},{31,0},{37,0},{41,0},
                        {43,0},{47,0},{53,0},{59,0},{61,0},{67,0},{71,0},{73,0},{79,0},{83,0},{89,0},{97,0}};

    while (scanf("%d", &number) && number != 0) {
        std::map<int,int>::iterator i;
        int temp, lim = 0;
        
        for(int fact = 2; fact <=number; ++fact) {
            i = prime.begin();
            temp = fact;
            while (i->first <= temp && temp > 0) {
                if (temp%(i->first) == 0) {
                    temp/=(i->first);
                    i->second++;
                } else ++i;
            }
        }
        
        i = prime.begin();
        printf("%3d! =",number);
        while (i->second != 0) {
            if (lim > 0 && lim%15 == 0)
                printf("\n      ");
            printf("%3d", i->second);
            i->second = 0;
            ++i; lim++;
        } 
        printf("\n");
    }
    return 0;
}
