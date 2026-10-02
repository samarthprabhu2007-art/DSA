class Solution{	
	public:
		bool anagramStrings(string &s,string &t){
			vector<int> alph(26,0);
            for(char x:s) alph[x-97]++;
            for(char x:t) alph[x-97]--;
            for(int x:alph) if(x!=0) return false;
            return true;
		}
};