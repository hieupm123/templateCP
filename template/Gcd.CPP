int Gcd(int a, int b){
	if(b == 0) return a;
	return Gcd(b, a % b);
}