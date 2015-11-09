#include <iostream>  
#include<vector>
#include <string>  
#include<queue>
#include<set>
#include<stack>
using namespace std;
class Solution {
public:
	Solution() :range({ 1000000000, 1000000, 1000 }),
		label({ "Billion", "Million", "Thousand" }),
		singlenumber({ "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" }),
		lowertwenty({ "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" }),
		uppertwenty({ "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" }){}
	string numberToWords(int num) {
		if (num == 0) return "Zero";
		string result;
		for (int i = 0; i < 3; i++){
			int q = num / range[i];
			num -= q*range[i];
			if (q != 0){
				appendnum(result, q);
				result += " " + label[i];
			}
		}
		appendnum(result, num);
		return result;
	}
private:
	vector<int> range;
	vector<string> label;
	vector<string> singlenumber;
	vector<string> lowertwenty;
	vector<string> uppertwenty;
	inline void appendnum(string& result, int num){
		int q;
		if (num >= 100){
			result += result.empty() ? "" : " ";
			q = num / 100;
			result += singlenumber[q - 1];
			num -= 100 * q;
			result += " Hundred";
		}
		if (num >= 20 && num < 100){
			result += result.empty() ? "" : " ";
			q = num / 10;
			result += uppertwenty[q - 2];
			num -= 10 * q;
		}
		if (num >= 10 && num <= 19){
			result += result.empty() ? "" : " ";
			result += lowertwenty[num - 10];
		}
		if (num>0 && num < 10){
			result += result.empty() ? "" : " ";
			result += singlenumber[num - 1];
		}
	}
};

int main(){
	Solution eg;
	int num = 123;
	cout << eg.numberToWords(num) << endl;
	return 0;
}