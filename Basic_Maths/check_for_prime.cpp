class Solution{	
	public:
		bool checkPrime(int num){
            if(num == 1) return false;
            bool prime = true;
            int x = sqrt(num);
            for(int i=2;i<=x;i++){
                if(num%i==0){
                    prime=false;
                    break;
                }
            }
            return prime;
		}
};