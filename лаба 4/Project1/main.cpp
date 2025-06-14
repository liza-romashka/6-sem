#include <iostream>
#include <vector>

using namespace std;

extern "C" float* SumR(int k, float* x);

extern "C" float fun_el(int i, float z) {
	float f;
	f = log(fabs(cos(z)+sin(z)));
	return f;
}

void graph(int n, float step, float* R) {
	int width = n / step;
	int height = 80;

	for (int y = height - 20; y >= -height; y--) {
		for (int x = 0; x < width; x++) {
			int outY = static_cast<int>(R[x] * height);

			if (y == outY) cout << '@';
			else if (y == 0) cout << '-';
			else if (x == 0) cout << '|';
			else cout << ' ';
		}
		cout << '\n';
	}
}

int main(int argc, char** argv) {
	int n;
	float step;

	cout << "Enter n: ";
	cin >> n;

	cout << "Enter step: ";
	cin >> step;

	float* x = new float[n / step + 1];

	for (int i = 0; i <= n / step; i++) {
		x[i] = i * step;
	}


	float* R;
	R = SumR(n / step + 1, x);

	cout << endl;

	graph(n, step, R);

	return 0;
}