#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    //list를 사용해서 매번 전체 순회 -> 30 * 100,000 개 시간 복잡도 OK
    list<string> cache;
    for(int i=0; i< cities.size(); i++){
        string city_name = cities[i];
        transform(city_name.begin(), city_name.end(),city_name.begin(),::toupper);
        auto cn = find(cache.begin(),cache.end(),city_name);
        if (cacheSize == 0){
            answer+= 5;
        } else if (cn == cache.end()){//cache miss
            if (cache.size() == cacheSize)
                cache.pop_front();
            cache.push_back(city_name);
            answer+=5;
        }else{ // cache hit
            cache.erase(cn);
            cache.push_back(city_name);
            answer++;
        }
    }
    return answer;
}