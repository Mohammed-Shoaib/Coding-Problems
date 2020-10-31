/*
Problem Statement: https://leetcode.com/problems/apply-discount-every-n-orders/
*/

class Cashier {
private:
	int cnt, n, discount;
	unordered_map<int, int> price;
public:
	Cashier(int n, int discount, vector<int>& products, vector<int>& prices) : cnt(0), n(n), discount(discount) {
		for (int i = 0; i < products.size(); i++)
			price[products[i]] = prices[i];
	}
	
	double getBill(vector<int> product, vector<int> amount) {
		double cost = 0;
		for (int i = 0; i < product.size(); i++)
			cost += price[product[i]] * amount[i];
		if (++cnt == n) {
			cost -= (cost * discount) / 100;
			cnt = 0;
		}
		return cost;
	}
};