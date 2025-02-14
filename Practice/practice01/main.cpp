#include <iostream>
#include <vector>

void showMenu() {
		std::cout << "\nMenu:\n";
		std::cout << "1. Add an item to an Vector\n";
		std::cout << "2. Print the Vector\n";
		std::cout << "3. Double the Vector\n";
		std::cout << "4. Find the Sum\n";
		std::cout << "5. Print Multiples of an Value\n";
		std::cout << "6. Exit\n";
	}


void addNumbertoVec(std::vector<int>& vec) {
	int x;
	std::cout << "Enter a Number: ";
	std::cin >> x;

	vec.push_back(x);
}

void doubleVec(std::vector<int>& vec) {
	for (int& num : vec) {
		num *= 2;
	}
}

void print(const std::vector<int>& vec) {
	std::cout << "Vector Elements: ";
	for (int num : vec) {
		std::cout << num << " ";
	}
	std::cout << "\n";
}

int findSum(const std::vector<int>& vec) {
	int sum = 0;
	for (const int& num : vec) {
	sum += num;
	}
	return sum;
}

void printMultiples(const std::vector<int>& vec) {
	int value;
	std::cout << "Enter a value to find its multiples: ";
	std::cin >> value;

	if (value == 0) {
		std::cout << "Value cannot be zero.\n";
		return;
	}

	std::cout << "Multiples of " << value << " in the vector: ";
	bool found = false;
	for (int num : vec) {
		if (num % value == 0) {
			std::cout << num << " ";
			found = true;
		}
	}
	
	if (!found) {
		std::cout << "None";
	}

	std::cout << "\n";
}


int main() {
	std::vector <int> vec;

	int choice;
	int sum = 0;
	

	do {
		showMenu();
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch (choice) {

		case 1:
			addNumbertoVec(vec);
			break;
		case 2:
			print(vec);
			break;
		case 3:
			doubleVec(vec);
			print(vec);
			break;
		case 4:
			sum = findSum(vec);
			std::cout << "Sum of elements: " << sum << "\n";
			break;
		case 5: 
			printMultiples(vec);
			break;
		case 6:                 
			std::cout << "Exiting program...\n";
			break;
		default:
			std::cout << "Invalid choice, try again.\n";
			break;


		}
	} while (choice != 6);

		return 0;
}