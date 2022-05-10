#include <iostream>
#include <vector>

bool sp(std::vector<int>& powt) {
	for (int i = 0; i < powt.size() - 1; i++) {
		if (powt[i] > powt[i + 1])
			return false;
	}
	return true;
}
void sb(std::vector<int>& powt, std::vector<char>& znak) {
	while (sp(powt) == false) {
		for (int i = 0; i < powt.size() - 1; i++) {
			if (powt[i] > powt[i + 1]) {
				int temp = powt[i];
				powt[i] = powt[i + 1];
				powt[i + 1] = temp;
				int temp2 = znak[i];
				znak[i] = znak[i + 1];
				znak[i + 1] = temp2;
			}
		}
	}
}

int main() {

	std::string kod;
	std::vector <char> znak;
	std::vector <int> powt;
	std::vector <float> prawd;
	

	bool flag;
	int all = 0;

	std::cout << "podaj kod: " << std::endl;
	std::cin >> kod;

	znak.push_back(kod[0]);
	powt.push_back(1);

	for (int i = 1; i < kod.size(); i++) {
		flag = 0;
		for (int j = 0; j < znak.size(); j++) {
			if (kod[i] == znak[j]) {
				flag = 1;
				powt[j]++;
			}
		}
		if (flag == 0) {
			znak.push_back(kod[i]);
			powt.push_back(1);
		}
	}
	std::cout << "przed sortowaniem:" << std::endl;
	for (int i = 0; i < znak.size(); i++) {
		std::cout << znak[i] << " " << powt[i] << std::endl;
	}

	sb(powt, znak);
	std::cout << "po sortowaniu:" << std::endl;
	for (int i = znak.size() - 1; i >= 0; i--) {
		std::cout << znak[i] << " " << powt[i] << std::endl;
	}

	for (int i = znak.size() - 1; i >= 0; i--) {
		all += powt[i];
	}
	for (int i = 0; i < znak.size(); i++) {
		prawd.push_back((float)powt[i] / (float)all);
		std::cout << prawd[i] << " ";
	}
	std::cout << std::endl;
	int one=1;
	std::vector <std::string> code;
	std::string kod2;
	code.push_back("0");
	for (int i = 1; i < znak.size(); i++) {
		if (i == znak.size() - 1) {
			for (int j = 0; j < znak.size()-1; j++) {
				kod2 += '1';
			}
		}
		else {
			for (int j = 0; j < one; j++) {
				kod2 += '1';
			}
			one++;
			kod2 += '0';
		}
		code.push_back(kod2);
		//std::cout << znak[i] << " " << powt[i] << " " << code[i] << std::endl;
		kod2 = "";
	}
	int xxx = 0;
	for (int i = znak.size() - 1; i >= 0; i--) {
		std::cout << znak[i] << " " << powt[i] << " " << code[xxx] << std::endl;
		xxx++;
	}

	for (int i = 0; i < kod.size(); i++) {
		for (int j = 0; j < znak.size(); j++) {
			if (kod[i] == znak[j]) {
				std::cout << code[code.size()-1  - j];
			}
		}
	}

	return 0;
}