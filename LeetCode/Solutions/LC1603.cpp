/*
Problem Statement: https://leetcode.com/problems/design-parking-system/
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib

|-----------------------------------|------|-------|
| Operations                        | Time | Space |
|-----------------------------------|------|-------|
| ParkingSystem(big, medium, small) | O(1) | O(1)  |
| addCar(carType)                   | O(1) | O(1)  |
|-----------------------------------|------|-------|
*/

class ParkingSystem {
private:
	vector<int> space;
public:
	ParkingSystem(int big, int medium, int small) : space{big, medium, small} {}
	
	bool addCar(int carType) {
		if (!space[--carType])
			return false;
		space[carType]--;
		return true;
	}
};