#include <iostream>

using namespace std;

int main() {
	class Table {
	private:              
		int from;
		int to;

		int col;
		int row;
	public:           
		Table(int fir, int sec, int thr, int fr) {
			from = fir;
			to = sec;
			col = thr;
			row = fr;
		}
		void play()    
		{
			int start_col;
			int end_col;
			int current_row;
			for (int i = 0; i < col; i++) {
				start_col = 2 + (i * row);
				end_col = 2 + ((i + 1) * row);
				for (int j = from; j < to; j++) {
					current_row = j;
					for (int k = start_col; k < end_col; k++) {
						cout << k << " X " << current_row << " = " << k * current_row << "\t\t";
					}
					cout << endl;
				}
				cout << endl;
			}
		}
	};
	Table table = Table(1, 9, 2, 4);
	table.play();
}