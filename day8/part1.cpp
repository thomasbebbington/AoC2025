#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <cmath>
#include <memory>
#include <algorithm>
#include <vector>

#define N 1000

struct Vec3 {
	int x;
	int y;
	int z;
};

struct PairDistance {
	Vec3 a;
	Vec3 b;
	double d;
};

int main() {
	std::fstream fs;
	fs.open("input.txt", std::fstream::in);
	
	struct Vec3 points[N] = {0};
	int index = 0;

	for (;;) {
		char buff[20] = {0};
		fs.getline(buff, 20);
		if (fs.eof()) break;

		int tmp[3] = {0};

		int i = 0;
		int j = 0;
		char buff2[6] = {'\0'};

		for (char c : buff) {
			if (c == ',' || c == '\0') {
				tmp[i] = std::stoi(buff2, NULL, 10);
				i++;
				j = 0;
				std::memset(buff2, '\0', 6);
				if (i == 3) break;
			} else {
				buff2[j] = c;
				j++;
			}
		}
		
		points[index].x = tmp[0];
		points[index].y = tmp[1];
		points[index].z = tmp[2];
		index++;
	}

	int paircount = (N * (N - 1)) / 2;
	std::unique_ptr<PairDistance[]> dists = std::make_unique<PairDistance[]>(paircount);
	
	int k = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			double d = sqrt(
					pow(points[i].x - points[j].x, 2) +
					pow(points[i].y - points[j].y, 2) + 
					pow(points[i].z - points[j].z, 2)
				       );
			PairDistance tmp = {0};
			tmp.a.x = points[i].x;
			tmp.a.y = points[i].y;
			tmp.a.z = points[i].z;
			tmp.b.x = points[j].x;
			tmp.b.y = points[j].y;
			tmp.b.z = points[j].z;
			tmp.d = d;
			dists[k] = tmp; 
			k++;
		}
	}	
	
	std::sort(dists.get(), dists.get() + paircount, 
			[](const PairDistance& p1, const PairDistance& p2) {
				return p2.d > p1.d;
			});


	std::vector<std::vector<Vec3>> circuits;

	for (int i = 0; i < 1000; i++) {
		Vec3 v1 = dists[i].a;
		Vec3 v2 = dists[i].b;
		
		// Check where v1 is
		int v1c = -1;
		int v1p = -1;
		for (int cir = 0; cir < circuits.size(); ++cir) {
			for (int pos = 0; pos < circuits[cir].size(); ++pos) {
				if (v1.x == circuits[cir][pos].x && v1.y == circuits[cir][pos].y && v1.z == circuits[cir][pos].z) {
					v1c = cir;
					v1p = pos;
				}
			}
		}

		// Check where v2 is
		int v2c = -1;
		int v2p = -1;
		for (int cir = 0; cir < circuits.size(); ++cir) {
			for (int pos = 0; pos < circuits[cir].size(); ++pos) {
				if (v2.x == circuits[cir][pos].x && v2.y == circuits[cir][pos].y && v2.z == circuits[cir][pos].z) {
					v2c = cir;
					v2p = pos;
				}
			}
		}

		if (v1c != -1 && v1c == v2c) {
			continue;
		} else if (v1c == -1 && v2c == -1) {
			circuits.push_back({v1, v2});
		} else if (v1c != -1 && v2c == -1) {
			circuits[v1c].push_back(v2);
		} else if (v2c != -1 && v1c == -1) {
			circuits[v2c].push_back(v1);
		} else {
			circuits[v1c].insert(circuits[v1c].end(), circuits[v2c].begin(), circuits[v2c].end());
			circuits.erase(circuits.begin() + v2c);
		}
	}

	std::sort(circuits.begin(), circuits.end(), 
		[](std::vector<Vec3> vec1, std::vector<Vec3> vec2) {
			return vec1.size() > vec2.size();
		});	

	std::cout << (circuits[0].size() * circuits[1].size() * circuits[2].size()) << std::endl;
}
