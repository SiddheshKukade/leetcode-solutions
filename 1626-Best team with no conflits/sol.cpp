class Solution {
public:
    int findMaxScore(vector<pair<int,int>>& ageScorePair){
        int n = ageScorePair.size(); // total no of players
        int answer=0;
        vector<int> dp(n);
        for(int i=0; i<n;i++){ //iterate over total players
            dp[i] = ageScorePair[i].second; // store the scores in the dp 
            answer=max(answer,dp[i]); // stored the max score of among all players 
        }
        for(int i=0; i<n;i++){ //iterate over total players
            for(int j=i-1; j>=0;j--){ // iterate backwards from each players to check for validations.
                if(ageScorePair[i].second >= ageScorePair[j].second){//if score of younger player is more than olders
                dp[i] = max(dp[i], ageScorePair[i].second + dp[j]); //take the max between the current score and the score with previous player's score combined
                }
            }
        answer = max(answer,dp[i]); // check if this was more than current highest score and store it if yes.
        }
    return answer;
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
// score is invalid if a younger person scores more than other old persons.
// Given two lists, scores and ages, where each scores[i] and ages[i] represents the score and age  of the ith player, respectively, return the highest overall score of all possible basketball teams.
    vector<pair<int,int>> ageScorePair;
    for(int i=0; i<scores.size();i++){
        ageScorePair.push_back({ages[i], scores[i]}); // makes pairs of ages and scores
    }
    sort(ageScorePair.begin(), ageScorePair.end()); // sort the ages 
    return findMaxScore(ageScorePair); // send to ans function.

    }
};
