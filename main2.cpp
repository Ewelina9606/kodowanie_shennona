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
	int all=0;

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

	sb(powt,znak);
	std::cout << "po sortowaniu:" << std::endl;
	for (int i = znak.size()-1; i >= 0; i--) {
		std::cout << znak[i] << " " << powt[i] << std::endl;
	}

	for (int i = znak.size() - 1; i >= 0; i--) {
		all += powt[i];
	}
	for (int i=0; i < znak.size(); i++) {
		prawd.push_back((float)powt[i] / (float)all);
		std::cout << prawd[i] << " ";
	}
	bool flag2;
	int N = powt.size();
	std::string *code = new std::string[N];
	for (int i = 0; i < N; i++) {
		flag2 = 0;
		std::string bin = "0,";
		do {
			std::cout << "do while";
			if (prawd[i] * 2 > 1) {
				bin += "1";
				prawd[i] = (prawd[i] * 2) - 1;
			}
			if (prawd[i] * 2 < 1) {
				bin += "0";
				prawd[i] = (prawd[i] * 2);
			}
			if (prawd[i] * 2 == 1) {
				bin += "1";
				flag2 = 1;
				std::cout << bin << " ";
				code[i] = bin;
				break;
			}
		} while (flag2!=1);
	}
	for (int i = 0; i < N; i++) {
		std::cout << znak[i] << " " << powt[i] << code[i] << std::endl;
	}


	return 0;
}