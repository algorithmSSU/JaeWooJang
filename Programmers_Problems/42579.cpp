//https://school.programmers.co.kr/learn/courses/30/lessons/42579
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Album {
public:
    int hash_val;
    int plays;
    vector<pair<int, int>> song;

    Album() {
        hash_val = 0;
        plays = 0;
    }

    Album(int hash_val, int plays, int i) {
        this->hash_val = hash_val;
        this->plays = plays;
        this->song.emplace_back(plays, i);
    }

    static bool cmpFunc(const Album& a, const Album& b) {
        return a.plays > b.plays;
    }
};

bool cmpFunc(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first > b.first)
        return true;

    else if (a.first < b.first)
        return false;

    return a.second < b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    hash<string> str_hash;

    vector<Album> album_builder;
    for (int i = 0; i < genres.size(); ++i) {
        int hash_val = str_hash(genres[i]);

        int j;
        for (j = 0; j < album_builder.size(); ++j) {
            if (album_builder[j].hash_val == hash_val) {
                album_builder[j].plays += plays[i];
                album_builder[j].song.emplace_back(plays[i], i);
                break;
            }
        }

        if (j == album_builder.size())
            album_builder.emplace_back(hash_val, plays[i], i);
    }

    sort(album_builder.begin(), album_builder.end(), Album::cmpFunc);

    for (int i = 0; i < album_builder.size(); ++i) {
        sort(album_builder[i].song.begin(), album_builder[i].song.end(), cmpFunc);

        for (int j = 1; j < album_builder[i].song.size(); j += 2) {
            answer.emplace_back(album_builder[i].song[j - 1].second);
            answer.emplace_back(album_builder[i].song[j].second);
        }
    }


    return answer;
}