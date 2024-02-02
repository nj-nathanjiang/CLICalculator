#include <iostream>
#include <cctype>

#include <string>
#include <stdexcept>

using namespace std;

// Function to remove the spaces in a string
void remove_spaces(string& original) {
	string modified;
	for (char cur : original) {
		if (cur != ' ') {
			modified += cur;
		}
	}

	original = modified;
}

// Function to print to console a list of commands
void print_help() {
	cout << "\n";
	cout << "Help\n\n";
	cout << "Commands\n";
	cout << "'help' - Prints command list\n";
	cout << "'exit' - Exits calculator\n\n";
	cout << "To evaluate an expression, type '[first integer] [operation] [second integer]' \n\n";
	cout << "Supported operation: '+', '-', '*', '/'\n\n";
}

// Parses input
void parse_input(string input, string& string_1, string& operation, string& string_2) {
	bool at_string_1 = true;
	for (char cur : input) {
		if (isdigit(cur)) {
			if (at_string_1) {
				string_1 += cur;
			} else {
				string_2 += cur;
			}
		} else {
			at_string_1 = false;
			operation += cur;
		}
	}
}

// Evaluates expression
int calculate(string string_1, string operation, string string_2) {
	if (operation == "+") {
		return stoi(string_1) + stoi(string_2);
	} else if (operation == "-") {
		return stoi(string_1) - stoi(string_2);
	} else if (operation == "*") {
		return stoi(string_1) * stoi(string_2);
	} else if (operation == "/") {
		return stoi(string_1) / stoi(string_2);
	} else {
		throw invalid_argument("invalid argument");
	}
}

int main() {
	cout << "Welcome to the Command Line Calculator\nEnter 'help' for a list of commands\nEnter 'exit' to exit\n\n";
	while (true) {
		cout << "[calculator] > ";

		// Read and clean input
		string input;
		getline(cin, input);
		remove_spaces(input);

		if (input == "exit") {
			break;
		} else if (input == "help") {
			print_help();
			continue;
		} else {
			string num_1_str, operation, num_2_str;

			parse_input(input, num_1_str, operation, num_2_str);

			try {
				cout << calculate(num_1_str, operation, num_2_str);
			} catch (const invalid_argument& e) {
				cout << "Invalid Argument";
			}

			cout << "\n";
		}
	}
}
