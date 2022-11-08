#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*
 * Complete the 'climbingLeaderboard' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY ranked
 *  2. INTEGER_ARRAY player
 */
 
void adjust_pos(map<int,int>& pos,vector<int>& ranked)
{
    int cnt = 1;
    int last_idx  = ranked.size()-1;
    
    pos[ranked[0]]=cnt++;//first place

    for(int i = 0; i < ranked.size()-1 ;i++)
    {
        if(ranked[i]!=ranked[i+1])// from 2nd to end
        {
            pos[ranked[i+1]]=cnt++;
        }
    }
}


vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) 
{

    vector<int> players_ranks;
    map<int,int> pos;//key:rank, value Pos
    
    adjust_pos(pos,ranked);
    
    for(int score=0; score < player.size();score++)
    {
        int middle  = 0;
        int left    = 0;
        int right   = ranked.size()-1;
        //binary search
        while((right-left) > 1)
        {
            middle = (right+left)/2;
            if(player[score] < ranked[middle])
            {
                left = middle+1;
            }
            else
            {
                right = middle;
            }
        }

        if (ranked[left] != player[score] || 
            ranked[right] != player[score]) 
        {   // not found
            int offset;
            if(player[score] > ranked[left])
            {
                offset = left-1;
            }
            else if(player[score] > ranked[middle])
            {
                offset = middle-1;
            }
            else if(player[score] < ranked[middle])
            {
                offset = middle+1;
            }
            else
            {
                offset = right;
            }

            ranked.insert(ranked.begin() + offset+1, player[score]);
            adjust_pos(pos,ranked);
        }
        players_ranks.push_back(pos[player[score]]);
    
    }
    return players_ranks;
}

int main()
{
    vector<int>ranked {100, 90, 90 ,80, 75, 60};
    vector<int>player {50, 65, 77, 90, 102};
    climbingLeaderboard(ranked,player);
}