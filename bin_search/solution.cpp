#include <iostream>
#include <vector>


int main() {
    int n, q;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        std::cin >> x;
        int l = 0;
        int r = n - 1;
        bool b = false;
        while (l <= r) { 
            int mid = (l + r) / 2;
            if (arr[mid] == x) {
                b = true;
                r = mid - 1; 
            }
            else if (arr[mid] < x) {
                l = mid + 1; 
            }
            else {
                r = mid - 1; 
            }
        }
        int l_idx = l; 
        l = 0, r = n - 1;
        while (l <= r) { 
            int mid = (l + r) / 2;
            if (arr[mid] <= x) {
                l = mid + 1; 
            }
            else {
                r = mid - 1; 
            }
        }
        int r_idx = r + 1; 
        std::cout << b << " " << l_idx << " " << r_idx << std::endl;
    }
    return 0;
}