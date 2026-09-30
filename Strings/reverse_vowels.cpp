class Solution {
public:
    bool isVowel(char ch) {
        // Convert to lowercase to handle both upper and lowercase inputs
        switch (std::tolower(static_cast<unsigned char>(ch))) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
            default:
                return false;
        }
  }
    string reverseVowels(string s) {
        int n = s.length();
        int st = 0;
        int end = n-1;
        while(st<end){
            while(st < end){
                if(!isVowel(s[st])) st++;
                else break;
            }
            while(st < end){
                if(!isVowel(s[end])) end--;
                else break;
            }
            if(st<end){
                swap(s[st],s[end]);
                st++;
                end--;
            }
            else break;
        }
        return s;
    }
};