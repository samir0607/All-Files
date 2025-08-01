#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

struct IndexedBITree {
	int tree_size;
	vi frequency_table;

	IndexedBITree(int input_size = 0) : tree_size(input_size), frequency_table(tree_size + 1, 0) {}

	void configure(int new_size) {
		tree_size = new_size;
		frequency_table.assign(tree_size + 1, 0);
	}

	void increment_frequency(int position_index) {
		for (; position_index <= tree_size; position_index += position_index & -position_index) {
			frequency_table[position_index]++;
		}
	}

	int prefix_query(int end_position) {
		int prefix_total = 0;
		for (; end_position > 0; end_position -= end_position & -end_position) {
			prefix_total += frequency_table[end_position];
		}
		return prefix_total;
	}
};

void solve() {
	int element_count;
	cin >> element_count;
	vi permutation_array(element_count + 1);

	for (int element_idx = 1; element_idx <= element_count; ++element_idx) {
		cin >> permutation_array[element_idx];
	}

	vi inversion_count_left(element_count + 1);
	vi inversion_count_right(element_count + 1);

	IndexedBITree bitree_handler(element_count);

	int total_inversion_pairs = 0;
	bitree_handler.configure(element_count);

	for (int scan_idx = element_count; scan_idx >= 1; --scan_idx) {
		inversion_count_left[scan_idx] = bitree_handler.prefix_query(permutation_array[scan_idx] - 1);
		total_inversion_pairs += inversion_count_left[scan_idx];
		bitree_handler.increment_frequency(permutation_array[scan_idx]);
	}

	bitree_handler.configure(element_count);
	for (int scan_idx = 1; scan_idx <= element_count; ++scan_idx) {
		inversion_count_right[scan_idx] = (scan_idx - 1) - bitree_handler.prefix_query(permutation_array[scan_idx]);
		bitree_handler.increment_frequency(permutation_array[scan_idx]);
	}

	ll accumulated_negative_shifts = 0;
	for (int scan_idx = 1; scan_idx <= element_count; ++scan_idx) {
		ll displacement_difference = (element_count - scan_idx) - inversion_count_left[scan_idx] - inversion_count_right[scan_idx];
		if (displacement_difference < 0) {
			accumulated_negative_shifts += displacement_difference;
		}
	}

	ll final_result_value = total_inversion_pairs + accumulated_negative_shifts;
	cout << final_result_value << endl;
}

int main() {
	fast_io;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}
