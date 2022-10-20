
import java.util.*;

class TUF{
static int prime = (int)(Math.pow(10,9)+7);

static int countUtil(String s1, String s2, int ind1, int ind2,int[][] dp){
    if(ind2<0)
        return 1;
    if(ind1<0)
        return 0;
    
    if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];
    
    if(s1.charAt(ind1)==s2.charAt(ind2)){
        int leaveOne = countUtil(s1,s2,ind1-1,ind2-1,dp);
        int stay = countUtil(s1,s2,ind1-1,ind2,dp);
        
        return dp[ind1][ind2] = (leaveOne + stay)%prime;
    }
    
    else{
        return dp[ind1][ind2] = countUtil(s1,s2,ind1-1,ind2,dp);
    }
}

static int subsequenceCounting(String t, String s, int lt, int ls) {
    // Write your code here.
    
    int dp[][]=new int[lt][ls];
    for(int rows[]: dp)
    Arrays.fill(rows,-1);
    return countUtil(t,s,lt-1,ls-1,dp);
} 

public static void main(String args[]) {

  String s1 = "babgbag";
  String s2 = "bag";

  System.out.println("The Count of Distinct Subsequences is "+
  subsequenceCounting(s1,s2,s1.length(),s2.length()));
}
}
